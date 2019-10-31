#include "qcthemeitem.h"


QcThemeItem::QcThemeItem(){
    font = "Aero";
    mainColor =  QColor("#6FC3DF");
    warningColor = QColor("#921111");
    noWarningColor = QColor("#14ff65");
    mediumWarningColor = QColor("#FFE64D");
    highWarningColor = QColor("#FF7D7D");
    backgroundColor = Qt::black;
    valuesRadius = 79;
    fontSizeValues = 0.075;
    fontSizeLabel = 0.09;
    fontSizeNeedleLabel = 0.12;
    fontSizeUnits = 0.055;
    needleRadius = 65;
    needleCoverRadius = 25;
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
    needleVisible = true;
    minDegree = -45;
    maxDegree = 225;
    dropShadow = false;
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
                else if (first == "noWarningColor"){
                    noWarningColor = QColor(second);
                }
                else if (first == "mediumWarningColor"){
                    mediumWarningColor = QColor(second);
                }
                else if (first == "highWarningColor"){
                    highWarningColor = QColor(second);
                }
                else if (first == "backgroundColor"){
                    backgroundColor = QColor(second);
                }
                else if (first == "fontSizeValues"){
                    fontSizeValues = static_cast<qreal>(second.toDouble());
                }
                else if (first == "valuesRadius"){
                    valuesRadius = static_cast<qreal>(second.toDouble());
                }
                else if (first == "fontSizeLabel"){
                    fontSizeLabel = static_cast<qreal>(second.toDouble());
                }
                else if (first == "fontSizeNeedleLabel"){
                    fontSizeNeedleLabel = static_cast<qreal>(second.toDouble());
                }
                else if (first == "fontSizeUnits"){
                    fontSizeUnits = static_cast<qreal>(second.toDouble());
                }
                else if (first == "needleRadius"){
                    needleRadius = static_cast<qreal>(second.toDouble());
                }
                else if (first == "needleCoverRadius"){
                    needleCoverRadius = static_cast<qreal>(second.toDouble());
                }
                else if (first == "outerRingRadius"){
                    outerRingRadius = static_cast<qreal>(second.toDouble());
                }
                else if (first == "mainBackgroundRadius"){
                    mainBackgroundRadius = static_cast<qreal>(second.toDouble());
                }
                else if (first == "arcRadius"){
                    arcRadius = static_cast<qreal>(second.toDouble());
                }
                else if (first == "arcWidth"){
                    arcWidth = static_cast<qreal>(second.toDouble());
                }
                else if (first == "colorBandRadius"){
                    colorBandRadius = static_cast<qreal>(second.toDouble());
                }
                else if (first == "colorBandWidth"){
                    colorBandWidth = static_cast<qreal>(second.toDouble());
                }
                else if (first == "mainDegreesRadius"){
                    mainDegreesRadius = static_cast<qreal>(second.toDouble());
                }
                else if (first == "subDegreesRadius"){
                    subDegreesRadius = static_cast<qreal>(second.toDouble());
                }
                else if (first == "mainDegreesWidth"){
                    mainDegreesWidth = static_cast<qreal>(second.toDouble());
                }
                else if (first == "subDegreesWidth"){
                    subDegreesWidth = static_cast<qreal>(second.toDouble());
                }
                else if (first == "mainDegreesLength"){
                    mainDegreesLength = static_cast<qreal>(second.toDouble());
                }
                else if (first == "subDegreesLength"){
                    subDegreesLength = static_cast<qreal>(second.toDouble());
                }
                else if (first == "needleVisible"){
                    if (second == "false"){
                        needleVisible = false;
                    }
                    else {
                        needleVisible = true;
                    }
                }
                else if (first == "minDegree"){
                    minDegree = static_cast<qreal>(second.toDouble());
                }
                else if (first == "maxDegree"){
                    maxDegree = static_cast<qreal>(second.toDouble());
                }
                else if (first == "dropShadow"){
                    if (second == "false"){
                        dropShadow = false;
                    }
                    else {
                        dropShadow = true;
                    }
                }
                if (dropShadow){
                    if (first == "dropShadowRadius"){
                        dropShadowRadius = static_cast<qreal>(second.toDouble());
                    }
                    else if (first == "dropShadowColor"){
                        dropShadowColor = QColor(second);
                    }
                    else if (first == "dropShadowAlpha"){
                        dropShadowAlpha = static_cast<qreal>(second.toDouble());
                        dropShadowColor.setAlphaF(dropShadowAlpha);
                    }
                    else if (first == "dropShadowHorOffset"){
                        dropShadowHorOffset = static_cast<qreal>(second.toDouble());
                    }
                    else if (first == "dropShadowVertOffset"){
                        dropShadowVertOffset =static_cast<qreal>(second.toDouble());
                    }
                }

            }
        }
    }


}
