#ifndef QCTHEMEITEM_H
#define QCTHEMEITEM_H

#include <QWidget>
#include <QPainter>
#include <QObject>
#include <QRectF>
#include <QtMath>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QDebug>

class QcThemeItem
{
public:
    QcThemeItem();
    QcThemeItem(QString directory, QString fileName);

    QString font;
    QColor mainColor;
    QColor mediumWarningColor;
    QColor noWarningColor;
    QColor highWarningColor;
    QColor warningColor;
    QColor backgroundColor;
    qreal fontSizeValues;
    qreal valuesRadius;
    qreal fontSizeLabel;
    qreal fontSizeNeedleLabel;
    qreal fontSizeUnits;
    qreal needleRadius;
    qreal needleCoverRadius;
    qreal outerRingRadius;
    qreal mainBackgroundRadius;
    qreal arcRadius;
    qreal arcWidth;
    qreal colorBandRadius;
    qreal colorBandWidth;
    qreal mainDegreesRadius;
    qreal subDegreesRadius;
    qreal mainDegreesWidth;
    qreal subDegreesWidth;
    qreal mainDegreesLength;
    qreal subDegreesLength;
    bool needleVisible;
    qreal minDegree;
    qreal maxDegree;
    bool dropShadow;
    qreal dropShadowRadius = 25;
    QColor dropShadowColor = QColor(0,0,0,40);
    qreal dropShadowAlpha = 0.4; //from 0 to 1
    qreal dropShadowHorOffset = 1; //negative values are to the left
    qreal dropShadowVertOffset = 2; //negative values are up

};
#endif // QCTHEMEITEM_H
