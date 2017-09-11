#include "webview.hh"
#include "webpage.hh"

WebView::WebView(QString url) {
    WebPage *page = new WebPage;
    this->setPage(page);

    this->load(QUrl(url));
    connect(this,SIGNAL(loadFinished(bool)),this,SLOT(onLoadFinished(bool)));
}

WebView::WebView() : WebView("https://duckduckgo.com") {
}

void WebView::loadUrl(QString url) {
    QString address = completeAddress(true,url);
    this->load(QUrl(address));
}

QString WebView::completeAddress(bool https, QString url) {
    QString address = url;
    QString start = "";
    if (https) {
        start = "https://";
    } else {
        start = "http://";
    }
    if (!address.startsWith(start)) {
        if ((!address.startsWith("ftp://"))||(!address.startsWith("file://"))) {
            address = start+url;
        }
    }
    return address;
}

void WebView::onLoadFinished(bool ok) {
    if (ok==false) {
        if (!tried) {
            QString url = this->url().toString();
            QString address = completeAddress(false,url);
            this->load(QUrl(address));
        }
    } else {
        tried = true;
        emit loadCompleted();
    }
}
