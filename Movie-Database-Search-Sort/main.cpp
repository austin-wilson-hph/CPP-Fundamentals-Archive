//file name: main.cpp
//Author: Austin Wilson
//Date: 10/22/2024

//Description: takes a file from user input to open
//and stores the various values into the object array
//movies[]. Then the program takes an int choice
//from user input of numbers between 1 and 5 to
//perform various sorting tasks of the object array
//or output specific values from the object array

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>  // Required for left and setw()
#include "Movie.h"

using namespace std;

void readMovies(ifstream& in, Movie movies[], int& size);
void displayMovies(Movie movies[], int SIZE);
int linearSearchByName(Movie movies[], int SIZE, string targetName);
int binarySearchById(Movie movies[], int SIZE, int targetId);
void sortById(Movie movies[], const int SIZE);
void sortByDateRating(Movie movies[], int SIZE);

//***********************************************
//displayMenu(): outputs the various choices of 1 to 5
//of what the user can input to either sort the object
//array or find a particular movie
//***********************************************
void displayMenu(){
    cout << "\nMenu\n"
         << "1. Display movies sorted by id\n"
         << "2. Display movies sorted by release date, then rating\n"
         << "3. Lookup a release date given a name\n"
         << "4. Lookup a movie by id\n"
         << "5. Quit the Program\n"
         << "Enter your choice:\n";
}

//***********************************************
//displayHeader(): outputs the header values of a table
//***********************************************
void displayHeader(){
    cout << left
         << setw(3) << "ID"
         << setw(26) << "Name"
         << setw(12) << "Date"
         << "Rating"
         << endl;
}

int main() {
        string filename;
        cout << "Filename: ";
        cin >> filename;

        ifstream inFile(filename);
        if (!inFile) {
            cerr << "Error opening file: " << filename << endl;
            return 1;
        }
    
        const int MAX_MOVIES = 100;
        Movie movies[MAX_MOVIES];
        int size = 0;

        readMovies(inFile, movies, size);

        inFile.close();
        int choice;
        displayMenu();
    
        do {
            
            cin >> choice;

            switch (choice) {
                    
                case 1:
                    sortById(movies, size);
                    displayHeader();
                    displayMovies(movies, size);
                    displayMenu();
                    break;
                    
                case 2:
                    sortByDateRating(movies, size);
                    displayHeader();
                    displayMovies(movies, size);
                    displayMenu();
                    break;
                    
                case 3: {
                    string movieName;
                    cout << "Please enter a movie name:\n";
                    cin.ignore();
                    getline(cin, movieName);
                    int index = linearSearchByName(movies, size, movieName);
                        
                        if (index != -1) {
                            cout << "Release date of '" << movies[index].getName()
                            << "' is " << movies[index].getReleaseDate() << endl;
                            
                        } else {
                            cout << "No movie found with name: "
                            << movieName << endl;
                        }
                    
                    displayMenu();
                    
                    break;
                }
                    
                case 4: {
                    int movieId;
                    cout << "Please enter a movie id:\n";
                    cin >> movieId;
                    
                    sortById(movies, size);
                        
                    int index = binarySearchById(movies, size, movieId);
                        
                    if (index != -1) {
                        displayHeader();
                        movies[index].display();
                        
                    } else {
                        cout << "No movie found with id: " << movieId << endl;
                    }
                    
                    displayMenu();
                        break;
                }
                    
                case 5:
                    cout << "Exiting the program...\n";
                    break;
                default:
                    cout << "Please enter 1, 2, 3, 4, or 5:\n";
                    break;
            }
            
        } while (choice != 5);
    
        return 0;
}

//***********************************************
//readMovies(): after the file is opened in int main
//the function sends a file stream address by pass by
//reference and the object array movies[], and the int
//size address to add various values from the file opened
//into the array movies[]
//***********************************************
void readMovies(ifstream& in, Movie movies[], int& size) {
    size = 0;
    
    int id;
    string name;
    string releaseDate;
    double rating;
    
    while (true) {
        
        if (!(in >> id)) break;
        in.ignore();
        
        getline(in, name);
        if (name.empty()) break;
        
        in >> releaseDate >> rating;
        in.ignore();
        
        movies[size] = Movie(id, name, releaseDate, rating);
        size++;
        
        string blankLine;
        getline(in, blankLine);
    }
}

//***********************************************
//displayMovies(): passes the object array movies[]
//and int SIZE into a for loop which outputs the various
//values of member variables in class Movie
//***********************************************
void displayMovies(Movie movies[], int SIZE) {
    for (int i = 0; i < SIZE; ++i) {
       
        movies[i].display();
    }
}

//***********************************************
//linearSearchByName(): takes 3 arguments: object array
//movies[], int SIZE, and string targetName and sends
//the values through a for loop to find a particular movie
//name from class Movie
//***********************************************
int linearSearchByName(Movie movies[], int SIZE, string targetName) {
    for (int i = 0; i < SIZE; i++) {
        
        if (movies[i].getName() == targetName) {
            return i;
        }
    }
    return -1;
}

//***********************************************
//binarySearchById(): takes 3 arguments: object array movies[],
//int SIZE, and int targetId to find a specific id from class
//Movie
//***********************************************
int binarySearchById(Movie movies[], int SIZE, int targetId) {
    int low = 0;
    int high = SIZE - 1;

    while (low <= high) {
        int mid = (high + low) / 2;
        
        if (movies[mid].getId() < targetId) {
            low = mid + 1;
        }
        else if (movies[mid].getId() > targetId) {
            high = mid - 1;
        }
        else {
            return mid;
        }
    }

    return -1;
}

//***********************************************
//sortById(): takes an object array movies[] and
//int SIZE and sorts the various movies from the file
//name by their id number in ascending order
//***********************************************
void sortById(Movie movies[], const int SIZE) {
    for (int i = 1; i < SIZE; i++) {
        Movie key = movies[i];
        int j = i - 1;

        while (j >= 0 && movies[j].getId() > key.getId()) {
            movies[j + 1] = movies[j];
            j = j - 1;
        }
        movies[j + 1] = key;
    }
}

//***********************************************
//sortByDateRating(): takes object array movies[]
//and int SIZE from main and sends it through a for
//loop to sort the private member variables of
//releaseDate and rating
//***********************************************
void sortByDateRating(Movie movies[], int SIZE) {
    for (int i = 1; i < SIZE; i++) {
        Movie key = movies[i];
        int j = i - 1;

        while (j >= 0 && (movies[j].getReleaseDate() > key.getReleaseDate() ||
                          (movies[j].getReleaseDate() == key.getReleaseDate() &&
                           movies[j].getRating() < key.getRating()))) {
            movies[j + 1] = movies[j];
            j = j - 1;
        }
        movies[j + 1] = key;
    }
}

