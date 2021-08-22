#pragma once

#include "Controller.h"
#include <QDialog>
#include <QPushButton>
#include <QWidget>
#include "SourceConfigButtonPanel.h"
#include "SourceConfigPanel.h"

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
                    class SourceConfigDialog : public QDialog
                    {
                        Q_OBJECT

                        Controller &mRefController;
                        SourceConfigButtonPanel *mPnlButtons;
                        SourceConfigPanel *mPnlSourceConfig;

                    protected:
                        Controller &getController() const;
                        void initControls();
                        void initDialog();
                    public:
                        SourceConfigDialog(QWidget *parent);
                        SourceConfigDialog(QWidget *parent, const Controller &refController);
                        ~SourceConfigDialog() = default;

                        void reject();

                        SourceConfigButtonPanel *getButtonsPanel();
                        SourceConfigPanel *getSourceConfigPanel();
                    };
                }
            }
        }
    }
}
