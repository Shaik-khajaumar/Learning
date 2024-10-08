#include "DoubleLinkedList.hpp"

int main () {
    DoubleLinkedList list;
    std::cout<<"Initially list size: "<<list.size()<<"\n";
    // list.push_back(10);
    // list.push_front(5);
    // std::cout<<"Now list size: "<<list.size()<<"\n";
    // list.Ftraversal();
    // std::cout<<"-------------------------------\n";
    // list.Btraversal();

    list.InsertAtPosition(0, 5);
    list.InsertAtPosition(1, 10);
    // std::cout<<"Now list size: "<<list.size()<<"\n";
    // list.Ftraversal();
    // std::cout<<"-------------------------------\n";
    // list.Btraversal();
    list.InsertAtPosition(1, 6);
    list.InsertAtPosition(1, 2);
    list.InsertAtPosition(3, 9);
    list.Ftraversal();
    std::cout<<"-------------------------------\n";
    list.Btraversal();
    list.pop_front();
    list.pop_back();
    list.pop_back();
    list.pop_back();
    list.pop_back();
    std::cout<<"-------------------------------\n";
    list.Ftraversal();
    list.Btraversal();
    list.push_back(100);
    list.push_front(10);
    list.push_front(5);
    list.DeleteAtPosition(1);
    list.Ftraversal();
    list.Btraversal();
}