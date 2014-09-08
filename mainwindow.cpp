#include "mainwindow.h"
//#include "ui_mainwindow.h"
#include <QtCore/QThread>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTextBrowser>
#include <QToolButton>
#include <QSystemTrayIcon>
#include <QMessageBox>
#include "qdevicewatcher.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout *vbl = new QVBoxLayout(this);
    setLayout(vbl);

    state = new QLabel(this);
    button = new QPushButton(tr("Start"), this);
    detail_button = new QToolButton(this);
    detail_button->setText(tr("Detail"));
    detail_button->setCheckable(true);
    detail_button->setChecked(true);
    msg_view = new QTextBrowser(this);
    msg_view->setLineWrapMode(QTextEdit::NoWrap);

    QHBoxLayout *hbl = new QHBoxLayout(this);
    hbl->addWidget(button);
    hbl->addWidget(detail_button);

    vbl->addWidget(state);
    vbl->addLayout(hbl);
    vbl->addWidget(msg_view);

    tray = new QSystemTrayIcon(this);
    tray->show();

    watcher = new QDeviceWatcher;
    watcher->appendEventReceiver(this);
    connect(watcher, SIGNAL(deviceAdded(QString)), this, SLOT(slotDeviceAdded(QString)), Qt::DirectConnection);
    connect(watcher, SIGNAL(deviceChanged(QString)), this, SLOT(slotDeviceChanged(QString)), Qt::DirectConnection);
    connect(watcher, SIGNAL(deviceRemoved(QString)), this, SLOT(slotDeviceRemoved(QString)), Qt::DirectConnection);

    connect(button, SIGNAL(clicked()), SLOT(toggleWatch()));
    connect(detail_button, SIGNAL(toggled(bool)), SLOT(showDetail(bool)));
}

MainWindow::~MainWindow()
{
    qDebug("Terminating main window");
}

void MainWindow::appendMessage(const QString &msg)
{
    msg_view->append(msg);
}

void MainWindow::toggleWatch()
{
    if (watcher->isRunning()) {
        if (!watcher->stop()) {
            QMessageBox::warning(0, tr("WARNING"), tr("Failed to stop"));
        }
        button->setText(tr("Start"));
    } else {
        if (!watcher->start()) {
            QMessageBox::warning(0, tr("WARNING"), tr("Failed to start"));
        }
        button->setText(tr("Stop"));
    }
}

void MainWindow::showDetail(bool show)
{
    msg_view->setVisible(show);
    int w = width();
    adjustSize();  //width changes
    resize(w, height());
}

void MainWindow::slotDeviceAdded(const QString &dev)
{
    qDebug("tid=%#x: add %s", (unsigned int) QThread::currentThreadId(), qPrintable(dev));

    state->setText("<font color=#0000ff>Add: </font>" + dev);
    tray->showMessage(tr("New device"), dev);
}

void MainWindow::slotDeviceChanged(const QString &dev)
{
    qDebug("tid=%#x: change %s", (unsigned int) QThread::currentThreadId(), qPrintable(dev));

    state->setText("<font color=#0000ff>Change: </font>" + dev);
    tray->showMessage(tr("Change device"), dev);
}

void MainWindow::slotDeviceRemoved(const QString &dev)
{
    qDebug("tid=%#x: remove %s", (unsigned int) QThread::currentThreadId(), qPrintable(dev));

    state->setText("<font color=#0000ff>Remove: </font>" + dev);
    tray->showMessage(tr("Remove device"), dev);
}
