#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
char s[maxn], t[maxn];
int ans;
const int modn = 1e9 + 7;

struct SuffixAutomation {
    int last, tot, step[maxn], pre[maxn], go[maxn][52], danger[maxn];

    int new_node(int s) {
        step[++tot] = s;
        pre[tot] = 0;
        memset(go[tot], 0, sizeof go[tot]);
        return tot;
    }

    void init() {
        memset(step, 0, sizeof step);
        memset(pre, 0, sizeof pre);
        memset(go, 0, sizeof go);
        memset(danger, 0, sizeof danger);
        tot = 0;
        last = new_node(0);
    }

    inline int idx(char c) {
        return isupper(c) ? (c - 'a' + 26) : (c - 'A');
    }

    int insert(char ch) {
        int c = idx(ch), p = last, cur = new_node(step[last] + 1);
        while (p && !go[p][c])
            go[p][c] = cur, p = pre[p];
        if (!p) pre[cur] = 1;
        else {
            int q = go[p][c];
            if (step[q] == step[p] + 1)pre[cur] = q;
            else {
                int nq = new_node(step[p] + 1);
                memcpy(go[nq], go[q], sizeof(go[q]));
                pre[nq] = pre[q];
                pre[cur] = pre[q] = nq;
                while (p && go[p][c] == q)
                    go[p][c] = nq, p = pre[p];
            }
        }
        last = cur;
        return last;
    }

    void solve(char *s, int Last) {
        int n = strlen(s), len = 0, u = 1;
        for (int i = 0; i < n; ++i) {
            int c = idx(s[i]);
            if (!go[u][c]) {
                while (u && !go[u][c])
                    u = pre[u];
                if (!u) u = 1, len = 0;
                else len = step[u] + 1, u = go[u][c];
            } else {
                len = len + 1;
                u = go[u][c];
            }
            if (danger[u]) {
                // printf("%d %d\n", len, ans);
                ans = (ans + 1LL * (len + 1) * len / 2) % modn;
                // printf("%d %d %d\n", len ,(len + 1) * len / 2, ans);
            }
            // printf("%d %d %d %d\n", len, u, danger[u], Last);
        }
    }
} sam;