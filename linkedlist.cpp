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
void Linkedlist::InsertNode(std::string name, std::string street, std::string city, std::string state, std::string zip, std::string dob, int id){
    //initializes new node with user info
    Node* newNode = new Node(name, street, city, state, zip, dob, id);
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
        std::string studentId = std::to_string(current->s_id);
        if(current->s_name == studentToDelete || studentId == studentToDelete)
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
bool Linkedlist::SearchNode(std::string studentToFind){
    if(head == nullptr){
        std::cout << RED_TEXT << "List empty." << WHITE_TEXT << std::endl;
        return false;
    } 

    Node* temp = head;
    bool studentExist = false;

    //iterates through list until student name/id is found
    while(temp && !studentExist){
        std::string studentId = std::to_string(temp->s_id);
        if(temp->s_name == studentToFind || studentId == studentToFind)
            studentExist = true;
        else{
            temp = temp->next;
        }
    }

    if(studentExist){
        std::cout << GREEN_TEXT << "Student in list:" << WHITE_TEXT << std::endl;
        std::cout << "Name: " << temp->s_name << std::endl;
        std::cout << "Street: " << temp->s_street << std::endl;
        std::cout << "City: " << temp->s_city << std::endl;
        std::cout << "State: " << temp->s_state << std::endl;
        std::cout << "Zipcode: " << temp->s_zipcode << std::endl;
        std::cout << "Date of Birth: " << temp->s_dob << std::endl;
        std::cout << "ID: " << temp->s_id << std::endl;
        return true;
    }
    else
        std::cout << RED_TEXT << "Student not found." << WHITE_TEXT << std::endl;
        return false;
}

//finds and updates a selected node
void Linkedlist::UpdateNode(std::string studentToUpdate, std::string name, std::string street, std::string city, std::string state, std::string zip, std::string dob){
    if(head == nullptr){
        std::cout << RED_TEXT << "List empty." << WHITE_TEXT << std::endl;
        return;
    } 

    Node* temp = head;
    bool studentExist = false;

    //iterates through list until student name/id is found
    while(temp && !studentExist){
        std::string studentId = std::to_string(temp->s_id);
        if(temp->s_name == studentToUpdate || studentId == studentToUpdate)
            studentExist = true;
        else{
            temp = temp->next;
        }
    }
    
    if(studentExist){
       temp->s_name = name;
       temp->s_street = street;
       temp->s_city = city;
       temp->s_state = state;
       temp->s_zipcode = zip;
       temp->s_dob = dob;
    }
    else
        std::cout << RED_TEXT << "Student not found." << WHITE_TEXT << std::endl;
}

//display all elements in linked list
void Linkedlist::DisplayList(){
    if(head == nullptr){
        std::cout << RED_TEXT << "List empty." << WHITE_TEXT << std::endl;
        return;
    }

    Node* temp = head;
    //iterates through list displaying student names
    std::cout << "Student List: " << std::endl;
    while(temp){
        std::cout << GREEN_TEXT << "Student|ID->" << WHITE_TEXT << temp->s_name << "|" << temp->s_id << std::endl;
        temp = temp->next;
    }
}
