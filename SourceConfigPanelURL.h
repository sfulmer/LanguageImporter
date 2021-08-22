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
            namespace languageimporter
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
                        QLabel *getEndingLabel();
                        QTextEdit *getEndingText();
                        QLabel *getOpeningLabel();
                        QTextEdit *getOpeningText();
                        QLabel *getURLLabel();
                        QLineEdit *getURLText();
                        void initControls();
                        void initPanel();
                    public:
                        SourceConfigPanelURL(QWidget *parent);
                        SourceConfigPanelURL(QWidget *parent, Controller &refController);
                        virtual ~SourceConfigPanelURL() = default;

                        virtual bool isOkAble();
                        virtual void reject();
                    public slots:
                        void endingTextChanged();
                        void openingTextChanged();
                        void URLTextChanged(const QString &sText);
                    };
                }
            }
        }
    }
}
