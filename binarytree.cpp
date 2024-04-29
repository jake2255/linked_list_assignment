#include "binarytree.h"

//class default constructor
Binarytree::Binarytree(){
    root = nullptr;
}

//class destructor
Binarytree::~Binarytree(){}

//creates new node and initialize with data
void Binarytree::InsertNode(std::string name, std::string street, std::string city, std::string state, std::string zip, std::string dob, int id){
    //initializes new node with user info
    TreeNode* newNode = new TreeNode(name, street, city, state, zip, dob, id);
    //if list is empty set head/tail to new node, else append new node to tail
    if(root == nullptr)
        root = newNode;
    else
        InsertHelper(root, name, street, city, state, zip, dob, id);
}

//traverses tree using binary search and inserts node under parent
void Binarytree::InsertHelper(TreeNode*& node, std::string name, std::string street, std::string city, std::string state, std::string zip, std::string dob, int id){
    if(node == nullptr)
        node = new TreeNode(name, street, city, state, zip, dob, id);
    else if(id < node->s_id)
        InsertHelper(node->left, name, street, city, state, zip, dob, id);
    else
        InsertHelper(node->right, name, street, city, state, zip, dob, id);
}

//checks if student id already exists, returns bool whether id is found
bool Binarytree::SearchForId(int id){
    bool idExist = false;
    SearchForIdHelper(root, id, idExist);
    return idExist;
}

//traverses tree in-order to search for id
void Binarytree::SearchForIdHelper(TreeNode* node, int id, bool& idExist){
    if(node != nullptr && !idExist){
        SearchForIdHelper(node->left, id, idExist);
        if(node->s_id == id)
            idExist = true;
        SearchForIdHelper(node->right, id, idExist);
    }
}

void Binarytree::DeleteNode(std::string studentToDelete){}
TreeNode* Binarytree::DeleteHelper(TreeNode* node, std::string name, std::string street, std::string city, std::string state, std::string zip, std::string dob, int id){return NULL;}

//finds and displays a selected node
bool Binarytree::SearchNode(std::string studentToFind){
    bool studentExist = false;
    if(root == nullptr){
        std::cout << RED_TEXT << "Tree empty." << WHITE_TEXT << std::endl;
        return false;
    }
    else{ 
        SearchNodeHelper(root, studentToFind, studentExist);
        if(!studentExist)
            std::cout << RED_TEXT << "Student not found in tree." << WHITE_TEXT << std::endl;
        return studentExist;
    }
} 

//traverses tree in-order to search for specified student
void Binarytree::SearchNodeHelper(TreeNode* node, std::string studentToFind, bool& studentExist){
    if(node != nullptr && !studentExist){
        SearchNodeHelper(node->left, studentToFind, studentExist);
        std::string studentId = std::to_string(node->s_id);
        if(node->s_name == studentToFind || studentId == studentToFind){
            studentExist = true;
            std::cout << GREEN_TEXT << "Student in tree:" << WHITE_TEXT << std::endl;
            std::cout << "Name: " << node->s_name << std::endl;
            std::cout << "Street: " << node->s_street << std::endl;
            std::cout << "City: " << node->s_city << std::endl;
            std::cout << "State: " << node->s_state << std::endl;
            std::cout << "Zipcode: " << node->s_zipcode << std::endl;
            std::cout << "Date of Birth: " << node->s_dob << std::endl;
            std::cout << "ID: " << node->s_id << std::endl;
        }
        SearchNodeHelper(node->right, studentToFind, studentExist);
    }
}

void Binarytree::UpdateNode(std::string studentToUpdate, std::string name, std::string street, std::string city, std::string state, std::string zip, std::string dob){}

