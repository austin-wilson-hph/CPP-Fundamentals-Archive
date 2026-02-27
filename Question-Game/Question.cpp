// File Name: Question.cpp
// Author: Austin Wilson
// Date: 9/23/2024

#include "Question.h"
#include <string>
#include <iostream>

using namespace std;

//Question::Question() acts as the default constructor

Question::Question() {
    key = 'X';
    score = 10;
    stem = "";
    hint = "";
    for (int i = 0; i < SIZE; i++) {
        arrayAnswers[i] = "";
    }
}

//Question::Question is a secondary constructor which takes specifically 3 strings and a
//char called newStem, newAnswers[], newKey and newHint
//a for loop is used to assign answers from the argument newAnswers[].

Question::Question(string newStem, string newAnswers[], char newKey, string newHint) {
    stem = newStem;
    
    for (int i = 0; i < SIZE; i++) {
        arrayAnswers[i] = newAnswers[i];
    }
    
    key = newKey;
    hint = newHint;
    
}

//setStem() takes an argument string called newStem and sets newStem to the private
//member stem

void Question::setStem(string newStem) {
    stem = newStem;
}

//getStem() returns the value within the private member stem value

string Question::getStem() const {
    return stem;
}

//setAnswers() takes an argument string called newAnswers[]
//and then incorporates a for loop which takes each newAnswers[]
//value and inputs them into the private member array of arrayAnswers[]

void Question::setAnswers(string newAnswers[]) {
    
    for (int i = 0; i < SIZE; i++) {
        arrayAnswers[i] = newAnswers[i];
    }
    
}

//getAnswer() takes an argument int index
//an if statement determines if the index value is between 0 and 4 and returns
//that index's arrayAnswers value
//if the index is not valid the function returns "Invalid"

string Question::getAnswer(int i) const {
    
    if (i >= 0 && i < SIZE) {
        return arrayAnswers[i];
    }
    
    else {
        return "Invalid";
    }
    
}

//setKey() takes an argument char called newKey and sets
//newKey to the private member of key

void Question::setKey(char newKey) {
    key = newKey;
}

//getKey() returns the private member value of key value

char Question::getKey() const {
    return key;
}

//getValue() returns the private member of score value

int Question::getValue() const {
    return score;
}

//setHint() takes an argument string called newHint and assigns
//the value of newHint to hint

void Question::setHint(string newHint) {
    hint = newHint;
}

//getHint() takes the private value of score and divides it by 2
//and returns the string value of hint

string Question::getHint() {
    score /= 2;
    return hint;
}

//ask() declares and initilizes a string called result and adds
//the string value of stem to it. Then it takes a for loop
//which assigns an A, B, C, and D to results
//as well as ". " and the various values of arrayAnswers[]

string Question::ask() {
    string result = stem + "\n";
    
    for (int i = 0; i < SIZE; i++) {
        result += char('A'+i);
        result += ". " + arrayAnswers[i] + "\n";
    }
    
    return result;
}
