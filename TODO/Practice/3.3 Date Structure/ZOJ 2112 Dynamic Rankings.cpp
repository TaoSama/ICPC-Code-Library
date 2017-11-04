//
//  Created by TaoSama on 2015-07-12
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
const int N = 5e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = N * 20;

int n, q, a[N], all[N << 1];
int x[10005], y[10005], z[10005];
int root[N << 1], sum[M << 1], ls[M << 1], rs[M << 1], sz;
int L[25], R[25], p[2];

void insert(int o, int v, int l, int r, int pre, int &rt) {
    rt = ++sz;
    sum[rt] = sum[pre] + v;
    if(l == r) return;
    ls[rt] = ls[pre]; rs[rt] = rs[pre];

    int m = l + r >> 1;
    if(o <= m) insert(o, v, l, m, ls[pre], ls[rt]);
    else insert(o, v, m + 1, r, rs[pre], rs[rt]);
}

void modify(int o, int v, int l, int r, int &rt) {
    if(!rt) rt = ++sz, sum[rt] = ls[rt] = rs[rt] = 0;
    sum[rt] += v;
    if(l == r) return;

    int m = l + r >> 1;
    if(o <= m) modify(o, v, l, m, ls[rt]);
    else modify(o, v, m + 1, r, rs[rt]);
}

//修改logn颗树 复杂度是log^2n
void add(int i, int o, int v, int l, int r) {
    for(; i <= n; i += i & -i) modify(o, v, l, r, root[i]);
}

//sum合到query里了 查询区间的根节点已经存在了L,R数组里
int query(int l, int r, int k) {
    if(l == r) return l;
    int m = l + r >> 1;

    int cnt = 0;
    for(int i = 1; i <= p[0]; ++i) cnt -= sum[ls[L[i]]];
    for(int i = 1; i <= p[1]; ++i) cnt += sum[ls[R[i]]];
    if(cnt >= k) {
        for(int i = 1; i <= p[0]; ++i) L[i] = ls[L[i]];
        for(int i = 1; i <= p[1]; ++i) R[i] = ls[R[i]];
        return query(l, m, k);
    } else {
        for(int i = 1; i <= p[0]; ++i) L[i] = rs[L[i]];
        for(int i = 1; i <= p[1]; ++i) R[i] = rs[R[i]];
        return query(m + 1, r, k - cnt);
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int T; scanf("%d", &T);
    while(T--) {
        sz = 0;
        memset(root, 0, sizeof root);
        scanf("%d%d", &n, &q);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            all[i] = a[i];
        }
        int cnt = n;
        for(int i = 1; i <= q; ++i) {
            char op[2]; scanf("%s%d%d", op, x + i, y + i);
            if(op[0] == 'Q') scanf("%d", z + i);
            else {
                z[i] = -1;
                all[++cnt] = y[i];
            }
        }
        sort(all + 1, all + cnt + 1);
        cnt = unique(all + 1, all + cnt + 1) - all - 1;

        //直接把离散化后的值映射到原数组 反正all都存了
        for(int i = 1; i <= n; ++i) {
            a[i] = lower_bound(all + 1, all + cnt + 1, a[i]) - all;
            insert(a[i], 1, 1, cnt, root[i == 1 ? 0 : i - 1 + n], root[i + n]);
        }
        for(int i = 1; i <= q; ++i) {
            if(~z[i]) {
                p[0] = p[1] = 1;
                L[1] = root[x[i] == 1 ? 0 : x[i] - 1 + n];
                R[1] = root[y[i] + n];
                //把要查询的区间的根节点存起来 利用前缀和
                for(int j = x[i] - 1; j; j -= j & -j) L[++p[0]] = root[j];
                for(int j = y[i]; j; j -= j & -j) R[++p[1]] = root[j];
                printf("%d\n", all[query(1, cnt, z[i])]);
            } else {
                add(x[i], a[x[i]], -1, 1, cnt);
                //将修改的结果映射到原数组 并更新前缀和
                a[x[i]] = lower_bound(all + 1, all + cnt + 1, y[i]) - all;
                add(x[i], a[x[i]], 1, 1, cnt);
            }
        }
    }
    return 0;
}
