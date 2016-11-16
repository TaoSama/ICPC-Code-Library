//
//  Created by TaoSama on 2016-11-16
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

int n;
int x0, y0;

inline bool checkHV(int x, int y) {
    return x == x0 || y == y0;
}

inline bool checkDiag(int x, int y) {
    return x0 + y0 == x + y || x0 - y0 == x - y;
}

inline int sgn(int x, int x0) {
    return x < x0 ? -1 : x > x0;
}

inline pair<int, int> get(int x, int y) {
    return {sgn(x, x0), sgn(y, y0)};
}

long long getDis(const pair<int, int>& A) {
    return 1LL * abs(A.first - x0) + 1LL * abs(A.second - y0);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &x0, &y0) == 3) {
        map<pair<int, int>, int> mp;
        int idx = 0, hv[8] = {};
        for(int i = -1; i <= 1; ++i) {
            for(int j = -1; j <= 1; ++j) {
                if(!i && !j) continue;
                if(i == 0 || j == 0) hv[idx] = 1;
                mp[ {i, j}] = idx++;
            }
        }

        vector<pair<pair<int, int>, char> > v[8];
        for(int i = 1; i <= n; ++i) {
            char c[2]; int x, y;
            scanf("%s%d%d", c, &x, &y);
            if(!checkDiag(x, y) && !checkHV(x, y)) continue;
            auto t = get(x, y);
//            cout << i << ": " << t.first << ' ' << t.second << endl;
            v[mp[get(x, y)]].push_back({{x, y}, *c});
        }

        using P = pair<pair<int, int>, char>;
        bool yes = false;
        for(int i = 0; i < 8; ++i) {
            auto& vec = v[i];
            if(!vec.size()) continue;
            auto iter = min_element(vec.begin(), vec.end(), [](const P & A, const P & B) {
                return getDis(A.first) < getDis(B.first);
            });
//            pr(iter->first.first); pr(iter->first.second); prln(hv[i]);
            if(iter->second == 'Q') yes = true;
            else if(iter->second == 'B' && !hv[i]) yes = true;
            else if(iter->second == 'R' && hv[i]) yes = true;
        }

        puts(yes ? "YES" : "NO");
    }

    return 0;
}
