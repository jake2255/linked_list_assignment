#include "binarytree.h"

Binarytree::Binarytree(){
    root = nullptr;
}

Binarytree::~Binarytree(){}

//recursive function that inserts new node into BST
void Binarytree::InsertHelper(TreeNode*& node, std::string name, std::string street, std::string city, std::string state, std::string zip, std::string dob, int id){
    if(node == nullptr)
        node = new TreeNode(name, street, city, state, zip, dob, id);
    else if(id < node->s_id)
        InsertHelper(node->left, name, street, city, state, zip, dob, id);
    else
        InsertHelper(node->right, name, street, city, state, zip, dob, id);
}

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


TreeNode* Binarytree::DeleteHelper(TreeNode* node, std::string name, std::string street, std::string city, std::string state, std::string zip, std::string dob, int id){}
void Binarytree::InOrderTraversalHelper(TreeNode* node){}
void Binarytree::PreOrderTraversalHelper(TreeNode* node){}
void Binarytree::PostOrderTraversalHelper(TreeNode* node){}

void Binarytree::DeleteNode(std::string studentToDelete){}
bool Binarytree::SearchNode(std::string studentToFind){} 
void Binarytree::UpdateNode(std::string studentToUpdate, std::string name, std::string street, std::string city, std::string state, std::string zip, std::string dob){}
void Binarytree::DisplayTree(){}  


