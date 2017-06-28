#include <QListWidget>
#include <QWebEngineHistory>
#include <QWebEngineHistoryItem>
#include <QList>

#include "history_page.hh"

HistoryPage::HistoryPage(WebView *view) {
    layout = new QVBoxLayout;
    layout->setContentsMargins(0,0,0,0);
    this->setLayout(layout);

    QListWidget *historyList = new QListWidget;
    layout->addWidget(historyList);

    QWebEngineHistory *history = view->history();
    QList<QWebEngineHistoryItem> items = history->items();
    for (int i = 0; i<items.size(); i++) {
        historyList->addItem(items.at(i).url().toString());
    }
}

HistoryPage::~HistoryPage() {
    delete layout;
}
