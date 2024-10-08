#include "CircularLinkedList.hpp"

int main () {

    // CircularLinkedList list;
    // if (list.empty())
    // std::cout<<"List size initially: "<<list.size()<<"\n";
    // list.push_back(55);
    // std::cout<<"List size Now: "<<list.size()<<"\n";
    // list.traversal();
    // std::cout<<"---------------------------------------\n";
    // list.InsertAtPosition(0, 44);
    // list.traversal();
    // std::cout<<"---------------------------------------\n";
    // list.push_front(34);
    // list.traversal();
    // std::cout<<"---------------------------------------\n";
    // std::cout<<"---------------------------------------\n";
    // list.push_back(900);
    // list.traversal();
    // std::cout<<"---------------------------------------\n";
    // std::cout<<"---------------------------------------\n";
    // std::cout<<"---------------------------------------\n";
    // std::cout<<"---------------------------------------\n";
    CircularLinkedList list2;
    list2.InsertAtPosition(0, 10);
    list2.push_back(20);
    list2.push_front(5);
    list2.InsertAtPosition(1, 7);
    list2.InsertAtPosition(2, 8);
    list2.push_back(300);
    list2.InsertAtPosition(5, 898989);
    list2.traversal();
    // list2.pop_back();
    std::cout<<"---------------------------------------\n";
    std::cout<<"---------------------------------------\n";
    list2.pop_back();
    list2.traversal();
    std::cout<<"---------------------------------------\n";
    std::cout<<"---------------------------------------\n";
    list2.pop_front();
    list2.traversal();
    std::cout<<"---------------------------------------\n";
    std::cout<<"---------------------------------------\n";
    list2.DeleteAtPosition(2);
    list2.traversal();
}

// C++ Program for Circular Linked List
// #include <iostream>
// using namespace std;

// Template class for a Node in the circular linked list
// template <typename T> class Node {
// public:
//     // Data stored in the node
//     T data;
//     // Pointer to the next node in the list
//     Node<T>* next;

//     // Constructor to initialize a node with given data and
//     // null next pointer
//     Node(T data)
//     {
//         this->data = data;
//         this->next = nullptr;
//     }
// };

// // Template class for the circular linked list
// template <typename T> class CircularLinkedList {
// private:
//     // Pointer to the head (first node) of the list
//     Node<T>* head;

// public:
//     // Constructor to initialize an empty list
//     CircularLinkedList() { head = nullptr; }

//     // Function to insert a node at the beginning of the
//     // list
//     void insertAtFirst(T value)
//     {
//         Node<T>* newNode = new Node<T>(value);
//         if (head == nullptr) {
//             head = newNode;
//             head->next = head;
//         }
//         else {
//             Node<T>* temp = head;
//             while (temp->next != head) {
//                 temp = temp->next;
//             }
//             newNode->next = head;
//             temp->next = newNode;
//             head = newNode;
//         }
//     }

//     // Function to insert a node at the end of the list
//     void insertAtEnd(T value)
//     {
//         Node<T>* newNode = new Node<T>(value);
//         if (head == nullptr) {
//             head = newNode;
//             head->next = head;
//         }
//         else {
//             Node<T>* temp = head;
//             while (temp->next != head) {
//                 temp = temp->next;
//             }
//             temp->next = newNode;
//             newNode->next = head;
//         }
//     }

//     // Function to insert a node at a specific position
//     void insertAtPosition(T value, int position)
//     {
//         Node<T>* newNode = new Node<T>(value);
//         if (position <= 1 || head == nullptr) {
//             insertAtFirst(value);
//         }
//         else {
//             Node<T>* temp = head;
//             for (int i = 1;
//                  i < position - 1 && temp->next != head;
//                  i++) {
//                 temp = temp->next;
//             }
//             newNode->next = temp->next;
//             temp->next = newNode;
//         }
//     }

//     // Function to delete the first node of the list
//     void deleteFromFirst()
//     {
//         if (head == nullptr)
//             return;
//         if (head->next == head) {
//             delete head;
//             head = nullptr;
//         }
//         else {
//             Node<T>* temp = head;
//             while (temp->next != head) {
//                 temp = temp->next;
//             }
//             Node<T>* tempHead = head;
//             temp->next = head->next;
//             head = head->next;
//             delete tempHead;
//         }
//     }

//     // Function to delete the last node of the list
//     void deleteFromEnd()
//     {
//         if (head == nullptr)
//             return;
//         if (head->next == head) {
//             delete head;
//             head = nullptr;
//         }
//         else {
//             Node<T>* temp = head;
//             Node<T>* prev = nullptr;
//             while (temp->next != head) {
//                 prev = temp;
//                 temp = temp->next;
//             }
//             prev->next = head;
//             delete temp;
//         }
//     }

//     // Function to delete a node with a specific key
//     void deleteByKey(T key)
//     {
//         if (head == nullptr)
//             return;
//         if (head->data == key) {
//             deleteFromFirst();
//             return;
//         }
//         Node<T>* temp = head;
//         Node<T>* prev = nullptr;
//         do {
//             prev = temp;
//             temp = temp->next;
//         } while (temp != head && temp->data != key);

//         if (temp->data == key) {
//             prev->next = temp->next;
//             delete temp;
//         }
//     }

//     // Function to print the elements of  the list
//     void display()
//     {
//         if (head == nullptr)
//             return;
//         Node<T>* temp = head;
//         do {
//             cout << temp->data << " -> ";
//             temp = temp->next;
//         } while (temp != head);
//         cout << "HEAD" << endl;
//     }
// };

// int main()
// {
//     // Initialize a circular linked list
//     CircularLinkedList<int> cll;

//     cout << "Circular linked list after inserting node at "
//             "the beginning:"
//          << endl;
//     cll.insertAtFirst(10);
//     cll.display();

//     cout << "Circular linked list after inserting "
//             "20,30,40,50 at the end:"
//          << endl;
//     cll.insertAtEnd(20);
//     cll.insertAtEnd(30);
//     cll.insertAtEnd(40);
//     cll.insertAtEnd(50);
//     cll.display();

//     cout << "Circular linked list after inserting 15 at "
//             "position 2:"
//          << endl;
//     cll.insertAtPosition(15, 2);
//     cll.display();

//     cout << "Circular linked list after deleting the first "
//             "node:"
//          << endl;
//     cll.deleteFromFirst();
//     cll.display();

//     cout << "Circular linked list after deleting the last "
//             "node:"
//          << endl;
//     cll.deleteFromEnd();
//     cll.display();

//     cout << "Circular linked list after deleting node with "
//             "key 30:"
//          << endl;
//     cll.deleteByKey(30);
//     cll.display();

//     return 0;
// }
