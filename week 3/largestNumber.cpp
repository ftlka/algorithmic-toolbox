/*
	Compose the largest number out of a set of integers
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

string largest_number(vector<string> a) {
	stringstream ret;
	for (size_t i = 0; i < a.size(); i++) {
		ret << a[i];
	}
	string result;
	ret >> result;
	return result;
}

bool cmp(string a, string b) {
	return a + b > b + a;
}

int main() {
	int n;
	cin >> n;
	vector<string> a(n);

	for (size_t i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end(), cmp);

	cout << largest_number(a) << endl;
}