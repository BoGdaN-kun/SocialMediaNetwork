//
// Created by dudut on 17/05/2022.
//

#ifndef PROIECT_MARE_REPOSITORY_H
#define PROIECT_MARE_REPOSITORY_H
#include "../Domain/User.h"
#include "../DataStructures/Multimap.h"
#include "../DataStructures/List.h"
class Repository {
private:
    List<User> users;
public:
    Repository();
    Repository &operator=(const Repository &);
    void add_user(User& user_to_add);
    void remove_user(User& user_to_delete);
    void update_user(User& old_user,User& new_user);
    void remove_friendship(Friend to_delete);
    User get_user(int index);
    User get_user_by_id(int id);
    int get_length();
    vector<User> get_all_users();
};


#endif //PROIECT_MARE_REPOSITORY_H
