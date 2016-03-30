//
//  Created by TaoSama on 2015-12-14
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
bool dp[1005][4];

vector<int> num;
void gao() {
    int sum = 0;
    num.push_back(0);
    for(int i = 1; i <= 1000; ++i) {
        sum += i;
        if(sum > 1000) break;
        num.push_back(sum);
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    gao();
    while(t--) {
        scanf("%d", &n);
        memset(dp, false, sizeof dp);
        dp[0][0] = true;
        for(int i = 1; i < num.size(); ++i)
            for(int j = num[i]; j <= n; ++j)
                for(int k = 1; k <= 3; ++k)
                    dp[j][k] |= dp[j - num[i]][k - 1];
        printf("%d\n", dp[n][3]);
    }
    return 0;
}
