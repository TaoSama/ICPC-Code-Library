//
//  Created by TaoSama on 2016-08-02
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
const double EPS = 1e-12, PI = acos(-1);

int sgn(double x) {
    return x < -EPS ? -1 : x > EPS;
}

int n;
struct Point {
    int x, y;
    double ang;
    void read() {scanf("%d%d", &x, &y);}
} p[N];

int calc(vector<Point>& v, double delta) {
    int angle = 0;
    for(int i = 0, j = 0, k = 0; i < n - 1; i = k + 1) {
        //collinear
        while(k + 1 < n - 1 && sgn(v[k + 1].ang - v[i].ang) == 0) ++k;
        j = max(j, k);
        while(j < v.size() && sgn(v[j].ang - v[i].ang - delta) < 0) ++j;
        angle += (k - i + 1) * (j - k - 1);
    }
    return angle;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) p[i].read();

        int acute = 0, obtuse = 0;
        for(int i = 1; i <= n; ++i) {
            vector<Point> v;
            for(int j = 1; j <= n; ++j) if(j != i) v.push_back(p[j]);
            for(int j = 0; j < n - 1; ++j)
                v[j].ang = atan2(v[j].y - p[i].y, v[j].x - p[i].x);
            sort(v.begin(), v.end(), [&](Point x, Point y) {
                return x.ang < y.ang;
            });

            //double it
            for(int j = 0; j < n - 1; ++j){
                Point tmp = v[j];
                tmp.ang += 2 * PI;
                v.push_back(tmp);
            }

            int curAcute = calc(v, PI / 2);
            int tot = calc(v, PI);

            acute += curAcute;
            obtuse += tot - curAcute;
        }
        int ans = (acute - 2 * obtuse) / 3;
        printf("%d\n", ans);
    }
    return 0;
}
