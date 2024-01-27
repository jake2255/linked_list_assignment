#include "linkedlist.h"
#include <iostream>

using namespace std;

//constructor
Linkedlist::Linkedlist(){
    head = nullptr;
    tail = nullptr;
}

//destructor
Linkedlist::~Linkedlist(){
    Node* temp = head;
    while(temp){
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
}

//insert new node to end of linked list
void Linkedlist::InsertNode(int value){
    Node* newNode = new Node;
    newNode->data = value;
    if(head == nullptr){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}

//delete node at the head of list
void Linkedlist::DeleteNode(){
    if(head != nullptr){
        head = head->next;
    }
}

//display all elements in linked list
void Linkedlist::DisplayList(){
    Node* temp = head;
    cout << "list elements: " << endl;
    while(temp){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

void Linkedlist::SearchNode(){}
void Linkedlist::ReverseList(){}
void Linkedlist::FindMidNode(){}