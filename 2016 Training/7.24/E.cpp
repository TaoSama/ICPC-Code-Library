//
//  Created by TaoSama on 2016-07-24
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

int n, a[N], b[N];

void solve(vector<int>& ans, bool rev) {
    map<int, int> mp;
    int sum = 0;
    for(int i = 1; i <= n; ++i) {
        sum += a[i] - b[i + rev];
        ++mp[sum];
    }

    int last = 0;
    for(auto& p : mp) {
        int tmp = p.second;
        p.second += last;
        last = tmp;
    }

    int delta = 0;
    for(int i = 1; i <= n; ++i) {
        auto iter = mp.lower_bound(delta);
        if(iter == mp.begin()) ans.push_back(rev ? n - i + 1 : i);
        delta += a[i] - b[i + rev];
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        for(int i = 1; i <= n; ++i) scanf("%d", b + i);

        vector<int> ans;

        solve(ans, 0);

        reverse(a + 1, a + 1 + n);
        reverse(b + 1, b + 1 + n);
        b[n + 1] = b[1];

        solve(ans, 1);

        sort(ans.begin(), ans.end());
        ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
        printf("%d\n", ans.size());
        for(int i = 0; i < ans.size(); ++i)
            printf("%d%c", ans[i], " \n"[i == ans.size() - 1]);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
