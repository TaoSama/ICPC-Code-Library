//
//  Created by TaoSama on 2015-10-21
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
#include <climits>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef unsigned long long ULL;

ULL dp[22][59055]; //3^10 = 59049
int digit[22], sta[10], vis[22][59055], kase;
//0 for none, 1 for odd, 2 for even

int encode() {
    int s = 0;
    for(int i = 0; i < 10; ++i) s = s * 3 + sta[i];
    return s;
}

void decode(int s) {
    for(int i = 9; ~i; --i, s /= 3) sta[i] = s % 3;
}

void print() {
    for(int i = 0; i < 10; ++i) cout << sta[i] << ' '; cout << endl;
}

bool check(int s) {
    decode(s);
    for(int i = 0; i < 10; ++i) {
        if((i & 1) && sta[i] == 1) return false;
        if(!(i & 1) && sta[i] == 2) return false;
    }
    return true;
}

int trans(int s, int d) {
    decode(s);
    if(sta[d] == 0) sta[d] = 1;
    else sta[d] = 3 - sta[d];
    return encode();
}

ULL dfs(int i, int s, bool first, bool e) {
    if(!i) return check(s);
    if(!e && vis[i][s] == kase) return dp[i][s];
    int to = e ? digit[i] : 9;
    ULL ret = 0;
    for(int d = 0; d <= to; ++d)
        ret += dfs(i - 1, first && !d ? s : trans(s, d),
                   first && !d, e && d == to);
    if(!e) vis[i][s] = kase, dp[i][s] = ret;
    return ret;
}

ULL calc(ULL x) {
    int cnt = 0;
    for(; x; x /= 10) digit[++cnt] = x % 10;
    return dfs(cnt, 0, 1, 1);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        ULL l, r; scanf("%llu%llu", &l, &r);
        ++kase;
        printf("%llu\n", calc(r) - calc(l - 1));
    }
    return 0;
}
