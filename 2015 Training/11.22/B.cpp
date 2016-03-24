//
//  Created by TaoSama on 2015-11-24
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

int n, a[20], dp[7][1 << 20];

int dfs(int left, int s) {
    int &ret = dp[left][s];
    if(!s) return 0;
    if(~ret) return ret;
    ret = INF;
    for(int i = 0; i < n; ++i) {
        if(!(s >> i & 1)) continue;
        if(a[i] > left)
            ret = min(ret, dfs(a[i] - left - 1, s ^ (1 << i)) + a[i] - left);
        else
            ret = min(ret, dfs(0, s ^ (1 << i)) + 1);
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) scanf("%d", a + i);
        memset(dp, -1, sizeof dp);
        printf("%d\n", dfs(0, (1 << n) - 1));
    }
    return 0;
}
