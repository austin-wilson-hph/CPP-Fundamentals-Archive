# Interactive Quiz Engine

A C++ command-line application that manages a multiple-choice trivia game. This project serves as a demonstration of class-based architecture, file stream manipulation, and dynamic scoring logic.

## Gameplay Mechanics
- **Dynamic Loading:** Loads questions, answers, and hints from an external `.txt` file based on user input.
- **Hint System:** Users can trade score potential for information. Calling a hint reduces the point value of the question by 50% ($score = score / 2$).
- **Case-Insensitivity:** Implements `toupper()` validation to ensure user input is robust.

## Technical Concepts
- **Composition:** Managing an array of custom `Question` objects.
- **File I/O:** Using `ifstream` and `getline` to parse multi-line data records.
- **ASCII Arithmetic:** Dynamically generating multiple-choice labels (A, B, C, D) using character offsets.

## Project Structure
- `QuizDriver.cpp`: Main controller and user interface.
- `Question.h` / `Question.cpp`: Logic for individual question state and behavior.
- `trivia.txt`: The data source containing the question bank.
