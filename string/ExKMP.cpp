// extend[i]表示T与S[i,n-1]的最长公共前缀，要求出所有extend[i](0<=i<n)
const int maxn = 100010;   
int next[maxn], ex[maxn];  

void get_next(char *str) {
    int i = 0, j, po, len = strlen(str);
    next[0] = len;  
    while (str[i] == str[i + 1] && i + 1 < len)  
        i++;
    next[1] = i;
    po = 1;  
    for (i = 2; i < len; i++) {
        if (next[i - po] + i < next[po] + po)  
            next[i] = next[i - po];
        else  
        {
            j = next[po] + po - i;
            if (j < 0) j = 0;
            while (i + j < len && str[j] == str[j + i])  
                j++;
            next[i] = j;
            po = i;  
        }
    }
}


void exkmp(char *s1, char *s2) {
    int i = 0, j, po, len = strlen(s1), l2 = strlen(s2);
    get_next(s2);
    while (s1[i] == s2[i] && i < l2 && i < len)
        i++;
    ex[0] = i;
    po = 0;
    for (i = 1; i < len; i++) {
        if (next[i - po] + i < ex[po] + po)
            ex[i] = next[i - po];
        else
        {
            j = ex[po] + po - i;
            if (j < 0) j = 0;
            while (i + j < len && j < l2 && s1[j + i] == s2[j])
                j++;
            ex[i] = j;
            po = i;
        }
    }
}
