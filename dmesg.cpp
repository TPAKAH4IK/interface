#include "dmesg.h"
#include <QIODevice>
#include <QFile>
#include <QTextStream>
#include <QProcess>

QString DmesgInfo::GetDmesgInfo()
{
    return dmesgInfo;
}

void DmesgInfo::SetDmesgInfo(QString value)
{
    dmesgInfo = value;
}

DmesgInfo::DmesgInfo()
{
    QFile file("./dmesginfo.txt");
    file.open(QIODevice::Text | QIODevice::ReadOnly);
    QTextStream in(&file);
    QString line = in.readLine();
    dmesgInfo += line;
    line = in.readLine();
    while(!line.isNull())
    {
        dmesgInfo += "\n";
        dmesgInfo += line;
        line = in.readLine();
    }
    file.close();
}
