//
//  Created by TaoSama on 2015-07-21
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
struct P {
    int id;
    double x, y, w, d, h;
    bool operator< (const P& rhs) const {
        if(x != rhs.x) return x < rhs.x;
        return y < rhs.y;
    }
} a[205];

bool inBound(int i, double p) {
    return p >= a[i].x && p <= a[i].x + a[i].w;
}

bool visble(int i, double p) {
    if(!inBound(i, p)) return false;
    for(int j = 1; j <= n; ++j) {
        if(inBound(j, p) && a[j].y < a[i].y && a[j].h >= a[i].h) return false;
    }
    return true;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(cin >> n && n) {
        vector<double> xs;
        for(int i = 1; i <= n; ++i) {
            cin >> a[i].x >> a[i].y >> a[i].w >> a[i].d >> a[i].h;
            a[i].id = i;
            xs.push_back(a[i].x);
            xs.push_back(a[i].x + a[i].w);
        }
        sort(a + 1, a + 1 + n);
        sort(xs.begin(), xs.end());
        int m = unique(xs.begin(), xs.end()) - xs.begin();

        if(kase) cout << '\n';
        cout << "For map #" << ++kase <<
             ", the visible buildings are numbered as follows:\n";
        cout << a[1].id;
        for(int i = 2; i <= n; ++i) {
            bool can = false;
            for(int j = 0; j < m - 1; ++j) {
                if(visble(i, (xs[j] + xs[j + 1]) / 2.0)) {
//                  cout << a[i].id << ' ' << xs[j] << endl;
                    can = true;
                    break;
                }
            }
            if(can) cout << ' ' << a[i].id;
        }
        cout << '\n';
    }
    return 0;
}
