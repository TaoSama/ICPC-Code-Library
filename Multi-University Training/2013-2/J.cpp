//
//  Created by TaoSama on 2016-03-01
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, w;
int r[35], tim[35], num[35], cut[35][15];

int ans, vis[205];
vector<int> tmp, path;

void dfs(int p, int cnt, int used, int lst) {
    if(cnt + (m - used) / 3 <= ans ||
            cnt + (n - p + 1) <= ans) return;

//    printf("p: %d cnt: %d used: %d lst: %d\n",
//           p, cnt, used, lst);
    if(p == n + 1) {
        ans = max(ans, cnt);
        path = tmp;
        return;
    }


    int cur = r[p];
    if(!lst || tim[cur] - tim[lst] <= w) {
        int cc = 0;
        for(int i = 1; i <= num[cur]; ++i) {
            int t = cut[cur][i];
            cc += !vis[t];
            ++vis[t];
        }
        tmp.push_back(cur);
        if(cc >= 3) dfs(p + 1, cnt + 1, used + cc, cur);
        tmp.pop_back();
        for(int i = 1; i <= num[cur]; ++i) {
            int t = cut[cur][i];
            --vis[t];
        }
    }
    dfs(p + 1, cnt, used, lst);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &m, &w);
        for(int i = 1; i <= n; ++i) {
            r[i] = i;
            scanf("%d%d", num + i, tim + i);
            for(int j = 1; j <= num[i]; ++j) scanf("%d", cut[i] + j);
        }
        sort(r + 1, r + 1 + n, [](int x, int y) {
            return tim[x] < tim[y];
        });
        ans = 0;
        dfs(1, 0, 0, 0);
        printf("%d\n", ans);
        sort(path.begin(), path.end());
        for(int i = 0; i < path.size(); ++i)
            printf("%d%c", path[i], " \n"[i == path.size() - 1]);
    }
    return 0;
}
