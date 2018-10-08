/*
	Represent a given positive integer n as a sum of as many
	pairwise distinct positive integers as possible
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> optimalSummands(int n) {
	vector<int> summands;
	int current = 1;
	int sum = n;

	while (sum - current > current) {
		summands.push_back(current);
		sum -= current;
		current++;
	}

	if (sum > 0) {
		summands.push_back(sum);
	}

	return summands;
}

int main() {
	int n;
  	cin >> n;

  	vector<int> summands = optimalSummands(n);
  	cout << summands.size() << endl;
  	for (size_t i = 0; i < summands.size(); i++) {
  		cout << summands[i] << ' ';
  	}
  	cout << endl;
    return 0;
}
