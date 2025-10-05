#include "FluSettingsVersionBox.h"

FluSettingsVersionBox::FluSettingsVersionBox(QWidget *parent /*= nullptr*/) : FluExpander(parent)
{
    m_iconAwesomeType = FluAwesomeType::None;

    m_wrap1->setFixedHeight(70);
    setFixedHeight(70);

    // icon
    m_iconLabel = new QLabel;
    m_iconLabel->setAlignment(Qt::AlignCenter);
    m_iconLabel->setFixedSize(40, 40);

    // title & info
    m_vLayout = new QVBoxLayout;
    m_titleLabel = new QLabel;
    m_infoLabel = new QLabel;

    // version
    m_versionLabel = new QLabel;
    m_versionLabel->setWordWrap(true);
    // m_versionLabel->setFixedWidth(50);

    m_titleLabel->setObjectName("titleLabel");
    m_infoLabel->setObjectName("infoLabel");
    m_versionLabel->setObjectName("versionLabel");
    m_iconLabel->setObjectName("iconLabel");

    m_vLayout->addWidget(m_titleLabel);
    m_vLayout->addWidget(m_infoLabel);

    getWrap1Layout()->addWidget(m_iconLabel);
    getWrap1Layout()->addLayout(m_vLayout, 1);
    getWrap1Layout()->addWidget(m_versionLabel);
    getWrap1Layout()->setContentsMargins(10, 10, 40, 10);

    onThemeChanged();
}

QLabel *FluSettingsVersionBox::getTitleLabel()
{
    return m_titleLabel;
}

QLabel *FluSettingsVersionBox::getInfoLabel()
{
    return m_infoLabel;
}

QLabel *FluSettingsVersionBox::getVersionLabel()
{
    return m_versionLabel;
}

QLabel *FluSettingsVersionBox::getIconLabel()
{
    return m_iconLabel;
}

void FluSettingsVersionBox::addVSplitLine()
{
    getWrap2Layout()->addWidget(new FluVSplitLine);
}

void FluSettingsVersionBox::addWidget(QWidget *widget)
{
    auto hLayout = new QHBoxLayout;
    hLayout->setContentsMargins(50, 0, 10, 0);

    hLayout->addWidget(widget);
    hLayout->addStretch();
    getWrap2Layout()->addLayout(hLayout);
}

void FluSettingsVersionBox::onThemeChanged()
{
    FluStyleSheetUitls::setQssByFileName("FluSettingsVersionBox.qss", this,
                                         FluThemeUtils::getUtils()->getTheme());
}
