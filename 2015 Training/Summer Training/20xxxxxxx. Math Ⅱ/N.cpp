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

vector<int> prime;

void gao() {
    bool vis[10005] = {};
    for(int i = 2; i <= 1e4; ++i) {
        if(!vis[i]) {
            prime.push_back(i);
            for(int j = i + i; j <= 1e4; j += i)
                vis[j] = 1;
        }
    }
}

int n;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    gao();
    while(scanf("%d", &n) == 1 && n) {
        int sum = 0, ans = 0;
        int l = 0, r = 0;
        while(l < prime.size() && prime[l] <= n) {
            sum += prime[r++];
            if(sum == n) {
                ++ans;
                sum += prime[r++];
            }
            while(sum > n) sum -= prime[l++];
            if(sum == n) ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}
