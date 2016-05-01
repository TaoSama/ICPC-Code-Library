//
//  Created by TaoSama on 2016-04-21
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
const int N = 4e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

struct Trie {
    static const int M = 32 * 4e5 + 10, S = 2;
    int root, sz;
    int nxt[M][S];
    int newNode() {
        memset(nxt[sz], -1, sizeof nxt[sz]);
        return sz++;
    }
    void init() {
        sz = 0;
        root = newNode();
    }
    void insert(int x) {
        int u = root;
        for(int i = 31; ~i; --i) {
            int c = x >> i & 1, &v = nxt[u][c];
            if(v == -1) v = newNode();
            u = v;
        }
    }
    int query(int x) {
        int u = root, ret = 0;
        for(int i = 31; ~i; --i) {
            int c = x >> i & 1;
            if(~nxt[u][c ^ 1]) {
                ret |= 1 << i;
                u = nxt[u][c ^ 1];
            } else u = nxt[u][c];
        }
        return ret;
    }
} trie;

int n, a[N], sum[N], pre[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d", &n);
    sum[0] = sum[n + 1] = 0;
    for(int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        sum[i] = sum[i - 1] ^ a[i];
    }

    trie.init(); trie.insert(sum[0]);
    for(int i = 1; i <= n; ++i) {
        pre[i] = max(pre[i - 1], trie.query(sum[i]));
        trie.insert(sum[i]);
    }

    int ans = 0;
    trie.init(); trie.insert(sum[n + 1]);
    for(int i = n; i > 1; --i) {
        sum[i] = sum[i + 1] ^ a[i];
        ans = max(ans, pre[i - 1] + trie.query(sum[i]));
        trie.insert(sum[i]);
    }
    printf("%d\n", ans);
    return 0;
}
