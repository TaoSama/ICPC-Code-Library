//
//  Created by TaoSama on 2015-05-29
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
const double EPS = 1e-10;

int a[5];

void dfs(int dep, double ans, double cur) {
    if(dep == 5) {
        if(abs(ans + cur - 24) < EPS || abs(ans - cur - 24) < EPS
                || abs(ans * cur - 24) < EPS) throw true;
        if(abs(cur) > EPS && abs(ans / cur - 24) < EPS) throw true;
        return;
    }
    dfs(dep + 1, ans + cur, a[dep + 1]);
    dfs(dep + 1, ans - cur, a[dep + 1]);
    dfs(dep + 1, ans * cur, a[dep + 1]);
    if(abs(cur) > EPS) dfs(dep + 1, ans / cur, a[dep + 1]);

    dfs(dep + 1, ans, cur + a[dep + 1]);
    dfs(dep + 1, ans, cur - a[dep + 1]);
    dfs(dep + 1, ans, cur * a[dep + 1]);
    if(abs(a[dep + 1]) > EPS) dfs(dep + 1, ans, cur / a[dep + 1]);
}

int main() {
#ifdef LOCAL
//    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        for(int i = 1; i <= 4; ++i) scanf("%d", a + i);
        sort(a + 1, a + 5);
        try {
            do {
                dfs(2, a[1], a[2]);
            } while(next_permutation(a + 1, a + 5));
            puts("no");
        } catch(bool) {
            puts("yes");
        }
    }
    return 0;
}
