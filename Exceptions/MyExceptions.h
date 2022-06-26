//
// Created by dudut on 23/05/2022.
//

#ifndef PROIECT_MARE_MYEXCEPTIONS_H
#define PROIECT_MARE_MYEXCEPTIONS_H
#include <exception>

class MyExceptions : public std::exception {
private:
    const char *mesaj;
public:

    MyExceptions(const char *message) : mesaj(message) {}

    const char *what() const noexcept override {
        return mesaj;
    }
};
class CRUDEXCEPTIONS : public MyExceptions{
    using MyExceptions::MyExceptions;
};
class FRIENDCLASSEXCEPTION : public MyExceptions{
    using MyExceptions::MyExceptions;
};

#endif //PROIECT_MARE_MYEXCEPTIONS_H
