#include "App.h"
#include "MainWindow.h"
#include <QGridLayout>

using namespace net::draconia::util::languageimporter::ui;

MainPanel *MainWindow::getMainPanel()
{
    if(mPnlMain == nullptr)
        mPnlMain = new MainPanel(this);

    return(mPnlMain);
}

void MainWindow::initControls()
{
    setCentralWidget(getMainPanel());
}

void MainWindow::initWindow()
{
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));

    initControls();
}

MainWindow::MainWindow(QWidget *parent)
    :   QMainWindow(parent)
    ,   mPnlMain(nullptr)
{
    initWindow();
}

MainWindow::~MainWindow()
{ }
