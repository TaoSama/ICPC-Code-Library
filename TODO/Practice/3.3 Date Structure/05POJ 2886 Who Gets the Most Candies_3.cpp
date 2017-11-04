//
//  Created by TaoSama on 2015-06-11
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 5e5 + 10;

typedef long long LL;

int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
map<LL, LL> mp, rmp; //divisors .. anti-prime
LL a[100], b[100], ct;

void dfs(int k, LL cur, LL cnt, int limit) {
    if(cur > N) return;
    if(!mp.count(cnt)) mp[cnt] = cur;
    else mp[cnt] = min(cur, mp[cnt]);
    for(int i = 1; i <= limit; ++i) {
        if(1.0 * cur * p[k] > N) break;
        dfs(k + 1, cur *= p[k], cnt * (i + 1), i);
    }
}

void init() {
    dfs(0, 1, 1, 60);
    map<LL, LL>::iterator i = mp.begin();
    for(; i != mp.end(); ++i) rmp.insert(make_pair(i->second, i->first));
    i = rmp.begin();
    for(; i != rmp.end(); ++i) {
        if(ct > 0 && i->second < b[ct - 1]) continue;
        a[ct] = i->first;
        b[ct++] = i->second;
    }
}

int n, k, v[N];
char name[N][10];

int sum[N * 3];

#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

void build(int l, int r, int rt){
    sum[rt] = r - l + 1;
    if(l == r) return;
    int m = l + r >> 1;
    build(lson);
    build(rson);
}

int query(int k, int l, int r, int rt){
    sum[rt]--;
    if(l == r) return l;
    int m = l + r >> 1;
    if(k <= sum[rt << 1]) return query(k, lson);
    else return query(k - sum[rt << 1], rson);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    init();
    while(scanf("%d%d", &n, &k) == 2) {
        build(root);
        for(int i = 1; i <= n; ++i) scanf("%s%d", name[i], v + i);

        int ans, idx = 0;
        while(a[idx] <= n && idx < ct) idx++;
        int cnt = a[idx - 1], Max = b[idx - 1]; //第cnt个就是最大的

        for(int i = 1; i <= cnt; ++i) {
            int mod = n - i;
            ans = query(k, root);
            if(mod == 0) break;
            if(v[ans] > 0) k = (k - 1 + v[ans]) % mod;
            else k = ((k - 1 + v[ans]) % mod + mod) % mod + 1;
            if(k == 0) k = mod;
        }
        printf("%s %d\n", name[ans], Max);
    }
    return 0;
}
