//
//  Created by TaoSama on 2015-10-23
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
    Point(int x = 0, int y = 0): x(x), y(y) {}
    void input() {
        scanf("%d%d", &x, &y);
    }
    void print() {
        cout << x << ' ' << y << endl;
    }
} A[35];

bool vis[205][205];

int l, r, up, down;

bool onLine(Point& a, Point& b) {
    return a.x == b.x || a.y == b.y;
}

bool isLegal(Point& a) {
    if(a.x >= l && a.x <= r && a.y >= down && a.y <= up) return 0;
    return 1;
}
bool isIn(Point& a) {
    return (a.x > l && a.x < r && a.y > down && a.y < up);
}

int getRectArea(Point a, Point b, Point& c, Point& d) {
    if(a.x > b.x) swap(a, b);
    c = Point(a.x, b.y), d = Point(b.x, a.y);
    if(vis[c.x][c.y] && vis[d.x][d.y])
        return abs(a.x - b.x) * abs(a.y - b.y);
    return -INF;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
//    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1 && n) {
        memset(vis, false, sizeof vis);
        for(int i = 1; i <= n; ++i) {
            A[i].input();
            vis[A[i].x][A[i].y] = true;
        }
        int ans = -INF;
        Point C, D;
        for(int a = 1; a <= n; ++a) {
            for(int b = 1; b <= n; ++b) {
                if(onLine(A[a], A[b])) continue;

                int tmp = getRectArea(A[a], A[b], C, D);
                if(tmp == -INF) continue;

                l = min(A[a].x, A[b].x), r = max(A[a].x, A[b].x);
                down = min(A[a].y, A[b].y), up = max(A[a].y, A[b].y);

                for(int c = 1; c <= n; ++c) {
                    for(int d = 1; d <= n; ++d) {
                        if(onLine(A[c], A[d])) continue;

                        int tmp2 = getRectArea(A[c], A[d], C, D);
                        if(tmp2 == -INF || tmp < tmp2) continue;
                        if(isIn(A[c]) && isIn(A[d]) && isIn(C) && isIn(D)) {
                            ans = max(ans, tmp);
                        }
//                        if(tmp == 3){
//                            A[a].print();
//                            A[b].print();
//                            A[c].print();
//                            A[d].print();
//                            cout << "max" << endl;
//                        }
                        if(!isLegal(A[c]) || !isLegal(A[d]) || !isLegal(C) || !isLegal(D))
                            continue;

                        ans = max(ans, tmp + tmp2);
//                        if(tmp + tmp2 == 3){
//                            A[a].print();
//                            A[b].print();
//                            A[c].print();
//                            A[d].print();
//                            cout << endl;
//                        }
                    }
                }
            }
        }
        if(ans != -INF) printf("%d\n", ans);
        else puts("imp");
    }
    return 0;
}
