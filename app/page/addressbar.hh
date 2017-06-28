#pragma once

#include <QLineEdit>
#include <QString>
#include <QKeyEvent>

#include "webview.hh"

class AddressBar : public QLineEdit {
    Q_OBJECT
public:
    explicit AddressBar(QString url);
protected:
    void keyPressEvent(QKeyEvent *event);
signals:
    QString urlSubmitted(QString url);
};
