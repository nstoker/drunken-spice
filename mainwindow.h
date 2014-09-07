#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include <QMainWindow>
#include <QWidget>

class QTextBrowser;
class QSystemTrayIcon;
class QLabel;
class QPushButton;
class QToolButton;
class QDeviceWatcher;

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void appendMessage(const QString& msg);

public slots:
    void toggleWatch();
    void showDetail(bool show);
    void slotDeviceAdded(const QString& dev);
    void slotDeviceRemoved(const QString& dev);
    void slotDeviceChanged(const QString& dev);

private:
    QDeviceWatcher *watcher;

    QLabel *state;
    QTextBrowser *msg_view;
    QPushButton *button;
    QToolButton *detail_button;
    QSystemTrayIcon *tray;
};

#endif // MAINWINDOW_H
