#ifndef DOUBLELINKEDLIST_HPP
#define DOUBLELINKEDLIST_HPP
#include <iostream>
#include <vector>

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
       int _size {0};
public:
    DoubleLinkedList() : _head(nullptr), _tail(nullptr), _size (0) {}
    ~DoubleLinkedList() {
        Node* cur = _head;
        while(cur != nullptr) {
            _head = _head->next();
            delete cur;
            cur = _head;
        }
    }

    bool empty() {
        if (_size == 0) {
            return true;
        }
        return false;
    }

    int size() {
        return _size;
    }

    void push_front(int val) {
        Node * newNode = new Node(val);
        if (_size == 0) {
            _head = newNode;
            _tail =  newNode;
            newNode->setNext(nullptr);
            newNode->setPrev(nullptr);
            _size++;
        }
        else {
            newNode->setPrev(nullptr);
            _head->setPrev(newNode);
            newNode->setNext(_head);
            _head = newNode;
            _size++;
        }
    }

    void push_back(int val) {
        Node * newNode = new Node(val);
        if (_size == 0) {
            _head = newNode;
            _tail =  newNode;
            newNode->setNext(nullptr);
            newNode->setPrev(nullptr);
            _size++;
        }
        else {
            newNode->setNext(nullptr);
            newNode->setPrev(_tail);
            _tail->setNext(newNode);
            _tail = newNode;
            _size++;
        }
    }

    void insert_at_position (int position, int val) {
        if (position < 0 || position > _size) {
            std::cout<<"Invalid position\n";
            return;
        }

        Node * newNode = new Node(val);

        if (position == 0) {
            push_front(val);
        }
        else if (position == _size) {
            push_back(val);
        }
        else {
            int t = 1;
            Node* temp = _head->next();
            while (t != position) {
                t++;
                temp = temp->next();
            }
            newNode->setPrev(temp->prev());
            temp->prev()->setNext(newNode);
            newNode->setNext(temp);
            temp->setPrev(newNode);
            _size++;
        }
    }

    void pop_front () {
        if (empty()) {
            std::cout<<"List is empty\n";
            return;
        }

        if (!empty() && _head == _tail) {
            delete _head;
            _head = nullptr;
            _tail = nullptr;
            _size--;
            return;
        }
        if (!empty()) {
            Node * temp = _head;
            _head = _head->next();
            _head->setPrev(nullptr);
            delete temp;
            _size--;
            return;
        }
    }

    void pop_back () {
        if (empty()) {
            std::cout<<"List is empty\n";
            return;
        }

        if (!empty() && _head == _tail) {
            delete _head;
            _head = nullptr;
            _tail = nullptr;
            _size--;
            return;
        }
        if (!empty()) {
            Node * temp = _tail;
            _tail = _tail->prev();
            _tail->setNext(nullptr);
            delete temp;  
            _size--;
            return;
        }     
    }

    void delete_at_position (int position) {
        if (empty()) {
            std::cout<<"List is empty\n";
            return;
        }

        if (position < 0 || position >= _size) {
            std::cout<<"Invalid position\n";
            return;
        }

        if (position == 0) {
            return pop_front();
        }
        
        if (position == _size - 1) {
            return pop_back();
        }

        if (!empty()) {
            int t = 1;
            Node * prev = _head;
            Node * cur = _head->next();

            while (t != position) {
                t++;
                prev = cur;
                cur = cur->next();
            }

            prev->setNext(cur->next());
            (cur->next())->setPrev(prev);

            if (cur == _tail) {
                _tail = prev;
            }
            delete cur;
            _size--;
            return;
        }
    }

    std::vector<int> forward_traversal () {
        if (!empty()) {
            std::vector<int> v(_size);
            int i = 0;
            Node* temp = _head;
            while (temp != nullptr) {
                v[i++] = temp->data();
                temp = temp->next();
            }
            return v;
        }
    }

    std::vector<int> backward_traversal () {
        if (!empty()) {
            std::vector<int> v(_size);
            int i = 0;
            Node* temp = _tail;
            while (temp != nullptr) {
                v[i++] = temp->data();
                temp = temp->prev();
            }
            return v;
        }
    }


};

#endif // DOUBLELINKEDLIST_HPP
