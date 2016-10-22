//
//  Created by TaoSama on 2016-10-05
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f;

inline int get(char c) {
    if(c == 'e') return 0;
    else if(c == 'a') return 1;
    else if(c == 's') return 2;
    return 3;
}

char s[N];
int pos[N], pre[N], last[N];

const int LOG = 20;
int f[LOG][N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%s", s + 1) == 1) {
        int n = strlen(s + 1);

        memset(pre, 0, sizeof pre);
        for(int i = 1; i <= n; ++i) {
            int c = get(s[i]);
            if(c) pre[i] = pos[c - 1];
            pos[c] = i;

            last[i] = last[i - 1];
            if(c == 3) {
                int e = i;
                for(int j = 0; j < 3; ++j) e = pre[e];
                last[i] = e;
            }
        }

        for(int i = 1; i <= n; ++i) f[0][i] = last[i];
        for(int i = 1; i < LOG; ++i)
            for(int j = 1; j <= n; ++j)
                f[i][j] = f[i - 1][f[i - 1][j]];

        int q; scanf("%d", &q);
        while(q--) {
            int l, r; scanf("%d%d", &l, &r);
            int ans = 0, t = r;
            for(int i = LOG - 1; ~i; --i) {
                if(f[i][t] >= l) {
                    ans |= 1 << i;
                    t = f[i][t] - 1;
                    if(!t) break;
                }
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}
