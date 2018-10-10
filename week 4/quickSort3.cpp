/*
    Quick sort with 3 partitions. Works faster than original
    with arrays filled with lots of same elements.
    Can be seen here https://www.toptal.com/developers/sorting-algorithms
    in column Quick3 and row Few Unique 
*/

#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>& a, int idx1, int idx2) {
	int temp = a[idx1];
	a[idx1] = a[idx2];
	a[idx2] = temp;
}

vector<int> partition3(vector<int>& a, int l, int r) {
	int x = a[l];
	int j = l;
	int sameNumbers = 0;
	for (int i = l + 1; i <= r; i++) {
		if (a[i] < x) {
      		j++;
      		swap(a, i, j);
    	}
  	}
  	swap(a, l, j);

  	for (int i = j + 1; i <= r; i++) {
		if (a[i] == x) {
      		sameNumbers++;
      		swap(a, i, j + sameNumbers);
    	}
  	}

  	return {j, j + sameNumbers};
}

void quickSort(vector<int>& a, int l, int r) {
	if (l >= r) {
		return;
	}

  	int k = l + rand() % (r - l + 1);
  	swap(a, l, k);
  	vector<int> ms = partition3(a, l, r);

  	quickSort(a, l, ms[0] - 1);
  	quickSort(a, ms[1] + 1, r);
}

int main() {
  	int n;
  	cin >> n;
  	vector<int> a(n);
  	for (size_t i = 0; i < a.size(); i++) {
    	cin >> a[i];
  	}

  	quickSort(a, 0, a.size() - 1);
  	for (int i = 0; i < a.size(); i++) {
    	cout << a[i] << ' ';
  	}
  	cout << endl;
  	return 0;
}
