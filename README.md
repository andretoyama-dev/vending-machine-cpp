# Vending Machine Simulator (C++)

A console-based object-oriented vending machine simulator. This was **my very first college project**, developed during my first semester in university to learn foundational programming logic and C++ fundamentals.

## Project Background

This project represents the start of my academic computer science journey. It applies basic Object-Oriented Programming (OOP) concepts in C++, utilizing data structure constructs like `std::map` to store dynamic inventories, and handling standard input/output streams for interactive menus.

## Features

- **User Mode**: Browse inventory, select product IDs, input cash amounts, purchase items, and receive exact change.
- **Administrator Mode**: Password-protected dashboard to restock items, inspect product records, and check detailed revenue statistics (accumulated earnings vs. potential stock value).
- **Interactive Console Menu**: Easy-to-navigate loop interface with input validation.

## Tech Stack

- **Language**: C++11
- **Standard Libraries**: `<iostream>`, `<map>`, `<string>`

## Local Setup & Compiling Instructions

To compile and run this application locally, you will need a C++ compiler installed (such as `g++` or `clang++`).

### Compiling

Open a terminal in the project directory and run:

```bash
g++ -std=c++11 main.cpp -o vending_machine
```

### Running

Run the compiled executable:

- On macOS/Linux:
  ```bash
  ./vending_machine
  ```
- On Windows:
  ```bash
  vending_machine.exe
  ```

---
*Created in my first semester of university.*
