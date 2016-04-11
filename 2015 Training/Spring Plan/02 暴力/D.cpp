//
//
//
//  Created by TaoSama on 2015-04-16
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

char a[505][505];
int n, m, row[505][505], col[505][505];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%s", a[i] + 1);
    for(int i = 1; i <= n; ++i) {
        int cnt = 0;
        for(int j = m; j >= 1; --j) {
            row[i][j] = cnt;
            if(a[i][j] == '.') ++cnt;
            else cnt = 0;
        }
    }
    /*for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cout << row[i][j];
        }
        cout << endl;
    }*/
    for(int j = 1; j <= m; ++j) {
        int cnt = 0;
        for(int i = n; i >= 1; --i) {
            col[i][j] = cnt;
            if(a[i][j] == '.') ++cnt;
            else cnt = 0;
        }
    }
    /*for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cout << col[i][j];
        }
        cout << endl;
    }*/
    int ans = -1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(a[i][j] == '.') {
                for(int k = row[i][j]; k >= 1; --k) {
                    for(int l = col[i][j]; l >= 1; --l) {
                        if(row[i + l][j] >= k && col[i][j + k] >= l) {
                            int t = k + l << 1;
                            if(t > ans) ans = t;
                        }
                    }
                }
            }
        }
    }
    if(ans == -1) puts("impossible");
    else printf("%d\n", ans);
    return 0;
}
