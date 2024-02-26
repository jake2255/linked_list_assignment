#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>

#define BLUE_TEXT "\x1b[36m"
#define WHITE_TEXT "\x1b[0m"
#define GREEN_TEXT "\x1b[32m"
#define RED_TEXT "\x1b[31m"

//struct that stores all the elements in each node
struct Node{
    Node* next;
    std::string s_name;
    std::string s_address;
    std::string s_dob;
    std::string s_id;
    Node(std::string n, std::string a, std::string d, std::string i): s_name(n), s_address(a), s_dob(d), s_id(i){}
};

//class that implements the nodes into a linked list
class Linkedlist{
    private:
        Node* head;
        Node* tail;
    public:
        Linkedlist();
        ~Linkedlist();
        void InsertNode(std::string, std::string, std::string, std::string);
        void DeleteNode(std::string);
        void SearchNode(std::string);
        void UpdateNode();
        void DisplayList();    
};

#endif
