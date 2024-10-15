#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include <iostream>
#include <vector>
/*
    PUT CONST AFTER ALL MEMBER FUNCTIONS OR ELSE CANNOT USE
    const LinkedList as parameter
*/
class LinkedList {
    
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

    Node* head {nullptr};
    Node* tail {nullptr};
    int _size {0};

    public:
    LinkedList () : head(nullptr), tail(nullptr), _size(0) {} //default cstr for LinkedList

    ~LinkedList () { // Need to delete all dynamically allocated Nodes
        Node* cur = nullptr;
        while (head != nullptr) {
        cur = head;
        head = head->next();
        delete cur;
        }
    }

    bool empty() {
        if (_size == 0) {
            return true;
        }
        return false;
    }

    int size () {
        return _size;
    }

    /*
        Insertion
    */
    void push_front (int data){
        if (_size == 0) {
            Node * newNode = new Node(data);
            head = newNode;
            tail = newNode;
            _size++;
        }
        else {
            Node * newNode = new Node(data);
            newNode->setNext(head);
            head = newNode;
            _size++;
        }
    }

    void push_back (int data)
    {
        if (_size == 0) {
            Node * newNode = new Node(data);
            head = newNode;
            tail = newNode;
            _size++;
        }
        else {
            Node * newNode = new Node(data);
            tail->setNext(newNode);
            tail = newNode;
            _size++;
        }
    }

    void insert_at_position (int data, int position) {

        if (position < 0 || position > _size) {
            std::cout<<"Invalid Position\n";
            return;
        }

        // If the list is empty or if position is 0th
        if (_size == 0 || position == 0) {
            push_front(data);
        }
        else if (position == _size) {
            push_back(data);
        }
        else {

            Node * newNode = new Node(data);

            int t = 1;
            Node * prev = head;
            Node * cur = head->next();         //Redundant Code traversal(insert)
            
            while (t != position) {
                t++;
                prev = cur;
                cur = cur->next();
            }

            prev->setNext(newNode);
            newNode->setNext(cur);
            _size++;
        }
    }

    /*
        Deletion
    */
   void pop_front () {
        if (empty()) {
            std::cout<<"list is empty\n";
            return;
        }
        if (!empty() && head == tail) {
            delete head;
            head = tail = nullptr;
            _size--;
            return;
        }
        if (!empty()) {
            Node * temp = head;
            head = head->next();
            delete temp;
            _size--;
            return;
        }
   }

   void pop_back () 
    {
        if (empty()) {
            std::cout<<"list is empty\n";
            return;
        }

        if (!empty() && head == tail) {
            delete head;
            head = tail = nullptr;
            _size--;
            return;
        }
        if (!empty()) {
            delete_at_position(_size - 1);
        }
    }

       void delete_at_position (int position) {
        
        if (empty()) {
            std::cout<<"list is empty\n";
            return;
        }

        if (position < 0 || position >= _size) {
            std::cout<<"Invalid Position\n";
            return;
        }

        if (position == 0) {
            return pop_front();
        }

        if (!empty()) {
            int t = 1;
            Node * prev = head;
            Node * cur = head->next();

            while (t != position) {
                t++;
                prev = cur;
                cur = cur->next();
            }
            prev->setNext(cur->next());
            if (cur == tail) {
                tail = prev;
            }
            delete cur;
            _size--;
            return;
        }
   }

    /*
        Traversing the linkedlist
    */
    std::vector<int> traversal () {
        if (_size > 0) {
        std::vector<int> v(_size);
        Node * cur = head;
        int i = 0;
        while (cur != nullptr) {               
            v[i++] = cur->data();
            cur = cur->next();
        }
        return v;
        }
    }

    Node * getHead() const { return head; }

    void setHead(Node * head_) { head = head_; }
};  

#endif // LINKEDLIST_HPP
