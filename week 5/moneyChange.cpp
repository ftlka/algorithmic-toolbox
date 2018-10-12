/*
	Returns minimum amount of coins with values 1, 3 and 4
	to change given sum.
*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

int getChangeRecursive(int m, int idx, map<string, int>& memo) {
	if (m == 0) {
		return 0;
	}
	vector<int> coins = {1, 3, 4};
	int minAmount = INT_MAX;

	for (int i = idx; i < coins.size(); i++) {
		if (m >= coins[i]) {
			string cur = to_string(m - coins[i]) + "-" + to_string(i);
			int current;

			if (memo[cur]) {
				current = memo[cur];
			} else {
				current = getChangeRecursive(m - coins[i], i, memo);
				memo[cur] = current;
			}

			if (current != INT_MAX && current + 1 < minAmount) {
				minAmount = current + 1;
			}
		}
	}
	return minAmount;
}

int getChange(int m) {
	map<string, int> coins;
	return getChangeRecursive(m, 0, coins);
}

int main() {
	int m;
	cin >> m;
	cout << getChange(m) << endl;
	return 0;
}
