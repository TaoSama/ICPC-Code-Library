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

map<vector<int>, double> dp;
char a[9][4][3];

bool read() {
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 4; ++j) {
            if(scanf("%s", a[i][j]) != 1) return false;
        }
    }
    return true;
}

double dfs(vector<int>& top, int k) {
    if(k == 0) return 1;
    if(dp.count(top)) return dp[top];
    double sum = 0; int cnt = 0;

    for(int i = 0; i < 9; ++i) {
        if(top[i] == 0) continue;
        for(int j = i + 1; j < 9; ++j) {
            if(top[j] == 0) continue;
            if(a[i][top[i] - 1][0] == a[j][top[j] - 1][0]) {
                ++cnt;
                --top[i]; --top[j];
                sum += dfs(top, k - 2);
                ++top[i]; ++top[j];
            }
        }
    }
    if(cnt == 0) return dp[top] = 0;
    return dp[top] = sum / cnt;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(read()) {
        dp.clear();
        vector<int> top(9, 4);
        printf("%.6f\n", dfs(top, 36));
    }
    return 0;
}
