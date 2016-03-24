//
//  Created by TaoSama on 2016-02-24
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
#include <bitset>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 998244353;

int n, cnt;
char s[N];
int digit[N], f[N][N], ans;

void add(int& x, int y){
	if((x += y) >= MOD) x -= MOD;
}

struct BIT{
	int n, b[N][N];
	void init(int _n){
		n = _n;
		memset(b, 0, sizeof b);
	}
	void add(int x, int y, int v){
		puts("add");
		for(int i = x; i <= n; i += i & -i)
			for(int j = y; j <= n; j += j & -j)
				::add(b[i][j], v);
	}
	int sum(int x, int y){
		int ret = 0;
		for(int i = x; i; i -= i & -i)
			for(int j = y; j; j -= j & -j)
				::add(ret, b[i][j]);
		return ret;
	}
} bit;

int divMod() {
    int mod = 0;
    for(int i = n; i; --i) {
        mod = mod * 10 + s[i];
        if(mod < 2) {
            if(i == n) --n;
            s[i] = 0;
        } else {
            s[i] = mod >> 1;
            mod &= 1;
        }
    }
    return mod;
}

int dfs(int i, int one, int e){
	pr(i); prln(one);
	if(i == cnt + 1){
		if(one) add(ans, bit.sum(cnt, cnt) - bit.sum(cnt, one) + MOD);
		printf("update %d\n", ans);
		return bool(one);
	}
    if(!e && ~f[i][one]) return f[i][one];
    int ret = 0, to = e ? digit[i] : 1;
    for(int d = 0; d <= to; ++d)
		add(ret, dfs(i + 1, one + d, e && d == to));
	if(one) bit.add(i, one, f[i][one]);
	if(!e){
		f[i][one] = ret;

	}
	return ret;
}

void calc() {
    n = strlen(s + 1), cnt = 0;
    for(int i = 1; i <= n; ++i) s[i] -= '0';
    reverse(s + 1, s + 1 + n);
    while(n) digit[++cnt] = divMod();
    reverse(digit + 1, digit + 1 + n);
//	for(int i = 1; i <= cnt; --i) printf("%d", digit[i]); puts("");
	bit.init(cnt);
	ans = 0;
	memset(f, -1, sizeof f);
    dfs(1, 0, 1);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%s", s + 1);
        calc();
        printf("%d\n", ans);
    }
    return 0;
}
