#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void readMatrix(int matrix[10][10], int& rows, int& cols) {
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[10][10], int rows, int cols) {
    int transposed[10][10];
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
    
    cout << "\nTransposed Matrix:" << endl;
    displayMatrix(transposed, cols, rows);
}

void addMatrices(int matrixA[10][10], int matrixB[10][10], int rows, int cols) {
    int result[10][10];
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    
    cout << "\nMatrix Sum:" << endl;
    displayMatrix(result, rows, cols);
}

void multiplyMatrices(int matrixA[10][10], int matrixB[10][10], int rowsA, int colsA, int rowsB, int colsB) {
    if (colsA != rowsB) {
        cout << "Error: Number of columns in A must equal number of rows in B." << endl;
        return;
    }
    
    int result[10][10];
    
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    
    cout << "\nMatrix Product (A x B):" << endl;
    displayMatrix(result, rowsA, colsB);
}

int main() {
    int matrixA[10][10], matrixB[10][10];
    int rowsA, colsA, rowsB, colsB;
    int choice;
    
    do {
        cout << "\n========================================" << endl;
        cout << "       MATRIX OPERATIONS MENU" << endl;
        cout << "========================================" << endl;
        cout << "1. Transpose a Matrix" << endl;
        cout << "2. Add Two Matrices" << endl;
        cout << "3. Multiply Two Matrices" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "\n--- TRANSPOSE MATRIX ---" << endl;
                readMatrix(matrixA, rowsA, colsA);
                transposeMatrix(matrixA, rowsA, colsA);
                break;
            
            case 2:
                cout << "\n--- ADD TWO MATRICES ---" << endl;
                cout << "\nEnter Matrix A:" << endl;
                readMatrix(matrixA, rowsA, colsA);
                cout << "\nEnter Matrix B (same dimensions):" << endl;
                readMatrix(matrixB, rowsB, colsB);
                
                if (rowsA == rowsB && colsA == colsB) {
                    addMatrices(matrixA, matrixB, rowsA, colsA);
                } else {
                    cout << "Error: Matrices must have the same dimensions." << endl;
                }
                break;
            
            case 3:
                cout << "\n--- MULTIPLY TWO MATRICES ---" << endl;
                cout << "\nEnter Matrix A:" << endl;
                readMatrix(matrixA, rowsA, colsA);
                cout << "\nEnter Matrix B:" << endl;
                readMatrix(matrixB, rowsB, colsB);
                multiplyMatrices(matrixA, matrixB, rowsA, colsA, rowsB, colsB);
                break;
            
            case 4:
                cout << "Goodbye!" << endl;
                break;
            
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
    
    return 0;
}