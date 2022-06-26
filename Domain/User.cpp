#include "User.h"

int User::getIdUnic() {
    return this->id_unic;
}

void User::setIdUnic(int idUnic) {
    this->id_unic = idUnic;
}

int User::getAge() {
    return this->age;
}

void User::setAge(int age) {
    User::age = age;
}

string &User::getName() {
    return this->name;
}

void User::setName(string &name) {
    User::name = name;
}

string &User::getOras() {
    return this->oras;
}

void User::setOras(string &oras) {
    User::oras = oras;
}


Multimap<int, Message> &User::getMessages() {
    return this->messages;
}

/**
 * Set a new message multimap through refference
 * @param messages multimap of messages
 */
void User::setMessages(Multimap<int, Message> &messages) {
    User::messages = messages;
}

/**
 * Put it in message multimap where id_frined is the key and can values are mesaj variable
 * @param mesaj mesaj
 * @param id_friend id friend
 */
void User::setMessages_2(Message mesaj, int id_friend) {
    this->messages.put(id_friend, mesaj);
}

void User::removeMessages(int id_friend) {
    this->messages.remove(id_friend);
}

void User::removeFriend(Friend friend_to_delete) {
    this->friends.remove_2(friend_to_delete);
}

User::User(int id, int ag, string Name, string Oras) {
    this->id_unic = id;
    this->age = ag;
    this->name = Name;
    this->oras = Oras;
}

bool User::operator==(const User &S) {
    return ((this->name == S.name) && (this->oras == S.oras) && (this->age == S.age) && (this->id_unic == S.id_unic));

}

User::User() {
    this->id_unic = -1;
    this->age = 0;
    this->name = "";
    this->oras = "";
}

vector<Message> User::get_messages_with_id(int id_user_friend) {
    return messages.get_items_by_key(id_user_friend);
}

User::User(const User &S) {
    this->id_unic = S.id_unic;
    this->age = S.age;
    this->oras = S.oras;
    this->name = S.name;
    this->messages = S.messages;
    this->friends = S.friends;
}

User &User::operator=(const User &S) {
    if (this != &S) {
        this->name = S.name;
        this->age = S.age;
        this->oras = S.oras;
        this->id_unic = S.id_unic;
        this->messages = S.messages;
        this->friends = S.friends;
    }
    return *this;
}

istream &operator>>(istream &is, User &S) {
    cout << "Indroduceti id:";
    is >> S.id_unic;
    cout << "Indroduceti numele Utilizatorului:";
    is >> S.name;
    cout << "Indroduceti numele Orasului:";
    is >> S.oras;
    cout << "Introduceti varsta: ";
    is >> S.age;

    return is;
}

ostream &operator<<(ostream &os, const User &S) {
    os << endl;
    os << "Id:" << S.id_unic << endl;
    os << "Numele Utilizatorului: " << S.name << endl;
    os << "Orasul: " << S.oras << endl;
    os << "Varsta: " << S.age << endl;
}

void User::setFriendship(int id_friend) {
    Friend aFriend;
    aFriend.setIdFriend(id_friend);
    this->friends.add(aFriend);
}

/**
 * Get friends with id
 * @param id_user_friend id user friend
 * @return a Friend with id , if not a default user arbitrary chosen
 */
Friend User::get_friends_with_id(int id_user_friend) {

    vector<Friend> result = this->friends.get_all();
    for (int i = 0; i < result.size(); i++)
        if (result[i].getIdFriend() == id_user_friend)
            return result[i];
    return Friend();
}

vector<Friend> User::get_all_friends() {
    return this->friends.get_all();
}



