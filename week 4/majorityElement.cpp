/*
    Outputs 1 if the sequence contains an element that appears
    more than n/2 times, and 0 otherwise.
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int getMajorityElem(vector<int>& a) {
    int majority = a.size() / 2 + 1;
    sort(a.begin(), a.end());

    int prev = a[0], amount = 1;
    for (int i = 1; i < a.size(); i++) {
    	if (a[i] == prev) {
    		amount++;
    		if (amount == majority) {
    			return 1;
    		}
    	} else {
    		prev = a[i];
    		amount = 1;
    	}
    }

    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < a.size(); i++) {
        cin >> a[i];
    }
    cout << (getMajorityElem(a) != -1);
    cout << endl;
}
