/*
    Adds parentheses to a given arithmetic expression
    to maximize its value.
*/

#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <sstream>
#include <cstdint>
#include <climits>

using namespace std;

vector<char> split(const string& s) {
    char buf;
    stringstream ss(s);
    vector<char> tokens;

    while (ss >> buf) {
        tokens.push_back(buf);
    }

    return tokens;
}

long long eval(long long a, char op, long long b) {
    if (op == '*') {
        return a * b;
    } else if (op == '+') {
        return a + b;
    } else if (op == '-') {
        return a - b;
    } else {
        assert(0);
    }
}

vector<long long> minMax(const vector<vector<long long>>& mins,
    const vector<vector<long long>>& maxs, int i, int j,
    const vector<char>& ops) {
    long long minE = LLONG_MAX;
    long long maxE = LLONG_MIN;
    for (int k = i; k < j; k++) {
        long long a = eval(maxs[i][k], ops[k], maxs[k+1][j]);
        long long b = eval(maxs[i][k], ops[k], mins[k+1][j]);
        long long c = eval(mins[i][k], ops[k], maxs[k+1][j]);
        long long d = eval(mins[i][k], ops[k], mins[k+1][j]);
        minE = min(min(min(a,b),min(c,d)),minE);
        maxE = max(max(max(a,b),max(c,d)),maxE);
    }
    return {minE,maxE};
}

long long getMaxVal(const string& exp) {
    vector<char> tokens = split(exp);
    vector<long long> nums;
    vector<char> operations;
    for (int i = 0; i < tokens.size(); i+=2) {
        nums.push_back((long long)tokens[i] - 48);
        operations.push_back(tokens[i+1]);
    }

    int tSize = nums.size();
    vector<vector<long long>> mins(tSize, vector<long long> (tSize));
    vector<vector<long long>> maxs(tSize, vector<long long> (tSize));
    for (int i = 0; i < tSize; i++) {
        mins[i][i] = nums[i];
        maxs[i][i] = nums[i];
    }
    for (int s = 2; s <= tSize; s++) {
        for (int i = 0; i < tSize - s + 1; i++) {
            int j = i + s - 1;
            vector<long long> minAndMax = minMax(mins, maxs, i, j, operations);
            mins[i][j] = minAndMax[0];
            maxs[i][j] = minAndMax[1];
        }
    }

    return maxs[0][tSize - 1];
}

int main() {
    string s;
    cin >> s;
    cout << getMaxVal(s) << endl;
    return 0;
}
