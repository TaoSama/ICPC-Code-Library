//
//  Created by TaoSama on 2017-04-16
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, no[N];
// exgcd
typedef long long LL;
LL exgcd(LL a, LL b, LL& x, LL& y) {
    LL d = a;
    if(!b) x = 1, y = 0;
    else {
        d = exgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    return d;
}
LL solve(LL a, LL b, LL c) {
    LL x, y, g = exgcd(a, b, x, y);
    if(c % g) return -1;
    x *= c / g;
    x = (x % b + b) % (b / g);
    return x;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
//    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        memset(no, 0, sizeof no);
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            no[x] = 1;
        }
        map<int, vector<int>> gcd;
        for(int i = 1; i < m; ++i)
            if(!no[i]) gcd[__gcd(i, m)].push_back(i);
        if(!no[0]) gcd[m].push_back(0);

        map<int, int> f, pre;
        pair<int, int> last = {0, 0};
        for(auto& p : gcd) {
            int y = p.first, sz = p.second.size();
            f[y] = pre[y] = 0;
            for(auto& np : gcd) {
                int x = np.first;
                if(y % x == 0) {
                    if(f[y] < f[x]) {
                        f[y] = f[x];
                        pre[y] = x;
                    }
                }
            }
            f[y] += sz;
            last = max(last, {f[y], y});
        }

        vector<int> ans;
        for(int u = last.second; u; u = pre[u])
            for(int x : gcd[u]) ans.push_back(x);
        reverse(ans.begin(), ans.end());

        printf("%d\n", ans.size());
        int pp = 1;
        for(int y : ans) {
            int mul = y ? solve(pp, m, y) : 0;
            printf("%d ", mul);
            pp = 1LL * pp * mul % m;
        }
        puts("");
    }

    return 0;
}
