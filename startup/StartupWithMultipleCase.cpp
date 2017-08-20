#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#ifdef ULTMASTER
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#define cerr if(0) cerr
#endif

const int N = 1e5 + 10;

int T;
int n;
int a[N];

int main() {
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        printf("Case #%d: ", cas);
    }
}
