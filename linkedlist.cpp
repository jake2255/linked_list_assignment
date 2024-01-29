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
void Linkedlist::InsertNode(string title, string id, string genre, int year, float rating){
    //initializes new node with user info
    Node* newNode = new Node;
    newNode->mTitle = title;
    newNode->mId = id;
    newNode->mGenre = genre;
    newNode->mYear = year;
    newNode->mRating = rating;
    newNode->next = nullptr;

    //if list is empty set head/tail to new node, else append new node to tail
    if(head == nullptr && tail == nullptr){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}

//delete node selected by user
void Linkedlist::DeleteNode(string movieDelete){
    if(head == nullptr){
        cout << RED_TEXT << "List empty." << WHITE_TEXT << endl;
        return;
    }
    
    Node* current = head;
    Node* previous = nullptr;
    bool movieExist = false;

    //iterate through list until movie is found or end of list
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
        cout << RED_TEXT << "Movie doesnt exist." << WHITE_TEXT << endl;
    }
    //deletes selected movie when its head of list
    else if(current == head){
        if(head->next == nullptr){ 
            head = nullptr;
            tail = nullptr;
            current = nullptr;
        }
        else{
            head = head->next;
        }
    }
    //deletes selected movie when its tail of list
    else if(current == tail){ 
        previous->next = nullptr;
        tail = previous;
    }
    //deletes selected movie when its in middle of list
    else{
        previous->next = current->next;
    }
}

//display all elements in linked list
void Linkedlist::DisplayList(){
    if(head == nullptr){
         cout << RED_TEXT << "List empty." << WHITE_TEXT << endl;
        return;
    }

    Node* temp = head;
    int counter = 1;

    //iterates through list displaying movie titles
    cout << "Movie List: " << endl;
    while(temp){
        cout << GREEN_TEXT << "Movie #" << counter << WHITE_TEXT << ": " << temp->mTitle << endl;
        temp = temp->next;
        counter++;
    }
}

//reverses the linked list
void Linkedlist::ReverseList(){
    if(head == nullptr){
        cout << RED_TEXT << "List empty." << WHITE_TEXT << endl;
        return;
    }   

    Node* current = head;
    Node* previous = nullptr;
    Node* next = nullptr;
    tail = head;

    //iterates through list and switches next pointer of current from next to previous
    while(current != nullptr){
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;
}

//finds the middle element in the linked list
void Linkedlist::FindMidNode(){
    if(head == nullptr){
        cout << RED_TEXT << "List empty." << WHITE_TEXT << endl;
        return;
    }

    Node* temp = head;
    int counter = 1;

    //finds amount of list elements and divides by 2
    while(temp){
        temp = temp->next;
        counter++;
    }
    int midNode = counter / 2;
    DisplaySingleNode(midNode);
}

//finds and displays a selected node
void Linkedlist::SearchNode(string movieSearch){
    if(head == nullptr){
        cout << RED_TEXT << "List empty." << WHITE_TEXT << endl;
        return;
    }

    Node* temp = head;
    bool found = false;
    int counter = 1;

    //iterates through list until user movie name/id if found
    while(temp && !found){
        if(temp->mTitle == movieSearch || temp->mId == movieSearch){
            found = true;
        }
        temp = temp->next;
        counter++;
    }

    if(found){
        DisplaySingleNode(counter-1);
    }
    else{
        cout << RED_TEXT << "Movie not found." << WHITE_TEXT << endl;
    }
}

//displays all the info from a selected node
void Linkedlist::DisplaySingleNode(int location){
    Node* temp = head;
    int counter = 1;
    while(location != counter){
        temp = temp->next;
        counter++;
    }

    cout << GREEN_TEXT << "Movie #" << counter << " in list:" << WHITE_TEXT << endl;
    cout << "Title: " << temp->mTitle << endl;
    cout << "ID: " << temp->mId << endl;
    cout << "Genre: " << temp->mGenre << endl;
    cout << "Release Year: " << temp->mYear << endl;
    cout << "Rating: " << temp->mRating << endl;
}
