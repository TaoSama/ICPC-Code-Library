//
//  Created by TaoSama on 2016-03-06
//  Copyright (c) 2016 TaoSama. All rights reserved.
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

int n, m, t, s;
int a[16], r[16];

bool cmp(int x, int y) {
    return a[x] > a[y];
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int q; scanf("%d", &q);
    while(q--) {
        scanf("%d%d%d%d", &n, &m, &t, &s);
        int nm = n * m;
        for(int i = 0; i < nm; ++i) scanf("%d", a + i), r[i] = i;
        sort(r, r + nm, cmp);

        vector<int> air, ship;
        for(int i = 1; i <= t; ++i) {
            int x; scanf("%d", &x);
            if(x) air.push_back(x);
        }
        for(int i = 1; i <= t; ++i) {
            int x; scanf("%d", &x);
            if(x) ship.push_back(x);
        }
        sort(air.begin(), air.end(), greater<int>());
        sort(ship.begin(), ship.end(), greater<int>());

        int maxAtk = -INF, yes = 0;
        for(int mask = 0; mask < 1 << nm; ++mask) {
            int f, g, each, d, atk;
            f = g = each = d = atk = 0;
            for(int i = 0; i < nm; ++i) {
                if(mask >> i & 1) {
                    if(f < air.size()) d += a[r[i]] * air[f++];
                } else {
                    if(g < ship.size()) {
                        atk += a[r[i]] * ship[g++];
                        each |= 1 << (r[i] / m);
                    }
                }
            }
            each = each == (1 << n) - 1;
            if(d >= s) {
                if(atk > maxAtk) {
                    maxAtk = atk;
                    yes = each;
                } else if(atk == maxAtk) yes |= each;
            }
        }

        if(maxAtk != -INF) {
            printf("%d\n", maxAtk);
            puts(yes ? "Yes" : "No");
        } else puts("Not Exist");
    }
    return 0;
}
