#include <bits/stdc++.h>
using namespace std;

bool checkRows(int arr[][9]) {
    for (int i = 0; i < 9; i++) {
        set<int> st;
        for (int j = 0; j < 9; j++) {
            if (arr[i][j] != 0) {
                if (st.find(arr[i][j]) != st.end()) {
                    return false;
                }
                st.insert(arr[i][j]);
            }
        }
    }
    return true;
}

bool checkColumns(int arr[][9]) {
    for (int j = 0; j < 9; j++) {
        set<int> st;
        for (int i = 0; i < 9; i++) {
            if (arr[i][j] != 0) {
                if (st.find(arr[i][j]) != st.end()) {
                    return false;
                }
                st.insert(arr[i][j]);
            }
        }
    }
    return true;
}

bool validBox(int arr[][9], int rowstart, int rowend, int colstart, int colend) {
    set<int> st;
    for (int i = rowstart; i <= rowend; i++) {
        for (int j = colstart; j <= colend; j++) {
            if (arr[i][j] != 0) {
                if (st.find(arr[i][j]) != st.end()) {
                    return false;
                }
                st.insert(arr[i][j]);
            }
        }
    }
    return true;
}

bool checkBoxes(int arr[][9]) {
    for (int rowstart = 0; rowstart < 9; rowstart += 3) {
        for (int colstart = 0; colstart < 9; colstart += 3) {
            if (!validBox(arr, rowstart, rowstart + 2, colstart, colstart + 2)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int arr[9][9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> arr[i][j];
        }
    }

    bool rowsValid = checkRows(arr);
    bool columnsValid = checkColumns(arr);
    bool boxesValid = checkBoxes(arr);

    if (rowsValid && columnsValid && boxesValid) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}
