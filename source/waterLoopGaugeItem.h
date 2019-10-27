#ifndef WATERLOOPGAUGEITEM_H
#define WATERLOOPGAUGEITEM_H

#include "qcgaugewidget.h"
#include "qcthemeitem.h"


class waterLoopGaugeItem : public QcGaugeWidget
{
public:
    waterLoopGaugeItem();
    waterLoopGaugeItem(QcThemeItem &theme, QString type, QString label, double maxValue, double warningValue, double stepSize);


private:
    QcGaugeWidget * mainGauge;
    QString type;
    QString label;
    double maxValue;
    double warningValue;
    double stepSize;



};

#endif // WATERLOOPGAUGEITEM_H
