//
//  Created by TaoSama on 2015-08-31
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

int n, k;
struct P {
    int id, op;
    double price;
    bool operator< (const P& rhs) const {
        return price > rhs.price;
    }
} a[1005];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &k) == 2) {
        int cnt = 0; double ans = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%lf%d", &a[i].price, &a[i].op);
            a[i].id = i;
            ans += a[i].price;
        }
        sort(a + 1, a + 1 + n);
        vector<int> sol[1005];
        double minp = INF;
        for(int i = 1; i <= n; ++i) {
            if(a[i].op == 1) {
                if(cnt < k) {
                    sol[++cnt].push_back(a[i].id);
                    if(cnt != k) ans -= 0.5 * a[i].price;
                    else minp = min(minp, a[i].price);
                } else {
                    sol[cnt].push_back(a[i].id);
                    minp = min(minp, a[i].price);
                }
            }
        }
        for(int i = 1; i <= n; ++i) {
            if(a[i].op == 2) {
                if(cnt < k) {
                    sol[++cnt].push_back(a[i].id);
                    minp = 0;
                } else {
                    sol[cnt].push_back(a[i].id);
                    minp = min(minp, a[i].price);
                }
            }
        }
        ans -= 0.5 * minp;
        printf("%.1f\n", ans);
        for(int i = 1; i <= k; ++i) {
            printf("%d", sol[i].size());
            for(int j = 0; j < sol[i].size(); ++j)
                printf(" %d", sol[i][j]);
            puts("");
        }
    }
    return 0;
}
