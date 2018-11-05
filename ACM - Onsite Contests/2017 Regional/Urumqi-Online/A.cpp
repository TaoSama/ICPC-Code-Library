
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

bitset<100> monkey[N];
bitset<100> place[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; scanf("%d", &t);
    while(t--) {
        int n, m; scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i) monkey[i].reset();
        for(int i = 1; i <= m; ++i) place[i].reset();
        for(int i = 1; i <= n; ++i) {
            int x, y; scanf("%d%d", &x, &y);
            monkey[x][y] = 1;
        }
        for(int i = 1; i <= m; ++i) {
            int x, y; scanf("%d%d", &x, &y);
            place[y][x] = 1;
        }

        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if((monkey[i] & place[j]).count()) {
                    printf("%d %d\n", i, j);
                }
            }
        }
        puts("");
    }
    return 0;
}
