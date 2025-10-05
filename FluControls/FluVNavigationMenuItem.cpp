﻿#include "FluVNavigationMenuItem.h"
#include "../FluUtils/FluUtils.h"
#include <QPropertyAnimation>

FluVNavigationMenuItem::FluVNavigationMenuItem(QWidget *parent /*= nullptr*/)
    : FluVNavigationItem(parent)
{
    m_itemType = FluVNavigationItemType::Menu;

    m_hLayout = new QHBoxLayout(this);

    m_wrapWidget1 = new QWidget;
    m_wrapWidget2 = new QWidget;

    m_hWrapWidgetLayout1 = new QHBoxLayout;
    m_wrapWidget1->setLayout(m_hWrapWidgetLayout1);
    m_hWrapWidgetLayout1->setContentsMargins(0, 4, 0, 4);

    m_wrapWidget1->setObjectName("wrapWidget1");
    m_wrapWidget2->setObjectName("wrapWidget2");

    m_menuButton = new QPushButton;
    m_menuButton->setIcon(FluIconUtils::getFluentIcon(FluAwesomeType::GlobalNavButton));
    m_menuButton->setIconSize(QSize(24, 24));
    m_menuButton->setFixedSize(44, 32);

    m_hWrapWidgetLayout1->addWidget(m_menuButton);

    m_hLayout->setSpacing(0);
    m_hLayout->addWidget(m_wrapWidget1);
    m_hLayout->addWidget(m_wrapWidget2, 1);
    // m_hLayout->setSpacing(0);
    // m_hLayout->setContentsMargins(0, 4, 0, 4);
    m_hLayout->setContentsMargins(0, 0, 0, 0);

    m_wrapWidget1->setFixedHeight(40);
    m_wrapWidget2->setFixedHeight(40);
    setFixedHeight(40);
    setFixedWidth(320);

    m_menuButton->setObjectName("menuButton");

    connect(m_menuButton, &QPushButton::clicked, [=](bool b) { emit menuItemClicked(); });

    onThemeChanged();
}

void FluVNavigationMenuItem::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
}

void FluVNavigationMenuItem::onThemeChanged()
{
    m_menuButton->setIcon(FluIconUtils::getFluentIcon(FluAwesomeType::GlobalNavButton,
                                                      FluThemeUtils::getUtils()->getTheme()));
    FluStyleSheetUitls::setQssByFileName("FluVNavigationMenuItem.qss", this,
                                         FluThemeUtils::getUtils()->getTheme());
}
