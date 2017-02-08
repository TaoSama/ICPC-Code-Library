//
//  Created by TaoSama on 2017-02-02
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
#include <cassert>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 5e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
int bx[N], by[N], ux[N], uy[N];
vector<int> G[N];

struct Line {
    int x, y, id;
    Line() {}
    Line(int x, int y, int id): x(x), y(y), id(id) {}
    bool operator<(const Line& l) const {
        if(x == l.x) {
            if(y == l.y) return id > l.id; //- first
            return y < l.y;
        }
        return x < l.x;
    }
};

void solve(int* bx, int* ux, int* by, int* uy) {
    vector<Line> events;
    for(int i = 1; i <= n; ++i) {
        events.push_back(Line(bx[i], by[i], -i));
        events.push_back(Line(bx[i], uy[i], i));
        events.push_back(Line(ux[i], by[i], -i));
        events.push_back(Line(ux[i], uy[i], i));
    }
    sort(events.begin(), events.end());

    int sum = 1;
    for(int i = 1; i < events.size(); ++i) {
        sum += events[i].id < 0 ? 1 : -1;
        int preID = abs(events[i - 1].id), curID = abs(events[i].id);
        pr("test"); pr(sum); pr(preID); prln(curID);
        if(sum >= 2) {
            G[preID].push_back(curID);
            G[curID].push_back(preID);
            pr(preID); prln(curID);
        }
    }
}

int c[N];

int choose(int u) {
    bool vis[5] = {};
    for(int v : G[u]) vis[c[v]] = 1;
    for(int i = 1; i <= 4; ++i) if(!vis[i]) return i;
    return 0;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d%d%d%d", bx + i, by + i, ux + i, uy + i);
    for(int i = 1; i <= n; ++i)
        c[i] = (abs(bx[i]) & 1) << 1 | (abs(by[i]) & 1);
//    solve(bx, ux, by, uy);
//    prln("----");
//    solve(by, uy, bx, ux);
//
//  for(int i = 1; i <= n; ++i) {
//      c[i] = choose(i);
//      assert(c[i]);
//  }
    puts("YES");
    for(int i = 1; i <= n; ++i)
        printf("%d\n", c[i] + 1);

    return 0;
}
