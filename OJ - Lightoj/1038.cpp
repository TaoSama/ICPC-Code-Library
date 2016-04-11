//
//  Created by TaoSama on 2015-11-13
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

int n;
bool vis[N];
double dp[N];

vector<int> fact(int n) {
    vector<int> divisor;
    for(int i = 2; i * i <= n; ++i) {
        if(n % i == 0) {
            divisor.push_back(i);
            int t = n / i;
            if(i != t) divisor.push_back(t);
        }
    }
    divisor.push_back(n);
    return divisor;
}

double dfs(int x) {
    double& ret = dp[x];
    if(x == 1) return 0;
    if(vis[x]) return ret;
    vis[x] = true;

    vector<int> divisor = fact(x);
    int n = divisor.size();
//  prln(x);
//  for(int i = 0; i < n; ++i) printf("%d ", divisor[i]); puts("");
    ret = 0;
    for(int i = 0; i < n; ++i) {
        ret += dfs(x / divisor[i]) + 1;
    }
    ret = (ret + 1) / n;
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    memset(vis, false, sizeof vis);
    while(t--) {
        scanf("%d", &n);
        printf("Case %d: %.12f\n", ++kase, dfs(n));
    }
    return 0;
}
