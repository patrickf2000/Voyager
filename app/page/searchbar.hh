#pragma once

#include <QString>

#include "addressbar.hh"

class SearchBar : public AddressBar {
    Q_OBJECT
public:
    SearchBar();
private slots:
    void onUrlSubmitted(QString url);
signals:
    QString completeAddressSubmitted(QString url);
};
