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

int n;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        map<pair<int, int>, int> mp;
        vector<vector<int>> ans;
        ans.reserve(n);
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            auto iter = mp.upper_bound({x, INF});
            if(iter != mp.begin()) {
                --iter;
                int idx = iter->first.second;
                ans[idx].push_back(i);
                mp[ {x, idx}] += 2;
                if(--iter->second == 0) mp.erase(iter);
            } else {
                ans.push_back(vector<int>(1, i));
                mp[ {x, ans.size() - 1}] += 2;
            }
        }
        printf("%d\n", ans.size());
        for(auto& v : ans) {
            printf("%d ", v.size());
            for(int i = 0; i < v.size(); ++i)
                printf("%d%c", v[i], " \n"[i + 1 == v.size()]);
        }
    }

    return 0;
}
