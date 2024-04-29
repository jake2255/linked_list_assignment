#include "linkedlist.h"
#include "binarytree.h"

int main(){

    Linkedlist list;  //linked list object
    //Binarytree tree;  //binary tree object
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
            //tree.InsertNode(name, street, city, state, zip, dob, id);
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
        std::cout << "Display student [5]" << std::endl;
        std::cout << "Quit program [0]" << std::endl;
        std::cout << "->" << WHITE_TEXT;
        std::cin >> option;
        system("clear");

        //add student
        if(option == 1){
            std::cout << "Student ID: ";
            std::cin >> id;
            bool found = list.InsertNodeHelper(id);

            if(!found){
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
                list.InsertNode(name, street, city, state, zip, dob, id);
                //tree.InsertNode(name, address, dob, id);
            }
            else if(found){
                std::cout << RED_TEXT << "Student ID already exists." << WHITE_TEXT << "\n";
            }
            //system("clear");
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
            bool found = list.SearchNode(studentToFind);
            //tree.SearchNode(studentToFind);
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
                list.UpdateNode(studentToUpdate, name, street, city, state, zip, dob);
                //tree.SearchNode(studentToFind);
            }
        }

        else if(option == 5){
            list.DisplayList();
            //tree.DisplayList();
        }
        
    }while(option != 0);

    std::cout << "have a nice day" << std::endl;

    return 0;
}
