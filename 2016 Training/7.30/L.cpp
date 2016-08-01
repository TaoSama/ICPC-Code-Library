//
//  Created by TaoSama on 2016-07-30
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
const int N = 200 * 200 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef set<int> MySet;
int n;
MySet s[N];
vector<int> G[N];
bool vis[N];

bool haveOrigin(MySet& s) {
    for(auto x : s) if(!vis[x]) return true;
    return false;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        set<MySet> ans;
        memset(vis, 0, sizeof vis);
        for(int i = 1; i <= 200; ++i) G[i].clear();

        int m = n * (n - 1) / 2;
        for(int i = 1; i <= m; ++i) {
            int k; scanf("%d", &k);
            s[i].clear();
            while(k--) {
                int x; scanf("%d", &x);
                s[i].insert(x);
                vis[x] = true;
                G[x].push_back(i);
            }
        }
        if(m == 1) {
            printf("1 %d\n", *s[1].begin());
            s[1].erase(s[1].begin());
            printf("%d", s[1].size());
            for(auto x : s[1]) printf(" %d", x);
            puts("");
            continue;
        }
        for(int i = 1; i <= 200; ++i) {
            if(!vis[i]) continue;
            int a = G[i][0], b = G[i][1];
            MySet origin;
            set_intersection(s[a].begin(), s[a].end(), s[b].begin(), s[b].end(),
                             inserter(origin, origin.begin()));
            if(origin.size()) ans.insert(origin);
        }
        if(ans.size() != n) printf("%d\n", 1 / 0);
        for(auto s : ans) {
            printf("%d", s.size());
            for(auto x : s) printf(" %d", x);
            puts("");
        }
    }

    return 0;
}
