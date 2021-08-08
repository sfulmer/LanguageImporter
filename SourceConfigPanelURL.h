#pragma once

#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <QTextEdit>
#include"SourceConfigPanel.h"

namespace net
{
    namespace draconia
    {
        namespace util
        {
            namespace ui
            {
                class SourceConfigPanelURL : public SourceConfigPanel
                {
                    Q_OBJECT

                    QLabel *mLblEnding, *mLblOpening, *mLblURL;
                    QLineEdit *mTxtURL;
                    QTextEdit *mTxtEnding, *mTxtOpening;
                protected:
                    void endingTextChanged(const QString &sText);
                    QLabel *getEndingLabel();
                    QTextEdit *getEndingText();
                    QLabel *getOpeningLabel();
                    QTextEdit *getOpeningText();
                    QLabel *getURLLabel();
                    QLineEdit *getURLText();
                    void initControls();
                    void initPanel();
                    void openingTextChanged(const QString &sText);
                    void URLTextChanged(const QString &sText);
                public:
                    SourceConfigPanelURL(QWidget *parent);
                    SourceConfigPanelURL(QWidget *parent, const Controller &refController);
                    virtual ~SourceConfigPanelURL() = default;

                    virtual void reject();
                };
            }
        }
    }
}
