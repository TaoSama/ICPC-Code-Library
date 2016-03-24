//
//  Created by TaoSama on 2015-08-04
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

int n, w, h;
typedef pair<int, int> P;
P a[105];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        cin >> n >> w >> h;

        vector<int> ys;
        ys.push_back(0); ys.push_back(h);
        for(int i = 1; i <= n; ++i) {
            cin >> a[i].first >> a[i].second;
            ys.push_back(a[i].second);
        }
        sort(ys.begin(), ys.end());
        ys.resize(unique(ys.begin(), ys.end()) - ys.begin());
        sort(a + 1, a + 1 + n);

        int ansx, ansy, side = -INF;
        for(int i = 0; i < ys.size(); ++i) {
            for(int j = i + 1; j < ys.size(); ++j) {
                int height = ys[j] - ys[i];
                int curx = 0;
                for(int k = 1; k <= n; ++k) {
                    if(a[k].second <= ys[i] || a[k].second >= ys[j])
                        continue;
                    int width = a[k].first - curx;
                    width = min(width, height);
                    if(width > side) {
                        ansx = curx, ansy = ys[i];
                        side = width;
                    }
                    curx = a[k].first;
                }
                //right bound
                int width = min(height, w - curx);
                if(width > side) {
                    ansx = curx, ansy = ys[i];
                    side = width;
                }
            }
        }
        cout << ansx << ' ' << ansy << ' ' << side << '\n';
        if(t) cout << '\n';
    }
    return 0;
}
