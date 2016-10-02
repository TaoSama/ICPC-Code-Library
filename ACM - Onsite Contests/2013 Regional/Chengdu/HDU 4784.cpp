//
//  Created by TaoSama on 2016-10-02
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
#include <stack>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 100 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, B, K, R, T;

int f[N][8][8][205]; //点 时空 袋子 时间
struct Edge {
    int v, t, c;
};
vector<Edge> G[N];

int p[8][N];

bool in[N][8][8][205];

struct Node {
    int x, k, b, t;
    bool operator<(const Node& e) const {
        return t > e.t;
    }
};

inline bool check(Node& v) {
    if(v.t > T) return false;
    if((v.x == 1 || v.x == n) && v.k) return false;
    if(v.b < 0 || v.b > B) return false;
    return true;
}

inline void relax(Node& v, priority_queue<Node>& q, int newOne) {
    if(!check(v)) return;
    if(newOne > 0) return;
    if(f[v.x][v.k][v.b][v.t] > newOne) {
        f[v.x][v.k][v.b][v.t] = newOne;
        if(!in[v.x][v.k][v.b][v.t]) {
            in[v.x][v.k][v.b][v.t] = true;
            q.push(v);
        }
    }
}

void see(Node u) {
    printf("%d have: %d ceng: %d time: %d cost: %d\n",
           u.x, u.k, u.b, u.t, f[u.x][u.k][u.b][u.t]);
}

int spfa() {
    Node s = {1, 0, 0, 0};
    priority_queue<Node> q; q.push(s);
    memset(f, 0x3f, sizeof f);
    memset(in, 0, sizeof in);
    f[1][0][0][0] = -R;

    int ans = INF;
    while(q.size()) {
        Node u = q.top(); q.pop();
        int last = f[u.x][u.k][u.b][u.t];
        in[u.x][u.k][u.b][u.t] = 0;

        if(u.x == n && u.k == 0) ans = min(ans, last);
        if(u.x == n) continue;

        for(Edge& e : G[u.x]) {
            Node v = u;
            v.x = e.v;
            v.t += e.t;
            int newOne = last + e.c;
            relax(v, q, newOne);

            //1, n can't trade
            if(v.x == 1 || v.x == n) continue;

            for(int i = -1; i <= 1; i += 2) {
                Node t = v;
                t.b += i;
                int cur = newOne + i * p[t.k][t.x];
                relax(t, q, cur);
            }
        }

        //1, n can't transport or trade
        if(u.x == 1 || u.x == n) continue;

        Node v = u;
        v.k = (v.k + 1) % K;
        v.t += 1;
        relax(v, q, last);

        for(int i = -1; i <= 1; i += 2) {
            Node t = v;
            t.b += i;
            int newOne = last + i * p[t.k][t.x];
            relax(t, q, newOne);
        }
    }

    return ans;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d%d%d%d", &n, &m, &B, &K, &R, &T);
        for(int i = 1; i <= n; ++i) G[i].clear();

        for(int i = 0; i < K; ++i)
            for(int j = 1; j <= n; ++j)
                scanf("%d", p[i] + j);

        for(int i = 1; i <= m; ++i) {
            int a, b, t, c; scanf("%d%d%d%d", &a, &b, &t, &c);
            G[a].push_back({b, t, c});
        }

        int ans = spfa();

        static int kase = 0;
        printf("Case #%d: ", ++kase);
        if(ans == INF) puts("Forever Alone");
        else printf("%d\n", -ans);

//        return 0;
    }

    return 0;
}
