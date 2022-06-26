//
// Created by dudut on 23/05/2022.
//

#include "PRESAVES.h"

Repository presavedRepo() {
    Repository rep;
    //Service serv;
    User user_1(12, 18, "Bogdan", "Cluj");
    User user_2(13, 18, "Vlad", "Cluj");
    User user_3(14, 18, "Ana", "Cluj");
    User user_14(26, 69, "Susana", "Cluj");
    User user_15(25, 74, "Laci", "Cluj");
    User user_4(15, 20, "Sebi", "Suceava");
    User user_5(16, 30, "Raul", "Cluj");
    User user_6(17, 44, "Mihnea", "Calarai");
    User user_7(18, 15, "Bella", "Cluj");
    User user_8(19, 17, "Amelie", "Birmingham");
    User user_9(20, 19, "Silvia", "Bistrita");
    User user_10(21, 23, "Marina", "Slobozia");
    User user_11(22, 45, "lori", "Slobozia");
    User user_12(23, 47, "Patricia", "Slobozia");
    User user_13(24, 47, "Andrei", "Slobozia");


    rep.add_user(user_1);
    rep.add_user(user_2);
    rep.add_user(user_3);
    rep.add_user(user_4);
    rep.add_user(user_5);
    rep.add_user(user_6);
    rep.add_user(user_7);
    rep.add_user(user_8);
    rep.add_user(user_9);
    rep.add_user(user_10);
    rep.add_user(user_11);
    rep.add_user(user_12);
    rep.add_user(user_13);
    rep.add_user(user_14);
    rep.add_user(user_15);
    return rep;
}

Service presavedService(Repository &rep) {
    Service serv;
    serv.set_repository(rep);
    serv.add_friendship(21, 25);
    serv.add_friendship(13, 12);
    serv.add_friendship(26, 13);
    serv.add_friendship(25, 14);
    serv.add_friendship(12, 15);
    serv.add_friendship(12, 16);
    serv.add_friendship(13, 17);
    serv.add_friendship(13, 18);
    serv.add_friendship(14, 19);
    serv.add_friendship(14, 20);
    serv.add_friendship(15, 21);
    serv.add_friendship(15, 22);
    serv.add_friendship(16, 23);
    serv.add_friendship(16, 24);
    serv.add_friendship(17, 25);
    serv.add_friendship(17, 26);
    serv.add_friendship(18, 12);
    serv.add_friendship(18, 15);
    serv.add_friendship(19, 20);
    serv.add_friendship(19, 15);
    serv.add_friendship(20, 16);
    serv.add_friendship(20, 17);
    serv.add_friendship(21, 18);
    serv.add_friendship(21, 19);
    serv.add_friendship(22, 20);
    serv.add_friendship(22, 21);
    serv.add_friendship(23, 22);
    serv.add_friendship(23, 20);
    serv.add_friendship(24, 25);
    serv.add_friendship(24, 26);


    serv.send_message_to_friend("Salut!!", 12, 13);
    serv.send_message_to_friend("Heyy", 13, 14);
    serv.send_message_to_friend("Bro?", 14, 15);
    serv.send_message_to_friend("Cand mergem la suc?", 15, 16);
    serv.send_message_to_friend("Unde esti?", 16, 17);
    serv.send_message_to_friend("Esti acasa?", 18, 19);
    serv.send_message_to_friend("Unde sa ma duc?", 20, 21);
    serv.send_message_to_friend("Hai sa ne jucam", 21, 22);
    serv.send_message_to_friend("Afara?", 22, 23);
    serv.send_message_to_friend("Unde mergem?", 24, 12);
    serv.send_message_to_friend("CAND??", 12, 15);
    serv.send_message_to_friend("Heyyyyyyy", 13, 12);
    serv.send_message_to_friend("Ma plictisesc", 20, 12);
    serv.send_message_to_friend("Ce mai faci?", 19, 15);
    serv.send_message_to_friend("Haide", 17, 23);

    return serv;
}