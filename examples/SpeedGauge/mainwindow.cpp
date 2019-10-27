/***************************************************************************
**                                                                        **
**  QcGauge, for instrumentation, and real time data measurement          **
**  visualization widget for Qt.                                          **
**  Copyright (C) 2015 Hadj Tahar Berrima                                 **
**                                                                        **
**  This program is free software: you can redistribute it and/or modify  **
**  it under the terms of the GNU Lesser General Public License as        **
**  published by the Free Software Foundation, either version 3 of the    **
**  License, or (at your option) any later version.                       **
**                                                                        **
**  This program is distributed in the hope that it will be useful,       **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of        **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         **
**  GNU Lesser General Public License for more details.                   **
**                                                                        **
**  You should have received a copy of the GNU Lesser General Public      **
**  License along with this program.                                      **
**  If not, see http://www.gnu.org/licenses/.                             **
**                                                                        **
****************************************************************************
**           Author:  Hadj Tahar Berrima                                  **
**           Website: http://pytricity.com/                               **
**           Contact: berrima_tahar@yahoo.com                             **
**           Date:    1 dec 2014                                          **
**           Version:  1.0                                                **
****************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QColor mainColor = QColor("#18CAE6");
    //mainColor = QColor("#7DFDFE");
    //mainColor = QColor("#FF7D7D");
    mainColor = QColor("#6FC3DF");
    QColor warningColor = QColor("#FF7D7D");
    warningColor = QColor("#921111");
    //mainColor = QColor("#FFE64D");
    //mainColor = QColor("#14ff65");
    maxSpeed = 400;

    QDir directory = QDir(QDir::current());
    directory.cdUp();
    directory.cdUp();

    QcThemeItem theme = QcThemeItem("D:/Coding/Workspaces/WaterLoop/qT/Development/Qt-custom-gauge-widget/source","waterLoopTheme.txt");
    qDebug() << theme.font;
    QString font = theme.font;
    mSpeedGauge = new QcGaugeWidget;

    QcBackgroundItem *bkg1 = mSpeedGauge->addBackground(99);
    bkg1->clearrColors();

    //bkg1->addColor(0.25,Qt::black);
    bkg1->addColor(1.0,mainColor);
    //bkg1->addColor(1.0,Qt::white);

    mainBackground= mSpeedGauge->addBackground(97);
    mainBackground->clearrColors();
    mainBackground->addColor(1.0, Qt::black);
    mainBackground->setDynamic(true);
    mainBackground->setWarningValue(300);
    mainBackground->setDynamicColors(Qt::black ,warningColor);
/*
    QcBackgroundItem *bkg2 = mSpeedGauge->addBackground(88);
    bkg2->clearrColors();
    bkg2->addColor(1.0,Qt::white);
*/
/*  QcArcItem * outerArc = mSpeedGauge->addArc(89);
    outerArc->setColor("#18CAE6");
    outerArc->setWidth(0.01);

    QcArcItem * outerArc1 = mSpeedGauge->addArc(93);
    outerArc1->setColor("#18CAE6");
    outerArc1->setWidth(0.01);
*/
    QcArcItem * arc =  mSpeedGauge->addArc(51);
    arc->setWidth(0.025);
    arc->setColor(mainColor);
    QcDegreesItem * majDeg = mSpeedGauge->addDegrees(58);
    majDeg->setStep(40);
    majDeg->setValueRange(0,maxSpeed);
    majDeg->setColor(mainColor);
    majDeg->setWidth(0.05);
    QcDegreesItem * deg = mSpeedGauge->addDegrees(58);
    deg->setStep(3);
    deg->setValueRange(0,maxSpeed);
    deg->setWidth(0.01);
    deg->setLength(0.05);
    deg->setColor(mainColor);

    QColor tmpColor;

    QPair<QColor,float> pair;
    QList<QPair<QColor,float>> lst;
    pair.first = QColor("#14ff65");
    pair.second = 50;
    lst.append(pair);

    pair.first = QColor("#FFE64D");
    pair.second = 75;
    lst.append(pair);

    pair.first = QColor("#FF7D7D");
    pair.second = 100;
    lst.append(pair);

    QcColorBand * cb = mSpeedGauge->addColorBand(44);
    cb->setWidth(0.1);
    cb->setColors(lst);

    mDynamicColorBand = mSpeedGauge->addColorBand(44);
    mDynamicColorBand->setWidth(0.11);
    mDynamicColorBand->setDynamic(true);
    mDynamicColorBand->setCoveringColor(Qt::black);
    mDynamicColorBand->setOpacity(0.75);

    mDynamicColorBandDegrees = mSpeedGauge->addColorBand(56);
    mDynamicColorBandDegrees->setWidth(0.1);
    mDynamicColorBandDegrees->setDynamic(true);
    mDynamicColorBandDegrees->setCoveringColor(Qt::black);
    mDynamicColorBandDegrees->setOpacity(0.5);


    lightUpValues = mSpeedGauge->addValues(79);
    lightUpValues->setValueRange(0,maxSpeed);
    lightUpValues->setFont(font);
    lightUpValues->setFontSize(0.075);
    lightUpValues->setDynamic(true);
    lightUpValues->setStep(40);
    lightUpValues->setColorLit(mainColor);
    lightUpValues->setColorUnlit(mainColor.darker());




    mSpeedNeedle = mSpeedGauge->addNeedle(65);

    mSpeedNeedle->setColor(mainColor);
    mSpeedNeedle->setValueRange(0,maxSpeed);
    needleCover = mSpeedGauge->addBackground(25);
    needleCover->clearrColors();
    needleCover->addColor(1.0, Qt::black);
    needleCover->setDynamic(true);
    needleCover->setWarningValue(300);
    needleCover->setDynamicColors(Qt::black, warningColor);
    QcLabelItem *lab = mSpeedGauge->addLabel(0);
    lab->setText("0");
    lab->setFont(font);
    lab->setFontSize(0.12);
    lab->setColor(mainColor);
    mSpeedNeedle->setLabel(lab);

    QcLabelItem * kmh = mSpeedGauge->addLabel(25);
    kmh->setText("Km/h");
    kmh->setColor(mainColor);
    kmh->setFont(font);
    kmh->setFontSize(0.055);

    QcLabelItem *descriptor = mSpeedGauge->addLabel(65);
    descriptor->setText("SPEED");
    descriptor->setFont(font);
    descriptor->setColor(mainColor);
    descriptor->setFontSize(0.09);


    ui->verticalLayout->addWidget(mSpeedGauge);

    mSpeedGauge1 = new QcGaugeWidget;

    QcBackgroundItem *bkg11 = mSpeedGauge1->addBackground(99);
    bkg11->clearrColors();

    //bkg1->addColor(0.25,Qt::black);
    //bkg11->addColor(1.0,"#18CAE6");
    bkg11->addColor(1.0,Qt::white);
