//
//  Created by TaoSama on 2016-03-04
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
int f, g, nxt[N];
pair<long long, char> s[N], t[N];
long long ans;

void getNxt() {
    nxt[0] = -1;
    int i = 0, j = -1;
    while(i < g) {
        if(j == -1 || t[i].second == t[j].second)
            nxt[++i] = ++j;
        else j = nxt[j];
    }
}

bool ok(int i, int j) {
//  printf("%d %d: (%d, %c) (%d, %c)\n", i, j, s[i].first, s[i].second,
//          t[j].first, t[j].second);
    if(j == -1) return true;
    if(s[i].second == t[j].second) {
        if((j == 0 || j == g - 1) && s[i].first >= t[j].first)
            return true;
        else if(s[i].first == t[j].first) return true;
        else return false;
    }
    return false;
}

long long kmp() {
    getNxt();
    int i = 0, j = 0;
    long long ret = 0;
    while(i < f) {
        if(ok(i, j)) ++i, ++j;
        else j = nxt[j];
        if(j == g) ++ret;
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        f = g = 0;
        for(int i = 1; i <= n; ++i) {
            int x = 0; char y[2];
            scanf("%d-%s", &x, y);
            if(i == 1) s[f++] = {x, *y};
            else {
                if(*y == s[f - 1].second) s[f - 1].first += x;
                else s[f++] = {x, *y};
            }
        }
        for(int i = 1; i <= m; ++i) {
            int x = 0; char y[2];
            scanf("%d-%s", &x, y);
            if(i == 1) t[g++] = {x, *y};
            else {
                if(*y == t[g - 1].second) t[g - 1].first += x;
                else t[g++] = {x, *y};
            }
        }
        if(g == 1) {
            long long ans = 0;
            for(int i = 0; i < f; ++i) {
                if(s[i].second == t[0].second)
                    ans += max(0LL, s[i].first - t[0].first + 1);
            }
            printf("%I64d\n", ans);
            continue;
        }
        printf("%I64d\n", kmp());
    }
    return 0;
}
