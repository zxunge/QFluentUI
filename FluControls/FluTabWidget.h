#pragma once

#include "../FluUtils/FluStyleSheetUitls.h"
#include <QTableWidget>

class FluTabWidget : public QTabWidget
{
    Q_OBJECT
public:
    FluTabWidget(QWidget *parent = nullptr);
};
