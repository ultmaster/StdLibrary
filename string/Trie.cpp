const int sigma_size = 26;
const int maxnode = 5000000;

int idx(char c) {
    return c - 'a';
}

struct Trie {
    int ch[maxnode][sigma_size];
    int val[maxnode];
    int sz;

    void init() {
        sz = 1;
        memset(ch[0], 0, sizeof ch[0]);
    }

    void insert(char* s, int v) {
        int u = 0, n = strlen(s);
        for (int i = 0; i < n; ++i) {
            int c = idx(s[i]);
            if (!ch[u][c]) {
                memset(ch[sz], 0, sizeof ch[sz]);
                val[sz] = 0;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
        val[u] = v;
    }
} trie;