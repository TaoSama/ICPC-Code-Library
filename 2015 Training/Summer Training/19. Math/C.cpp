//
//  Created by TaoSama on 2015-08-14
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

int p, q, r, s;

vector<int> prime;
void init() {
    bool vis[10005] = {};
    for(int i = 2; i <= 10000; ++i) {
        if(!vis[i]) {
            prime.push_back(i);
            for(int j = i + i; j <= 10000; j += i)
                vis[j] = 1;
        }
    }
}

int e[10005];

void add(int x, int d) {
    for(int i = 2; i <= x; ++i) {
        int t = i;
        for(auto &p : prime) {
            while(t % p == 0) {
                t /= p;
                e[p] += d;
            }
            if(t == 1) break;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    init();
    while(scanf("%d%d%d%d", &p, &q, &r, &s) == 4) {
        memset(e, 0, sizeof e);
        add(p, 1); add(r, -1);
        add(p - q, -1); add(r - s, 1);
        add(q, -1); add(s, 1);

        double ans = 1;
        for(auto &p : prime) ans *= pow(1.0 * p, 1.0 * e[p]);
        printf("%.5f\n", ans);
    }
    return 0;
}
