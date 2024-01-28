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
        if(head->next == nullptr){
            head = nullptr;
            tail = nullptr;
            current = nullptr;
        }
        else{
            head = head->next;
        }
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
    if(head == nullptr){
        cout << "List empty." << endl;
        return;
    }

    Node* temp = head;
    int counter = 1;

    cout << "Movie List: " << endl;
    while(temp){
        cout << "Movie #" << counter << ": " << temp->mTitle << endl;
        temp = temp->next;
        counter++;
    }
}

//reverses the linked list
void Linkedlist::ReverseList(){
    if(head == nullptr){
        cout << "List empty." << endl;
        return;
    }   

    Node* current = head;
    Node* previous = nullptr;
    Node* next = nullptr;

    while(current != NULL){
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
        cout << "List empty." << endl;
        return;
    }

    Node* temp = head;
    int counter = 1;
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
        cout << "List empty." << endl;
        return;
    }

    Node* temp = head;
    bool found = false;
    int counter = 1;

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
        cout << "Movie not found." << endl;
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

    cout << "Movie #" << counter << " in list:" << endl;
    cout << "Title: " << temp->mTitle << endl;
    cout << "ID: " << temp->mId << endl;
    cout << "Genre: " << temp->mGenre << endl;
    cout << "Release Year: " << temp->mYear << endl;
    cout << "Rating: " << temp->mRating << endl;
}
