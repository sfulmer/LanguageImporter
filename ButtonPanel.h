#pragma once

#include "Controller.h"
#include <QPushButton>
#include <QWidget>

using net::draconia::util::Controller;

namespace net
{
    namespace draconia
    {
        namespace util
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
                    void initControls() const;
                    void initPanel() const;
                public:
                    ButtonPanel(QWidget *parent, Controller &refController);
                    ~ButtonPanel();
                };
            }
        }
    }
}
