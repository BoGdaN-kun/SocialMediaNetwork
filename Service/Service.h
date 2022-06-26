//
// Created by dudut on 18/05/2022.
//

#ifndef PROIECT_MARE_SERVICE_H
#define PROIECT_MARE_SERVICE_H

#include "../Repository/Repository.h"
class Service {
private:
    Repository repo;
public:
    Service();
    Service(Service&);
    void add_user(User& user_to_add);
    void remove_user(User& user_to_delete);
    void update_user(User& old_user,User& new_user);
    vector<User> get_allusers();
    void set_repository(Repository& repositor);
    User get_users(int id_user);
    vector<Message> get_messages_of_a_user_with_friend(int id_user,int id_friend);
    void send_message_to_friend(string message,int id_user,int id_friend);
    void delete_message_to_friend(int id_user,int id_friend);
    void add_friendship(int id_user,int id_friend);
    vector<Friend> get_all_friends_by_id(int id_user);
    void delete_friendship(int id_user, int id_friend);

};


#endif //PROIECT_MARE_SERVICE_H
