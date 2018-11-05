
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k;
pair<pair<int, int>, int> a[N];
int col[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; ++i) {
            pair<int, int> tmp;
            scanf("%d%d", &tmp.first, &tmp.second);
            a[i] = {tmp, i};
        }
        if (n < k) {
            puts("-1");
            continue;
        }
        sort(a + 1, a + 1 + n);
        priority_queue<int> colors;
        priority_queue<pair<int, int>> rights;
        for (int i = 1; i <= k; ++i) colors.push(-i);
        int right = 0;
        long long ans = 0;
        for (int i = 1; i <= n; ++i) {
            while(rights.size() && -rights.top().first <= right) {
                colors.push(-col[rights.top().second]);
                rights.pop();
            }
            int l, r, id = a[i].second; tie(l, r) = a[i].first;
            l = max(l, right + 1);
            col[id] = -colors.top(); colors.pop();
            rights.push({-r, id});
            if (colors.empty()) {
                ans += -rights.top().first - l + 1;
                right = -rights.top().first; 
            }
        }
        printf("%lld\n", ans);
        for (int i = 1; i <= n; ++i) printf("%d%c", col[i], " \n"[i == n]);
    }
    return 0;
}
