 #ifndef DATA_H
 #define DATA_H

#include <iostream>
using namespace std;

class Data {
public:
    Data(int v) : value{v} {
    cout << "Construct data object " << value << endl;
    }   
    Data(const Data& d){
        cout<<"Copy constructor of data!"<<endl;
        value=d.value;
    }
    ~Data() { cout << "Destroy data object " << value << endl; }    
    int getValue() const { return value; }

private:
    int value; // The value stored
};
#endif
/* File: Node.h */
#ifndef NODE_H
#define NODE_H

class Node {
public:
    Node(const Data& d) : data{d} {
    cout << "Construct node object " << data.getValue() << endl;
    }   
    ~Node() { cout << "Destroy node object " << data.getValue() << endl; }  
    Data getData() const { return data; }
    Node* getNext() const { return next; }  
    void setNext(Node* next) { this->next = next; }

private:
    Data data; // The data associated with this node
    Node* next { nullptr }; // The pointer pointing to the next node
};

 #endif /* NODE_H */

 /* File: SpecialList.h */

#ifndef SPECIALLIST_H
#define SPECIALLIST_H



class SpecialList {
public:
    SpecialList() { cout << "Construct special list" << endl; }
    // TODO: (c)(i) Implement the destructor

    // TODO: (c)(ii) Implement the copy constructor ** deep copy is required **
    SpecialList(const SpecialList& another);
    void add(const Data &data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            newNode->setNext(newNode);
        } else {
            Node* cur = head;
            while (cur->getNext() != head)
            cur = cur->getNext();
            cur->setNext(newNode);
            newNode->setNext(head);
        }
    }
    void printHead() const {
        if (head == nullptr) return;
        cout << head->getData().getValue() << endl<<"After?"<<endl;
    }

private:
    Node* head { nullptr };
};
#endif

using namespace std;
int main() {
    SpecialList* list = new SpecialList;
    Data data1(1);
    Data data2(2);
    Data data3(3);
    list->add(data1);
    list->add(data2);
    list->add(data3);
    list->printHead();

}