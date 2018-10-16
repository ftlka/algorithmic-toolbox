/*
	You and two of your friends have just returned back home
	after visiting various countries. Now you would like to
	evenly split all the souvenirs that all three of you bought.
*/

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

bool recursionF(const vector<int>& s, int n, int a, int b, int c, map<string, int>& memo) {
	if (a == 0 && b == 0 && c == 0) {
		return true;
	}
	if (n < 0) {
		return false;
	}

	bool item = false;
	string key = to_string(n) + "-" + to_string(a) + "-" + to_string(b) + "-" + to_string(c);
	if (memo.count(key) > 0) {
		return memo[key];
	}
	if (a - s[n] >= 0) {
		item = recursionF(s, n - 1, a - s[n], b, c, memo);
		memo[key] = item;

		if (item) {
			return true;
		}
	}

	if (b - s[n] >= 0) {
		item = recursionF(s, n - 1, a, b - s[n], c, memo);
		memo[key] = item;

		if (item) {
			return true;
		}
	}

	if (c - s[n] >= 0) {
		item = recursionF(s, n - 1, a, b, c - s[n], memo);
		memo[key] = item;

		if (item) {
			return true;
		}
	}
	memo[key] = false;

	return false;
}

bool partition3(const vector<int>& souvenirs) {
	int sum = 0;
	for (auto e : souvenirs) {
		sum += e;
	}
	if (souvenirs.size() < 3 || sum % 3 != 0) {
		return false;
	}
	int partSum = sum / 3;
	map<string, int> memo;
	return recursionF(souvenirs, souvenirs.size() - 1, partSum, partSum, partSum, memo);
}

int main() {
	int n;
	cin >> n;
	vector<int> souvenirs(n);
	for (int i = 0; i < n; i++) {
		cin >> souvenirs[i];
	}
	cout << partition3(souvenirs) << endl;
	return 0;
}
