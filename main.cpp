#include "mainwindow.h"
#include <QApplication>

static MainWindow *gui =0;

#if  QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
#define qInstallMessageHandler qInstallMsgHandler
void MsgOutput(QtMsgType type, const char *msg)
{
#else
void MsgOutput(QtMsgType type, const QMessageLogContext &, const QString& qmsg)
{
    const char* msg = qPrintable(qmsg);
#endif
    Q_UNUSED(type);
    if (gui)
        gui->appendMessage(msg);
}

int main(int argc, char *argv[])
{
    qInstallMessageHandler(MsgOutput);
    QApplication a(argc, argv);

    MainWindow w;
    gui = &w;
    w.show();

    return a.exec();
}
