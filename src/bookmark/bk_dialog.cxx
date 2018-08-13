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
#include "bk_dialog.hh"
#include "bk_manager.hh"

BkDialog::BkDialog(QString title, QString url)
    : layout(new QVBoxLayout),
      titleWidget(new QFrame),
      urlWidget(new QFrame),
      titleLayout(new QHBoxLayout),
      urlLayout(new QHBoxLayout),
      titleLabel(new QLabel),
      urlLabel(new QLabel),
      titleEdit(new QLineEdit),
      urlEdit(new QLineEdit)
{
    this->setWindowTitle("Bookmark Page");
    this->setFixedSize(350,200);
    this->setLayout(layout);

    //For setting the title
    titleLabel->setText("Title: ");

    titleEdit->setText(title);
    titleEdit->setClearButtonEnabled(true);

    titleLayout->addWidget(titleLabel);
    titleLayout->addWidget(titleEdit);

    titleWidget->setLayout(titleLayout);
    layout->addWidget(titleWidget,0,Qt::AlignTop);

    //For setting the URL
    urlLabel->setText("URL: ");

    urlEdit->setText(url);
    urlEdit->setClearButtonEnabled(true);

    urlLayout->addWidget(urlLabel);
    urlLayout->addWidget(urlEdit);

    urlWidget->setLayout(urlLayout);
    layout->addWidget(urlWidget,0,Qt::AlignTop);

    //The dialog button box
    dialogButtons = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    layout->addWidget(dialogButtons);

    connect(dialogButtons,&QDialogButtonBox::accepted,this,&BkDialog::onOk);
    connect(dialogButtons,&QDialogButtonBox::rejected,this,&BkDialog::close);
}

void BkDialog::onOk() {
    BkManager::addBookmark(titleEdit->text(),urlEdit->text());
    close();
}
