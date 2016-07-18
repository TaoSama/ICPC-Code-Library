//
//  Created by TaoSama on 2016-07-10
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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

int A[55][55];
bool mark[55][55];
struct node {
    int x, y;
    bool operator <(const node& a)const {
        return A[x][y] > A[a.x][a.y];
    }
};
int rx[] = {0, 1, 0, -1};
int ry[] = {1, 0, -1, 0};
int n, m, ans;
priority_queue<node> Q;
bool check(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}
void dfs(int x, int y) {
    mark[x][y] = 1;
    for(int j = 0; j < 4; j++) {
        int x1 = x + rx[j], y1 = y + ry[j];
        if(!check(x1, y1) || mark[x1][y1]) continue;
        if(A[x1][y1] < A[x][y]) {
            //printf("%d %d %d %d\n",x,y,x1,y1);
            ans += A[x][y] - A[x1][y1];
            A[x1][y1] = A[x][y];
            dfs(x1, y1);
        } else {
            Q.push({x1, y1});
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    int t; scanf("%d", &t);
    while(t--) {
        memset(mark, 0, sizeof(mark));
        ans = 0;
        scanf("%d%d", &n, &m);
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= m; k++) {
                scanf("%d", &A[j][k]);
            }
        }
        while(!Q.empty()) Q.pop();
        for(int j = 1; j <= n; j++) Q.push({j, 1}), Q.push({j, m});
        for(int j = 2; j < m; j++) Q.push({1, j}), Q.push({n, j});
        while(!Q.empty()) {
            node now = Q.top(); Q.pop();
            //printf("%d %d\n",now.x,now.y);
            dfs(now.x, now.y);
        }
        static int kase = 0;
        printf("Case #%d: %d\n", ++kase, ans);
    }

#ifdef LOCAL
//    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
