#include "ButtonPanel.h"
#include <QHBoxLayout>

using namespace net::draconia::util::ui;

void ButtonPanel::doReset()
{
    getController().reset();
}

void ButtonPanel::doSave()
{
    getController().save();
}

Controller &ButtonPanel::getController() const
{
    return(mRefController);
}

QPushButton *ButtonPanel::getResetButton()
{
    if(mBtnReset == nullptr)
        {
        mBtnReset = new QPushButton("&Reset", this);

        connect(mBtnReset, &QPushButton::clicked, this, &ButtonPanel::doReset);
        }

    return(mBtnReset);
}

QPushButton *ButtonPanel::getSaveButton()
{
    if(mBtnSave == nullptr)
        {
        mBtnSave = new QPushButton("&Save", this);

        connect(mBtnSave, &QPushButton::clicked, this, &ButtonPanel::doSave);
        }

    return(mBtnSave);
}

void ButtonPanel::initControls() const
{
    ButtonPanel *ptrThis = const_cast<ButtonPanel *>(this);
    QLayout *layout = new QHBoxLayout(ptrThis);

    layout->addWidget(ptrThis->getResetButton());
    layout->addWidget(ptrThis->getSaveButton());

    ptrThis->setLayout(layout);
}

void ButtonPanel::initPanel() const
{
    ButtonPanel *ptrThis = const_cast<ButtonPanel *>(this);

    ptrThis->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));

    initControls();
}

ButtonPanel::ButtonPanel(QWidget *parent, Controller &refController)
    :   QWidget(parent)
    ,   mRefController(refController)
    ,   mBtnReset(nullptr)
    ,   mBtnSave(nullptr)
{
    initPanel();
}

ButtonPanel::~ButtonPanel()
{ }
