#include <iostream>
#include "LinkedList.hpp"

void Merge(LinkedList& list1, LinkedList& list2, Node* &first, Node* &last) {
    
    Node* temp1 = list1.getHead();
    Node* temp2 = list2.getHead();

    if (temp1->data() < temp2->data()) {
        first = temp1;
        last = temp1;
        temp1 = temp1->next();
        last->setNext(nullptr);
    }
    else {
        first = temp2;
        last = temp2;
        temp2 = temp2->next();
        last->setNext(nullptr);
    }
    while (temp1 != nullptr && temp2 != nullptr) {
        if (temp1->data() < temp2->data()) {
            last->setNext(temp1);
            last = temp1;
            temp1 = temp1->next();
            last->setNext(nullptr);
        }
        else {
            last->setNext(temp2);
            last = temp2;
            temp2 = temp2->next();
            last->setNext(nullptr);
        }
    }
    if (temp1 != nullptr) {
        std::cout<<"Temo1\n";
        last->setNext(temp1);
    }
    if (temp2 != nullptr) {
        std::cout<<"Temp2\n";
        last->setNext(temp2);
    }
}

int main () {
    LinkedList list1;
    list1.push_front(50);
    list1.push_front(15);
    list1.push_front(10);
    LinkedList list2;
    list2.push_front(60);
    list2.push_front(40);
    list2.push_front(20);
    Node* first = nullptr;
    Node* last = nullptr;
    Merge(list1, list2, first, last);
    Node* temp = first;
    std::cout<<"Over\n";
    while (temp != nullptr) {
        std::cout<<"Data: "<<temp->data()<<"\n";
        temp = temp->next();
    }
}