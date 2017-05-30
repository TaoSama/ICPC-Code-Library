//
//  Created by TaoSama on 2017-05-11
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, p[N], a[N], b[N], m;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) scanf("%d", p + i);
        set<int> s1[4], s2[4];
        for(int i = 1; i <= 3; ++i) s1[i].insert(INF), s2[i].insert(INF);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            s1[a[i]].insert(p[i]);
        }
        for(int i = 1; i <= n; ++i) {
            scanf("%d", b + i);
            s2[b[i]].insert(p[i]);
        }
        scanf("%d", &m);
        for(int i = 1; i <= m; ++i) {
            int x; scanf("%d", &x);
            int to = min(*s1[x].begin(), *s2[x].begin());
            if(to == INF) printf("%d%c", -1, " \n"[i == m]);
            else {
                printf("%d%c", to, " \n"[i == m]);
                for(int j = 1; j <= 3; ++j) {
                    s1[j].erase(to);
                    s2[j].erase(to);
                }
            }
        }
    }

    return 0;
}