/*
    QcBackgroundItem *bkg21 = mSpeedGauge1->addBackground(97);
    bkg21->clearrColors();
    bkg21->addColor(1.0, Qt::black);
*/
/*
    QcBackgroundItem *bkg2 = mSpeedGauge1->addBackground(88);
    bkg2->clearrColors();
    bkg2->addColor(1.0,Qt::white);
*/
/*  QcArcItem * outerArc = mSpeedGauge1->addArc(89);
    outerArc->setColor("#18CAE6");
    outerArc->setWidth(0.01);

    QcArcItem * outerArc1 = mSpeedGauge1->addArc(93);
    outerArc1->setColor("#18CAE6");
    outerArc1->setWidth(0.01);
*/

    QcArcItem * arc1 =  mSpeedGauge1->addArc(67);
    arc1->setWidth(0.025);
    arc1->setColor(Qt::black);
    QcDegreesItem * majDeg1 = mSpeedGauge1->addDegrees(73);
    majDeg1->setValueRange(0,80);
    majDeg1->setWidth(0.04);
    majDeg1->setLength(0.06);
    majDeg1->setColor(Qt::black);


    QcDegreesItem * deg1 = mSpeedGauge1->addDegrees(71);
    deg1->setStep(1);
    deg1->setWidth(0.01);
    deg1->setLength(0.04);
    deg1->setColor(Qt::black);



    QcColorBand * cb1 = mSpeedGauge1->addColorBand(54);
    cb1->setWidth(0.25);


    mDynamicColorBand1= mSpeedGauge1->addColorBand(57);
    mDynamicColorBand1->setWidth(0.2);
    mDynamicColorBand1->setDynamic(true);
    mDynamicColorBand1->setCoveringColor(Qt::white);
    mDynamicColorBand1->setOpacity(0.85);


    QcValuesItem *v1 = mSpeedGauge1->addValues(85);
    v1->setValueRange(0,80);
    v1->setFont("Calibri");
    v1->setFontSize(0.09);
    //v1->setColor("#18CAE6");



    mSpeedNeedle1 = mSpeedGauge1->addNeedle(70);

    mSpeedNeedle1->setColor(Qt::darkBlue);
    mSpeedNeedle1->setValueRange(0,80);
    QcBackgroundItem *needleCover1 = mSpeedGauge1->addBackground(27);
    needleCover1->clearrColors();
    needleCover1->addColor(1.0, Qt::lightGray);


    QcLabelItem * kmh1 = mSpeedGauge1->addLabel(7);
    kmh1->setText("Km/h");
    //kmh1->setColor("#18CAE6");
    kmh1->setFont("Calibri");
    kmh1->setFontSize(0.05);

    QcLabelItem *lab1 = mSpeedGauge1->addLabel(3);
    lab1->setText("0");
    lab1->setFont("Calibri");
    lab1->setFontSize(0.12);
    lab1->setAngle(90);
    //lab1->setColor("#18CAE6");
    mSpeedNeedle1->setLabel(lab1);

    QcLabelItem *descriptor1 = mSpeedGauge1->addLabel(65);
    descriptor1->setText("SPEED");
    descriptor1->setFont("Calibri");
    //descriptor1->setColor("#18CAE6");
    descriptor1->setFontSize(0.09);

    //ui->verticalLayout->addWidget(mSpeedGauge1);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{

    mSpeedNeedle->setCurrentValue(((float) value / 99 * maxSpeed)); //needs actual value
    mDynamicColorBand->setCurrentValue( ((float) value / 99 *100)); //needs percentages
    mDynamicColorBandDegrees->setCurrentValue( ((float) value / 99 *100));
    mainBackground->setCurrentValue(((float) value / 99 * maxSpeed));
    needleCover->setCurrentValue(((float) value / 99 * maxSpeed));
    lightUpValues->setCurrentValue(((float) value / 99 * maxSpeed));
    mSpeedNeedle1->setCurrentValue(value);
    mDynamicColorBand1->setCurrentValue(((float) value / 80 *100));


}
