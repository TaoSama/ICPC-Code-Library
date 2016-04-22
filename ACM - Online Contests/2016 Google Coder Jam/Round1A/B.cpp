//
//  Created by TaoSama on 2016-04-16
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>
#include <bitset>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 100 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;

int main() {
#ifdef LOCAL
    freopen("B-large-practice.in", "r", stdin);
    freopen("B-large-practice.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        map<int, int> mp;
        for(int i = 0; i < 2 * n - 1; ++i) {
            for(int j = 0; j < n; ++j) {
                int x; scanf("%d", &x);
                mp[x]++;
            }
        }
        vector<int> ans;
        for(auto p : mp)
            if(p.second & 1) ans.push_back(p.first);
        sort(ans.begin(), ans.end());

        static int kase = 0;
        printf("Case #%d:", ++kase);
        for(int x : ans) printf(" %d", x);
        puts("");
    }

    return 0;
}
