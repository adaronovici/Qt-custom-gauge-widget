#ifndef WATERLOOPGAUGEITEM_H
#define WATERLOOPGAUGEITEM_H

#include "qcgaugewidget.h"
#include "qcthemeitem.h"
#include <QGraphicsDropShadowEffect>


class waterLoopGaugeItem : public QcGaugeWidget
{
public:
    waterLoopGaugeItem();
    waterLoopGaugeItem(QcThemeItem &theme, QString type, QString label, QString units,qreal precision, qreal maxValue, qreal warningValueHigh, qreal warningValueMed, qreal stepSize);
    QcGaugeWidget * getGauge();
    void setCurrentValue(qreal value);

private:
    QcGaugeWidget * mainGauge;
    QcNeedleItem * mSpeedNeedle;
    QcColorBand * mDynamicColorBand;
    QcColorBand * mDynamicColorBandDegrees;
    QcValuesItem * lightUpValues;
    QcBackgroundItem * mainBackground;
    QcBackgroundItem * needleCover;
    QGraphicsDropShadowEffect * dropShadow;
    QString type;
    QString label;
    QString units;
    qreal maxValue;
    qreal warningValueHigh;
    qreal warningValueMed;
    qreal stepSize;



};

#endif // WATERLOOPGAUGEITEM_H
