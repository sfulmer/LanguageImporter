#pragma once

#include "Controller.h"
#include <QDialog>
#include <QPushButton>
#include <QWidget>
#include "SourceConfigButtonPanel.h"
#include "SourceConfigPanel.h"

using net::draconia::util::Controller;

namespace net
{
    namespace draconia
    {
        namespace util
        {
            namespace ui
            {
                class SourceConfigDialog : public QDialog
                {
                    Q_OBJECT

                    Controller &mRefController;
                    SourceConfigButtonPanel *mPnlButtons;
                    SourceConfigPanel *mPnlSourceConfig;

                protected:
                    SourceConfigButtonPanel *getButtonsPanel();
                    Controller &getController() const;
                    SourceConfigPanel *getSourceConfigPanel();
                    void initControls();
                    void initDialog();
                public:
                    SourceConfigDialog(QWidget *parent);
                    SourceConfigDialog(QWidget *parent, const Controller &refController);
                    ~SourceConfigDialog() = default;

                    void reject();
                };
            }
        }
    }
}
