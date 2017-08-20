#include <bits/stdc++.h>
using namespace std;

const int MAXS = 90 * 1024 * 1024;
const int modn = 998244353;
char buf[MAXS];

void fread_init() {
    int len = fread(buf, 1, MAXS, stdin);
    buf[len] = '\0';
}

int next_int() {
    static char* loc = buf;
    int res = 0;
    while (*loc < '0' || *loc > '9') {
        if (!(*loc)) {
            // over
            return -1;
        }
        loc++;
    }
    while (*loc >= '0' && *loc <= '9') {
        res = res * 10 + *loc - '0';
        loc++;
    }
    return res;
}

int main() {
    int ans = 0, t;
    fread_init();
    while ((t = next_int()) >= 0)
        ans = (ans + t) % modn;
    printf("%d\n", ans);
    return 0;
}