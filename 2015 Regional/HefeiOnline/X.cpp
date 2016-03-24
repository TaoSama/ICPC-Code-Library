//
//  Created by Running Photon on 2015-09-27
//  Copyright (c) 2015 Running Photon. All rights reserved.
//
//
//#pragma comment(linker, "/STACK:102400000,102400000")
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
#include <sstream>
#include <set>
#include <vector>
#include <stack>
#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x,begin())
#define ll long long
#define CLR(x) memset(x, 0, sizeof x)
#define MAXN 9999
#define MAXSIZE 10
#define DLEN 4
using namespace std;
const int inf = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int maxn = 1e5 + 10;
const int maxv = 1e3 + 10;
const double eps = 1e-9;


inline int read() {
    char c = getchar();
    int f = 1;
    while(!isdigit(c)) {
        if(c == '-') f = -1;
        c = getchar();
    }
    int x = 0;
    while(isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}
int t, n, m;
int a[maxn];
int tree[maxn << 2];
vector <int> compress;
int g[maxn], h[maxn], f[maxn];
void updata(int id, int l, int r, int pos, int x) {
    if(l > r || l > pos || r < pos) return;
    if(l == r) {
        tree[id] = max(tree[id], x); //改。
        return;
    }
    int mid = (l + r) >> 1;
    if(mid < pos) updata(id << 1 | 1, mid + 1, r, pos, x); //改。
    else updata(id << 1, l, mid, pos, x);
    tree[id] = max(tree[id << 1], tree[id << 1 | 1]);
}
int query(int id, int l, int r, int L, int R) {
    if(l <= L && r >= R) return tree[id];
    int mid = (L + R) >> 1;
    int ret = 0;
    if(l <= mid) ret = query(id << 1, l, r, L, mid);
    if(r > mid) ret = max(ret, query(id << 1 | 1, l, r, mid + 1, R));
    return ret;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    t = read();
    int cas = 0;
    while(t--) {
        printf("Case #%d: ", ++cas);
        compress.clear();
        n = read(), m = read();
        for(int i = 0; i < n; i++) {
            a[i] = read();
            compress.push_back(a[i]);
        }
        CLR(tree);
        sort(ALL(compress));
        compress.resize(unique(ALL(compress)) - compress.begin());
        int tot = compress.size();

        memset(h, 0x3f, sizeof h);
        a[n] = inf, g[n] = 0;
        for(int i = 0; i < n; ++i) {
            int k = lower_bound(h, h + n, a[i]) - h + 1;
            f[i] = k;
            h[k - 1] = a[i];  //改。
        }

        memset(h, 0x3f, sizeof h);
        for(int i = n - 1; i >= 0; --i) {
            int k = lower_bound(h, h + n, -a[i]) - h + 1;
            g[i] = k;
            h[k - 1] = -a[i]; //改。
        }

        int ans = 0;
        for(int i = m; i <= n; i++) {
            int pos = lower_bound(ALL(compress), a[i]) - compress.begin() + 1;
//            printf("%d %d\n",  query(1, 0, pos - 1, 0, tot), g[i]);
            ans = max(ans, query(1, 0, pos - 1, 0, tot) + g[i]);
//            printf("pos = %d %d\n", pos, ans);
            pos = lower_bound(ALL(compress), a[i - m]) - compress.begin() + 1;
//            printf("pos2 = %d\n", pos);
            updata(1, 0, tot, pos, f[i - m]);
        }
        printf("%d\n", ans);
    }

    return 0;
}
