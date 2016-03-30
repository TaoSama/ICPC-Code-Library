//
//  Created by TaoSama on 2016-03-22
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
const int B = 250;

int n;
int x[N], y[N];

typedef pair<int, int> P;

P pre[B][B]; //x's prefix max
struct Node {
    int first, second;
    int id;
} X[N], Y[N];

void compress(int *x, int delta) {
    vector<pair<int, int> > xs;
    for(int i = 1; i <= n; ++i) xs.push_back({x[i], delta * i});
    sort(xs.begin(), xs.end());
    for(int i = 1; i <= n; ++i)
        x[i] = lower_bound(xs.begin(), xs.end(), make_pair(x[i],
                           delta * i)) - xs.begin() + 1;
}

void getMax(P& x, P y) {
    if(x.first < y.first) x = y;
    else if(x.first == y.first && x.second > y.second) x = y;
}

void update(int x, int y, int v, int id) {
    X[y] = {x, v, id}, Y[x] = {y, v, id};
    for(int i = 0; i <= y / B; ++i) getMax(pre[x / B][i], {v, id});
}

pair<int, int> query(int x, int y) {
    pair<int, int> ret = {0, 0};
    int tx = x / B, ty = y / B;
    for(int i = tx * B; i < x; ++i)
        if(Y[i].first > y) getMax(ret, {Y[i].second, Y[i].id});
    for(int i = y + 1; i < (ty + 1) * B; ++i)
        if(X[i].first < x) getMax(ret, {X[i].second, X[i].id});
    for(int i = 0; i < tx; ++i) getMax(ret, pre[i][ty + 1]);
    return ret;
}

int prevv[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) scanf("%d", x + i);
        for(int i = 1; i <= n; ++i) scanf("%d", y + i);
        compress(x, -1);
        compress(y, 1);

        memset(pre, 0, sizeof pre);
        memset(Y, 0xc0, sizeof Y);
        memset(X, 0x3f, sizeof X);

        P ans = {0, 0};
        memset(prevv, 0, sizeof prevv);
        for(int i = n; i >= 1; --i) {
            P ret = query(x[i], y[i]);
            prevv[i] = ret.second;

            update(x[i], y[i], ret.first + 1, i);
            getMax(ans, {ret.first + 1, i});
        }

        printf("%d\n", ans.first);
        vector<int> path;
        int u = ans.second;
        for(int i = 1; i <= ans.first; ++i) {
            path.push_back(u);
            u = prevv[u];
        }
        for(int i = 0; i < path.size(); ++i)
            printf("%d%c", path[i], " \n"[i == path.size() - 1]);
    }
    return 0;
}
