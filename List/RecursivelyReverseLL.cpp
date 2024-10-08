#include "LinkedList.hpp"

void Reverse (LinkedList& list, Node * temp1, Node * temp2) {
    if (list.empty()) {
        return;
    }

    if(temp1 != nullptr) {
        Reverse(list, temp1->next(), temp1);
        temp1->setNext(temp2);
    }
    else {
        // list.getHead()->setNext(nullptr);
        list.setHead(temp2);
    }
}
int main () {
    LinkedList list;
    list.push_front(10);
    list.push_front(20);
    list.push_front(2);
    list.push_front(5);
    list.push_front(15);

    list.Traversal();
    Node* temp1 = list.getHead();
    Node* temp2 = nullptr;
    Reverse(list, temp1, temp2);
    list.Traversal();
}