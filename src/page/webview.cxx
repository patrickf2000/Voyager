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
