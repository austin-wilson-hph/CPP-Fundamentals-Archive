// File Name: QuizDriver.cpp
// Author: Austin Wilson
// Date: 9/23/2024

// Description:
// An interactive trivia application that demonstrates dynamic data loading and 
// object-oriented state management. The program reads a user-specified number 
// of questions from an external data file, populating an array of Question objects.

// Key Features:
// - Interactive gameplay loop with real-time input validation.
// - Hint System: Users can request a hint ('H'), which triggers a dynamic 
//   point penalty logic defined within the Question class.
// - Dynamic Formatting: Automatically labels multiple-choice answers (A-D).
// - Score Tracking: Compares user input against encrypted keys to calculate 
//   final performance relative to the total possible score.

#include "Question.h"

#include <fstream>

int main()
{
    
    Question questionArray[MAX_QUESTIONS];
    string filename;
    int qCount;
    
    cout << "Filename: ";
    cin >> filename;
    
    cout << "Number of questions (1-10): " << endl;
    cin >> qCount;
    
    ifstream inputFile;
    inputFile.open(filename);
    
    if (!inputFile) {
        return 1;
    }
    
    for (int i = 0; i < qCount; ++i) {
        
        string lines[7];
        
        for (int j = 0; j < 7; ++j) {
            getline(inputFile, lines[j]);
        }
        
        string stem = lines[0];
        string answers[4] = { lines[1], lines[2], lines[3], lines[4] };
        string hint = lines [5];
        char correctKey = lines [6][0];
        
        questionArray[i].setStem(stem);
        questionArray[i].setAnswers(answers);
        questionArray[i].setKey(correctKey);
        questionArray[i].setHint(hint);
        //questionArray[i] = Question(stem, answers, str.at(0), hint);
        }
    
    inputFile.close();
    
    int userScore = 0;
    int totalScore = 0;
    char userVal;

    for (int i = 0; i < qCount; ++i) {
        
        totalScore += questionArray[i].getValue();
        string indexNum = to_string(char(i+1));
        cout << indexNum << ". " << questionArray[i].ask();
        
        cout << "Your answer (enter the letter, or H to ask for a Hint): ";
        cin >> userVal;
        userVal = toupper(userVal);
        
        if (userVal == 'H') {
            
            cout << questionArray[i].getHint() << endl;
            cout << "Your answer (enter the letter): ";
            cin >> userVal;
            userVal = toupper(userVal);
        }
        
        if (userVal == questionArray[i].getKey()) {
            userScore += questionArray[i].getValue();
        }
        cout << endl;
    }

    cout << "Answers: " << endl;
    
    for (int i = 0; i < qCount; i++) {
        cout << questionArray[i].getKey() << " ";
    }
    
    cout << endl << endl;
    cout << "Your score out of " << totalScore << ": " << userScore << endl;
    
    return 0;
}

