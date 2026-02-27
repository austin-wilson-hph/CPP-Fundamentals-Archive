# Movie Database Parser (Search & Sort)

A C++ application that demonstrates Object-Oriented Programming (OOP) principles by managing a database of movies. This project focuses on the implementation of classic searching and sorting algorithms to organize and retrieve structured data from external files.

## Technical Features
- **Object-Oriented Design:** Utilizes a custom `Movie` class with full encapsulation (private data members and public accessors/getters).
- **Data Persistence:** Implements robust File I/O to parse structured text data into an object array, handling stream buffers and newline characters.
- **Sorting Algorithms:** - **Insertion Sort (by ID):** Efficiently organizes records for optimized searching.
    - **Multi-Level Sort:** A complex sort that organizes data by Release Date, then by Rating as a secondary tie-breaker.
- **Search Algorithms:**
    - **Linear Search:** Used for non-indexed name lookups.
    - **Binary Search:** Achieves $O(\log n)$ efficiency for ID lookups by leveraging the pre-sorted state of the array.

## File Structure
- `Movie.h` / `Movie.cpp`: The class definition and implementation for the Movie object.
- `main.cpp`: The driver program containing the menu system and algorithm implementations.
- `movies.txt`: Sample input file containing movie IDs, titles, release dates, and ratings.

## Performance Analysis
By implementing **Binary Search**, this program demonstrates an understanding of time complexity. While a Linear Search would take $O(n)$ time, the Binary Search reduces the search space by half each iteration, making it significantly faster for larger datasets.



## How to Build
1. Compile all source files together:
   ```bash
   g++ main.cpp Movie.cpp -o MovieManager
