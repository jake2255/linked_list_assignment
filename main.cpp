#include "linkedlist.h"

int main(){

    Linkedlist list;
    int option = 0;
    string title, id, genre;
    int year;
    float rating;

    cout <<"****MOVIE DATABASE****"<< endl;
    do{
        cout << "Add movie[1], delete movie [2], display movie list [3], find middle movie [4], search movie [5], reverse list [6] or quit [0]: ";
        cin >> option;

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
            cout << "Movie in middle of list.";
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

    return 0;
}
