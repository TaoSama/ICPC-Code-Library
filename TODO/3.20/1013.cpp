//
//  Created by TaoSama on 2017-03-22
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
#include <unordered_map>
#include <unordered_set>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef unsigned long long ULL;
const ULL seed[1] = {MOD};
struct Hash {
//    typedef pair<ULL, ULL> Type;
    typedef ULL Type;
    ULL power[1][N], h[1][N];

    void init(char* a) {
        for(int i = 0; i < 1; ++i) {
            power[i][0] = 1; h[i][0] = 0;
            for(int j = 1; a[j]; ++j) {
                power[i][j] = power[i][j - 1] * seed[i];
                h[i][j] = h[i][j - 1] * seed[i] + a[j];
            }
        }
    }

    inline Type get(int l, int r) { // [l, r]
        ULL a = h[0][r] - h[0][l - 1] * power[0][r - l + 1];
//        ULL b = h[1][r] - h[1][l - 1] * power[1][r - l + 1];
        return a;
    }
} hs, ht;

struct HashTable {
    static const int M = 1000003;
    struct Edge {
        int nxt;
        Hash::Type key;
        int val;
    } edges[M];
    int cnt, head[M];

    int timStp, vis[M];
    void init() {
        cnt = 0;
        ++timStp;
    }
    inline void lazyClear(int u) {
        if(vis[u] != timStp) {
            vis[u] = timStp;
            head[u] = -1;
        }
    }

    inline bool add(Hash::Type& h, int val) {
        int u = h % M;
        lazyClear(u);
        for(int i = head[u]; ~i; i = edges[i].nxt) {
            if(h == edges[i].key) {
                edges[i].val += val;
                return true;
            }
        }
        if(val) {
            edges[cnt] = {head[u], h, val};
            head[u] = cnt++;
        }
        return false;
    }
} hshTbls, hshTblt;


int sl, tl;
int count(int l, bool ct) {
    hshTbls.init();
    for(int i = 1; i + l - 1 <= sl; ++i) {
        Hash::Type h = hs.get(i, i + l - 1);
        hshTbls.add(h, 1);
    }

    if(!ct) {
        for(int i = 1; i + l - 1 <= tl; ++i) {
            Hash::Type h = ht.get(i, i + l - 1);
            if(!hshTbls.add(h, 0)) return true;
        }
        return false;
    } else {
        int cnt = 0;
        hshTblt.init();
        for(int i = 1; i + l - 1 <= tl; ++i) {
            Hash::Type h = ht.get(i, i + l - 1);
            if(hshTbls.add(h, 0)) continue;
            cnt += !hshTblt.add(h, 1);
        }
        return cnt;
    }
}

char s[N], t[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%s%s", s + 1, t + 1) == 2) {
        hs.init(s);
        ht.init(t);

        sl = strlen(s + 1), tl = strlen(t + 1);
        int l = 1, r = min(sl + 1, tl), ans = -1;
        while(l <= r) {
            int m = l + r >> 1;
            if(count(m, 0)) ans = m, r = m - 1;
            else l = m + 1;
        }
        if(ans == -1) puts("-1");
        else {
            printf("%d %d\n", ans, count(ans, 1));
        }
    }

    return 0;
}
