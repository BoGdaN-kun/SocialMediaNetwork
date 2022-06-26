
#ifndef PROIECT_MARE_USER_H
#define PROIECT_MARE_USER_H

#include <map>
#include "../DataStructures/List.h"
#include "../DataStructures/Multimap.h"
#include "Messages.h"
#include "Friend.h"
#include <vector>

class User {
private:
    int id_unic;
    int age;
    string name;
    string oras;
    List<Friend> friends;
    Multimap<int, Message> messages;

private:
public:
    User();

    User(const User &);

    User(int id, int ag, string Name, string Oras);

    User &operator=(const User &);

    void setFriendship(int id_friend);

    Friend get_friends_with_id(int id_user_friend);

    vector<Friend> get_all_friends();

    int getIdUnic();

    void setIdUnic(int idUnic);

    int getAge();

    void setAge(int age);

    string &getName();

    void setName(string &name);

    string &getOras();

    void setOras(string &oras);

    Multimap<int, Message> &getMessages();

    void setMessages(Multimap<int, Message> &messages);

    void setMessages_2(Message mesaj, int id_friend);
    void removeMessages(int id_friend);
    void removeFriend(Friend friend_to_delete);

    bool operator==(const User &);

    vector<Message> get_messages_with_id(int id_user_friend);

    friend istream &operator>>(istream &is, User &);

    friend ostream &operator<<(ostream &os, const User &);

};

#endif
