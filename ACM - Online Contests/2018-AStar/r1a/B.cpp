//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1.5e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

void read(int &x){
    char ch = getchar();x = 0;
    for (; ch < '0' || ch > '9'; ch = getchar());
    for (; ch >='0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}

struct Deque {
    vector<int> v[2];
    int f[2];
    void add(int val, int d) {
        v[d].push_back(val);
    }
    int del(int d) {
        int ret = -1;
        if(d) {
           if(f[1] < v[1].size()) {
               ret = v[1].back();
               v[1].pop_back();
           }
           else if(f[0] < v[0].size()) {
               ret = v[0][f[0]];
               f[0]++;
           }
        }
        else {
           if(f[0] < v[0].size()) {
               ret = v[0].back();
               v[0].pop_back();
           }
           else if(f[1] < v[1].size()) {
               ret = v[1][f[1]];
               f[1]++;
           }
        }
        return ret;
    }
    void clear() {
        f[0] = f[1] = 0;
        vector<int>().swap(v[0]);
        vector<int>().swap(v[1]);
    }
} q[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, q;
    while(scanf("%d%d", &n, &q) == 2) {
        for(int i = 1; i <= q; ++i) {
            // for(int j = 1; j <= n; ++j) {
                // printf("%d: ", j);
                // for(int x : ::q[j]) printf("%d ", x);
                // puts("");
            // }
            int op, u, v, val;
            read(op); read(u); read(v); 
            if(op == 1) {
                read(val);
                ::q[u].add(val, v);
            }
            else if(op == 2) {
                int ans = ::q[u].del(v);
                printf("%d\n", ans);
            }
            else {
                read(val);
                int cur, ok = 0;
                while((cur=::q[v].del(val)) != -1) {
                    ::q[u].add(cur, 1);
                    ok = 1;
                }
                if(ok == 1) ::q[v].clear();
            }
        }
        for(int i = 1; i <= n; ++i) ::q[i].clear();
    }
    return 0;
}

