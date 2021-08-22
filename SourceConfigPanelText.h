#pragma once

#include <QComboBox>
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
                    class SourceConfigPanelText : public SourceConfigPanel
                    {
                        Q_OBJECT

                        QComboBox *mCboConversion;
                        QLabel *mLblConversion, *mLblText;
                        QTextEdit *mTxtText;
                    protected:
                        QComboBox *getConversionField();
                        QLabel *getConversionLabel();
                        QLabel *getTextLabel();
                        QTextEdit *getText();
                        void initControls();
                        void initPanel();
                    public:
                        SourceConfigPanelText(QWidget *parent);
                        SourceConfigPanelText(QWidget *parent, Controller &refController);
                        virtual ~SourceConfigPanelText() = default;

                        virtual bool isOkAble();
                        virtual void reject();
                    public slots:
                        void conversionSelectionChanged(const int iConversionIndex);
                        void textChanged();
                    };
                }
            }
        }
    }
}
