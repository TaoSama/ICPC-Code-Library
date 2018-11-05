
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

vector<int> divisors[N];

void init() {
    for(int i = 1; i < N; ++i) {
        for(int j = i; j < N; j += i) {
            divisors[j].emplace_back(i);
        }
    }
}

long long C(int n, int m) {
    long long ans = 1;
    for(int i = 1; i <= m; ++i) {
        ans *= n - i + 1;
        ans /= i;
    }
    return ans;
}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    init();

    vector<tuple<int, int, int>> order;
    for(int i = 0; i < 8; ++i) {
        if(!(i >> 0 & 1)) continue;
        for(int j = 0; j < 8; ++j) {
            if(!(j >> 1 & 1)) continue;
            for(int k = 0; k < 8; ++k) {
                if(!(k >> 2 & 1)) continue;
                int a[3] = {i, j, k};
                sort(a, a + 3);
                order.emplace_back(a[0], a[1], a[2]);
            }
        }
    }
    sort(order.begin(), order.end());
    order.resize(unique(order.begin(), order.end()) - order.begin());

    // for(auto& p : order) cout << get<0>(p) << ' ' << get<1>(p) << ' ' << get<2>(p) << endl;

    int t; scanf("%d", &t);
    while(t--) {
        map<int, int> mp;
        int a, b, c; scanf("%d%d%d", &a, &b, &c);

        for(const auto& x : divisors[a]) mp[x] |= 1 << 0;
        for(const auto& x : divisors[b]) mp[x] |= 1 << 1;
        for(const auto& x : divisors[c]) mp[x] |= 1 << 2;

        long long sz[8] = {};
        for(const auto& p : mp) sz[p.second]++;

        long long ans = 0;
        for(const auto& p : order) {
            int a, b, c; tie(a, b, c) = p;
            if(a == b && b == c) ans += C(sz[a] + 2, 3);
            else if(a == b) ans += C(sz[a] + 1, 2) * sz[c];
            else if(b == c) ans += C(sz[b] + 1, 2) * sz[a];
            else ans += sz[a] * sz[b] * sz[c];
        }
        printf("%lld\n", ans);
        return 0;
    }
    return 0;
}
