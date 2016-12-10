//
//  Created by TaoSama on 2016-08-20
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

struct SAM {
    static const int M = 4e5 + 10, S = 27;
    int sz, root, last;
    int nxt[M][S], link[M], len[M], real[M];
    int newNode(int l) {
        len[++sz] = l;
        memset(nxt[sz], 0, S << 2);
        return sz;
    }
    void init() {
        sz = 0;
        last = root = newNode(0);
        real[root] = link[root] = 0;
    }
    void extend(int c, int idx) {
        int cur = newNode(len[last] + 1), p = last;
        real[cur] = idx;
        for(; p && !nxt[p][c]; p = link[p]) nxt[p][c] = cur;
        if(!p) link[cur] = root;
        else {
            int q = nxt[p][c];
            if(len[p] + 1 == len[q]) link[cur] = q;
            else {
                int nq = newNode(len[p] + 1);
                real[nq] = idx;
                memcpy(nxt[nq], nxt[q], S << 2);
                for(; p && nxt[p][c] == q; p = link[p]) nxt[p][c] = nq;
                link[nq] = link[q];
                link[cur] = link[q] = nq;
            }
        }
        last = cur;
    }
    int solve(char* s) {
        int cur = root;
        for(int i = 0; s[i]; ++i) {
            cur = nxt[cur][s[i] - 'a'];
            if(!cur) break;
        }
        return min(real[cur], len[cur]) - len[link[cur]];
    }
} sam;

int n, q;
char a[N], b[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &q);

        sam.init();
        for(int i = 1; i <= n; ++i) {
            scanf("%s", a + 1);
            for(int j = 1; a[j]; ++j) sam.extend(a[j] - 'a', j);
            sam.extend(26, 0);
        }

        static int kase = 0;
        printf("Case #%d:\n", ++kase);
        while(q--) {
            scanf("%s", b);
            printf("%d\n", sam.solve(b));
        }
    }

    return 0;
}
