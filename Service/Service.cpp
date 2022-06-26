//
// Created by dudut on 18/05/2022.
//

#include "Service.h"
#include "../Exceptions/MyExceptions.h"
/**
 * Service Constructor
 */
Service::Service() {

}

/**
 * Copy constructor
 * @param S Service to be copied
 */
Service::Service(Service &S) {
    this->repo = S.repo;
}


/**
 * get messages with a friend
 * @param id_user - id user
 * @param id_friend - id friend
 * @return vector of messages
 */
vector<Message> Service::get_messages_of_a_user_with_friend(int id_user, int id_friend) {

    User user1 = repo.get_user_by_id(id_user);
    return user1.getMessages().get_items_by_key(id_friend);


}

/**
 * send_message_to_friend
 * @param message mesaj
 * @param id_user id user
 * @param id_friend id friend
 */
void Service::send_message_to_friend(string message, int id_user, int id_friend) {
    //creare mesaj
    Message message_to_send;
    message_to_send.setMessage(message);
    string sender = repo.get_user_by_id(id_user).getName();
    string receiver = repo.get_user_by_id(id_friend).getName();
    message_to_send.setSender(sender);
    message_to_send.setReciever(receiver);

    //actualizare useri
    User old_user = repo.get_user_by_id(id_user);
    User user_to_update = repo.get_user_by_id(id_user);
    user_to_update.setMessages_2(message_to_send, id_friend);
    repo.update_user(old_user, user_to_update);

    old_user = repo.get_user_by_id(id_friend);
    user_to_update = repo.get_user_by_id(id_friend);
    user_to_update.setMessages_2(message_to_send, id_user);
    repo.update_user(old_user, user_to_update);

}

/**
 * Delete message with a friend
 * @param id_user id user
 * @param id_friend id friend
 */
void Service::delete_message_to_friend(int id_user, int id_friend) {
    User old_user = repo.get_user_by_id(id_user);
    User user_to_update = repo.get_user_by_id(id_user);
    user_to_update.removeMessages(id_friend);
    repo.update_user(old_user, user_to_update);
}


void Service::set_repository(Repository &repositor) {
    this->repo = repositor;
}

User Service::get_users(int id_user) {
    return repo.get_user_by_id(id_user);
}

void Service::add_user(User &user_to_add) {
    repo.add_user(user_to_add);
}

void Service::update_user(User &old_user, User &new_user) {
    repo.update_user(old_user, new_user);
}

vector<User> Service::get_allusers() {
    return repo.get_all_users();
}

void Service::remove_user(User &user_to_delete) {
    repo.remove_user(user_to_delete);
}

/**
 * Add friendship
 * @param id_user  id user
 * @param id_friend  id friend
 */
void Service::add_friendship(int id_user, int id_friend) {
    User old_user_1 = repo.get_user_by_id(id_user);
    User old_user_2 = repo.get_user_by_id(id_friend);

    User user_1 = repo.get_user_by_id(id_user);
    user_1.setFriendship(id_friend);
    User user_2 = repo.get_user_by_id(id_friend);
    user_2.setFriendship(id_user);
    if(user_1.getIdUnic()==-1)
        throw FRIENDCLASSEXCEPTION("ID-ul userului nu exista");
    if(user_2.getIdUnic()==-1)
        throw FRIENDCLASSEXCEPTION("ID-ul prietenului nu exista");
    repo.update_user(old_user_1, user_1);
    repo.update_user(old_user_2, user_2);
}

/**
 * get all friends by id
 * @param id_user  id user
 * @return vector with friends
 */
vector<Friend> Service::get_all_friends_by_id(int id_user) {
    vector<User> all_users = repo.get_all_users();
    vector<Friend> all_friend;
    for (int i = 0; i < all_users.size(); i++)
        if (all_users[i].getIdUnic() == id_user)
            all_friend = all_users[i].get_all_friends();
    return all_friend;
}

/**
 * Delete friendship
 * @param id_user  id user
 * @param id_friend id friend
 */
void Service::delete_friendship(int id_user, int id_friend) {
    User old_user_1 = repo.get_user_by_id(id_user);
    User old_user_2 = repo.get_user_by_id(id_friend);
    if(old_user_1.getIdUnic()==-1)
        throw CRUDEXCEPTIONS("ID-ul userlui nu exista!");
    if(old_user_2.getIdUnic()==-1)
        throw CRUDEXCEPTIONS("ID-ul prietenului nu exista!");
    Friend friend_1 = repo.get_user_by_id(id_user).get_friends_with_id(id_friend);
    Friend friend_2 = repo.get_user_by_id(id_friend).get_friends_with_id(id_user);

    User user_1 = old_user_1;
    User user_2 = old_user_2;

    user_1.removeFriend(friend_1);
    user_2.removeFriend(friend_2);
    repo.update_user(old_user_1, user_1);

    repo.update_user(old_user_2, user_2);
}



