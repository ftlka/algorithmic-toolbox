/*
	Computes the edit distance between two strings
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void printTable(vector<vector<int>>& a, int rows, int columns) {
	for (int i = 0; i < columns; i++) {
		for (int j = 0; j < rows; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
}

int editDistance(const string& str1, const string& str2) {
	// if characters are different we take min of 3(up, left and up-left)
	// and add 1 otherwise we just grab diagonal
	int columns = str1.size() + 1;
	int rows = str2.size() + 1;
	vector<vector<int>> table(columns, vector<int> (rows, 0));
	for (int i = 0; i < columns; i++) {
		table[i][0] = i;
	}
	for (int i = 0; i < rows; i++) {
		table[0][i] = i;
	}
	for (int i = 1; i < columns; i++) {
		for (int j = 1; j < rows; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				table[i][j] = table[i-1][j-1];
			} else {
				table[i][j] = min(table[i-1][j-1], table[i-1][j]);
				table[i][j] = min(table[i][j], table[i][j-1]) + 1;
			}
		}
	}
	// printTable(table, rows, columns);

	return table[columns - 1][rows - 1];
}

int main() {
	string str1, str2;
	cin >> str1 >> str2;
	cout << editDistance(str1, str2) << endl;
  	return 0;
}
