/*
    Calculates n-th Fibonacci Number mod second argument and prints it
    js fails on 99999999999999999 % 3 - returns 1 instead of 0
*/
#include <iostream>

int getPisanoPeriod(long long m) {
    int a = 0;
    int b = 1;
    int c = a + b;
    for (int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        // it means that the next iteration started and we need to stop
        if (a == 0 && b == 1) {
            return i + 1;
        }
    }
}

int fibAgain(long long n, long long m) {
    // to solve this we need to calculate pisano period's length
    int remainder = n % getPisanoPeriod(m);

    int first = 0;
    int second = 1;

    int res = remainder;

    for (int i = 1; i < remainder; i++) {
        res = (first + second) % m;
        first = second;
        second = res;
    }

    return res;
}

int main() {
  long long n, m;
  std::cin >> n >> m;
  std::cout << fibAgain(n, m) << std::endl;
  return 0;
}
