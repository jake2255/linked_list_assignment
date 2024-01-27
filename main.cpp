#include "linkedlist.h"
#include <iostream>

using namespace std;

int main(){

    Linkedlist list;
    int option = 0;
    do{
        cout << "Enter linked list elements [1], display list [2], delete node [3], or quit [4]: ";
        cin >> option;

        if(option == 1){
            int newVal = 0;
            cout << "Enter value to add to linked list: ";
            cin >> newVal;
            list.InsertNode(newVal);
        }
        else if(option == 2){
            list.DisplayList();
        }
        else if(option == 3){
            list.DeleteNode();
        }
        
    }while(option != 4);

    return 0;
}