#ifndef CHECKDATA_H
#define CHECKDATA_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QFile>

namespace Ui {
class CheckData;
}

class CheckData : public QMainWindow
{
    Q_OBJECT

public:
    explicit CheckData(QWidget *parent = 0);
    ~CheckData();

private:
    Ui::CheckData *ui;
    QSerialPort *port;
    QString command;
    bool flagPackage;
    bool flagChannel_1;
    bool flagChannel_2;
    bool flagNumPackage;
    int numPackage;
    int numBit;
    QByteArray Channel1;
    QByteArray Channel2;
    QVector <QString> VPattern;
    bool flagSyncFile_1;
    bool flagSyncFile_2;
    int countValidity_Ch1;
    int countValidity_Ch2;
    double validity_1;
    double validity_2;


private slots:
    void openPort();
    void closePort();
    void setRate_slot(int rate);
    void reset_Arduino();
    void parsingPackage(QByteArray data);
    void writePort(QByteArray data);
    QByteArray readPort();
    void openPatternFile();
    void validitySignal(int numChannel, QByteArray byte_msg);
    void writeFileMSG(int numChannel, QByteArray msg);
    void clearFileMSG();
    void alarmMSG();
    void debugTextEdit(bool status, QString debMSG);
};

#endif // CHECKDATA_H
