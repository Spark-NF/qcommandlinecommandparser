#include <QCoreApplication>
#include "../src/qcommandlinecommandparser.h"


int listCommand(const QCoreApplication &app)
{
	QCommandLineCommandParser parser;
	parser.addHelpOptionOnly();
	parser.setApplicationDescription("List items");
	parser.setPrefix({ "list" });
	parser.process(app);

	qDebug() << "List command";
	return 0;
}

int addCommand(const QCoreApplication &app)
{
	QCommandLineCommandParser parser;
	parser.addHelpOptionOnly();
	parser.setApplicationDescription("Add a new item");
	parser.setPrefix({ "add" });

	parser.addPositionalArgument("item", "The item to add", "<item>");
	parser.addOption(QCommandLineOption("type", "Item type", "item_type"));

	parser.process(app);

	const QStringList args = parser.positionalArguments();
	const QString item = args.length() == 1 ? args.first() : QString();
	if (item.isEmpty()) {
		parser.showHelp(1);
		return 1;
	}

	qDebug() << "Add command" << item;
	return 0;
}

int rootParser(const QCoreApplication &app)
{
	QCommandLineCommandParser parser;
	parser.addVersionOption();
	parser.addHelpOptionOnly();
	parser.setApplicationDescription("Manage items");

	parser.addCommand("list", "List items");
	parser.addCommand("add", "Add a new item");

	parser.process(app);

	// Handle each specific command separately
	const QString command = parser.command();
	if (command == "list") {
		return listCommand(app);
	}
	if (command == "add") {
		return addCommand(app);
	}

	// If we're here, that means that help was requested or no command was passed
	parser.showHelp();
	return 0;
}

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);
	app.setApplicationName("Example");
	app.setApplicationVersion("1.2.3");

	return rootParser(app);
}
