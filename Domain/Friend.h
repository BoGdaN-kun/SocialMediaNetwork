

#ifndef PROIECT_MARE_FRIEND_H
#define PROIECT_MARE_FRIEND_H

#include <iostream>

using namespace std;

class Friend {
private:
    int id_friend;

public:
    Friend();
    Friend(const Friend &);
    Friend &operator=(const Friend &);
    int getIdFriend();
    void setIdFriend(int idFriend);
    bool operator==(const Friend &);
    friend istream &operator>>(istream &is, Friend &);
    friend ostream &operator<<(ostream &os, const Friend &);
};

#endif
