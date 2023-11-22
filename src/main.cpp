#include <QtCore/QCoreApplication>
#include <QtCore/QCommandLineParser>
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QtCore/QDebug>
#include "lzstring.h"

int main(int argc, char* argv[]) {
    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName("LZString CLI");
    QCoreApplication::setApplicationVersion("1.0");

    QCommandLineParser parser;
    parser.setApplicationDescription("LZString Compression Utility");

    QCommandLineOption compressOption("compress", "Compress input stream");
    QCommandLineOption compressToUTF16Option("compressToUTF16", "Compress input stream to UTF16 format");
    QCommandLineOption compressToBase64Option("compressToBase64", "Compress input stream to Base64 format");
    QCommandLineOption decompressOption("decompress", "Decompress input stream");
    QCommandLineOption decompressFromUTF16Option("decompressFromUTF16", "Decompress input stream from UTF16 format");
    QCommandLineOption decompressFromBase64Option("decompressFromBase64", "Decompress input stream from Base64 format");

    parser.addOption(compressOption);
    parser.addOption(compressToUTF16Option);
    parser.addOption(compressToBase64Option);
    parser.addOption(decompressOption);
    parser.addOption(decompressFromUTF16Option);
    parser.addOption(decompressFromBase64Option);

    parser.addPositionalArgument("[input]", "The input file to process or '-' for standard input", "[input]");
    parser.addPositionalArgument("[output]", "The output file or '-' for standard output", "[output]");

    parser.process(app);

    const QStringList args = parser.positionalArguments();
    QTextStream in(stdin);
    QTextStream out(stdout);
    QString inputContents, outputContents;

    if (args.isEmpty() || args.first() == "-") {
        inputContents = in.readAll();
    }
    else {
        QFile inputFile(args.first());
        if (!inputFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qCritical() << "Error: Cannot open input file for reading.";
            return -1;
        }
        in.setDevice(&inputFile);
        inputContents = in.readAll();
        inputFile.close();
    }

    if (parser.isSet(compressOption)) {
        outputContents = LZString::compress(inputContents);
    }
    else if (parser.isSet(compressToUTF16Option)) {
        outputContents = LZString::compressToUTF16(inputContents);
    }
    else if (parser.isSet(compressToBase64Option)) {
        outputContents = LZString::compressToBase64(inputContents);
    }
    else if (parser.isSet(decompressOption)) {
        outputContents = LZString::decompress(inputContents);
    }
    else if (parser.isSet(decompressFromUTF16Option)) {
        outputContents = LZString::decompressFromUTF16(inputContents);
    }
    else if (parser.isSet(decompressFromBase64Option)) {
        outputContents = LZString::decompressFromBase64(inputContents);
    }
    else {
        qCritical() << "Error: No valid operation selected.";
        return -1;
    }

    if (args.size() < 2 || args[1] == "-") {
        out << outputContents;
    }
    else {
        QFile outputFile(args[1]);
        if (!outputFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qCritical() << "Error: Cannot open output file for writing.";
            return -1;
        }
        out.setDevice(&outputFile);
        out << outputContents;
        outputFile.close();
    }

    return 0;
}
    // Compress a file lzstring --compress input.txt output.lz

   //  Compress a file to UTF16 lzstring --compressToUTF16 input.txt output.lz16

     //  Compress a file to Base64
      //  lzstring --compressToBase64 input.txt output.lz64

    //    Decompress a file
   //lzstring --decompress input.lz output.txt

     //   Decompress a file from UTF16
    //    lzstring --decompressFromUTF16 input.lz16 output.txt

     //   Decompress a file from Base64
     //   lzstring --decompressFromBase64 input.lz64 output.txt


