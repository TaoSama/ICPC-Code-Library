//
//  Created by TaoSama on 2016-08-16
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1 << 28;

int n, X, L, a[N], sum[N];

struct Trie {
    static const int M = N * 30, S = 2;
    int sz, root;
    int nxt[M][S], val[M], pos[M];
    int newNode() {
        val[sz] = pos[sz] = -1;
        memset(nxt[sz], -1, S << 2);
        return sz++;
    }
    void init() {
        sz = 0;
        root = newNode();
    }
    int get(int u) {
        return ~u ? val[u] : -1;
    }
    void update(int x, int v, int id) {
        update(27, root, x, v, id);
    }
    void update(int dep, int u, int x, int w, int id) {
        if(dep == -1) {
            if(~w) {
                val[u] = w;
                pos[u] = id;
            } else {
                if(pos[u] == id) val[u] = -1;
            }
            return;
        }
        int c = x >> dep & 1;
        int& v = nxt[u][c];
        if(v == -1) v = newNode();

        update(dep - 1, v, x, w, id);
        val[u] = max(get(nxt[u][c ^ 1]), val[v]);
    }

    int query(int cur) {
        int ret = -1;
        int u = root;
        for(int i = 27; ~i; --i) {
            int c1 = cur >> i & 1, c2 = X >> i & 1;
            if(c2) {
                ret = max(ret, get(nxt[u][c1])); //0, less
                u = nxt[u][c1 ^ 1];  //1, equal
                if(u == -1) return ret;
            } else {
                if(~nxt[u][c1]) {
                    u = nxt[u][c1]; //0, equal
                    if(u == -1) return ret;
                } else return ret; //1, greater
            }
        }
        ret = max(ret, val[u]);
        return ret;
    }
} trie;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &X, &L);
        int p, q; scanf("%d%d%d", a + 1, &p, &q);
        for(int i = 2; i <= n; ++i) a[i] = (1LL * a[i - 1] * p + q) % MOD;

//        for(int i = 1; i <= n; ++i) printf("%d ", a[i]); puts("");

        trie.init();
        trie.update(0, 0, 0);

        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1] ^ a[i];
            int cur = trie.query(sum[i]);
            if(cur == -1) ans = 0;
            else {
                ans = cur + 1;
                trie.update(sum[i], ans, i);
            }
            if(i >= L) trie.update(sum[i - L], -1, i - L);
        }
        printf("%d\n", ans);
    }

    return 0;
}
