//
//  Created by TaoSama on 2015-09-11
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

bool vis[1005];

void gao() {
    for(int i = 2; i <= 1000; ++i) {
        if(!vis[i]) {
            for(int j = i + i; j <= 1000; j += i) vis[j] = true;
        }
    }
}

long long __lcm(long long a, long long b) {
    return a / __gcd(a, b) * b;
}

int n;
bool have[1005];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    gao();
    while(scanf("%d", &n) == 1) {
        if(n == 1) {
            puts("0\n");
            continue;
        }
        vector<int> ans;
        memset(have, false, sizeof have);
        for(int i = 2; i <= n; ++i) {
            if(!vis[i]) ans.push_back(i), have[i] = true;
            else {
                long long lcm = 1;
                for(int j = 0; j < ans.size(); ++j)
                    if(i % ans[j] == 0) lcm = __lcm(lcm, ans[j]);
                if(have[lcm]) {
                    ans.push_back(i);
                    have[i] = true;
                }
            }
        }
        printf("%d\n", ans.size());
        for(int i = 0; i < ans.size(); ++i)
            printf("%d%c", ans[i], " \n"[i == ans.size() - 1]);
    }
    return 0;
}
