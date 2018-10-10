/*
    Calculates number of inversions.
    The number of inversions of a sequence in some sense
    measures how close the sequence is to being sorted.

    For example, a sorted (in non-descending order) sequence
    contains no inversions at all, while in a sequence sorted in
    decending order any two elements constitute an inversion
    (for a total of n(n − 1)/2 inversions). 
*/

#include <iostream>
#include <vector>

using namespace std;

struct vecAndLong {
	vector<long long> vec;
	long long inversions;
};

vecAndLong merge(vector<long long>& b, vector<long long>& c) {
	vector<long long> d;
	// mid and i are for b.size() computation and length
	// of path we travel to place our element
	int mid = b.size();
	int i = 0;
	long long counter = 0;
	while (b.size() && c.size()) {
		// take and compare first elements from each sorted array
		int elem1 = b[0];
		int elem2 = c[0];
		// take min element, erase it from array and
		// add to resulting array
		if (elem1 <= elem2) {
			d.push_back(elem1);
			b.erase(b.begin());
			i++;
		} else {
			// increase counter because we moved c element
			// in front of b element
			counter += (mid - i);
			d.push_back(elem2);
			c.erase(c.begin());
		}
	}

	for (auto e : b) {
		d.push_back(e);
	}
	for (auto e : c) {
		d.push_back(e);
	}

	return {d, counter};
}

vecAndLong mergeSort(vector<long long>& a) {
	long long inversions = 0;
	if (a.size() == 1) {
		return {a, inversions};
	}
	int mid = a.size() / 2;
	vector<long long> b(a.begin(), a.begin() + mid);
	vecAndLong bStruct = mergeSort(b);
	b = bStruct.vec;
	inversions += bStruct.inversions;

	vector<long long> c(a.begin() + mid, a.end());
	vecAndLong cStruct = mergeSort(c);
	c = cStruct.vec;
	inversions += cStruct.inversions;

	vecAndLong finalStruct = merge(b, c);
	inversions += finalStruct.inversions;
	return {finalStruct.vec, inversions};
}

int main() {
  	int n;
  	cin >> n;
  	vector<long long> a(n);
  	for (int i = 0; i < a.size(); i++) {
    	cin >> a[i];
  	}
  	vecAndLong res = mergeSort(a);

  	cout << res.inversions;
  	cout << endl;
  	return 0;
}
