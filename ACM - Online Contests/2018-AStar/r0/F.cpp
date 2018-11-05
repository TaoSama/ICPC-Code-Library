
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
int u[N], v[N], w[N];
char c[N][2];
int r[N];

int p[N];
int find(int x) {
    return p[x] = p[x] == x ? x : find(p[x]);
}

bool cmp(int x, int y) { return w[x] < w[y];}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= m; ++i) scanf("%d%d%d%s", u + i, v + i, w + i, c[i]);
        for(int i = 1; i <= m; ++i) r[i] = i;
        sort(r + 1, r + 1 + m, cmp);
        static int kase = 0;
        printf("Case #%d:\n", ++kase);

        for(int x = 1; x <= m; ++x) {
            if(x < n - 1) {
                puts("-1");
                continue;
            }

            int ans = INF;
            {
                int cur = 0;
                int cnt = 0, need = x - n + 1;
                for(int i = 1; i <= n; ++i) p[i] = i;
                for(int i = 1; i <= m; ++i) {
                    int j = r[i];
                    int l = find(u[j]), r = find(v[j]);
                    if(*c[j] == 'R' || l == r) {
                        if(need > 0) {
                            cur += w[j];
                            need--;
                        }
                    }
                    else {
                        if(cnt < n - 1) {
                            cur += w[j];
                            p[l] = r;
                            cnt++;
                        }
                    }
                }
                if(cnt == n - 1) ans = min(ans, cur);
            }
            {
                int cur = 0;
                int cnt = 0, need = x - n + 1;
                for(int i = 1; i <= n; ++i) p[i] = i;
                for(int i = 1; i <= m; ++i) {
                    int j = r[i];
                    int l = find(u[j]), r = find(v[j]);
                    if(*c[j] == 'B' || l == r) {
                        if(need > 0) {
                            cur += w[j];
                            need--;
                        }
                    }
                    else {
                        if(cnt < n - 1) {
                            cur += w[j];
                            p[l] = r;
                            cnt++;
                        }
                    }
                }
                if(cnt == n - 1) ans = min(ans, cur);
            }
            if(ans == INF) ans = -1;
            printf("%d\n", ans);
        }

    }
    return 0;
}
