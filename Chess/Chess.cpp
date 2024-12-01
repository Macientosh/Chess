#include <iostream>
#include <vector>
using namespace std;

// Функция для проверки, можно ли поставить ферзя в клетку (row, col)
bool isSafe(const vector<int>& board, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col ||                         // Проверка по столбцу
            board[i] - i == col - row ||               // Проверка по диагонали "/"
            board[i] + i == col + row) {               // Проверка по диагонали "\\"
            return false;
        }
    }
    return true;
}

// Рекурсивная функция для решения задачи N-ферзей
bool solveNQueens(vector<int>& board, int row, int N) {
    if (row == N) return true; // Все ферзи расставлены

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col; // Поставить ферзя
            if (solveNQueens(board, row + 1, N)) {
                return true;
            }
            // Откат, если решение не найдено
            board[row] = -1;
        }
    }
    return false;
}

// Функция для вывода доски
void printBoard(const vector<int>& board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i] == j) {
                cout << "Q ";
            }
            else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int N;
    cout << "Enter the size of the chessboard (N > 3): ";
    cin >> N;

    if (N <= 3) {
        cout << "The value of N must be greater than 3." << endl;
        return 1;
    }

    vector<int> board(N, -1); // Инициализация доски

    if (solveNQueens(board, 0, N)) {
        cout << "Solution for " << N << "-Queens problem:" << endl;
        printBoard(board, N);
    }
    else {
        cout << "No solution exists for " << N << "-Queens problem." << endl;
    }

    return 0;
}
