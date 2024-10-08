#ifndef DOUBLELINKEDLIST_HPP
#define DOUBLELINKEDLIST_HPP
#include <iostream>

class Node {
    int _data;
    Node* _next {nullptr};
    Node* _prev {nullptr};

    public:
    Node (int data) : _data(data), _next(nullptr), _prev(nullptr) {}    

    Node* next() const { return _next; }
    void setNext(Node* next) { _next = next; }

    Node* prev() const { return _prev; }
    void setPrev(Node* prev) { _prev = prev; }

    int data() const { return _data; }
    void setData(int data) { _data = data; }
};

class DoubleLinkedList
{
private:
       Node* _head {nullptr};
       Node* _tail {nullptr};
public:
    DoubleLinkedList() : _head(nullptr), _tail(nullptr) {}
    ~DoubleLinkedList() {
        Node* temp = _head;
        while(temp != nullptr) {
            _head = _head->next();
            delete temp;
            temp = _head;
        }
    }

    bool isempty() {
        if (_head == nullptr) {
            // std::cout<<"List is empty\n";
            return true;
        }
        return false;
    }

    int size() {
        if (isempty()) {
            std::cout<<"List is empty\n";
            return 0;
        }
        Node *temp = _head;
        int t {0};
        while (temp != nullptr) {
            t++;
            temp = temp->next();
        }
        return t;
    }

    void push_front(int val) {
        Node * newNode = new Node(val);
        if (isempty()) {
            _head = newNode;
            _tail =  newNode;
            newNode->setNext(nullptr);
            newNode->setPrev(nullptr);
        }
        else {
            newNode->setPrev(nullptr);
            _head->setPrev(newNode);
            newNode->setNext(_head);
            _head = newNode;
        }
    }

    void push_back(int val) {
        Node * newNode = new Node(val);
        if (isempty()) {
            _head = newNode;
            _tail =  newNode;
            newNode->setNext(nullptr);
            newNode->setPrev(nullptr);
        }
        else {
            newNode->setNext(nullptr);
            newNode->setPrev(_tail);
            _tail->setNext(newNode);
            _tail = newNode;
        }
    }

    void InsertAtPosition (int position, int val) {
        if (position < 0 || position >size()) {
            std::cout<<"Invalid position\n";
            return;
        }

        Node * newNode = new Node(val);

        if (position == 0) {
            push_front(val);
        }
        else if (position == size()) {
            push_back(val);
        }
        else {
            int t = 1;
            Node* temp = _head->next();
            while (temp != nullptr) {
                if (t == position) {
                    newNode->setPrev(temp->prev());
                    temp->prev()->setNext(newNode);
                    newNode->setNext(temp);
                    temp->setPrev(newNode);
                    return;
                }
                temp = temp->next();
                t++;
            }
        }
    }

    void Ftraversal () {
        if (isempty ()) {
            std::cout<<"list is empty\n";
            return;
        }
        Node* temp = _head;
        while (temp != nullptr) {
            std::cout<<"data: "<<temp->data()<<"\n";
            temp = temp->next();
        }
    }

    void Btraversal () {
        if (isempty ()) {
            std::cout<<"list is empty\n";
            return;
        }
        Node* temp = _tail;
        while (temp != nullptr) {
            std::cout<<"data: "<<temp->data()<<"\n";
            temp = temp->prev();
        }
    }

    void pop_front () {
        if (isempty()) {
            std::cout<<"List is empty\n";
            return;
        }
        if (_head == _tail) {
            Node * temp = _head;
            _head = nullptr;
            _tail = nullptr;
            delete temp;
            return;
        }
        Node * temp = _head;
        _head = _head->next();
        _head->setPrev(nullptr);
        delete temp;
    }

    void pop_back () {
        if (isempty()) {
            std::cout<<"list is empty\n";
            return;
        }
        if (_head == _tail) {
            Node * temp = _head;
            _head = nullptr;
            _tail = nullptr;
            delete temp;
            return;
        }
        Node * temp = _tail;
        _tail = _tail->prev();
        _tail->setNext(nullptr);
        delete temp;       
    }

    void DeleteAtPosition (int position) {
        if (isempty()) {
            std::cout<<"list is empty\n";
            return;
        }

        if (position < 0 || position >= size()) {
            std::cout<<"Invalid position\n";
            return;
        }

        if (position == 0) {
            pop_front();
        }
        else if (position == size() - 1) {
            pop_back();
        }
        else {
            Node * temp = _head->next();
            int t = 1;
            temp->prev()->setNext(temp->next());
            temp->next()->setPrev(temp->prev());
            delete temp;
        }
    }
};

#endif // DOUBLELINKEDLIST_HPP
