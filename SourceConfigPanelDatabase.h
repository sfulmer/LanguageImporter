#pragma once

#include <QComboBox>
#include <QLabel>
#include "SourceConfigDialog.h"
#include "SourceConfigPanel.h"

using net::draconia::util::languageimporter::ui::SourceConfigPanel;

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
                   class SourceConfigPanelDatabase : public SourceConfigPanel
                   {
                       Q_OBJECT

                       QComboBox *mCboDatabase, *mCboDriver, *mCboLanguageField, *mCboLocaleField, *mCboTable;
                       QLabel *mLblDatabase, *mLblDriver, *mLblLanguageField, *mLblLocaleField, *mLblTable;
                   protected:
                       QComboBox *getDatabaseField();
                       QLabel *getDatabaseLabel();
                       QComboBox *getDriverField();
                       QLabel *getDriverLabel();
                       QComboBox *getLanguageFieldField();
                       QLabel *getLanguageFieldLabel();
                       QComboBox *getLocaleFieldField();
                       QLabel *getLocaleFieldLabel();
                       QComboBox *getTableField();
                       QLabel *getTableLabel();
                       void initControls();
                       void initPanel();
                   public:
                       SourceConfigPanelDatabase(SourceConfigDialog *parent);
                       SourceConfigPanelDatabase(SourceConfigDialog *parent, Controller &refController);
                       ~SourceConfigPanelDatabase() = default;

                       virtual bool isOkAble();
                       virtual void reject();
                   public slots:
                       void DatabaseIndexChanged(int iDatabase);
                       void DriverIndexChanged(int iDriver);
                       void LanguageFieldIndexChanged(const int iLanguageField);
                       void LocaleFieldIndexChanged(const int iLocaleField);
                       void TableIndexChanged(const int iTable);
                   };
               }
            }
        }
    }
}
