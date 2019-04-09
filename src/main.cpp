#include <QApplication>
#include <QFileInfo>
#include <QCommandLineParser>

#include "../../lsMisc/stdQt/stdQt.h"

#include "consts.h"


using namespace AmbiesoftQt;
using namespace Consts;


void processCommandLine(QCoreApplication& app, QStringList& files)
{
    QCommandLineParser parser;
    parser.setApplicationDescription("Show Canonical Path");
    parser.addHelpOption();
    parser.addVersionOption();
//    parser.addPositionalArgument("source", QCoreApplication::translate("main", "Source file to copy."));
//    parser.addPositionalArgument("destination", QCoreApplication::translate("main", "Destination directory."));
    parser.addPositionalArgument("file", QCoreApplication::translate("main", "path"));

    // A boolean option with a single name (-p)
//    QCommandLineOption showProgressOption("p", QCoreApplication::translate("main", "Show progress during copy"));
//    parser.addOption(showProgressOption);

    // A boolean option with multiple names (-f, --force)
//    QCommandLineOption forceOption(QStringList() << "f" << "force",
//                                   QCoreApplication::translate("main", "Overwrite existing files."));
//    parser.addOption(forceOption);

    // An option with a value
//    QCommandLineOption targetDirectoryOption(QStringList() << "t" << "target-directory",
//                                             QCoreApplication::translate("main", "Copy all source files into <directory>."),
//                                             QCoreApplication::translate("main", "directory"));
//    parser.addOption(targetDirectoryOption);

    // Process the actual command line arguments given by the user
    parser.process(app);

    files = parser.positionalArguments();
    // source is args.at(0), destination is args.at(1)

//    bool showProgress = parser.isSet(showProgressOption);
//    bool force = parser.isSet(forceOption);
//    QString targetDir = parser.value(targetDirectoryOption);
}


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QCoreApplication::setOrganizationName(ORGANIZATION);
    QCoreApplication::setApplicationName(APPNAME);
    QCoreApplication::setApplicationVersion(APPVER);

    QStringList filesToOpen;
    processCommandLine(app, filesToOpen);

    if(filesToOpen.isEmpty())
    {
        Alert(nullptr,
              QObject::tr(STR_NO_INPUT_PATHS));
        return 1;
    }

    QString message;
    for (auto&& path : filesToOpen)
    {
        message += path;
        message += "\n";
        message += QFileInfo(path).canonicalFilePath();
        message += "\n\n";
    }

    Info(nullptr, message);

//    MainWindow w;
//    w.show();

    return 0;
}
