//
//  Created by TaoSama on 2017-04-26
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
int f[2][1 << 16];
int attack[16], stopped[16], go;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d", &n, &m);
    int a, b, c; scanf("%d%d%d", &a, &b, &c);
    while(a--) {
        int x, y; scanf("%d%d", &x, &y);
        attack[x] |= 1 << y;
    }
    while(b--) {
        int x, y; scanf("%d%d", &x, &y);
        stopped[y] |= 1 << x;
    }
    while(c--) {
        int x; scanf("%d", &x);
        go |= 1 << x;
    }

    int tot = (1 << n) - 1;
    queue<pair<int, int>> q;
    q.push({0, tot});
    memset(f, -1, sizeof f);
    f[0][tot] = 0;
    while(q.size()) {
        int side, s; tie(side, s) = q.front(); q.pop();
        for(int s0 = s; s0; s0 = (s0 - 1) & s) {
            static auto safe = [&](int s) {
                for(int i = 0; i < n; ++i)
                    if((s >> i & 1) && (s & attack[i]) && !(s & stopped[i])) return false;
                return true;
            };
            if(__builtin_popcount(s0) > m || !(s0 & go)) continue;
            if(!safe(s ^ s0) || !safe(s0) || !safe(tot ^ s ^ s0)) continue;
            if(f[side ^ 1][tot ^ s | s0] == -1) {
                f[side ^ 1][tot ^ s | s0] = f[side][s] + 1;
                q.push({side ^ 1, tot ^ s | s0});
            }
        }
    }
    printf("%d\n", f[1][tot]);

    return 0;
}
