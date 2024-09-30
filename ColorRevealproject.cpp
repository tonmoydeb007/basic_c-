#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int GRID_SIZE = 4;  // 4x4 grid
const int NUM_COLORS = 4; // Number of unique colors

// Function to initialize the grid with random colors
void initializeGrid(int grid[GRID_SIZE][GRID_SIZE]) {
    srand(time(0));
    for(int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = rand() % NUM_COLORS + 1; // Random color from 1 to NUM_COLORS
        }
    }
}

// Function to display the grid
void displayGrid(int grid[GRID_SIZE][GRID_SIZE], bool revealed[GRID_SIZE][GRID_SIZE]) {
    cout << "\nGrid:\n";
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (revealed[i][j]) {
                cout << grid[i][j] << " ";  // Show the color if revealed
            } else {
                cout << "* ";  // Hide the color
            }
        }
        cout << endl;
    }
}

// Function to check if all colors are revealed
bool checkWin(bool revealed[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (!revealed[i][j]) {
                return false;  // If any square is still hidden, player hasn't won
            }
        }
    }
    return true;
}

int main() {
    int grid[GRID_SIZE][GRID_SIZE];
    bool revealed[GRID_SIZE][GRID_SIZE] = {false}; // Keeps track of revealed squares
    initializeGrid(grid);

    int turns = 0;  // Count the number of turns

    cout << "Welcome to the Colored Squares Game!" << endl;
    cout << "Reveal all the squares to win." << endl;

    while (true) {
        displayGrid(grid, revealed);

        // Ask the player for input
        int row, col;
        cout << "Enter row and column to reveal (0-" << GRID_SIZE-1 << "): ";
        cin >> row >> col;

        // Validate input
        if (row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE) {
            cout << "Invalid input! Try again." << endl;
            continue;
        }

        // Reveal the selected square
        if (!revealed[row][col]) {
            revealed[row][col] = true;
            turns++;
        } else {
            cout << "Square already revealed! Try a different one." << endl;
        }

        // Check if player has won
        if (checkWin(revealed)) {
            cout << "Congratulations! You've revealed all the squares in " << turns << " turns." << endl;
            displayGrid(grid, revealed);
            break;
        }
    }

    return 0;
}