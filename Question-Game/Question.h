// File Name: Question.h
// Author: Austin Wilson
// Date: 9/23/2024

#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <iostream>

int const SIZE = 4;
int const MAX_QUESTIONS = 10;

class Question {

  public:
    static const int NUM_ANSWERS = 4;
    Question();
    Question(std::string newStem, std::string newAnswers[], char newKey, std::string newHint);
    
    void setStem(std::string);
    std::string getStem() const;
    
    void setAnswers(std::string[]);
    std::string getAnswer(int) const;
    
    void setKey(char);
    char getKey() const;
    
    int getValue() const;
    
    void setHint(std::string);
    std::string getHint() const;
    
    std::string ask();
    
  private:
    
    std::string stem;
    std::string arrayAnswers[NUM_ANSWERS];
    std::string hint;
    char key;
    int score = 10;
    
};


#endif
