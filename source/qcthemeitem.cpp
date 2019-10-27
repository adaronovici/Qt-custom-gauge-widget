#include "qcthemeitem.h"


QcThemeItem::QcThemeItem(){
    font = "Aero";
    mainColor =  QColor("#6FC3DF");
    warningColor = QColor("#921111");
    backgroundColor = Qt::black;
    fontSizeValues = 0.075;
    fontSizeLabel = 0.09;
    fontSizeNeedleLabel = 0.12;
    fontSizeUnits = 0.055;
    needleRadius = 65;
    outerRingRadius = 99;
    mainBackgroundRadius = 97;
    arcRadius  = 51;
    arcWidth = 0.025;
    colorBandRadius  = 44;
    colorBandWidth = 0.1;
    mainDegreesRadius = 58;
    subDegreesRadius = 58;
    mainDegreesWidth = 0.05;
    subDegreesWidth = 0.01;
    mainDegreesLength = 0.1;
    subDegreesLength = 0.05;
}

QcThemeItem::QcThemeItem(QString directory, QString fileName)
{
    QcThemeItem();
    QDir dir(directory);
    if (!dir.exists()){
        QcThemeItem();
        qDebug() << "DID NOT FIND DIR";
        return;
    }

    QFile inputFile(dir.filePath(fileName));
    if (!inputFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QcThemeItem();
        qDebug() << "DID NOT FIND FILE";
        return;
    }
    QString first;
    QString second;
    QString temp;
    QTextStream is;
    while(!inputFile.atEnd()){
        QByteArray line = inputFile.readLine();
        temp =  QString::fromStdString(line.toStdString());
        if(temp.length() > 2){
            temp =  QString::fromStdString(line.toStdString());
            if (!(temp[0] == '/' && temp[1]=='/')){

                is.setString(&temp);
                is >> first;
                is >> second;
                is.flush();
                if (first == "font"){
                    font = second;
                }
                else if (first == "mainColor"){
                    mainColor = QColor(second);
                }
                else if (first == "warningColor"){
                    warningColor = QColor(second);
                }
                else if (first == "backgroundColor"){
                    backgroundColor = QColor(second);
                }
                else if (first == "fontSizeValues"){
                    fontSizeValues = second.toDouble();
                }
                else if (first == "fontSizeLabel"){
                    fontSizeLabel = second.toDouble();
                }
                else if (first == "fontSizeNeedleLabel"){
                    fontSizeNeedleLabel = second.toDouble();
                }
                else if (first == "fontSizeUnits"){
                    fontSizeUnits = second.toDouble();
                }
                else if (first == "needleRadius"){
                    needleRadius = second.toDouble();
                }
                else if (first == "outerRingRadius"){
                    outerRingRadius = second.toDouble();
                }
                else if (first == "mainBackgroundRadius"){
                    mainBackgroundRadius = second.toDouble();
                }
                else if (first == "arcRadius"){
                    arcRadius = second.toDouble();
                }
                else if (first == "arcWidth"){
                    arcWidth = second.toDouble();
                }
                else if (first == "colorBandRadius"){
                    colorBandRadius = second.toDouble();
                }
                else if (first == "colorBandWidth"){
                    colorBandWidth = second.toDouble();
                }
                else if (first == "mainDegreesRadius"){
                    mainDegreesRadius = second.toDouble();
                }
                else if (first == "subDegreesRadius"){
                    subDegreesRadius = second.toDouble();
                }
                else if (first == "mainDegreesWidth"){
                    mainDegreesWidth = second.toDouble();
                }
                else if (first == "subDegreesWidth"){
                    subDegreesWidth = second.toDouble();
                }
                else if (first == "mainDegreesLength"){
                    mainDegreesLength = second.toDouble();
                }
                else if (first == "subDegreesLength"){
                    subDegreesLength = second.toDouble();
                }
            }
        }
    }


}
