//
//  Created by TaoSama on 2017-01-29
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

int n, k;
int rx, ry;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    cin >> n >> k;
    cin >> rx >> ry;
    map<pair<int, int>, int> mp;
    auto check = [](int dx, int dy) {

        return true;
    };
    auto get = [&](int ox, int oy, int i, int j) {
        int dx = ox - rx, dy = oy - ry;
        if(i && !dx || j && !dy) return -1;
        if(!i && dx || !j && dy) return -1;
        if(i) dx /= i;
        if(j) dy /= j;
        if(dx < 0 || dy < 0 || (dx && dy && dx != dy)) return -1;
        return max(dx, dy);
    };

    for(int i = -1; i <= 1; ++i) {
        int bx = i == -1 ? 0 : i == 0 ? rx : n + 1;
        for(int j = -1; j <= 1; ++j) {
            if(!i && !j) continue;
            int by = j == -1 ? 0 : j == 0 ? ry : n + 1;
            int dx = bx - rx, dy = by - ry;
            if(i) dx /= i;
            if(j) dy /= j;
            int step = dx && dy ? min(dx, dy) : max(dx, dy);
            mp[ {i, j}] = step - 1;
//            pr(bx); prln(by);
//            pr(i); pr(j); prln((mp[ {i, j}]));
        }
    }

    for(int t = 1; t <= k; ++t) {
        int bx, by; cin >> bx >> by;
        int ok = false;
        for(int i = -1; i <= 1 && !ok; ++i) {
            for(int j = -1; j <= 1 && !ok; ++j) {
                if(!i && !j) continue;
                int step = get(bx, by, i, j);
                if(step == -1) continue;
                ok = true;
                mp[ {i, j}] = min(mp[ {i, j}], step - 1);
            }
        }
    }

    int ans = 0;
    for(auto& p : mp) ans += p.second;
    cout << ans << endl;

    return 0;
}
