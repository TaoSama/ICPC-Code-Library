//
//  Created by TaoSama on 2015-09-28
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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

int n, ans[N];
int sum[N << 2];
typedef pair<int, int> P;
P a[N];

#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

void build(int l, int r, int rt) {
    sum[rt] = r - l + 1;
    if(l == r) return;
    int m = l + r >> 1;
    build(lson);
    build(rson);
}

void update(int k, int v, int l, int r, int rt) {
    --sum[rt];
    if(l == r) {
        ans[l] = v;
        return;
    }
    int m = l + r >> 1;
    if(sum[rt << 1] > k) update(k, v, lson);
    else update(k - sum[rt << 1], v, rson);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%d%d", &a[i].first, &a[i].second);
        sort(a + 1, a + 1 + n);
        build(root);
        bool ok = true;
        for(int i = 1; i <= n; ++i) {
            int k = a[i].second, v = a[i].first;
            k = min(k, n - i - k);
            if(k < 0) {
                ok = false;
                break;
            }
            update(k, v, root);
        }
        printf("Case #%d: ", ++kase);
        if(!ok) puts("impossible");
        else for(int i = 1; i <= n; ++i) printf("%d%c", ans[i], " \n"[i == n]);
    }
    return 0;
}
