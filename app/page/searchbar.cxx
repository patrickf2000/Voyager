#include "searchbar.hh"

SearchBar::SearchBar() : AddressBar("") {
    connect(this,SIGNAL(urlSubmitted(QString)),this,SLOT(onUrlSubmitted(QString)));
}

void SearchBar::onUrlSubmitted(QString url) {
    QString address = "https://www.google.com/?gws_rd=ssl#q="+url;
    emit completeAddressSubmitted(address);
}
