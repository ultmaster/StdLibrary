#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int MOD = 998244353;
const int CHAR_SIZE = 3;
const int MAX_SIZE = 1e2 + 8;

int mp(char ch) {
    switch (ch) {
        case 'E':
            return 0;
        case 'O':
            return 1;
        case 'J':
            return 2;
    }
    return -1;
}

inline int mod(int x) { return x - x / MOD * MOD; }

struct AC_Machine {
    int ch[MAX_SIZE][CHAR_SIZE], danger[MAX_SIZE], fail[MAX_SIZE];
    int sz;

    void init() {
        sz = 1;
        memset(ch[0], 0, sizeof ch[0]);
        memset(danger, 0, sizeof danger);
    }

    void _insert(const string &s, int m) {
        int n = s.size();
        int u = 0, c;
        for (int i = 0; i < n; i++) {
            c = mp(s[i]);
            if (!ch[u][c]) {
                memset(ch[sz], 0, sizeof ch[sz]);
                danger[sz] = 0;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
        danger[u] |= 1 << m;
    }

    void _build() {
        queue<int> Q;
        fail[0] = 0;
        for (int c = 0, u; c < CHAR_SIZE; c++) {
            u = ch[0][c];
            if (u) {
                Q.push(u);
                fail[u] = 0;
            }
        }
        int r;
        while (!Q.empty()) {
            r = Q.front();
            Q.pop();
            danger[r] |= danger[fail[r]];
            for (int c = 0, u; c < CHAR_SIZE; c++) {
                u = ch[r][c];
                if (!u) {
                    ch[r][c] = ch[fail[r]][c];
                    continue;
                }
                fail[u] = ch[fail[r]][c];
                Q.push(u);
            }
        }
    }
} ac;

string ss;
int dp[2][MAX_SIZE][1 << 10];
int ans[50];

int main() {
    int n, m, i, j, k, s, x, u;
    cin >> m >> n;
    ac.init();
    for (i = 0; i < m; i++) {
        cin >> ss;
        // cout << ss << endl;
        ac._insert(ss, i);
    }
    ac._build();

    memset(dp, 0, sizeof dp);
    dp[0][0][0] = 1;
    for (i = 0, x = 1; i < n; i++, x ^= 1) {
        memset(dp[x], 0, sizeof dp[x]);
        for (j = 0; j < ac.sz; j++) {
            for (s = 0; s < (1 << m); s++) {
                if (dp[x ^ 1][j][s] == 0)
                    continue;
                for (k = 0; k < CHAR_SIZE; k++) {
                    u = ac.ch[j][k];
                    dp[x][u][s | ac.danger[u]] =
                            mod(dp[x][u][s | ac.danger[u]] + dp[x ^ 1][j][s]);
                }
            }
        }
    }

    memset(ans, 0, sizeof ans);
    for (s = 0; s < (1 << m); s++) {
        int kk = __builtin_popcount(s);
        for (j = 0; j < ac.sz; j++)
            ans[kk] = mod(ans[kk] + dp[x ^ 1][j][s]);
    }
    int final = 0;
    for (i = 0; i <= m; ++i) {
        cout << ans[i] << endl;
        final = (final + 1LL * ans[i] * (i + 1) * (i + 1)) % MOD;
    }
    cout << final << endl;

    return 0;
}
