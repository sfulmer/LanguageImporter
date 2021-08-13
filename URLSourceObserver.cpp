#include "App.h"
#include "Controller.h"
#include "Model.h"
#include "ModelConfig.h"
#include "ModelConfigSourceURL.h"
#include <QNetworkReply>
#include <QStringRef>
#include "URLSourceObserver.h"

using namespace net::draconia::util::languageimporter::model;
using namespace net::draconia::util::languageimporter::observers;

QNetworkAccessManager *URLSourceObserver::getNetworkAccessManager()
{
    if(mPtrNAM == nullptr)
        {
        mPtrNAM = new QNetworkAccessManager(this);

        connect(mPtrNAM, &QNetworkAccessManager::finished, this, &URLSourceObserver::NAMFinished);
        }

    return(mPtrNAM);
}

void URLSourceObserver::NAMFinished(QNetworkReply *reply)
{
    Controller &refController = static_cast<App *>(qApp)->getController();
    ModelConfig &refModelConfig = refController.getModel().getConfiguration();

    if(refModelConfig.getSource() == "URL")
        {
        ModelConfigSourceURL &refModel = static_cast<ModelConfigSourceURL &>(refModelConfig.getSourceConfig());

        refController.getModel().clearLanguages();

        QByteArray bytes = reply->readAll();
        QString sText(bytes.toStdString().c_str());

        // Search for the Opening
        int iIndexOpening = sText.indexOf(refModel.getOpening());
        int iIndexEnding = sText.indexOf(refModel.getEnding());

        QStringRef sParseable = QStringRef(&sText, iIndexOpening, iIndexEnding - (iIndexOpening + refModel.getOpening().length()));
        QVector<QStringRef> sList = sParseable.split("\n");

        for(QStringRef &sOption : sList)
            {
            QString sStrOption = sOption.toString();
            int iValueStart = sStrOption.indexOf("\"") + 1;
            int iValueEnd = sStrOption.indexOf("\"", iValueStart) - 1;
            QString sLocale = QStringRef(&sStrOption, iValueStart, iValueEnd - iValueStart + 1).toString();
            int iLanguageStart = sStrOption.indexOf(">") + 1;
            int iLanguageEnd = sStrOption.lastIndexOf("<") - 1;
            QString sLanguage = QStringRef(&sStrOption, iLanguageStart, iLanguageEnd - iLanguageStart + 1).toString();

            refController.getModel().addLanguage(Language(sLanguage, sLocale));
            }
        }
}

URLSourceObserver::URLSourceObserver()
    :   QObject()
    ,   Observer()
    ,   mPtrNAM(nullptr)
{ }

void URLSourceObserver::update(Observable &refObservable, const QString &sProperty)
{
    Q_UNUSED(sProperty);

    ModelConfigSourceURL &refModel = static_cast<ModelConfigSourceURL &>(refObservable);

    if((!refModel.getEnding().isEmpty()) && (!refModel.getOpening().isEmpty()) && (!refModel.getURL().isEmpty()))
        getNetworkAccessManager()->get(QNetworkRequest(QUrl(refModel.getURL())));
}
