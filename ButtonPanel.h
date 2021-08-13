#pragma once

#include "Controller.h"
#include <QPushButton>
#include <QWidget>

using net::draconia::util::languageimporter::Controller;

namespace net
{
    namespace draconia
    {
        namespace util
        {
            namespace languageimporter
            {
                namespace ui
                {
                    class ButtonPanel : public QWidget
                    {
                        Q_OBJECT

                        Controller &mRefController;
                        QPushButton *mBtnReset, *mBtnSave;
                    protected:
                        void doReset();
                        void doSave();
                        Controller &getController() const;
                        QPushButton *getResetButton();
                        QPushButton *getSaveButton();
                        void initControls();
                        void initPanel();
                    public:
                        ButtonPanel(QWidget *parent, Controller &refController);
                        ~ButtonPanel();
                    };
                }
            }
        }
    }
}
