//
//  Created by TaoSama on 2016-07-30
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

int n, a[N];
int f[N][N];
pair<int, pair<int, int> > dir[N][N];

bool getMin(int& x, int y) {
    if(x > y) {
        x = y;
        return true;
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        if(n == 1) {
            printf("%d\n1\n", a[1]);
            continue;
        }
        if(n == 2) {
            printf("%d\n1 2\n", max(a[1], a[2]));
            continue;
        }

        memset(f, 0x3f, sizeof f);

        f[3][1] = max(a[2], a[3]); dir[3][1] = {1, {2, 3}};
        f[3][2] = max(a[1], a[3]); dir[3][2] = {1, {1, 3}};
        f[3][3] = max(a[1], a[2]); dir[3][3] = {1, {1, 2}};
        for(int i = 5; i <= n; i += 2) {
            for(int j = 1; j < i; ++j) {
                if(f[i - 2][j] == INF) continue;
                if(getMin(f[i][j], f[i - 2][j] + max(a[i], a[i - 1])))
                    dir[i][j] = {j, {i - 1, i}};
                if(getMin(f[i][i - 1], f[i - 2][j] + max(a[i], a[j])))
                    dir[i][i - 1] = {j, {j, i}};
                if(getMin(f[i][i], f[i - 2][j] + max(a[j], a[i - 1])))
                    dir[i][i] = {j, {j, i - 1}};
            }
        }

        int ans = -1;
        vector<pair<int, int> > path;
        if(n & 1) {
            pair<int, int> des = {INF, INF};
            for(int i = 1; i <= n; ++i) des = min(des, {f[n][i] + a[i], i});
            ans = des.first;
            path.push_back({des.second, -1});
            for(int u = n, v = des.second; u != 1; u -= 2) {
                path.push_back(dir[u][v].second);
                v = dir[u][v].first;
            }
        } else {
            pair<int, int> des = {INF, INF};
            for(int i = 1; i <= n; ++i) des = min(des, {f[n - 1][i] + max(a[i], a[n]), i});
            ans = des.first;
            path.push_back({des.second, n});
            for(int u = n - 1, v = des.second; u != 1; u -= 2) {
                path.push_back(dir[u][v].second);
                v = dir[u][v].first;
            }
        }
        reverse(path.begin(), path.end());
        printf("%d\n", ans);
        for(auto& p : path) {
            if(~p.second) printf("%d %d\n", p.first, p.second);
            else printf("%d\n", p.first);
        }
    }

    return 0;
}
