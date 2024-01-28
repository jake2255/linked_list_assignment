#include "linkedlist.h"

//constructor
Linkedlist::Linkedlist(){
    head = nullptr;
    tail = nullptr;
}

//destructor
Linkedlist::~Linkedlist(){
    Node* temp = head;
    while(temp){
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
}

//insert new node to end of linked list
void Linkedlist::InsertNode(string title, string id, string genre, int year, float rating){
    Node* newNode = new Node;
    newNode->mTitle = title;
    newNode->mId = id;
    newNode->mGenre = genre;
    newNode->mYear = year;
    newNode->mRating = rating;

    if(head == nullptr){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}

//delete node at the head of list
void Linkedlist::DeleteNode(string movieDelete){
    if(head == nullptr){
        cout << "List empty." << endl;
        return;
    }
    
    Node* current = head;
    Node* previous = nullptr;
    bool movieExist = false;

    while(current && !movieExist){
        if(current->mTitle == movieDelete){
            movieExist = true;
        }
        else{
            previous = current;
            current = current->next;
        }
    }

    if(!movieExist){
        cout << "Movie doesnt exist." << endl;
    }
    else if(current == head){
        head = nullptr;
        tail = nullptr;
    }
    else if(current == tail){
        previous->next = nullptr;
        tail = previous;
    }
    else{
        previous->next = current->next;
    }
    //free(current);
    //free(previous);
}

//display all elements in linked list
void Linkedlist::DisplayList(){
    Node* temp = head;
    int counter = 1;

    cout << "Movie List: " << endl;
    while(temp){
        cout << "Movie #" << counter << ": " << temp->mTitle << endl;
        temp = temp->next;
        counter++;
    }
}

void Linkedlist::ReverseList(){}
void Linkedlist::FindMidNode(){}
void Linkedlist::SearchNode(){}
