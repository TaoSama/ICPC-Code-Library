//
//  Created by TaoSama on 2015-08-17
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
const int N = 505, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = N * 100;

int pnt[M], cap[M], nxt[M], head[M], cnt;

void add_edge(int u, int v, int w) {
    pnt[cnt] = v;
    cap[cnt] = w;
    nxt[cnt] = head[u];
    head[u] = cnt++;
}

void add_double(int u, int v, int w) {
    add_edge(u, v, w);
    add_edge(v, u, 0);
}

int delta[N], pre[N];
int maxFlow(int s, int t) {
    int flow = 0;
    while(true) {
        queue<int> q;
        memset(delta, 0, sizeof delta);
        q.push(s); delta[s] = INF;
        while(q.size()) {
            int u = q.front(); q.pop();
            for(int i = head[u]; ~i; i = nxt[i]) {
                int v = pnt[i];
                if(!delta[v] && cap[i] > 0) {
                    delta[v] = min(delta[u], cap[i]);
                    pre[v] = i;
                    q.push(v);
                }
            }
            if(delta[t]) break;
        }
        if(!delta[t]) break;

        flow += delta[t];
        for(int i, u = t; u != s; u = pnt[i ^ 1]) {
            i = pre[u];
            cap[i] -= delta[t];
            cap[i ^ 1] += delta[t];
        }
    }
    return flow;
}

int n, F, D;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &F, &D) == 3) {
        cnt = 0; memset(head, -1, sizeof head);

        //split the cow's vertex to edge
        //Food->CowL 2n+1~2n+F -> 1~n
        //CowR->Drink n+1~2n -> 2n+F+1~2n+F+D
        //CowL->CowR 1~n -> n+1~2n

        int s = 0, t = 2 * n + F + D + 1;
        for(int i = 1; i <= n; ++i) {
            int nf, nd; scanf("%d%d", &nf, &nd);
            for(int j = 1; j <= nf; ++j) { //Food
                int x; scanf("%d", &x);
                add_double(2 * n + x, i, 1);
            }
            for(int j = 1; j <= nd; ++j) {
                int x; scanf("%d", &x);
                add_double(n + i, 2 * n + F + x, 1);
            }
        }
        //CowL & CowR
        for(int i = 1; i <= n; ++i) add_double(i, n + i, 1);
        //s->Food
        for(int i = 1; i <= F; ++i) add_double(0, 2 * n + i, 1);
        //Drink->t
        for(int i = 1; i <= D; ++i) add_double(2 * n + F + i, t, 1);

        printf("%d\n", maxFlow(s, t));
    }
    return 0;
}
