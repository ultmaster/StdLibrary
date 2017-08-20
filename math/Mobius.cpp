#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int modn = 1e9 + 7;
const int N = 1e5 + 10;
typedef pair<int, int> pii;
int mu[N], prime[N], vis[N], cnt;

void mobius() {
    memset(vis, 0, sizeof vis);
    mu[1] = 1;
    int cnt = 0;
    for (int i = 2; i < N; i++) {
        if (!vis[i]) {
            prime[cnt++] = i;
            mu[i] = -1;
        }
        for (int j = 0; j < cnt && i * prime[j] < N; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j])
                mu[i * prime[j]] = -mu[i];
            else {
                mu[i * prime[j]] = 0;
                break;
            }
        }
    }
}

int main() {
    mobius();
}
