//
//  Created by TaoSama on 2017-04-22
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, x, y;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d%d", &n, &m, &x, &y);
        vector<pair<int, int>> va, vb;
        for(int i = 0; i < x; ++i) {
            int l, r; scanf("%d%d", &l, &r);
            va.push_back({l, r});
        }
        for(int i = 0; i < y; ++i) {
            int l, r; scanf("%d%d", &l, &r);
            vb.push_back({l, r});
        }
        vector<pair<int, int>> vc;
        for(auto& a : va) {
            for(auto& b : vb) {
                int ml = max(a.first, b.first);
                int mr = min(a.second, b.second);
                if(ml <= mr) vc.push_back({ml, mr});
            }
        }

        vector<pair<int, int>> ans;
        for(auto& c : vc) {
            if(!ans.size()) ans.push_back(c);
            else {
                if(ans.back().second + 1 == c.first) {
                    pair<int, int> newOne = {ans.back().first, c.second};
                    ans.pop_back();
                    ans.push_back(newOne);
                } else ans.push_back(c);
            }
        }

        long long tot = 0;
        for(auto& c : ans) {
            int l = c.second - c.first + 1 - m + 1;
            tot += max(0, l);
        }
        printf("%lld\n", tot);
    }

    return 0;
}
