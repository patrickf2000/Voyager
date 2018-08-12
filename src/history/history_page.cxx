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
#include <QListWidget>
#include <QStringList>
#include <QIcon>

#include "history_page.hh"
#include "history.hh"

HistoryPage::HistoryPage() {
    layout = new QVBoxLayout;
    layout->setContentsMargins(0,0,0,0);
    this->setLayout(layout);

    toolbar = new QToolBar;
    layout->addWidget(toolbar,0,Qt::AlignTop);

    historyList = new QListWidget;
    layout->addWidget(historyList);

    loadHistory();

    clear = new QToolButton;
    clear->setIcon(QIcon::fromTheme("edit-delete"));
    clear->setToolTip("Clear history");
    toolbar->addWidget(clear);

    connect(clear,&QToolButton::clicked,this,&HistoryPage::onClearClicked);
}

HistoryPage::~HistoryPage() {
    delete layout;
}

void HistoryPage::loadHistory() {
    historyList->clear();
    QStringList *list1 = History::AllEntries();
    QStringList *list2 = new QStringList;
    for (int i = 0; i<list1->size(); i++) {
        list2->push_front(list1->at(i));
    }

    for (int i = 0; i<list2->size(); i++) {
        historyList->addItem(list2->at(i));
    }
}

void HistoryPage::onClearClicked() {
    History::ClearAllEntries();
    loadHistory();
}
