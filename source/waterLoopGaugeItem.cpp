#include "waterLoopGaugeItem.h"

waterLoopGaugeItem::waterLoopGaugeItem()
{
    mainGauge = new QcGaugeWidget;
    QcThemeItem theme = QcThemeItem();

}

waterLoopGaugeItem::waterLoopGaugeItem(QcThemeItem &theme, QString type, QString label,QString units ,qreal precision, qreal maxValue, qreal warningValueHigh, qreal warningValueMed, qreal stepSize){
    mainGauge = new QcGaugeWidget;
    this->maxValue = maxValue;
    this->stepSize = stepSize;
    this->warningValueMed = warningValueMed;
    this->warningValueHigh = warningValueHigh;
    QcBackgroundItem *bkg1 = mainGauge->addBackground(theme.outerRingRadius);
    bkg1->clearrColors();
    bkg1->addColor(1.0, theme.mainColor);
    mainBackground= mainGauge->addBackground(theme.mainBackgroundRadius);
    mainBackground->clearrColors();
    mainBackground->addColor(1.0, theme.backgroundColor);
    mainBackground->setDynamic(true);
    mainBackground->setWarningValue(warningValueHigh);
    mainBackground->setDynamicColors(theme.backgroundColor ,theme.warningColor);

    QcArcItem * arc =  mainGauge->addArc(theme.arcRadius);
    arc->setWidth(theme.arcWidth);
    arc->setColor(theme.mainColor);
    arc->setDegreeRange(theme.minDegree,theme.maxDegree);

    QcDegreesItem * majDeg = mainGauge->addDegrees(theme.subDegreesRadius);
    majDeg->setStep(stepSize);
    majDeg->setValueRange(0,maxValue);
    majDeg->setColor(theme.mainColor);
    majDeg->setWidth(theme.mainDegreesWidth);
    majDeg->setLength(theme.mainDegreesLength);
    majDeg->setDegreeRange(theme.minDegree,theme.maxDegree);

    QcDegreesItem * deg = mainGauge->addDegrees(theme.subDegreesRadius);
    deg->setStep(stepSize/10.0);
    deg->setValueRange(0,maxValue);
    deg->setWidth(theme.subDegreesWidth);
    deg->setLength(theme.subDegreesLength);
    deg->setColor(theme.mainColor);
    deg->setDegreeRange(theme.minDegree,theme.maxDegree);

    QColor tmpColor;

    QPair<QColor,qreal> pair;
    QList<QPair<QColor,qreal>> lst;

    pair.first = QColor(theme.noWarningColor);
    pair.second = 100* warningValueMed/maxValue;
    lst.append(pair);

    pair.first = QColor(theme.mediumWarningColor);
    pair.second = 100 * warningValueHigh/maxValue;
    lst.append(pair);

    pair.first = QColor(theme.highWarningColor);
    pair.second = 100;
    lst.append(pair);

    QcColorBand * cb = mainGauge->addColorBand(theme.colorBandRadius);
    cb->setWidth(theme.colorBandWidth);
    cb->setColors(lst);
    cb->setDegreeRange(theme.minDegree,theme.maxDegree);

    mDynamicColorBand = mainGauge->addColorBand(theme.colorBandRadius);
    mDynamicColorBand->setWidth(theme.colorBandWidth + 0.01);
    mDynamicColorBand->setDynamic(true);
    mDynamicColorBand->setCoveringColor(theme.backgroundColor);
    mDynamicColorBand->setOpacity(0.75);
    mDynamicColorBand->setDegreeRange(theme.minDegree,theme.maxDegree);

    mDynamicColorBandDegrees = mainGauge->addColorBand(theme.mainDegreesRadius - 2);
    mDynamicColorBandDegrees->setWidth(theme.colorBandWidth);
    mDynamicColorBandDegrees->setDynamic(true);
    mDynamicColorBandDegrees->setCoveringColor(theme.backgroundColor);
    mDynamicColorBandDegrees->setOpacity(0.5);
    mDynamicColorBandDegrees->setDegreeRange(theme.minDegree,theme.maxDegree);


    lightUpValues = mainGauge->addValues(theme.valuesRadius);
    lightUpValues->setValueRange(0,maxValue);
    lightUpValues->setFont(theme.font);
    lightUpValues->setFontSize(theme.fontSizeValues);
    lightUpValues->setDynamic(true);
    lightUpValues->setStep(stepSize);
    lightUpValues->setColorLit(theme.mainColor);
    lightUpValues->setColorUnlit(theme.mainColor.darker());
    lightUpValues->setDegreeRange(theme.minDegree,theme.maxDegree);

    mSpeedNeedle = mainGauge->addNeedle(theme.needleRadius);

    if (theme.needleVisible){
        mSpeedNeedle->setColor(theme.mainColor);
    }
    else{
        mSpeedNeedle->setColor(Qt::transparent);
    }
    mSpeedNeedle->setValueRange(0,maxValue);
    mSpeedNeedle->setDegreeRange(theme.minDegree, theme.maxDegree);
    needleCover = mainGauge->addBackground(theme.needleCoverRadius);
    needleCover->clearrColors();
    needleCover->addColor(1.0, theme.backgroundColor);
    needleCover->setDynamic(true);
    needleCover->setWarningValue(warningValueHigh);
    needleCover->setDynamicColors(theme.backgroundColor, theme.warningColor);
    QcLabelItem *lab = mainGauge->addLabel(0);
    lab->setText("0");
    lab->setFont(theme.font);
    lab->setFontSize(theme.fontSizeNeedleLabel);
    lab->setColor(theme.mainColor);
    mSpeedNeedle->setLabel(lab);
    mSpeedNeedle->setPrecision(precision);

    QcLabelItem * kmh = mainGauge->addLabel(25);
    kmh->setText(units);
    kmh->setColor(theme.mainColor);
    kmh->setFont(theme.font);
    kmh->setFontSize(theme.fontSizeUnits);

    QcLabelItem *descriptor = mainGauge->addLabel(65);
    descriptor->setText(label);
    descriptor->setFont(theme.font);
    descriptor->setColor(theme.mainColor);
    descriptor->setFontSize(theme.fontSizeLabel);

    if (theme.dropShadow){
        dropShadow = new QGraphicsDropShadowEffect(mainGauge);
        dropShadow->setBlurRadius(theme.dropShadowRadius);
        dropShadow->setColor(theme.dropShadowColor);
        dropShadow->setOffset(QPointF(theme.dropShadowHorOffset,theme.dropShadowVertOffset));
        mainGauge->setGraphicsEffect(dropShadow);
    }
}

QcGaugeWidget * waterLoopGaugeItem::getGauge(){
    return this->mainGauge;
}

void waterLoopGaugeItem::setCurrentValue(qreal value){
    mSpeedNeedle->setCurrentValue(((qreal) value / 99 * maxValue)); //needs actual value
    mDynamicColorBand->setCurrentValue( ((qreal) value / 99 *100)); //needs percentages
    mDynamicColorBandDegrees->setCurrentValue( ((qreal) value / 99 *100));
    mainBackground->setCurrentValue(((qreal) value / 99 * maxValue));
    needleCover->setCurrentValue(((qreal) value / 99 * maxValue));
    lightUpValues->setCurrentValue(((qreal) value / 99 * maxValue));

}
