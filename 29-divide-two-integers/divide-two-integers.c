int divide(int dividend, int divisor) {

    if (dividend == -2147483648 && divisor == -1)
        return 2147483647;

    long long a = dividend;
    long long b = divisor;

    int negative = (a < 0) ^ (b < 0);

    if (a < 0)
        a = -a;

    if (b < 0)
        b = -b;

    long long quotient = 0;

    while (a >= b) {
        long long temp = b;
        long long multiple = 1;

        while (temp <= a - temp) {
            temp += temp;
            multiple += multiple;
        }

        a -= temp;
        quotient += multiple;
    }

    if (negative)
        quotient = -quotient;

    return (int)quotient;
}