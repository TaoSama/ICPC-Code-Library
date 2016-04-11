//
//  Created by TaoSama on 2015-09-26
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

int prime[N];
int make_ans(int num, int m) {
    int ans = 0;
    for(int i = 1; i < (1 << m); i++) {
        int tmp = 1, flag = 0;
        for(int j = 0; j < m; j++)
            if(i & ((1 << j))) //判断第几个因子目前被用到
                flag++, tmp *= prime[j];
        if(flag & 1) //容斥原理，奇加偶减
            ans += num / tmp;
        else
            ans -= num / tmp;
    }
    return ans;
}

inline int read(){
	char c = getchar();
	while(!isdigit(c)) c = getchar();
	int x = 0;
	while(isdigit(c)){
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x;
}

void out(int x){
	if(x > 9) out(x / 10);
	putchar(x % 10 + '0');
}

int head[N], nxt[N << 1], pnt[N << 1], cnt;
int n, a[N], st[N], ed[N];

void add_edge(int u, int v){
	pnt[cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt++;
}

int dfn;

void dfs(int u, int f){
	st[u] = ++dfn;
	for(int i = head[u]; ~i; i = nxt[i]){
		int v = pnt[i];
		if(v == f) continue;
		dfs(v, u);
	}
	ed[u] = dfn;
}

bool cmp(int x, int y){
	return st[x] < st[y];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

	int kase = 0;
	while(scanf("%d", &n) == 1){
		cnt = 0; memset(head, -1, sizeof head);
		for(int i = 1; i < n; ++i){
			int u = read(), v = read();
			add_edge(u, v);
			add_edge(v, u);
		}
		for(int i = 1; i <= n; ++i) a[i] = read();
		dfn = 0;
		dfs(1, -1);
		for(int i = 1; i <= n; ++i)
			printf("%d %d %d\n", st[i], ed[i], a[st[i]]);
		printf("Case #%d: ", ++kase);
		for(int i = 1; i <= n; ++i){
			int m = 0, t = a[i];
			for(int j = 2; j * j <= a[i]; ++j)
		}
	}
    return 0;
}
