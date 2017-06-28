#include "page.hh"

TabPage::TabPage(QString url) {
    layout = new QVBoxLayout;
    layout->setContentsMargins(0,0,0,0);
    this->setLayout(layout);

    view = new WebView(url);
    layout->addWidget(view);
}

TabPage::TabPage() : TabPage("https://duckduckgo.com") {
}

TabPage::~TabPage() {
    delete layout;
    delete view;
}

WebView *TabPage::webView() {
    return view;
}

QString TabPage::pageTitle() {
    return view->title();
}
