﻿#include "FluIconButton.h"

FluIconButton::FluIconButton(QWidget *parent /*= nullptr*/)
    : QPushButton(parent),
      m_type1(FluAwesomeType::None),
      m_type2(FluAwesomeType::None),
      m_type(FluAwesomeType::None)
{
    // set fixed size
    // setFixedSize(30, 30);
    setIconSize(QSize(20, 20));
    setNoBorder(false);

    onThemeChanged();
    connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, this,
            [=](FluTheme theme) { onThemeChanged(); });
}

FluIconButton::FluIconButton(FluAwesomeType type1, QWidget *parent /*= nullptr*/)
    : QPushButton(parent)
{
    setFixedSize(30, 30);
    setIconSize(QSize(20, 20));
    setNoBorder(false);

    // please ensure type1 will in FluAwesomeType, if can't suitable may crash.

    m_type1 = type1;
    setType(type1);
    onThemeChanged();
    connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, this,
            [=](FluTheme theme) { onThemeChanged(); });
}

FluIconButton::FluIconButton(FluAwesomeType type1, FluAwesomeType type2,
                             QWidget *parent /*= nullptr*/)
    : QPushButton(parent), m_type1(type1), m_type2(type2), m_type(FluAwesomeType::None)
{
    setFixedSize(30, 30);
    setIconSize(QSize(20, 20));
    setNoBorder(false);

    // please ensure type1 will in FluAwesomeType, if can't suitable may crash.

    QPixmap pixmap =
            FluIconUtils::getFluentIconPixmap(type1, FluThemeUtils::getUtils()->getTheme());
    pixmap = pixmap.scaled(20, 20, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    setIcon(QIcon(pixmap));

    // can change type1 to type2, type2 auto change to type1
    m_timer = new QTimer;
    m_timer->setInterval(500);
    connect(m_timer, &QTimer::timeout, [=]() {
        // change type2 to type1
        setType(m_type1);
    });

    connect(this, &FluIconButton::clicked, [=](bool b) {
        // change to type2
        setType(m_type2);
        m_timer->start();
    });

    onThemeChanged();
    connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, this,
            [=](FluTheme theme) { onThemeChanged(); });
}

void FluIconButton::setType(FluAwesomeType type)
{
    m_type = type;
    QPixmap pixmap = FluIconUtils::getFluentIconPixmap(type, FluThemeUtils::getUtils()->getTheme());
    pixmap = pixmap.scaled(20, 20, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    setIcon(QIcon(pixmap));
}

void FluIconButton::setType1(FluAwesomeType type)
{
    m_type1 = type;
    setType(m_type1);
}

void FluIconButton::setType2(FluAwesomeType type)
{
    m_type2 = type;
    setType(m_type2);
}

void FluIconButton::setNoBorder(bool bNoBorder)
{
    setProperty("noBorder", bNoBorder);
    style()->polish(this);
}

void FluIconButton::onThemeChanged()
{
    FluStyleSheetUitls::setQssByFileName("FluIconButton.qss", this,
                                         FluThemeUtils::getUtils()->getTheme());
    setType(m_type);
}
