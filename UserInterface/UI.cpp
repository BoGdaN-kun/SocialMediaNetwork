//
// Created by dudut on 20/05/2022.
//

#include "UI.h"

UI::UI() {
    Repository repository_1;
    this->repository = repository_1;

    Service service_1;
    service_1.set_repository(repository_1);
    this->service = service_1;
}

UI::UI(Repository &repo, Service &servic) {
    this->repository = repo;
    this->service = servic;
    this->service.set_repository(repo);
}


void UI::handle_adaugare() {
    try {
        User user_to_add;
        cin >> user_to_add;
        service.add_user(user_to_add);
    }
    catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
}

void UI::handle_vizualizare_mesaje_user() {
    cin.get();
    int id_user, id_friend;
    cout << "Introduceti id-ul userului la care sa vedeti mesajele: ";
    cin >> id_user;
    cout << "Introduceti id-ul prietenului la care sa vedeti mesajele: ";
    cin >> id_friend;
    vector<Message> mesaje = service.get_users(id_user).getMessages().get_items_by_key(id_friend);
    for (int i = 0; i < mesaje.size(); i++)
        cout << mesaje[i] << " " << endl;
    cout << endl;
}

void menu() {
    cout << endl;
    cout << "1.Adaugare User " << endl;
    cout << "2.Update User " << endl;
    cout << "3.Stergere User " << endl;
    cout << "4.Afisarea tuturor Users " << endl;
    cout << "5.Trimitere mesaj " << endl;
    cout << "6.Vizualizare mesaje " << endl;
    cout << "7.Cautare dupa nume " << endl;
    cout << "8.Adaugare prietenie " << endl;
    cout << "9.Vizualizare prietenii: " << endl;
    cout << "10.Stergere mesaje " << endl;
    cout << "11.Stergere prietenie " << endl;
    cout << "0.Exit " << endl;
}


void UI::show_menu() {
    menu();
    int optiune;
    cout << "Introduceti optiunea: " << endl;
    cin >> optiune;
    while (optiune) {
        switch (optiune) {
            case 1:
                handle_adaugare();
                break;
            case 2:
                handle_update();
                break;
            case 3:
                handle_stergere_user();
                break;
            case 4:
                handle_show_all_users();
                break;
            case 5:
                handle_trimitere_mesaj();
                break;
            case 6:
                handle_vizualizare_mesaje_user();
                break;
            case 7:
                search_by_name();
                break;
            case 8:
                handle_add_friendship();
                break;
            case 9:
                handle_show_friendships();
                break;
            case 10:
                handle_stergere_mesaj();
                break;
            case 11:
                handle_delete_friend();
                break;
            default:
                cout << "Comanda invalida !" << endl;
        }
        menu();
        cout << "Introduceti optiunea: " << endl;
        cin >> optiune;
    }
}

void UI::handle_trimitere_mesaj() {
    int id_user, id_friend;
    string mesaj;
    cout << "Introduceti id-ul cine trimite: ";
    cin >> id_user;
    cout << "Introduceti id-ul cine primeste: ";
    cin >> id_friend;
    cout << "Introduceti mesajul : ";
    char s[40];
    cin.get();
    cin.getline(s, 40);
    mesaj = (string) s;
    //cin >> mesaj;

    service.send_message_to_friend(mesaj, id_user, id_friend);

}

void UI::handle_stergere_mesaj() {
    int id_user, id_friend;
    string mesaj;
    cout << "Introduceti id-ul cui sa ii stergeti mesajul: ";
    cin >> id_user;
    cout << "Introduceti id-ul cu cine : ";
    cin >> id_friend;
    service.delete_message_to_friend(id_user, id_friend);
}

void UI::handle_update() {
    int id_user;
    cout << "Introudceti id-ul userului pentru al updata: ";
    cin >> id_user;
    User old_user = service.get_users(id_user);
    User user_to_udpate = service.get_users(id_user);

    string new_name;
    cout << "Introudceti noul nume:";
    cin >> new_name;
    user_to_udpate.setName(new_name);
    string new_oras;
    cout << "Introduceti noul oras: ";
    cin >> new_oras;
    user_to_udpate.setOras(new_oras);
    int new_age;
    cout << "Introduceti noua varsta: ";
    cin >> new_age;
    user_to_udpate.setAge(new_age);
    service.update_user(old_user, user_to_udpate);
}

void UI::handle_show_all_users() {
    vector<User> all_users = service.get_allusers();
    for (int i = 0; i < all_users.size(); i++)
        cout << all_users[i] << " " << endl;
    cout << endl;

}

void UI::handle_stergere_user() {
    try {
        int id_user_to_delete;
        cout << "Introduceti id-ul userului pe care sa-l stergeti: ";
        cin >> id_user_to_delete;
        User user_to_delete = service.get_users(id_user_to_delete);
        service.remove_user(user_to_delete);
    }
    catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
}

void UI::search_by_name() {
    vector<User> all_users = service.get_allusers();
    vector<User> named_users;
    string name;
    cout << "Introudceti numele: ";
    cin >> name;
    for (int i = 0; i < all_users.size(); i++)
        if (all_users[i].getName() == name)
            named_users.push_back(all_users[i]);
    if (named_users.size() == 0)
        cout << "Nu exista utilizator cu numele acesta!";
    else {
        for (int i = 0; i < named_users.size(); i++)
            cout << i << ")" << named_users[i].getName() << " with id: " << named_users[i].getIdUnic() << endl;
        cout << "Selectati user-ul!(daca comanda este gresita va trebui sa reluati procesul!)" << endl;
        int option;
        cin >> option;
        if (option < 0 || option >= named_users.size())
            cout << "Optiune incorecta!";
        else
            cout << named_users[option];
    }
}

void UI::handle_add_friendship() {
    try {
        int id_user_1, id_user_2;
        cout << "Introduceti id-ul primei persoane care se imprieteneste: ";
        cin >> id_user_1;
        cout << "Introduceti id-ul celei de a doua persoane care se imprieteneste: ";
        cin >> id_user_2;
        service.add_friendship(id_user_1, id_user_2);
    }
    catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
}


void UI::handle_show_friendships() {
    int id_user;
    cout << "introudceti id-ul persoanei la care sa ii vedeti prieteniile: ";
    cin >> id_user;
    vector<Friend> all_friends = service.get_all_friends_by_id(id_user);
    for (auto &all_friend: all_friends)
        cout << service.get_users(all_friend.getIdFriend()).getName() << "#id:"
             << service.get_users(all_friend.getIdFriend()).getIdUnic() << endl;
    cout << endl;
}

void UI::handle_delete_friend() {
    try {
        int id_user_1, id_user_2;
        cout << "Introduceti id-ul primei persoane care sa ii stergeti prietenul: ";
        cin >> id_user_1;
        cout << "Introduceti id-ul persoanei de a sterge: ";
        cin >> id_user_2;
        service.delete_friendship(id_user_1, id_user_2);
    }
    catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
}

