#pragma once

#include "FluWidget.h"
#include "FluLoopView.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include "../FluUtils/FluUtils.h"
#include <QPainter>
#include <QStyleOption>
#include "FluTimePickerViewMask.h"
#include "FluHSplitLine.h"
#include "FluVSplitLine.h"
#include <QFrame>
#include <QGraphicsDropShadowEffect>
#include <QApplication>

class FluTimePicker24HView : public FluWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor maskBackgroundColorEx READ getMaskBackgroundColorEx WRITE
                       setMaskBackgroundColorEx)
    Q_PROPERTY(QColor maskTextColorEx READ getMaskTextColorEx WRITE setMaskTextColorEx)
public:
    FluTimePicker24HView(QWidget *parent = nullptr);

    void setMaskBackgroundColorEx(QColor color) { m_mask->setBackgroundColorEx(color); }

    QColor getMaskBackgroundColorEx() { return m_mask->getBackgroundColorEx(); }

    void setMaskTextColorEx(QColor color) { m_mask->setTextColorEx(color); }

    QColor getMaskTextColorEx() { return m_mask->getTextColorEx(); }

    int getHour();

    int getMinute();

    void setHour(int hour);

    void setMinute(int minute);

    void updateTime();

    void setShadowEffect();

    void paintEvent(QPaintEvent *event);

    void showEvent(QShowEvent *event);

    void resizeEvent(QResizeEvent *event);
signals:
    void clickedOk();
    void clickedCancel();
public slots:
    void onThemeChanged();

protected:
    QFrame *m_mainView;
    QHBoxLayout *m_hMainViewLayout;
    QGraphicsDropShadowEffect *m_shadowEffect;

    QVBoxLayout *m_vMainLayout;
    QHBoxLayout *m_hViewLayout;
    QHBoxLayout *m_hBtnLayout;

    FluTimePickerViewMask *m_mask;

    FluLoopView *m_hourView;
    FluLoopView *m_minuteView;

    QPushButton *m_okBtn;
    QPushButton *m_cancelBtn;

    int m_hour;
    int m_minute;

    bool m_bFirstShow;
};
