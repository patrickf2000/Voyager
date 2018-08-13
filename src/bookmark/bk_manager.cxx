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
#include <QFile>
#include <QTextStream>

#include "bk_manager.hh"
#include "../path.hh"

QString BkManager::path;
QStringList BkManager::items;

void BkManager::init() {
    path = Path::sysPath();
    path+="bookmarks.txt";

    if (!QFile(path).exists()) {
        QFile file(path);
        if (!file.open(QFile::ReadWrite)) {
            file.close();
        }
    } else {
        QFile file(path);
        if (file.open(QFile::ReadWrite)) {
            QTextStream reader(&file);

            while (!reader.atEnd()) {
                QString ln = reader.readLine();
                items.push_back(ln);
            }
        }
    }
}

void BkManager::addBookmark(QString name, QString url) {
    QString ln = name+"="+url;
    items.push_back(ln);

    write();
}

void BkManager::write() {
    QFile file(path);
    if (file.open(QFile::ReadWrite)) {
        QTextStream writer(&file);

        for (int i = 0; i<items.size(); i++) {
            QString current = items.at(i);
            current+="\n";

            writer << current;
        }

        file.close();
    }
}

QStringList BkManager::bookmarkNames() {
    return items;
}

QString BkManager::name(QString ln) {
    QString ret = "";

    for (int i = 0; i<ln.size(); i++) {
        if (ln.at(i)=='=') {
            break;
        }
        ret+=ln.at(i);
    }

    return ret;
}

QString BkManager::url(QString ln) {
    QString ret = "";

    bool found = false;
    for (int i = 0; i<ln.size(); i++) {
        if (ln.at(i)=='=') {
            found = true;
        } else {
            if (found) {
                ret+=ln.at(i);
            }
        }
    }

    return ret;
}
