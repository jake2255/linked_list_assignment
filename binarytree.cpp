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

//takes student ID from main menu and searches for the 
void Binarytree::DeleteNode(int studentToDelete){
    int delId = studentToDelete; //save id for passing to helper
    TreeNode *deleteNode =  DeleteHelper(root, delId); //passes root and id to helper for first iteration
    TreeNode *minMaxNode;
    
    TreeNode *tempLeft;
    TreeNode *tempRight;

    TreeNode *parentRight = deleteNode->right;
    TreeNode *parentLeft = deleteNode->left;
    

    

    

    //checking that returned value isn't NULL, then swapping nodes
    if(deleteNode != NULL){  
        if(deleteNode->s_id > root->s_id){
            //right side of tree
          minMaxNode = MinMaxHelper(deleteNode, 2);

        }
        if(deleteNode->s_id < root->s_id){
            //left side of tree
            minMaxNode = MinMaxHelper(deleteNode, 1);
            
        }
    }
    

    //node pointer swapping occurs here
    
    if(deleteNode->s_id > delId){
        tempLeft = parentLeft->left;
        tempRight = parentLeft->right;
        delete(parentLeft);
        deleteNode->left = minMaxNode;
        minMaxNode->left = tempLeft;
        minMaxNode->right = tempRight;
        std::cout << "Student ID " << delId << " has been deleted" << std::endl;

    }

    if(deleteNode->s_id < delId){
        tempLeft = parentRight->left;
        tempRight = parentRight->right;
        delete(parentRight);
        deleteNode->right = minMaxNode;
        minMaxNode->left = tempLeft;
        minMaxNode->right = tempRight;
        std::cout << "Student ID " << delId << " has been deleted" << std::endl;

        
    }


    }




TreeNode* Binarytree::DeleteHelper(TreeNode* node, int id){
    TreeNode *dNode = node; //node passed to 
    int delId = id;
    
    if(dNode->s_id == delId){ //checks if this node it the correct one
        return dNode;
    }


    if(dNode->s_id != delId){
        if(delId > dNode->s_id){
            //right side
            if(dNode->right->s_id == delId){
                return node;
            }
           return DeleteHelper(dNode->right, delId); //checks right node if not correct node
        }
        else if(delId < dNode->s_id){
            //left side
            if(dNode->left->s_id == delId){
                return node;
            }
            return DeleteHelper(dNode->left, delId); //checks left node if not correct node
        }
    }

    
    return NULL;
    }


//second helper method to find the node to swap for balancing of delete option.
TreeNode* Binarytree::MinMaxHelper(TreeNode *node, int minMax){
    TreeNode *childNodeHelper;
    
    //case for node to left of root
    if(minMax == 1){
        if(node->right == NULL){
            childNodeHelper =  node;
        }
        else {
            childNodeHelper = MinMaxHelper(node->right, 1);
            if((childNodeHelper->left != NULL) && (childNodeHelper == node->right)){
                node->right = childNodeHelper->left; 
                
            }
        }
    }

    //case for node to right of root
    if(minMax == 2){
        if(node->left == NULL){
            childNodeHelper =  node;
        }
        else {
            childNodeHelper = MinMaxHelper(node->left, 2);
            if((childNodeHelper->right != NULL) && (childNodeHelper == node->left)){
                node->left = childNodeHelper->right;
        }
    }



    }
    return childNodeHelper;
};


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


void Binarytree::UpdateNode(int studentId, std::string newName, std::string newStreet, std::string newCity, std::string newState, std::string newZip, std::string newDob){
    if(root == nullptr){
        std::cout << RED_TEXT << "The Tree is empty." << WHITE_TEXT << std::endl;
        return;
    }

    UpdateNodeHelper(root, studentId, newName, newStreet, newCity, newState, newZip, newDob);
}
void Binarytree::UpdateNodeHelper(TreeNode* node, int studentId, std::string newName, std::string newStreet, std::string newCity, std::string newState, std::string newZip, std::string newDob){

    if(node != nullptr){
        if(node->s_id == studentId){
            // Display current information
            std::cout << "Current information. " << std::endl;
            std::cout << "Name: " << node->s_name << std::endl;
            std::cout << "Street: " << node->s_street << std::endl;
            std::cout << "City: " << node->s_city << std::endl;
            std::cout << "State: " << node->s_state << std::endl;
            std::cout << "Zipcode: " << node->s_zipcode << std::endl;
            std::cout << "Date of Birth: " << node->s_dob << std::endl;
            std::cout << "ID: " << node->s_id << std::endl;

            //asking the user for updated information
            std::cout << "Enter new information." << std::endl;
            std::cout << "Name: ";
            std::getline(std::cin, newName);
            std::cout << "Street: ";
            std::getline(std::cin, newStreet);
            std::cout << "City: ";
            std::getline(std::cin, newCity);
            std::cout << "State: ";
            std::getline(std::cin, newState);
            std::cout << "Zipcode: ";
            std::getline(std::cin, newZip);
            std::cout << "Date of Birth: ";
            std::getline(std::cin, newDob);

            // Update each node's attributes
            node->s_name = newName;
            node->s_street = newStreet;
            node->s_city = newCity;
            node->s_state = newState;
            node->s_zipcode = newZip;
            node->s_dob = newDob;

            std::cout << GREEN_TEXT << "Student record updated successfully." << WHITE_TEXT << std::endl;
            return;
        }
        else if(studentId < node->s_id){
            UpdateNodeHelper(node->left, studentId, newName, newStreet, newCity, newState, newZip, newDob);
        }
        else{
            UpdateNodeHelper(node->right, studentId, newName, newStreet, newCity, newState, newZip, newDob);
        }
    }
    else{
        std::cout << RED_TEXT << "Student with ID of " << studentId << " not found in tree." << WHITE_TEXT << std::endl;
    }
}

