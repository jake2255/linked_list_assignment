#include "linkedlist.h"

int main(){

    Linkedlist list;    //linked list object
    int option = 0; //menu selection
    string title, id, genre; //user info for movie
    int year;
    float rating;

    cout <<"****MOVIE DATABASE****"<< endl;
    do{
        cout << BLUE_TEXT << "Add movie [1]" << endl;
        cout << "Delete movie [2]" << endl;
        cout << "Display movie list [3]" << endl;
        cout << "Find middle movie [4]" << endl;
        cout << "Search movie [5]" << endl;
        cout << "Reverse list [6]" << endl;
        cout << "Quit program [0]" << WHITE_TEXT << endl;
        cin >> option;
        system("clear");

        //options to modify the movie database
        if(option == 1){
            cout << "Movie title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Movie ID: ";
            getline(cin, id);
            cout << "Movie genre: ";
            getline(cin, genre);
            cout << "Movie release year: ";
            cin >> year;
            cout << "Movie rating [1-10]: ";
            cin >> rating;
            list.InsertNode(title, id, genre, year, rating);
            system("clear");
        }
        else if(option == 2){
            string movieDelete;
            cout << "Title of movie to delete: ";
            cin.ignore();
            getline(cin, movieDelete);
            list.DeleteNode(movieDelete);
        }
        else if(option == 3){
            list.DisplayList();
        }
        else if(option == 4){
            list.FindMidNode();
        }
        else if(option == 5){
            string movieToFind;
            cout << "Enter the title or ID of movie: ";
            cin >> movieToFind;
            list.SearchNode(movieToFind);
        }
        else if(option == 6){
            list.ReverseList();
            list.DisplayList();
        }

    }while(option != 0);

    cout << "have a nice day";

    return 0;
}
