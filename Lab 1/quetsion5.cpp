#include <iostream>

using namespace std;

bool searchTargetInMatrix(int matrix[][100], int numRows, int numCols, int target) {
    int leftIndex = 0;
    int rightIndex = numRows * numCols - 1;

    while (leftIndex <= rightIndex) {
        int midIndex = leftIndex + (rightIndex - leftIndex) / 2;
        int midValue = matrix[midIndex / numCols][midIndex % numCols];

        if (midValue == target) {
            return true;
        } else if (midValue < target) {
            leftIndex = midIndex + 1;
        } else {
            rightIndex = midIndex - 1;
        }
    }

    return false;
}

int main() {
    int numRows, numCols, targetValue;
    
    cout << "Enter the number of rows: ";
    cin >> numRows;
    
    cout << "Enter the number of columns: ";
    cin >> numCols;
    
    int matrix[100][100]; // Assuming maximum size 100x100 as per constraints

    cout << "Enter the elements of the matrix row-wise:" << endl;
    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {
            cin >> matrix[row][col];
        }
    }

    cout << "Enter the target value: ";
    cin >> targetValue;

    bool isFound = searchTargetInMatrix(matrix, numRows, numCols, targetValue);

    if (isFound) {
        cout << "Output: true" << endl;
    } else {
        cout << "Output: false" << endl;
    }

    return 0;
}
