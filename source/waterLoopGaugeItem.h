#ifndef WATERLOOPGAUGEITEM_H
#define WATERLOOPGAUGEITEM_H

#include "qcgaugewidget.h"
#include "qcthemeitem.h"


class waterLoopGaugeItem : public QcGaugeWidget
{
public:
    waterLoopGaugeItem();
    waterLoopGaugeItem(QcThemeItem &theme, QString type, QString label, QString units, double maxValue, double warningValueHigh, double warningValueMed, double stepSize);
    QcGaugeWidget * getGauge();
    void setCurrentValue(double value);

private:
    QcGaugeWidget * mainGauge;
    QcNeedleItem * mSpeedNeedle;
    QcColorBand * mDynamicColorBand;
    QcColorBand * mDynamicColorBandDegrees;
    QcValuesItem * lightUpValues;
    QcBackgroundItem * mainBackground;
    QcBackgroundItem * needleCover;
    QString type;
    QString label;
    QString units;
    double maxValue;
    double warningValueHigh;
    double warningValueMed;
    double stepSize;



};

#endif // WATERLOOPGAUGEITEM_H
