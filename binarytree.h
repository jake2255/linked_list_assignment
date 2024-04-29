#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <string>

#define BLUE_TEXT "\x1b[36m"
#define WHITE_TEXT "\x1b[0m"
#define GREEN_TEXT "\x1b[32m"
#define RED_TEXT "\x1b[31m"

//struct that stores all the elements in each node
struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    std::string s_name;
    std::string s_street;
    std::string s_city;
    std::string s_state;
    std::string s_zipcode;
    std::string s_dob;
    int s_id;

    TreeNode(std::string name, std::string street, std::string city, std::string state, std::string zip, std::string dob, int id): 
        s_name(name), s_street(street), s_city(city), s_state(state), s_zipcode(zip), s_dob(dob), s_id(id), left(NULL), right(NULL){}
};

class Binarytree{
    private:
        TreeNode* root;
        void InsertHelper(TreeNode*&, std::string, std::string, std::string, std::string, std::string, std::string, int);
        void SearchForIdHelper(TreeNode*, int, bool&);
        TreeNode* DeleteHelper(TreeNode*, std::string, std::string, std::string, std::string, std::string, std::string, int);
        void SearchNodeHelper(TreeNode*, std::string, bool&);

    public:
        Binarytree();
        ~Binarytree();
        void InsertNode(std::string, std::string, std::string, std::string, std::string, std::string, int);
        bool SearchForId(int);
        void DeleteNode(std::string);
        bool SearchNode(std::string);
        void UpdateNode(std::string, std::string, std::string, std::string, std::string, std::string, std::string); 
};

#endif
