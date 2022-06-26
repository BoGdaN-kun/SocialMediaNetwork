//
// Created by dudut on 08/05/2022.
//

#ifndef PROIECT_MARE_LIST_H
#define PROIECT_MARE_LIST_H

#include "Node.h"
#include "vector"

template<class T>
class List {
private:
    Node<T> *head;
public:
    List() { head = nullptr; }
    /**
     * Adds the elem in the list
     * @param elem elem to add
     */
    void add(T elem) {
        if (head == nullptr) {
            head = new Node<T>(elem);
        } else {
            Node<T> *p = head;
            while (p->next != nullptr)
                p = p->next;
            p->next = new Node<T>(elem);
        }
    }
    /**
     * Removes the element
     * @param element_to_remove
     * @return Deleted info , else a default info
     */
    T remove(T element_to_remove) {
        Node<T> *nodeToDelete = nullptr;
        T infoToReturn;

        if (head != nullptr) { // if the list is not empty
            if (head->info == element_to_remove) {
                nodeToDelete = head;
                head = head->next; //head points to the next node
            } else {
                Node<T> *p = head->next;
                Node<T> *q = head;
                while (p != nullptr)
                    if (p->info == element_to_remove) {
                        nodeToDelete = p;
                        p = nullptr;
                    } else {
                        p = p->next;
                        q = q->next;
                    }
                if (nodeToDelete != nullptr)
                    q->next = nodeToDelete->next;
            }
        }
        if (nodeToDelete != nullptr) {
            infoToReturn = nodeToDelete->info;
            delete nodeToDelete;
            return infoToReturn;
        }
        return T(); // e does not exist in the list or the list is empty return a arbitraru of type T
    }
    /**
     * Removes a element
     * @param element_to_remove
     */
    void remove_2(T element_to_remove) {
        Node<T> *nodeToDelete = nullptr;
        if (head != nullptr) { // if the list is not empty
            if (head->info == element_to_remove) {
                nodeToDelete = head;
                head = head->next; //head points to the next node
            } else {
                Node<T> *p = head->next;
                Node<T> *q = head;
                while (p != nullptr)
                    if (p->info == element_to_remove) {
                        nodeToDelete = p;
                        p = nullptr;
                    } else {
                        p = p->next;
                        q = q->next;
                    }
                if (nodeToDelete != nullptr)
                    q->next = nodeToDelete->next;
            }
        }
        if (nodeToDelete != nullptr) {
            delete nodeToDelete;
        }
    }
    /**
     * UPdates the element
     * @param old_element
     * @param new_element
     */
    void update(T old_element, T new_element) {
        if (head != nullptr) {
            if (head->info == old_element) {
                head->info = new_element;
            } else {
                Node<T> *p = head->next;
                while (p != nullptr)
                    if (p->info == old_element) {
                        p->info = new_element;
                        p = p->next;
                    } else {
                        p = p->next;
                    }
            }
        }
    }

    /**
     * Get at index
     * @param index
     * @return returns elem at index
     */
    T get(int index) {
        int i = 0;
        Node<T> *q = head;
        while (i != index && q->next != nullptr) {
            if (q->next != nullptr)
                i++, q = q->next;
        }
        if (i == index)
            return q->info;
        else
            //return -1;
            return T();
    }

    T operator[](int index) {
        if (index > length()) {

            return head->info;
        }
        int i = 0;
    }
/**
 * Get all
 * @return A vector with all elements
 */
    std::vector<T> get_all() {
        Node<T> *temp = head;
        std::vector<T> all;
        while (temp) {
            all.push_back(temp->info);
            temp = temp->next;
        }
        return all;
    }
/**
 * Get the length of the list
 * @return Returns  the length of the list
 */
    int length() {
        Node<T> *temp = head;
        int len = 0;
        while (temp!= nullptr) {
            len++;
            temp = temp->next;
        }
        return len;
    }
};

#endif //PROIECT_MARE_LIST_H
