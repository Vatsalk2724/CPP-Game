#include <iostream>
#include <string>
using namespace std;

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row, column;
char token = 'x';
bool tie = false;
string n1, n2;

void functionOne() {
    cout << "   |     |     \n";
    cout << " " << space[0][0] << " |  " << space[0][1] << "  |  " << space[0][2] << " \n";
    cout << "___|_____|___\n";
    cout << "   |     |     \n";
    cout << " " << space[1][0] << " |  " << space[1][1] << "  |  " << space[1][2] << " \n";
    cout << "___|_____|___\n";
    cout << "   |     |     \n";
    cout << " " << space[2][0] << " |  " << space[2][1] << "  |  " << space[2][2] << " \n";
    cout << "   |     |     \n";
}

void functionTwo() {
    int digit;

    if (token == 'x') {
        cout << n1 << ", please enter a number: ";
        cin >> digit;
    } else {
        cout << n2 << ", please enter a number: ";
        cin >> digit;
    }

    if (digit == 1) {
        row = 0, column = 0;
    } else if (digit == 2) {
        row = 0, column = 1;
    } else if (digit == 3) {
        row = 0, column = 2;
    } else if (digit == 4) {
        row = 1, column = 0;
    } else if (digit == 5) {
        row = 1, column = 1;
    } else if (digit == 6) {
        row = 1, column = 2;
    } else if (digit == 7) {
        row = 2, column = 0;
    } else if (digit == 8) {
        row = 2, column = 1;
    } else if (digit == 9) {
        row = 2, column = 2;
    } else {
        cout << "Invalid input! Please try again.\n";
        functionTwo();
        return;
    }

    if (space[row][column] != 'x' && space[row][column] != '0') {
        space[row][column] = token;
        token = (token == 'x') ? '0' : 'x';
    } else {
        cout << "The cell is already filled! Please choose another.\n";
        functionTwo();
    }

    functionOne();
}

bool functionThree() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((space[i][0] == space[i][1] && space[i][0] == space[i][2]) || 
            (space[0][i] == space[1][i] && space[0][i] == space[2][i])) {
            return true;
        }
    }

    // Check diagonals
    if ((space[0][0] == space[1][1] && space[1][1] == space[2][2]) || 
        (space[0][2] == space[1][1] && space[1][1] == space[2][0])) {
        return true;
    }

    // Check for tie
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (space[i][j] != 'x' && space[i][j] != '0') {
                return false;
            }
        }
    }
    tie = true;
    return false;
}

int main() {
    cout << "Enter the name of the first player: ";
    getline(cin, n1);
    cout << "Enter the name of the second player: ";
    getline(cin, n2);

    cout << n1 << " will play as 'x'.\n";
    cout << n2 << " will play as '0'.\n";

    while (!functionThree()) {
        functionOne();
        functionTwo();
    }

    if (tie) {
        cout << "It's a draw!\n";
    } else if (token == '0') {
        cout << n1 << " wins!\n";
    } else {
        cout << n2 << " wins!\n";
    }

    return 0;
}
