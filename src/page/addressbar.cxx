#include "addressbar.hh"

AddressBar::AddressBar(QString url) : QLineEdit(url) {
}

void AddressBar::keyPressEvent(QKeyEvent *event) {
    if ((event->key()==Qt::Key_Enter)||(event->key()==Qt::Key_Return)) {
        emit urlSubmitted(this->text());
    } else {
        QLineEdit::keyPressEvent(event);
    }
}


