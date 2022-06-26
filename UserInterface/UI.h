//
// Created by dudut on 20/05/2022.
//

#ifndef PROIECT_MARE_UI_H
#define PROIECT_MARE_UI_H
#include "../Service/Service.h"
#include "../Repository/Repository.h"

class UI {
private:
    Service service;
    Repository repository;
    void handle_adaugare();
    void handle_show_all_users();
    void handle_update();
    void handle_stergere_user();
    void handle_trimitere_mesaj();
    void handle_stergere_mesaj();
    void handle_vizualizare_mesaje_user();
    void search_by_name();
    void handle_add_friendship();
    void handle_show_friendships();
    void handle_delete_friend();
public:
    UI();
    UI(Repository&, Service&);
    void show_menu();
};


#endif
