/*
	You are given a primitive calculator that can perform
	the following three operations with the current number x:
	multiply x by 2, multiply x by 3, or add 1 to x.
	Your goal is given a positive integer n, find the minimum
	number of operations needed to obtain the number n starting
	from the number 1.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> optimalSequence(int n) {
	vector<vector<int>> memo = {{}, {1}};
	for (int current = 2; current <= n; current++) {
		vector<int> currentVector = memo[current - 1];

		if (current % 2 == 0 && memo[current / 2].size() < currentVector.size()) {
			currentVector = memo[current / 2];
		}

		if (current % 3 == 0 && memo[current / 3].size() < currentVector.size()) {
			currentVector = memo[current / 3];
		}

		currentVector.push_back(current);
		memo.push_back(currentVector);
	}

	return memo[n];
}

int main() {
	int n;
	cin >> n;
	vector<int> sequence = optimalSequence(n);
	cout << sequence.size() - 1 << endl;
	for (int i = 0; i < sequence.size(); i++) {
		cout << sequence[i] << " ";
	}
	cout << endl;
	return 0;
}
