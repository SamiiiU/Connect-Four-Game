Matching Game in C++

Overview
This project implements a simple console-based board game called the "Matching game" in C++. The game is played between two players (X and 0) on a 6x7 grid where they take turns placing their respective symbols to achieve a sequence of four in a row (horizontal, vertical, or diagonal).

Features:
Board Representation:

The game board is represented using a 2D character array (arr[6][8]), where each cell initially contains a space to signify an empty position.
Game Mechanics:

Players alternately choose a column (from 0 to 6) where they want to place their symbol (X or 0).
If a column is full, the player is prompted to choose another column.
After each valid move, the updated board state is displayed.

Winning Conditions:

The game checks after each move if there is a winner by verifying if four consecutive symbols of the same player exist in a row (horizontal, vertical, or diagonal).
If a winning condition is met, the respective player is declared the winner.
If the board fills up without a winner, the game ends in a draw.
Restart Option:

After each game concludes (whether there is a winner or a draw), players are given the option to restart the game by entering "Yes" or "YES".
Implementation Details

Functions:

Print_Table(arr): Prints the current state of the board.
RowCheck(R, C): Checks for the next available row in a column where a player can place their symbol.
check_player(player): Alternates between players X and 0.
check_T(arr): Checks if the board is full.
winner_char(arr): Checks if there is a winner based on the current board state.


Game Loop:

The game runs in a do-while loop, allowing players to play multiple games consecutively until they choose not to restart.
The loop ensures that the game continues until a decision (win, draw, or exit) is reached after each game.
Usage


To play the game:

Compile the code using a C++ compiler (g++ -o matching_game matching_game.cpp).
Run the executable (./matching_game).
Follow the prompts to enter column numbers for your moves.
Enjoy playing until you decide to stop!

Conclusion
This project provides a basic yet functional implementation of a classic board game in C++, 
demonstrating fundamental concepts such as arrays, loops, functions, and conditional statements. 
Feel free to explore the code, modify it, and enhance it further based on your preferences.
