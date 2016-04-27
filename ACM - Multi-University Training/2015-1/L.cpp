//
//  Created by TaoSama on 2016-04-27
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const double EPS = 1e-8;

int sgn(double x) {
    return x < -EPS ? -1 : x > EPS;
}

double timeLine;
struct Circle {
    double x, y, r;
    void read() {
        scanf("%lf%lf%lf", &x, &y, &r);
    }
    double getY(int up) {
        return y + up * (sqrt(r * r - (x - timeLine) * (x - timeLine)));
    }
} c[N];

typedef pair<double, int> Event; //x
Event e[N << 1];

struct Node {
    int id, d;
    bool operator<(const Node& r) const {
        double y1 = c[id].getY(d), y2 = c[r.id].getY(r.d); //y
        return sgn(y1 - y2) ? y1 < y2 : d < r.d;
    }
};

int n, dep[N], p[N];
vector<int> G[N];

int dfs(int u) {
    int sg = 0;
    for(int v : G[u]) sg ^= dfs(v) + 1;
    return sg;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i <= n; ++i) G[i].clear();
        for(int i = 1; i <= n; ++i) {
            c[i].read();
            e[2 * i - 1] = {c[i].x - c[i].r, i};
            e[2 * i] = {c[i].x + c[i].r, -i};
        }
        sort(e + 1, e + 2 * n + 1);

        set<Node> s;
        memset(dep, 0, sizeof dep);
        for(int i = 1; i <= 2 * n; ++i) {
            timeLine = e[i].first;
            int id = e[i].second;

            if(id < 0) {
                s.erase({ -id, 1});
                s.erase({ -id, -1});
                continue;
            }

            auto up = s.lower_bound({id, 1}), dw = up;
            if(up == s.end() || dw == s.begin()) { //无包含
                p[id] = 0;
                dep[id] = 1;
                G[0].push_back(id);
            } else if((--dw)->id == up->id) { //直接被包含
                p[id] = dw->id;
                dep[id] = dep[dw->id] + 1;
                G[dw->id].push_back(id);
            } else {
                if(dep[dw->id] == dep[up->id]) { //三圆是兄弟
                    p[id] = p[dw->id];
                    dep[id] = dep[dw->id];
                    G[p[dw->id]].push_back(id);
                } else { //两圆是兄弟，另一圆（深度小的）包两圆
                    if(dep[dw->id] > dep[up->id]) swap(up, dw);
                    p[id] = dw->id;
                    dep[id] = dep[dw->id] + 1;
                    G[dw->id].push_back(id);
                }
            }

            s.insert({id, 1});
            s.insert({id, -1});
        }

//      for(int i = 1; i <= n; ++i) printf("%d->%d\n", p[i], i);

        puts(dfs(0) ? "Alice" : "Bob");
    }
    return 0;
}
