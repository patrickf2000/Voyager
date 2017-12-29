#include <QDir>
#include <QFile>
#include <QTextStream>
#include <iostream>

#include "history.hh"

QString History::path;

void History::Init() {
    path = QDir::homePath();
    if (!path.endsWith("/")) {
        path+="/";
    }
    path+=".Voyager/";
    if (!QDir(path).exists()) {
        QDir().mkpath(path);
    }
    path+="history.txt";
    if (!QFile(path).exists()) {
        QFile file(path);
        if (!file.open(QFile::ReadWrite)) {
            file.close();
        }
    }
}

void History::AddPath(QString filePath) {
    QStringList *items = AllEntries();
    items->push_back(filePath);
    QFile file(path);
    if (file.open(QFile::ReadWrite)) {
        QTextStream writer(&file);
        for (int i = 0; i<items->size(); i++) {
            writer << items->at(i) << endl;
        }
    }
}

QStringList *History::AllEntries() {
    QStringList *entries = new QStringList;
    QFile file(path);
    if (file.open(QFile::ReadOnly)) {
        QTextStream reader(&file);
        while (!reader.atEnd()) {
            entries->push_back(reader.readLine());
        }
    }
    return entries;
}

void History::ClearAllEntries() {
    QFile file(path);
    if (file.open(QFile::WriteOnly | QFile::Truncate)) {
        file.close();
    }
}
