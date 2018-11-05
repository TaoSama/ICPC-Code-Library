
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;



int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, A;
    while(scanf("%d%d", &n, &A) == 2){
        vector<int> c(n), pre(n);
        map<int, int> cnt;
        bool canInsert = true;
        for(int i = 0; i < n; ++i){
            scanf("%d", &c[i]);
            if(c[i] != A && canInsert) cnt[c[i]] = 0;
            else canInsert = false;
            pre[i] = (i == 0 ? 0 : pre[i - 1]) + (c[i] == A);
        }
    //  for(int i = 0; i < n; ++i) printf("%d%c", pre[i], " \n"[i + 1 == n]);
        set<pair<int, int>> s;
        for(int i = 0; i < n; ++i){
            int x = c[i];
            if(cnt.count(x)){
                s.erase({-cnt[x], x});
                ++cnt[x];
                s.insert({-cnt[x], x});
            }
            auto iter = s.upper_bound({-pre[i], INF});
            for(; iter != s.end(); iter = s.erase(iter)){
                cnt.erase(iter->second);
            }
        }
        if(s.size()) printf("%d\n", s.begin()->second);
        else puts("-1");
    }
    return 0;
}
