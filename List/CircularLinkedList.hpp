#ifndef CIRCULARLINKEDLIST_HPP
#define CIRCULARLINKEDLIST_HPP
#include <iostream>

class Node {
    int _data;
    Node * _next {nullptr};

    public:
    Node (int data) : _data(data), _next(nullptr) {} //para cstr for Node

    int data() const { return _data; }
    void setData(int data) { _data = data; }

    Node * next() const { return _next; }
    void setNext(Node * next) { _next = next; }
};
    
class CircularLinkedList {
    Node * _head {nullptr};

    public:
    CircularLinkedList () : _head {nullptr} {}
    ~CircularLinkedList () {
        Node * temp = _head;
        Node* curr = temp;
        do {
        curr = temp;
        delete curr;
        temp = temp->next();
        } while (temp != _head);
    }

    bool empty () {
        if (_head == nullptr) {
            return true;
        }
        return false;
    }

    int size() {
        if (empty())
        return 0;
        int _size {0};

        Node * temp = _head;
    do {
        _size++;
        temp = temp->next();
        } while (temp != _head);
        
        return _size;
    }

    void push_front (int data) {
        Node* newNode = new Node(data);

        if (_head == nullptr) {
            _head = newNode;
            newNode->setNext(_head);
        }
        else {
            Node* temp = _head;
            do {
                temp = temp->next();
            } while (temp->next() != _head);
            newNode->setNext(_head);
            temp->setNext(newNode);
            _head = newNode;
        }
    }

    void InsertAtPosition (int position, int data) {

        if (empty() || position == 0) { // empty Does not make sense 
            push_front(data);
        }

        if( position < 0 || position >= size()) {
            std::cout<<"Invalid position\n";
            return;
        }

        else {
        Node* newNode = new Node(data);

        int t = 1;
        Node * temp = _head;
        do {
        if (t == position) {
            newNode->setNext(temp->next());
            temp->setNext(newNode);
            return;
        }
        temp = temp->next();
        t++;
        } while (temp != _head);
        }
    }

    void push_back (int data) {
        Node* newNode = new Node(data);

        if (_head == nullptr) {
            _head = newNode;
            newNode->setNext(_head);
        }
        else {
            Node * temp = _head;
            do {
            temp = temp->next();
            }while (temp->next() != _head);
            temp->setNext(newNode);
            newNode->setNext(_head);
        }
    }

    void traversal () {
        if (empty()) {
            std::cout<<"List is empty\n";
            return;
        }
        Node* temp = _head;
        do {
            std::cout<<"data: "<<temp->data()<<"\n";
            temp = temp->next();
        }while (temp != _head);
    }

    void pop_back() {
        if (empty()) {
            std::cout<<"List is empty\n";
            return;
        }
        if (_head->next() == _head) {
            delete _head;
            _head = nullptr;
            return;
        }
        Node* temp = _head;
        Node* prev = nullptr;
            while (temp->next() != _head) {
                prev = temp;
                temp = temp->next();
            }
            prev->setNext(_head);
            delete temp;
    }

    void pop_front() {
        if (empty()) {
            std::cout<<"List is empty\n";
            return;
        }
        if (_head->next() == _head) {
            delete _head;
            _head = nullptr;
        }
        else {
        Node* temp = _head;
        while (temp->next() != _head) {
            temp = temp->next();
        }
        Node* temp1 = _head;
        temp->setNext(_head->next());   
        _head = _head->next();
        delete temp1;
        }
    }

    void DeleteAtPosition (int position) {

        if (position < 0 || position >= size()) {
            std::cout<<"Invalid position\n";
            return;
        }

        if (position == 0) {
            pop_front();
            return;
        }
        else {
            int t = 1;
            Node * temp = _head->next();
            Node * prev = nullptr;
        do {
            if (t == position) {
            prev->setNext(temp->next());
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->next();
        t++;
        } while (temp != _head);
        }

    }
};

#endif // CIRCULARLINKEDLIST_HPP

