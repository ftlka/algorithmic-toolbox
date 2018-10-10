/*
	least common multiple of two numbers
	js cannot comprehend multiplication of two big numbers, found no solution to fix it
*/
#include <iostream>

using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int c = a;
		a = b;
		b = c % b;
	}
	return a;
}

long long lcm_naive(int a, int b) {
	return (long long) a * b / gcd(a, b);
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << lcm_naive(a, b) << endl;
	return 0;
}
