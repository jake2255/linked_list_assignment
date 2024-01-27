#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>

using namespace std;

struct Node{
    Node* next;
    string mTitle;
    string mId;
    string mGenre;
    int mYear;
    float mRating;
};

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
        void SearchNode();
};

#endif
