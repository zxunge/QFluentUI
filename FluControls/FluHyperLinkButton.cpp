#include "FluHyperLinkButton.h"

FluHyperLinkButton::FluHyperLinkButton(QString linkUrl, QWidget *parent /* = nullptr*/)
    : QPushButton(parent), m_linkUrl(linkUrl)
{
    connect(this, &FluHyperLinkButton::clicked,
            [=](bool bClicked) { QDesktopServices::openUrl(QUrl(m_linkUrl)); });

    onThemeChanged();
    connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, this,
            [=](FluTheme theme) { onThemeChanged(); });
}

void FluHyperLinkButton::setLinkUrl(QString linkUrl)
{
    m_linkUrl = linkUrl;
}

void FluHyperLinkButton::onThemeChanged()
{
    FluStyleSheetUitls::setQssByFileName("FluHyperLinkButton.qss", this,
                                         FluThemeUtils::getUtils()->getTheme());
}
