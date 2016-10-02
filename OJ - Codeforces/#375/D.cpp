//
//  Created by TaoSama on 2016-10-01
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

int n, a[N];

bool update(int u, map<int, int>& mp) {
    if(u == 1) return false;
    if(mp[u / 2]) {
        if(!update(u / 2, mp)) return false;
    }
    if(--mp[u] == 0) mp.erase(u);
    u /= 2;
    ++mp[u];
    return true;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);

        map<int, int> mp;
        priority_queue<int> q;
        for(int i = 1; i <= n; ++i) {
            q.push(a[i]);
            ++mp[a[i]];
        }

        while(true) {
            int u = mp.rbegin()->first;
            if(!update(u, mp)) break;
        }

        vector<int> ans;
        for(auto p : mp) {
            int x, y; tie(x, y) = p;
            while(y--) ans.push_back(x);
        }
        for(int i = 1; i <= n; ++i) printf("%d%c", ans[i - 1], " \n"[i == n]);

    }

    return 0;
}
