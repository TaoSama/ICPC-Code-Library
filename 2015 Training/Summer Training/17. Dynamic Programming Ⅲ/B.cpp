//
//  Created by TaoSama on 2015-08-11
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
#include <cassert>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[45][5];
int dp[45][45][45][45];

int dfs(vector<int> v, vector<int> s) {
    int &ret = dp[v[1]][v[2]][v[3]][v[4]];
    if(ret >= 0) return ret;

    if(s.size() == 5) return 0;
    ret = 0;
    for(int i = 1; i <= 4; ++i) {
        if(v[i] == n) continue; //can't take
        vector<int> vv(v), ss(s);
        int cur = a[++vv[i]][i], gain = 0;  //cur take
        for(int j = 0; j < ss.size(); ++j) { //check can gain
            if(cur == ss[j]) {
                gain = 1;
                ss.erase(ss.begin() + j);
                break;
            }
        }
        if(!gain) ss.push_back(cur);
        ret = max(ret, dfs(vv, ss) + gain);
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1 && n) {
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= 4; ++j)
                scanf("%d", &a[i][j]);

        memset(dp, -1, sizeof dp);
        printf("%d\n", dfs(vector<int>(5), vector<int>()));
    }
    return 0;
}
