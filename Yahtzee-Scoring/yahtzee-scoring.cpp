// File Name: yahtzee_logic.cpp
// Author: Austin Wilson
// Description: A standalone scoring engine for Yahtzee dice rolls.

#include <iostream>
using namespace std;

const int SIZE = 5;

// Calculates the "Chance" score (sum of all dice)
int getChanceScore(int val[]) {
    int total = 0;
    for (int i = 0; i < SIZE; i++) {
        total += val[i];
    }
    return total;
}

// Checks for five identical dice (50 points)
int getFiveOfKindScore(int diceVal[]) {
    if (diceVal[0] == diceVal[1] && diceVal[1] == diceVal[2] &&
        diceVal[2] == diceVal[3] && diceVal[3] == diceVal[4]) {
        return 50;
    }
    return 0;
}

// Checks for a large straight (40 points)
int getStraightScore(int diceVal[]) {
    if (diceVal[0] < diceVal[1] && diceVal[1] < diceVal[2] &&
        diceVal[2] < diceVal[3] && diceVal[3] < diceVal[4]) {
        return 40;
    }
    return 0;
}

// Validation: Ensure input is sorted for the scoring logic to work
bool isInputSorted(int diceVal[]) {
    for (int i = 1; i < SIZE; ++i) {
        if (diceVal[i] < diceVal[i-1]) return false;
    }
    return true;
}

int main() {
    int diceVal[SIZE];
    
    cout << "Enter 5 dice values (sorted ascending): ";
    for (int i = 0; i < SIZE; i++) {
        cin >> diceVal[i];
    }

    if (!isInputSorted(diceVal)) {
        cout << "Error: Dice must be entered in increasing order for scoring logic." << endl;
        return 1;
    }

    int straight = getStraightScore(diceVal);
    int fiveKind = getFiveOfKindScore(diceVal);
    int chance = getChanceScore(diceVal);

    // Logic to determine the best possible score
    int highScore = chance;
    if (straight > highScore) highScore = straight;
    if (fiveKind > highScore) highScore = fiveKind;

    cout << "Calculated High Score: " << highScore << endl;

    return 0;
}
