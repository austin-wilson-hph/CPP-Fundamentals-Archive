//file name: Movie.cpp
//Author: Austin Wilson
//Date: 10/22/2024

#include "Movie.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//***********************************************
//Movie() is the default constructor which
//initializes private members id, name,
//releaseDate and rating to specific values
//***********************************************
Movie::Movie() {
    id = 0;
    name = "";
    releaseDate = "";
    rating = 0.0;
}

//***********************************************
//Movie(): a constructor with 4 variables which takes
//int newId, string newName, string newReleaseDate,
//and double newRating and assigns them to their
//various private member variables
//***********************************************
Movie::Movie(int newId, string newName, string newReleaseDate, double newRating) {
    id = newId;
    name = newName;
    releaseDate = newReleaseDate;
    rating = newRating;
}

//***********************************************
//getId(): returns the int variable id's value
//***********************************************
int Movie::getId() {
    return id;
}

//***********************************************
//getName(): returns the string variable's value
//***********************************************
string Movie::getName() {
    return name;
}

//***********************************************
//getReleaseDate(): returns the string releaseDate
//variable value
//***********************************************
string Movie::getReleaseDate() {
    return releaseDate;
}
double Movie::getRating() {
    return rating;
}

//***********************************************
//display(): outputs the values of id, name, releaseDate,
//and rating in a table format
//***********************************************
void Movie::display() {
    cout << left << setw(3) << id
         << setw(26) << name
         << setw(12) << releaseDate
         << fixed << setprecision(1) << rating << endl;
}
