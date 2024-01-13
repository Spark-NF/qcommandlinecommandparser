<h1 align="center">QCommandLineCommandParser</h1>

## About
Parser based on Qt's [QCommandLineParser](https://doc.qt.io/qt-6/qcommandlineparser.html) that adds support for commands.

### Authors
* Nicolas Faure ([Spark-NF](https://github.com/Spark-NF))

### License
The script is licensed under the [Apache License 2.0](http://www.apache.org/licenses/LICENSE-2.0).

## Usage
### Example
You can find a full example in [example/main.cpp](example/main.cpp).

It can be built and run with:
```sh
mkdir build
cd build

cmake ../example
make

./example
```

### Root parser
```cpp
// Create a parser
QCommandLineCommandParser parser;

// Add some commands
parser.addCommand("list", "List items");
parser.addCommand("add", "Add a new item");

// Process the arguments as usual
parser.process(qApp);

// Get the chosen command
const QString command = parser.command();
```

### Command parser
```cpp
// Create a parser
QCommandLineCommandParser parser;

// Set the prefix (used in help text and to remove it from positionalArguments())
parser.setPrefix({ "add" });

// Process the arguments as usual
parser.process(qApp);
```

## Included vendor files
Due to the fact that many of the inner workings of `QCommandLineParser` are private but that this parser does not want to re-invent the wheel, it includes a copy of some of `QCommandLineParser` internal functions.

If you're using a different Qt version, you might want to update them to match.
