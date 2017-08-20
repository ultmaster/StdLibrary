// Find one solution to a*x + b*y == gcd(a,b)
long long exGcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long r = exGcd(b, a % b, x, y);
    long long t = x;
    x = y;
    y = t - a / b * y;
    return r;
}
