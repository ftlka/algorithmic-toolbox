/*
    Maximize sum of products of two sequences
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long maProduct(vector<int> a, vector<int> b) {
    long long result = 0;

    for (size_t i = 0; i < a.size(); i++) {
        result += ((long long) a[i]) * b[i];
    }

    return result;
}


bool cmp(int a, int b) { 
    return a > b; 
}

int main() {
    size_t n;
    cin >> n;
    vector<int> a(n), b(n);
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (size_t i = 0; i < n; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end(), cmp);
    sort(b.begin(), b.end(), cmp);

    cout << maProduct(a, b) << endl;
    return 0;
}
