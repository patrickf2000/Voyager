#pragma once

#include <QString>
#include <QStringList>

class History {
public:
    static void Init();
    static void AddPath(QString filePath);
    static QStringList *AllEntries();
    static void ClearAllEntries();
private:
    static QString path;
};
