//
//  Created by TaoSama on 2016-01-19
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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

const long double PI = acosl(-1);

int n;

struct Point {
    int x, y;
    long double ang;
    int id;
    void read() {
        scanf("%d%d", &x, &y);
        ang = atan2l(y, x);
    }
    bool operator<(const Point& p) const {
        return ang < p.ang;
    }
} a[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) {
            a[i].read();
            a[i].id = i;
        }
        sort(a + 1, a + 1 + n);
        a[n + 1] = a[1];
        a[n + 1].ang += 2 * PI;

        long double angle = INF;
        int ans;
        for(int i = 1; i <= n; ++i) {
            long double cur = a[i + 1].ang - a[i].ang;
//          cout << a[i].id << ' ' << a[i + 1].id << ' ' << cur << endl;
            if(cur < angle) {
                angle = cur;
                ans = i;
            }
        }
        printf("%d %d\n", a[ans].id, a[ans + 1].id);
    }
    return 0;
}
