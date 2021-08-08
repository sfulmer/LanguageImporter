#pragma once

#include "MainWindow.h"
#include "Controller.h"
#include <QApplication>
#include <QList>
#include <QString>

using net::draconia::util::ui::MainWindow;

namespace net
{
    namespace draconia
    {
        namespace util
        {
            class App : public QApplication
            {
                MainWindow mWndMain;
                Controller mObjController;
                QList<QString> mLstArgs;
            protected:
                void setArguments(int argc, char *argv[]);
                void showMainWindow();
            public:
                App(int argc, char *argv[]);
                int exec();
                void exit();
                QList<QString> &getArguments() const;
                Controller &getController();
                MainWindow &getMainWindow();
            };
        }
    }
}
