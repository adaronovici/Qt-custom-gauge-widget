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
    double fontSizeValues;
    double valuesRadius;
    double fontSizeLabel;
    double fontSizeNeedleLabel;
    double fontSizeUnits;
    double needleRadius;
    double needleCoverRadius;
    double outerRingRadius;
    double mainBackgroundRadius;
    double arcRadius;
    double arcWidth;
    double colorBandRadius;
    double colorBandWidth;
    double mainDegreesRadius;
    double subDegreesRadius;
    double mainDegreesWidth;
    double subDegreesWidth;
    double mainDegreesLength;
    double subDegreesLength;

};
#endif // QCTHEMEITEM_H
