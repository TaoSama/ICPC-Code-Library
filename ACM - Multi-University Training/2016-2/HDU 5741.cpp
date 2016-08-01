//
//  Created by TaoSama on 2016-07-25
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
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, a[N];
char ans[N * N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    /*
       |            ___B
       |      G ___|   |
       |    ___|  _____|
       |___|     |
       |    _____| R
       |   |
    ___|___|_____________
      0|
    */

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; ++i) scanf("%d", a + i);

        vector<pair<int, int> > up, dw;
        for(int i = 0; i < n; ++i) {
            int zero = 0, one = 0;
            for(int j = i; j < n; ++j) {
                if(j % 2 == 0) zero += a[j];
                else one += a[j];

                //red points
                if(i % 2 == 0 && j % 2 == 0) dw.push_back({zero, one});
                //green points
                if(i % 2 == 1 && j % 2 == 1) up.push_back({zero, one});
            }
        }
        sort(dw.begin(), dw.end());
        sort(up.begin(), up.end());

        n = 0; //erase blues points, save lower red points
        for(int i = 0, j; i < dw.size(); i = j) {
            //jump vertical line
            for(j = i; j < dw.size() && dw[j].first == dw[i].first; ++j);
            //pop upper ones, save this lowest one
            while(n > 0 && dw[n - 1].second >= dw[i].second) --n;
            dw[n++] = dw[i];
        }
        dw.resize(n);

        n = 0; //erase blues points, save upper green points
        for(int i = 0, j; i < up.size(); i = j) {
            //go vertical line's top
            for(j = i; j < up.size() && up[j].first == up[i].first; ++j);
            //if upper
            if(!n || up[j - 1].second >= up[n - 1].second)
                up[n++] = up[j - 1];
        }
        up.resize(n);

        for(int i = 0; i < m; ++i) {
            int a, b; scanf("%d%d", &a, &b);
            auto st = lower_bound(dw.begin(), dw.end(), make_pair(a, -INF));
            auto ed = upper_bound(up.begin(), up.end(), make_pair(a, +INF));
            ans[i] = '0';
            if(st != dw.end()) {
                --ed;
                if(b >= st->second && b <= ed->second) ans[i] = '1';
            }
        }
        ans[m] = 0;
        puts(ans);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}

/*
dw:
3 0
up:
0 4

dw:
3 0
4 2
up:
0 2

dw:
3 0
4 2
6 3
7 7
8 11
10 12
up:
0 7
1 8
2 9
3 12
4 16
7 18
8 19
*/
