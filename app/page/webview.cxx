#include "webview.hh"

WebView::WebView(QString url) {
    this->load(QUrl(url));
}

WebView::WebView() : WebView("https://duckduckgo.com") {
}
