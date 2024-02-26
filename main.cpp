#include "linkedlist.h"
#include "binarytree.h"

int main(){

    Linkedlist list;  //linked list object
    Binarytree tree;  //binary tree object
    int option = 0;   //menu selection
    std::string name, address, dob, id; //student variables

    std::cout <<"****STUDENT DATABASE****"<< std::endl;
    do{
        std::cout << BLUE_TEXT << "Add student [1]" << std::endl;
        std::cout << "Delete student [2]" << std::endl;
        std::cout << "Search student [3]" << std::endl;
        std::cout << "Update student [4]" << std::endl;
        std::cout << "Display student [5]" << std::endl;
        std::cout << "Quit program [0]" << WHITE_TEXT << std::endl;
        std::cin >> option;
        system("clear");

        //add student
        if(option == 1){
            std::cout << "Student name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << "Student address: ";
            std::getline(std::cin, address);
            std::cout << "Student date of birth: ";
            std::getline(std::cin, dob);
            std::cout << "Student ID: ";
            std::getline(std::cin, id);

            list.InsertNode(name, address, dob, id);
            //tree.InsertNode(name, address, dob, id);
            system("clear");
        }
        else if(option == 2){
            std::string studentToDelete;
            std::cout << "Name/ID of student to delete: ";
            std::cin.ignore();
            std::getline(std::cin, studentToDelete);
            list.DeleteNode(studentToDelete);
            //tree.DeleteNode(studentToDelete);
        }
        else if(option == 3){
            std::string studentToFind;
            std::cout << "Name/ID of student to search: ";
            std::cin.ignore();
            std::getline(std::cin, studentToFind);
            list.SearchNode(studentToFind);
            //tree.SearchNode(studentToFind);
        }
        else if(option == 4){}
        else if(option == 5){
            list.DisplayList();
            //tree.DisplayList();
        }
        
    }while(option != 0);

    std::cout << "have a nice day";

    return 0;
}
