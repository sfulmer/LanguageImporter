#include "App.h"

using namespace net::draconia::util::languageimporter;

void App::setArguments(int argc, char *argv[])
{
    for(int iLength = argc, iLoop = 0; iLoop < iLength; iLoop++)
        mLstArgs.append(argv[iLoop]);
}

void App::showMainWindow()
{
    getMainWindow()->show();
}

App::App(int argc, char *argv[])
    :   QApplication(argc, argv)
    ,   mWndMain(nullptr)
    ,   mPtrController(nullptr)
{
    setArguments(argc, argv);
}

App::~App()
{
    if(mPtrController != nullptr)
        {
        delete mPtrController;

        mPtrController = nullptr;
        }

    if(mWndMain != nullptr)
        delete mWndMain;
}

int App::exec()
{
    showMainWindow();

    return(QApplication::exec());
}

void App::exit()
{
    MainWindow *wnd = getMainWindow();

    wnd->close();
}

QList<QString> &App::getArguments()
{
    return(mLstArgs);
}

Controller &App::getController()
{
    if(mPtrController == nullptr)
        mPtrController = new Controller(*this);

    return(*mPtrController);
}

MainWindow *App::getMainWindow()
{
    if(mWndMain == nullptr)
        mWndMain = new MainWindow(nullptr);

    return(mWndMain);
}
