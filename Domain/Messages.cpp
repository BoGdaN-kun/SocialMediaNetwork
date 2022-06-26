#include "Messages.h"

Message::Message() {
    sender = "";
    reciever = "";
    message = "";
}

Message::Message(string Sender, string Reciever, string Message) {
    this->sender = Sender;
    this->reciever = Reciever;
    this->message = Message;

}

string &Message::getSender() {
    return sender;
}

void Message::setSender(string &sender) {
    Message::sender = sender;
}

string &Message::getReciever() {
    return reciever;
}

void Message::setReciever(string &reciever) {
    Message::reciever = reciever;
}

string &Message::getMessage() {
    return this->message;
}

void Message::setMessage(string &message) {
    Message::message = message;
}

Message::Message(const Message &S) {
    this->sender = S.sender;
    this->message = S.message;
    this->reciever = S.reciever;

}

Message &Message::operator=(const Message &S) {
    if (this != &S) {
        this->sender = S.sender;
        this->reciever = S.reciever;
        this->message = S.message;

    }
    return *this;
}

istream &operator>>(istream &is, Message &mesaj) {

    cout << "Introduceti numele senderului: ";
    is >> mesaj.sender;
    cout << "Introduceti numele receiverului: ";
    is >> mesaj.reciever;
    cout << "Introduceti mesajul: ";
    is >> mesaj.message;
    return is;
}

ostream &operator<<(ostream &os, const Message &mesaj) {
    os << endl;
    os << "Senderul este  : " << mesaj.sender << endl;
    os << "Receiverul este : " << mesaj.reciever << endl;
    os << "Mesaj:  " << mesaj.message << endl;
}


