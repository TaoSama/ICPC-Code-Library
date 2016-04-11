//
//  Created by TaoSama on 2015-10-29
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;

struct Point {
    int x, y;
    void input() {
        scanf("%d%d", &x, &y);
    }
    Point operator- (const Point& p) const {
        return (Point) {x - p.x, y - p.y};
    }
    int operator^ (const Point& p) const {
        return x * p.y - y * p.x;
    }
} a[16];

bool onLine(Point& a, Point& b, Point& c) {
    return ((a - c) ^ (b - c)) == 0;
}

int line[16][16];
int dp[1 << 16];

int dfs(int s) {
    if(!s) return 0;
    int& ret = dp[s];
    if(~ret) return ret;
    if(__builtin_popcount(s) <= 2) return 1;
    ret = INF;
    for(int i = 0; i < n; ++i) {
        if(!(s >> i & 1)) continue;
        for(int j = i + 1; j < n; ++j) {
            if(!(s >> j & 1)) continue;
            ret = min(ret, dfs(s ^ (s & line[i][j])) + 1);
        }
        break; //or it will T
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) a[i].input();
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                line[i][j] = (1 << i) | (1 << j);
                for(int k = 0; k < n; ++k) {
                    if(k == i || k == j) continue;
                    if(onLine(a[i], a[j], a[k]))
                        line[i][j] |= 1 << k;
                }
            }
        }
        memset(dp, -1, sizeof dp);
        printf("Case %d: %d\n", ++kase, dfs((1 << n) - 1));
    }
    return 0;
}
