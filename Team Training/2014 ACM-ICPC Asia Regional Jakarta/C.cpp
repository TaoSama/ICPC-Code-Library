//
//  Created by TaoSama on 2015-12-21
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k, e, ans;
int h[N], f[N][11][51][4];
bool in[N][11][51][4];
int power[] = {0, 4, 8, 11};

struct Sta {
    int p, c, e, l; //position, chance, energy, level
};

void see(Sta u, Sta v) {
    int &cur = f[u.p][u.c][u.e][u.l];
    int &nxt = f[v.p][v.c][v.e][v.l];
    printf("f[%d][%d][%d][%d] = %d → ", u.p, u.c, u.e, u.l, cur);
    printf("f[%d][%d][%d][%d] = %d\n", v.p, v.c, v.e, v.l, nxt);
}

void spfa() {
    queue<Sta> q;
    memset(f, 0x3f, sizeof f);
    memset(in, false, sizeof in);
    f[0][k][e][0] = 0; in[0][k][e][0] = true;
    q.push((Sta) {0, k, e, 0});
    while(q.size()) {
        Sta u = q.front(); q.pop();
        in[u.p][u.c][u.e][u.l] = false;
        int &cur = f[u.p][u.c][u.e][u.l];
        if(u.p == n) {
            ans = min(ans, cur);
            continue;
        }
        if(u.c) {
            for(int i = 0; i < 4; ++i) {
                if(i == u.l || u.e < i) continue;
                Sta v = u;
                ++v.p; --v.c; v.e -= i; v.l = i;
                int cost = max(0, h[v.p] - power[v.l]);
                int &nxt = f[v.p][v.c][v.e][v.l];
                if(nxt > cur + cost) {
                    nxt = cur + cost;
//                  see(u, v);
                    if(!in[v.p][v.c][v.e][v.l]) {
                        in[v.p][v.c][v.e][v.l] = true;
                        q.push(v);
                    }
                }
            }
        }
        Sta v = u; ++v.p;
        if(v.e < v.l) v.c = v.e = v.l = 0; //lack energy, just set 0
        else v.e -= v.l;
        int cost = max(0, h[v.p] - power[v.l]);
        int &nxt = f[v.p][v.c][v.e][v.l];
        if(nxt > cur + cost) {
            nxt = cur + cost;
            if(!in[v.p][v.c][v.e][v.l]) {
                in[v.p][v.c][v.e][v.l] = true;
                q.push(v);
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &k, &e);
        for(int i = 1; i <= n; ++i) scanf("%d", h + i);

        ans = INF;
        spfa();
        static int kase = 0;
        printf("Case #%d: %d\n", ++kase, ans);
    }
    return 0;
}
