//
//  Created by TaoSama on 2015-08-15
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
int dp[20][1200]; //dp[i][j] take out i prime whose sum = j

vector<int> prime;
void gao() {
    bool vis[1200] = {};
    for(int i = 2; i <= 1120; ++i) {
        if(!vis[i]) {
            prime.push_back(i);
            for(int j = i + i; j <= 1120; j += i)
                vis[j] = 1;
        }
    }

    dp[0][0] = 1;
    for(int k = 0; k < prime.size(); ++k) {
        for(int i = 14; i >= 1; --i) {
            for(int j = 1120; j >= prime[k]; --j)
                dp[i][j] += dp[i - 1][j - prime[k]];
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    gao();
    while(scanf("%d%d", &n, &k) == 2 && (n || k)) {
        printf("%d\n", dp[k][n]);
    }
    return 0;
}
