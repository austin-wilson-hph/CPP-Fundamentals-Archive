# Yahtzee Scoring Logic (C++)

A focused implementation of a scoring engine for a Yahtzee-style dice game. This project demonstrates foundational algorithmic thinking, array validation, and conditional pattern matching.

## Logic & Features
The program accepts five dice values as input and evaluates them against three major scoring categories to determine the highest possible point value:

- **Five-of-a-Kind:** Detects when all five dice are identical (Fixed 50 points).
- **Large Straight:** Identifies a continuous sequence of five values (Fixed 40 points).
- **Chance:** Calculates the sum of all dice values.

## Key Technical Concepts
- **Input Validation:** Implements a sorting check (`isInputSorted`) to ensure data integrity before running scoring algorithms.
- **Modular Design:** Logic is separated into discrete functions for each scoring category, improving readability and maintainability.
- **Algorithmic Efficiency:** Uses single-pass array traversal ($O(n)$ complexity) to calculate sums and verify sequences.

## How to Run
1. Compile the source file:
   ```bash
   g++ yahtzee_logic.cpp -o yahtzee
