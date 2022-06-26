//
// Created by dudut on 18/05/2022.
//

#include "TESTS.h"
#include "../Repository/Repository.h"
void test_users(){
    User bb(12,18,"Bogdan","Cluj");
    User bb_2(13,18,"Vlad","Cluj");
    User bb_3(14,18,"Mircea","Cluj");
    Repository repo;
    repo.add_user(bb);
    //repo.remove_user(bb);
    User test = repo.get_user(0);
    repo.update_user(bb,bb_2);
    User eqwe = repo.get_user(0);
    int lungime = repo.get_length();
    repo.add_user(bb_3);
    lungime = repo.get_length();
    repo.remove_user(bb_3);
    lungime= repo.get_length();
    //is bune
}