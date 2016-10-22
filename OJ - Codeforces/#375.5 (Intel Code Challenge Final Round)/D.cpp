//
//  Created by TaoSama on 2016-10-08
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

int m;
char s[N];

struct SparseTable {
    static const int LOG = 20;
    int n;
    pair<char, int> f[LOG][N];
    void init(int _n, pair<char, int>* a) {
        n = _n;
        for(int i = 1; i <= n; ++i) f[0][i] = a[i];
        for(int i = 1; i < LOG; ++i)
            for(int j = 1; j + (1 << i) - 1 <= n; ++j)
                f[i][j] = min(f[i - 1][j], f[i - 1][j + (1 << i - 1)]);
    }
    pair<int, int> RMQ(int l, int r) {
        int k = 31 - __builtin_clz(r - l + 1);
        return min(f[k][l], f[k][r - (1 << k) + 1]);
    }
} st;

pair<char, int> a[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%s", &m, s + 1) == 2) {
        int n = strlen(s + 1);
        for(int i = 1; i <= n; ++i) {
            a[i] = {s[i], -i};
        }
        st.init(n, a);

        string ans;
        int l = 1, r = m;
        char maxC = 'a';
        vector<int> vis(n + 1, 0);
        while(true) {
            char c; int p;
            tie(c, p) = st.RMQ(l, r);
            p = -p;
            vis[p] = true;
            maxC = max(maxC, c);
            ans += c;
            if(p + m - 1 >= n) break;
            l = p + 1;
            r = min(l + m - 1, n);
//          printf("%c %d %d\n", c, l, r);
        }
        for(int i = 1; i <= n; ++i)
            if(!vis[i] && s[i] < maxC) ans += s[i];
        sort(ans.begin(), ans.end());

        cout << ans << endl;
    }

    return 0;
}
