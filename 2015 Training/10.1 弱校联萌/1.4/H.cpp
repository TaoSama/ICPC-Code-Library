//
//  Created by TaoSama on 2015-10-05
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
#include <stack>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

int n;
LL dp[35], x, y;
char op[10][5];

LL calc(int n) {
    LL ret = 0;
    int last = -1;
    stack<int> stk[3];
    for(int i = n; i; --i) stk[0].push(i);
    while(true) {
        for(int i = 1; i <= 6; ++i) {
            int s = op[i][0] - 'A', t = op[i][1] - 'A';
            if(stk[s].size() && stk[s].top() != last &&
                    (stk[t].empty() || stk[s].top() < stk[t].top())) {
                last = stk[s].top();
                stk[t].push(stk[s].top());
                stk[s].pop();
                ++ret;
                break;
            }
        }
        if(stk[1].size() == n || stk[2].size() == n) return ret;
    }
    return -1;
}

LL gao() {
    for(int i = 1; i <= 3; ++i)
        dp[i] = calc(i);
    x = (dp[2] - dp[3]) / (dp[1] - dp[2]);
    y = dp[2] - x * dp[1];
    for(int i = 4; i <= n; i++)
        dp[i] = x * dp[i - 1] + y;
    return dp[n];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= 6; ++i) scanf("%s", op[i]);
        printf("%lld\n", gao());
    }
    return 0;
}
