
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

long long fact[20], ans;
int cnt[10];

void dfs(int cur, int first, int tot, long long div) {
    if (cur == 10) {
        ans += fact[tot] / div;
        return;
    }
    if (cnt[cur] == 0) {
        dfs(cur + 1, first, tot, div);
    }
    else {
        for (int i = cur == first ? 0 : 1; i <= cnt[cur]; ++i) {
            dfs(cur + 1, first, tot + i, div * fact[i]);
        }
    }
}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    fact[0] = 1;
    for(int i = 1; i < 20; ++i) fact[i] = fact[i - 1] * i;
    string s;
    while(cin >> s) {
        memset(cnt, 0, sizeof cnt);
        for(const auto& c : s) cnt[c - '0']++;          
        ans = 0;
        for(int i = 1; i < 10; ++i) {
            if(cnt[i]) {
                cnt[i] --;
                dfs(0, i, 0, 1);
                cnt[i] ++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
