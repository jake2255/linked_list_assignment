#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node{
    Node* next;
    int data;
};

class Linkedlist{
    private:
        Node* head;
        Node* tail;
    public:
        Linkedlist();
        ~Linkedlist();
        void InsertNode(int value);
        void DeleteNode();
        void DisplayList();
        void SearchNode();
        void ReverseList();
        void FindMidNode();
};

#endif
