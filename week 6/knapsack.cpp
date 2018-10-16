/*
    You are given a set of bars of gold and your goal is to
    take as much gold as possible into your bag.
    There is just one copy of each bar and for each bar you
    can either take it or not (hence you cannot take a
    fraction of a bar).
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printTable(const vector<vector<int>>& a, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}

int optimalWeight(int w, const vector<int>& items) {
    int columns = w + 1;
    int rows = items.size() + 1;
    vector<vector<int>> table(rows, vector<int> (columns, 0));
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < columns; j++) {
            if (items[i-1] <= j) {
                table[i][j] = max(table[i-1][j], table[i-1][j-items[i-1]]+items[i-1]);
            } else {
                table[i][j] = table[i-1][j];
            }
        }
    }
    // printTable(table, rows, columns);
    return table[rows-1][columns-1];
}

int main() {
    int n, w;
    cin >> w >> n;
    vector<int> items(n);
    for (int i = 0; i < n; i++) {
        cin >> items[i];
    }
    cout << optimalWeight(w, items) << endl;
    return 0;
}
