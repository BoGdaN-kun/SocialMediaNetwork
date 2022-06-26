#include "Repository/Repository.h"
#include "Service/Service.h"
#include "UserInterface/UI.h"
#include "Tests/PRESAVES.h"

int main() {

    Repository repo;
    repo = presavedRepo();
    Service service;
    service = presavedService(repo);

    UI ui(repo, service);
    ui.show_menu();
    return 0;
}
