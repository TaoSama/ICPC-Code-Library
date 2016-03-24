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
const int N = 1e6 + 3e5, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

bool vis[N];
pair<int, int> prime[N];

void gao() {
    for(int i = 2; i <= 1299709; ++i) {
        if(!vis[i])
            for(int j = i + i; j <= 1299709; j += i)
                vis[j] = 1;
    }
    int last, pre;
    for(int i = 2; i <= 1299709; ++i) {
        if(!vis[i]) {
            last = i;
            continue;
        }
        prime[i].first = last;
    }
    for(int i = 1299709; i > 2; --i) {
        if(!vis[i]) {
            pre = i;
            continue;
        }
        prime[i].second = pre;
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
        int ans = prime[n].second - prime[n].first;
        printf("%d\n", ans);
    }
    return 0;
}
