//file name: Movie.h
//Author: Austin Wilson
//Date: 10/22/2024

//Description: header file for class Movie

#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>

class Movie {
    private:
        int id;
        std::string name;
        std::string releaseDate;
        double rating;
    public:
        Movie();
        Movie(int, std::string, std::string, double);
        void display();
        int getId();
        std::string getName();
        std::string getReleaseDate();
        double getRating();
};

#endif