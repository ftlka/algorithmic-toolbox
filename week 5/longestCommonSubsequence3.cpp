/*
	Computes the length of longest common subsequence
	of three sequences
*/

#include <iostream>
#include <vector>

using namespace std;

int lcs3(vector<int>& a, vector<int>& b, vector<int>& c) {
	int columns = a.size() + 1;
	int rows = b.size() + 1;
	int depth = c.size() + 1;
	vector<vector<vector<int>>> table(columns, vector<vector<int>> (rows, vector<int>(depth, 0)));

	for (int i = 1; i < columns; i++) {
		for (int j = 1; j < rows; j++) {
			for (int k = 1; k < depth; k++) {
				if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1]) {
					table[i][j][k] = table[i-1][j-1][k-1] + 1;
				} else {
					table[i][j][k] = max(
						max(table[i][j-1][k], table[i-1][j][k]),
						table[i][j][k-1]);
				}
			}
		}
	}

	return table[columns - 1][rows - 1][depth-1];
}

int main() {
	int an;
	cin >> an;
	vector<int> a(an);
	for (int i = 0; i < an; i++) {
		cin >> a[i];
	}

	int bn;
	cin >> bn;
	vector<int> b(bn);
	for (int i = 0; i < bn; i++) {
		cin >> b[i];
	}

	int cn;
	cin >> cn;
	vector<int> c(cn);
	for (int i = 0; i < cn; i++) {
		cin >> c[i];
	}

	cout << lcs3(a, b, c) << endl;
	return 0;
}
