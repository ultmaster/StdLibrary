#include <bits/stdc++.h>

using namespace std;

template<int MOD>
struct ModInt {
    static const int Mod = MOD;
    unsigned x;

    ModInt() : x(0) {}

    ModInt(signed sig) {
        int sigt = sig % MOD;
        if (sigt < 0) sigt += MOD;
        x = sigt;
    }

    ModInt(signed long long sig) {
        int sigt = sig % MOD;
        if (sigt < 0) sigt += MOD;
        x = sigt;
    }

    int get() const { return (int) x; }

    ModInt &operator+=(ModInt that) {
        if ((x += that.x) >= MOD) x -= MOD;
        return *this;
    }

    ModInt &operator-=(ModInt that) {
        if ((x += MOD - that.x) >= MOD) x -= MOD;
        return *this;
    }

    ModInt &operator*=(ModInt that) {
        x = (unsigned long long) x * that.x % MOD;
        return *this;
    }

    ModInt &operator/=(ModInt that) {
        (*this) *= (that ^ (MOD - 2));
        return *this;
    }

    ModInt operator^(int n) const {
        ModInt r = ModInt(1);
        ModInt a = ModInt(*this);
        while (n) {
            if (n & 1) r *= a;
            n >>= 1;
            a *= a;
        }
        return r;
    }

    ModInt operator+(ModInt that) const { return ModInt(*this) += that; }

    ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }

    ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }

    ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
};

typedef ModInt<1000000007> mint;

int main() {
    mint m(2);
    for (int i = 2; i <= 100; ++i)
        printf("%d\n", ((m ^ i) / (m ^ (i - 2))).get());
}