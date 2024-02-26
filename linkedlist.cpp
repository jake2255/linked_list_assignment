#include "linkedlist.h"

//class default constructor
Linkedlist::Linkedlist(){
    head = nullptr;
    tail = nullptr;
}

//class destructor
Linkedlist::~Linkedlist(){
    Node* temp = head;
    while(temp){
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
}

//insert new node to end of linked list
void Linkedlist::InsertNode(std::string name, std::string address, std::string dob, std::string id){
    //initializes new node with user info
    Node* newNode = new Node(name, address, dob, id);
    //if list is empty set head/tail to new node, else append new node to tail
    if(head == nullptr){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}

//delete node selected by user
void Linkedlist::DeleteNode(std::string studentToDelete){
    if(head == nullptr){
        std::cout << RED_TEXT << "List empty." << WHITE_TEXT << std::endl;
        return;
    }

    Node* current = head;
    Node* previous = nullptr;
    bool studentExist = false;

    //iterate through list until student is found or end of list
    while(current && !studentExist){
        if(current->s_name == studentToDelete || current->s_id == studentToDelete)
            studentExist = true;
        else{
            previous = current;
            current = current->next;
        }
    }
    if(!studentExist)
        std::cout << RED_TEXT << "Student doesnt exist." << WHITE_TEXT << std::endl;

    //deletes selected student when its head of list
    else if(current == head){
        if(head->next == nullptr){ 
            head = nullptr;
            tail = nullptr;
            current = nullptr;
        }
        else
            head = head->next;
    }
    //deletes selected student when its tail of list
    else if(current == tail){ 
        previous->next = nullptr;
        tail = previous;
    }
    //deletes selected student when its in middle of list
    else
        previous->next = current->next;
}

//finds and displays a selected node
void Linkedlist::SearchNode(std::string studentToFind){
    if(head == nullptr){
        std::cout << RED_TEXT << "List empty." << WHITE_TEXT << std::endl;
        return;
    } 

    Node* temp = head;
    bool studentExist = false;
    int counter = 1;

    //iterates through list until student name/id is found
    while(temp && !studentExist){
        if(temp->s_name == studentToFind || temp->s_id == studentToFind)
            studentExist = true;
        else{
            temp = temp->next;
            counter++;
        }
    }
    if(studentExist){
        std::cout << GREEN_TEXT << "Student #" << counter << " in list:" << WHITE_TEXT << std::endl;
        std::cout << "Name: " << temp->s_name << std::endl;
        std::cout << "Address: " << temp->s_address << std::endl;
        std::cout << "Date of Birth: " << temp->s_dob << std::endl;
        std::cout << "ID: " << temp->s_id << std::endl;
    }
    else
        std::cout << RED_TEXT << "Student not found." << WHITE_TEXT << std::endl;
}

void Linkedlist::UpdateNode(){

}

//display all elements in linked list
void Linkedlist::DisplayList(){
    if(head == nullptr){
        std::cout << RED_TEXT << "List empty." << WHITE_TEXT << std::endl;
        return;
    }

    Node* temp = head;
    int counter = 1;

    //iterates through list displaying student names
    std::cout << "Student List: " << std::endl;
    while(temp){
        std::cout << GREEN_TEXT << "Student #" << counter << WHITE_TEXT << ": " << temp->s_name << std::endl;
        temp = temp->next;
        counter++;
    }
}
