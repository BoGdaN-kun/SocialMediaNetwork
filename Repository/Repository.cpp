//
// Created by dudut on 17/05/2022.
//

#include "Repository.h"
#include "../Exceptions/MyExceptions.h"

Repository::Repository() {

}

//add user
void Repository::add_user(User &user_to_add) {
    if (get_user_by_id(user_to_add.getIdUnic()).getIdUnic() != -1)
        throw CRUDEXCEPTIONS("User-ul cu acest id deja exista");
    users.add(user_to_add);
}

//remove user
void Repository::remove_user(User &user_to_delete) {
    if(get_user_by_id(user_to_delete.getIdUnic()).getIdUnic()==-1)
        throw CRUDEXCEPTIONS("Nu exista user cu acest ID");
    users.remove(user_to_delete);
}

//update user
void Repository::update_user(User &old_user, User &new_user) {
    users.update(old_user, new_user);
}

User Repository::get_user(int index) {
    return users.get(index);
}

/**
 * get user by id
 * @param id id user
 * @return User-ul gasit , daca nu un user default arbitrat
 */
User Repository::get_user_by_id(int id) {
    for (int i = 0; i < users.length(); i++)
        if (users.get(i).getIdUnic() == id)
            return users.get(i);
    return User();
}

int Repository::get_length() {
    return users.length();
}

vector<User> Repository::get_all_users() {
    return users.get_all();
}

Repository &Repository::operator=(const Repository &S) {
    if (this != &S) {
        this->users = S.users;
    }
    return *this;
}

