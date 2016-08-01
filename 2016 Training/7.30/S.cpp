//
//  Created by TaoSama on 2016-07-30
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

int n;
typedef long long LL;
LL sum[N << 2][5], cnt[N << 2];

void up(int rt) {
    int ls = rt << 1, rs = ls | 1;
    cnt[rt] = cnt[ls] + cnt[rs];
    int offset = cnt[ls];
    for(int i = 0; i < 5; ++i) sum[rt][i] = sum[ls][i];
    for(int i = 0; i < 5; ++i) sum[rt][(offset + i) % 5] += sum[rs][i];
}

vector<int> xs;
void update(int o, int v, int l, int r, int rt) {
    if(l == r) {
        cnt[rt] = v;
        sum[rt][0] = v * xs[l - 1];
        return;
    }
    int m = l + r >> 1;
    if(o <= m) update(o, v, l, m, rt << 1);
    else update(o, v, m + 1, r, rt << 1 | 1);
    up(rt);
}

int op[N], x[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        char buf[10]; scanf("%s", buf);
        if(*buf != 's') {
            scanf("%d", x + i);
            xs.push_back(x[i]);
            op[i] = *buf == 'a';
        } else op[i] = 2;
    }
    sort(xs.begin(), xs.end());
    xs.resize(unique(xs.begin(), xs.end()) - xs.begin());

    for(int i = 1; i <= n; ++i) {
        if(op[i] != 2) {
            x[i] = lower_bound(xs.begin(), xs.end(), x[i]) - xs.begin() + 1;
            update(x[i], op[i], 1, xs.size(), 1);
        } else printf("%I64d\n", sum[1][2]);
    }

    return 0;
}
