//
//  Created by TaoSama on 2015-09-30
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

int n, a[N];
char op[N][5];
vector<int> xs;

typedef long long LL;
int cnt[N << 2];
LL sum[N << 2][5];

#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

void push_up(int rt) {
    cnt[rt] = cnt[rt << 1] + cnt[rt << 1 | 1];
    int off = cnt[rt << 1];
    for(int i = 0; i < 5; ++i) sum[rt][i] = sum[rt << 1][i];
    for(int i = 0; i < 5; ++i) sum[rt][(i + off) % 5] += sum[rt << 1 | 1][i];
}

void update(int o, int v, int l, int r, int rt) {
    if(l == r) {
        cnt[rt] = v;
        sum[rt][1] = v * xs[l - 1];
        return;
    }
    int m = l + r >> 1;
    if(o <= m) update(o, v, lson);
    else update(o, v, rson);
    push_up(rt);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        xs.clear();
        for(int i = 1; i <= n; ++i) {
            scanf("%s", op[i]);
            if(*op[i] == 'a' || *op[i] == 'd') {
                scanf("%d", a + i);
                xs.push_back(a[i]);
            }
        }
        sort(xs.begin(), xs.end());
        xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
        memset(sum, 0, sizeof sum);
        memset(cnt, 0, sizeof cnt);
        for(int i = 1; i <= n; ++i) {
            if(*op[i] == 's') printf("%I64d\n", sum[1][3]);
            else {
                int o = lower_bound(xs.begin(), xs.end(), a[i]) - xs.begin() + 1;
                int v = *op[i] == 'a';
                update(o, v, 1, xs.size(), 1);
            }
        }
    }
    return 0;
}
