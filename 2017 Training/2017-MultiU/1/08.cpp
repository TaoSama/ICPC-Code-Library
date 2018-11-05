
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;

unsigned x, y, z;
unsigned rng61() {
  unsigned t;
  x ^= x << 16;
  x ^= x >> 5;
  x ^= x << 1;
  t = x;
  x = y;
  y = z;
  z = t ^ x ^ y;
  return z;
}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(scanf("%d%d%u%u%u", &n, &m, &x, &y, &z) == 5){
        int nB = (1 << 17) + 5;
        vector<vector<unsigned>> blocks(nB);
        for(int i = 1; i <= n; ++i) {
            unsigned x = rng61();
            // printf("wh = %d %u ", x / B, x);
            blocks[x >> 23].push_back(x);
        }
        // puts("");
        // puts("done");

        vector<pair<int, int>> queries(m);
        for(int i = 0; i < m; ++i) {
            int x; scanf("%d", &x);
            queries[i].first = x;
            queries[i].second = i;
        }
        vector<unsigned> ans(m);
        sort(queries.begin(), queries.end());
        vector<int> sorted(nB, 0);
        int rk = 0, bidx = 0;
        int last = -1, lastId = -1;
        for(auto& p : queries){
            int x, id; tie(x, id) = p;
            if(x == last){
                ans[id] = ans[lastId];
                continue;
            }
            while(bidx < nB && static_cast<int>(rk + blocks[bidx].size()) <= x) rk += blocks[bidx++].size();
            int to = x - rk;     
            // printf("idx = %d rk = %d to = %d\n", bidx - 1, rk, to);
            nth_element(blocks[bidx].begin(), blocks[bidx].begin() + to, blocks[bidx].end());
            assert(bidx < nB);
            // if(!sorted[bidx]){
                // sort(blocks[bidx].begin(), blocks[bidx].end());
                // sorted[bidx] = true;
            // }
            ans[id] = blocks[bidx][to];
            last = x;
            lastId = id;
        }
        static int kase = 0;
        printf("Case #%d: ", ++kase);
        for(int i = 0; i < m; ++i){
            printf("%u%c", ans[i], " \n"[i + 1 == m]);
        }
    } 
    return 0;
}
