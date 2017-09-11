#pragma once

#include <QString>
#include <QStringList>

class History {
public:
    static void Init();
    static void AddPath(QString filePath);
    static QStringList *AllEntries();
private:
    static QString path;
};
