//
//  Created by TaoSama on 2016-08-13
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

int root[N];
struct PersistentTrie {
    static const int M = N * 10, S = 5;
    int sz;
    struct Node {
        LL val;
        int nxt[S];
    } dat[M];
    void init() {
        sz = 0;
        memset(&dat[0], 0, sizeof dat[0]);
    }
    int newNode(int rt) {
        dat[++sz] = dat[rt];
        return sz;
    }
    void update(char* s, int n, int& rt) {
        rt = newNode(rt);
        int u = rt;
        for(int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            int& v = dat[u].nxt[c];
            v = newNode(v);
            ++dat[v].val;
            u = v;
        }
    }
    LL query(char* s, int rt) {
        int u = rt;
        for(int i = 0; s[i]; ++i) {
            int c = s[i] - 'a';
            u = dat[u].nxt[c];
        }
        return dat[u].val;
    }
} trie;

int q;
char s[N], t[N][15];
int l[N], r[N];
LL ans[N];

bool check(char* s, int len) {
    for(int i = 0; i < len / 2; ++i)
        if(s[-i] != s[-(len - i - 1)]) return false;
    return true;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%s%d", s + 1, &q) == 2) {
        int n = strlen(s + 1);
        for(int i = 1; i <= q; ++i) scanf("%d%d%s", l + i, r + i, t[i]);

        memset(ans, 0, sizeof ans);
        for(int len = 1; len < 20; ++len) {
            trie.init();
            for(int i = 1; i <= n; ++i) {
                root[i] = root[i - 1];
                if(i < len) continue;
                bool ok = check(s + i, len);
                if(!ok) continue;
                int l = i - (len - 1) / 2;
                trie.update(s + l, (len + 1) / 2, root[i]);
            }
            for(int i = 1; i <= q; ++i) {
                if(r[i] - l[i] + 1 < len) continue;
                ans[i] += trie.query(t[i], root[r[i]]) - trie.query(t[i], root[l[i] + len - 2]);
            }
        }
        for(int i = 1; i <= q; ++i)
            printf("%I64d\n", ans[i]);
    }
    return 0;
}
