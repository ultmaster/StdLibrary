int quick_pow(int a, int b) {
    if (b == 0) return 1;
    if (b == 1) return a % MOD;
    int res = quick_pow(a, b / 2);
    res = 1LL * res * res % MOD;
    if (b & 1) res = 1LL * res * a % MOD;
    return res;
}