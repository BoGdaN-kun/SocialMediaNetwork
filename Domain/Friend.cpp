//
// Created by dudut on 09/05/2022.
//

#include "Friend.h"

Friend::Friend() {
    this->id_friend = -1;
}

int Friend::getIdFriend()  {
    return id_friend;
}

void Friend::setIdFriend(int idFriend) {
    this->id_friend = idFriend;
}

Friend::Friend(const Friend &S) {
    this->id_friend = S.id_friend;
}

Friend &Friend::operator=(const Friend &S) {
    if (this != &S) {
        this->id_friend = S.id_friend;
    }
    return *this;
}


ostream &operator<<(ostream &os, const Friend &S) {
    cout<<"Id friend:"<<S.id_friend<<endl;
    return os;
}

istream &operator>>(istream &is, Friend &S) {
    cout<<"Introduceti id ul prietenului:";is>>S.id_friend;
    return is;

}

bool Friend::operator==(const Friend &S) {
    return (this->id_friend==S.id_friend);

}