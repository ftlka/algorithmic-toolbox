/*
	Computes the length of longest common subsequence
	of two sequences
*/

#include <iostream>
#include <vector>

using namespace std;

void printTable(vector<vector<int>>& a, int rows, int columns) {
	for (int i = 0; i < columns; i++) {
		for (int j = 0; j < rows; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
}

int lcs2(vector<int>& a , vector<int>& b) {
	int columns = a.size() + 1;
	int rows = b.size() + 1;
	vector<vector<int>> table(columns, vector<int> (rows, 0));

	for (int i = 1; i < columns; i++) {
		for (int j = 1; j < rows; j++) {
			if (a[i - 1] == b[j - 1]) {
				table[i][j] = table[i-1][j-1] + 1;
			} else {
				table[i][j] = max(table[i][j-1], table[i-1][j]);
			}
		}
	}
	// printTable(table, rows, columns);

	return table[columns - 1][rows - 1];
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

  	int m;
  	cin >> m;
  	vector<int> b(m);
  	for (int i = 0; i < m; i++) {
    	cin >> b[i];
  	}

	cout << lcs2(a, b) << endl;
	return 0;
}
