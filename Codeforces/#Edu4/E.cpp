//
//  Created by TaoSama on 2016-02-11
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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N];
int vis[N], id[N], ans[N];
vector<int> cycle[N];

bool cmp(const vector<int>& x, const vector<int>& y) {
    return x.size() < y.size();
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        int cnt = 0;
        memset(vis, false, sizeof vis);
        for(int i = 1; i <= n; ++i) {
            if(vis[i]) continue;
            int tmp = i;
            cycle[++cnt].clear();
            do {
                vis[tmp] = 1;
                cycle[cnt].push_back(tmp);
                tmp = a[tmp];
            } while(tmp != i);
        }
        sort(cycle + 1, cycle + 1 + cnt, cmp);

        bool ok = true;
        for(int i = 1; i <= cnt; ++i) {
            int sz = cycle[i].size();
            if(sz & 1) {
                for(int j = 0; j < sz; ++j)
                    id[2 * j % sz] = cycle[i][j];
                for(int j = 0; j < sz; ++j)
                    ans[id[j]] = id[(j + 1) % sz];
            } else if(i + 1 <= cnt && cycle[i + 1].size() == sz) {
                for(int j = 0, k = 0; j < sz; ++j) {
                    id[k++] = cycle[i][j];
                    id[k++] = cycle[i + 1][j];
                }
                sz <<= 1;
                for(int j = 0; j < sz; ++j)
                    ans[id[j]] = id[(j + 1) % sz];
                ++i;
            } else {
                ok = false;
                break;
            }
        }
        if(!ok) puts("-1");
        else {
            for(int i = 1; i <= n; ++i)
                printf("%d%c", ans[i], " \n"[i == n]);
        }
    }
    return 0;
}
