/*
    Calculates minimum amount of coins needed
    to change the input value into coins
*/

#include <iostream>
#include <vector>

using namespace std;

int getChange(int m) {
	vector<int> coinValues = {1, 5, 10};
	int n = 0;

	for (int i = coinValues.size() - 1; i >= 0; i--) {
		int currentCoins = m / coinValues[i];
		m -= currentCoins * coinValues[i];
		n += currentCoins;
	}

	return n;
}

int main() {
  int m;
  cin >> m;
  cout << getChange(m) << endl;
}
