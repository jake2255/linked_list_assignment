#include "linkedlist.h"
#include "binarytree.h"
#include <chrono>

int main(){
    

    Linkedlist list;  //linked list object
    Binarytree tree;  //binary tree object
    int option = 0;   //menu selection
    std::string name, street, city, state, zip, dob; //student variables
    int id;

    // inserting info from file into data structure
    std::ifstream input("student_info2.csv");
    std::string line;

    if(!input.is_open()){
        std::cout << "Error: File not found.\n";
        return 0;
    }

    while(std::getline(input, line)){
		std::istringstream ss(line);
		std::vector<std::string> student; 
        std::string data;

		while(std::getline(ss, data, ','))
			student.push_back(data);

        if(student.size() == 7){
            name = student[0];
            street = student[1];
            city = student[2];
            state = student[3];
            zip = student[4];
            dob = student[5];
            id = std::stoi(student[6]);

            list.InsertNode(name, street, city, state, zip, dob, id);
            tree.InsertNode(name, street, city, state, zip, dob, id);
            
        }
        else  
            std::cout << "Error: Malformed line in file.\n";
    }

    input.close();

    std::cout <<"****STUDENT DATABASE****"<< std::endl;
    do{
        std::cout << BLUE_TEXT << "Add student [1]" << std::endl;
        std::cout << "Delete student [2]" << std::endl;
        std::cout << "Search student [3]" << std::endl;
        std::cout << "Update student [4]" << std::endl;
        std::cout << "Quit program [0]" << std::endl;
        std::cout << "->" << WHITE_TEXT;
        std::cin >> option;
        system("clear");

        //add student
        if(option == 1){
            std::cout << "Student ID: ";
            std::cin >> id;
            bool foundList = list.SearchForId(id);
            bool foundTree = tree.SearchForId(id);

            if(!foundList && !foundTree){
                std::cout << "Student name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Student street: ";
                std::getline(std::cin, street);
                std::cout << "Student city: ";
                std::getline(std::cin, city);
                std::cout << "Student state: ";
                std::getline(std::cin, state);
                std::cout << "Student zipcode: ";
                std::getline(std::cin, zip);
                std::cout << "Student date of birth: ";
                std::getline(std::cin, dob);

                auto listInsertStart = std::chrono::high_resolution_clock::now();
                list.InsertNode(name, street, city, state, zip, dob, id);
                auto listInsertStop = std::chrono::high_resolution_clock::now();
                auto listInsertDuration = std::chrono::duration_cast<std::chrono::microseconds>(listInsertStop - listInsertStart);
                std::cout << "Time taken by function: "
         << listInsertDuration.count() << " microseconds" << std::endl;;
                
                auto treeInsertStart = std::chrono::high_resolution_clock::now();
                tree.InsertNode(name, street, city, state, zip, dob, id);
                auto treeInsertStop = std::chrono::high_resolution_clock::now();
                auto treeInsertDuration = std::chrono::duration_cast<std::chrono::microseconds>(treeInsertStop - treeInsertStart);
                std::cout << "Time taken by function: "
         << treeInsertDuration.count() << " microseconds" << std::endl;
            
            }
            if(foundList)
                std::cout << RED_TEXT << "Student ID already exists in list." << WHITE_TEXT << "\n";
            if(foundTree)
                std::cout << RED_TEXT << "Student ID already exists in tree." << WHITE_TEXT << "\n";
        }

        else if(option == 2){
            std::string studentToDelete;
            std::cout << "Name/ID of student to delete: ";
            std::cin.ignore();
            std::getline(std::cin, studentToDelete);

            auto listDeleteStart = std::chrono::high_resolution_clock::now();
            list.DeleteNode(studentToDelete);
            auto listDeleteStop = std::chrono::high_resolution_clock::now();
                auto listDeleteDuration = std::chrono::duration_cast<std::chrono::microseconds>(listDeleteStop - listDeleteStart);
                std::cout << "Time taken by function: "
         << listDeleteDuration.count() << " microseconds" << std::endl;

            auto treeDeleteStart = std::chrono::high_resolution_clock::now();
            tree.DeleteNode(stoi(studentToDelete));
            auto treeDeleteStop = std::chrono::high_resolution_clock::now();
                auto treeDeleteDuration = std::chrono::duration_cast<std::chrono::microseconds>(treeDeleteStop - treeDeleteStart);
                std::cout << "Time taken by function: "
         << treeDeleteDuration.count() << " microseconds" << std::endl;

        }

        else if(option == 3){
            std::string studentToFind;
            std::cout << "Name/ID of student to search: ";
            std::cin.ignore();
            std::getline(std::cin, studentToFind);

            auto listSearchStart = std::chrono::high_resolution_clock::now();
            bool foundList = list.SearchNode(studentToFind);
            auto listSearchStop = std::chrono::high_resolution_clock::now();
                auto listSearchDuration = std::chrono::duration_cast<std::chrono::microseconds>(listSearchStop - listSearchStart);
                std::cout << "Time taken by function: "
         << listSearchDuration.count() << " microseconds" << std::endl;;

            auto treeSearchStart = std::chrono::high_resolution_clock::now();
            bool foundTree = tree.SearchNode(studentToFind);
            auto treeSearchStop = std::chrono::high_resolution_clock::now();
                auto treeSearcheDuration = std::chrono::duration_cast<std::chrono::microseconds>(treeSearchStop - treeSearchStart);
                std::cout << "Time taken by function: "
         << treeSearcheDuration.count() << " microseconds" << std::endl;;
        }

        else if(option == 4){
            std::string studentToUpdate;
            std::cout << "Name/ID of student to update: ";
            std::cin.ignore();
            std::getline(std::cin, studentToUpdate);
            bool found = list.SearchNode(studentToUpdate);
            
            if(found){
                std::cout << "Updated student name: ";
                std::getline(std::cin, name);
                std::cout << "Updated student street: ";
                std::getline(std::cin, street);
                std::cout << "Updated student city: ";
                std::getline(std::cin, city);
                std::cout << "Updated student state: ";
                std::getline(std::cin, state);
                std::cout << "Updated student zipcode: ";
                std::getline(std::cin, zip);
                std::cout << "Updated student date of birth: ";
                std::getline(std::cin, dob);

                auto listUpdateStart = std::chrono::high_resolution_clock::now();
                list.UpdateNode(studentToUpdate, name, street, city, state, zip, dob);
                auto listUpdateStop = std::chrono::high_resolution_clock::now();
                auto listUpdateDuration = std::chrono::duration_cast<std::chrono::microseconds>(listUpdateStop - listUpdateStart);
                std::cout << "Time taken by function: "
         << listUpdateDuration.count() << " microseconds" << std::endl;;

                auto treeUpdateStart = std::chrono::high_resolution_clock::now();
                tree.UpdateNode(stoi(studentToUpdate), name, street, city, state, zip, dob);
                auto treeUpdateStop = std::chrono::high_resolution_clock::now();
                auto treeUpdateDuration = std::chrono::duration_cast<std::chrono::microseconds>(treeUpdateStop - treeUpdateStart);
                std::cout << "Time taken by function: "
         << treeUpdateDuration.count() << " microseconds" << std::endl;;
            }
        }
    }while(option != 0);

    std::cout << "have a nice day" << std::endl;

    return 0;
}
