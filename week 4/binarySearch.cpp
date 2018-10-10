/*
    Binary search implementation for finding m indexes of elements
    in a given sorted array of length n
*/

#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int>& a, int x) {
	int left = 0, right = a.size() - 1, mid;
	while (left <= right) {
		mid =  (right + left) / 2;
		if (a[mid] == x) {
			return mid;
		} else if (a[mid] > x) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return -1;
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

	for (int i = 0; i < m; i++) {
		cout << binarySearch(a, b[i]) << ' ';
	}
	cout << endl;
	return 0;
}
