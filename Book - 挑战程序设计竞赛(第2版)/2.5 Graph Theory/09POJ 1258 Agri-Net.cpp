//
//  POJ 1258  Agri-Net
//
//  Created by TaoSama on 2015-03-21
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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
#define CLR(x,y) memset(x, y, sizeof(x))

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, a[105][105], minCost[105];
bool used[105];
typedef pair<int, int> Sta;

int prim() {
    int ret = 0;
    memset(minCost, 0x3f, sizeof minCost);
    memset(used, false, sizeof used);
    priority_queue<Sta, vector<Sta>, greater<Sta> > pq;
    pq.push(Sta(0, 1)); minCost[1] = 0;
    while(!pq.empty()) {
        Sta p = pq.top(); pq.pop();
        int u = p.second;
        if(used[u] || p.first > minCost[u]) continue;
        used[u] = true; ret += minCost[u];
        for(int i = 1; i <= n; ++i) {
            if(minCost[i] > a[u][i]) {
                minCost[i] = a[u][i];
                pq.push(Sta(minCost[i], i));
            }
        }
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                scanf("%d", &a[i][j]);

        printf("%d\n", prim());
    }
    return 0;
}
