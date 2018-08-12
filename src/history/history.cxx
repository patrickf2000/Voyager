// Copyright 2018 Patrick Flynn
//
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//	this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice, this
//	list of conditions and the following disclaimer in the documentation and/or
//	other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors may
//	be used to endorse or promote products derived from this software
//	without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
// INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
// EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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
