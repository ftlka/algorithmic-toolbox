/*
    Calculates last digit of fibonacci numbers sum
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

int fibLastSumDigit(long long n) {
    int remainder = n % getPisanoPeriod(10);

    if (remainder == 0) {
        return remainder;
    }

    int first = 0;
    int second = 1;
    int sum = 1;

    int res = remainder;

    for (int i = 1; i < remainder; i++) {
        res = (first + second) % 10;
        sum += res;
        first = second;
        second = res;
    }

    return sum % 10;
}

int main() {
    long long n;
    std::cin >> n;
    std::cout << fibLastSumDigit(n) << std::endl;
    return 0;
}
