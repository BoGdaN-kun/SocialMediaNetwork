
#ifndef PROIECT_MARE_MESSAGES_H
#define PROIECT_MARE_MESSAGES_H

#include "../DataStructures/Multimap.h"
#include "../DataStructures/List.h"
#include <string>
class Message {
private:
    string sender;
    string reciever;
    string message;

public:
    Message();

    Message(const Message &);

    Message &operator=(const Message &);

    Message(string Sender, string Reciever, string Message);

    string &getSender();

    void setSender(string &sender);

    string &getReciever();

    void setReciever(string &reciever);

    string &getMessage();

    friend istream &operator>>(istream &is, Message &);

    friend ostream &operator<<(ostream &os, const Message &);

    void setMessage(string &message);
};


#endif
