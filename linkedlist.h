#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
#define BLUE_TEXT "\x1b[36m"
#define WHITE_TEXT "\x1b[0m"
#define GREEN_TEXT "\x1b[32m"
#define RED_TEXT "\x1b[31m"

using namespace std;

//struct that stores all the elements in each node
struct Node{
    Node* next;
    string mTitle;
    string mId;
    string mGenre;
    int mYear;
    float mRating;
};

//class that implements the nodes into a linked list
class Linkedlist{
    private:
        Node* head;
        Node* tail;
    public:
        Linkedlist();
        ~Linkedlist();
        void InsertNode(string title, string id, string genre, int year, float rating);
        void DeleteNode(string movieDelete);
        void DisplayList();
        void ReverseList();
        void FindMidNode();
        void SearchNode(string movieSearch);
        void DisplaySingleNode(int location);
};

#endif
