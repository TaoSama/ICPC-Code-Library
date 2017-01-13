//
//  Created by TaoSama on 2016-12-30
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

int n, t[50];
int d[][2] = {0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1, -1, 0, -1, 1};

struct Sta {
    int x, y, dir, tim;
    bool operator<(const Sta& s) const {
        return make_tuple(x, y, dir, tim)
               < make_tuple(s.x, s.y, s.dir, s.tim);
    }
};
set<Sta> vis;
set<pair<int, int> > ss;
int go[1000];

void dfs(int x, int y, int dir, int tim) {
    if(tim > t[n]) return;
    Sta cur = {x, y, dir, tim};
    if(vis.count(cur)) return;
    vis.insert(cur);
//    pr(x); prln(y);
    ss.insert({x, y});
    if(go[tim]) {
        int a = (dir + 7) % 8, b = (dir + 1) % 8;
        dfs(x + d[a][0], y + d[a][1], a, tim + 1);
        dfs(x + d[b][0], y + d[b][1], b, tim + 1);
    } else dfs(x + d[dir][0], y + d[dir][1], dir, tim + 1);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        memset(go, 0, sizeof go);
        for(int i = 1; i <= n; ++i) {
            cin >> t[i];
            t[i] += t[i - 1];
            go[t[i]] = true;
        }

        vis.clear();
        ss.clear();
        dfs(0, 0, 0, 1);
        cout << ss.size() << endl;
    }

    return 0;
}
