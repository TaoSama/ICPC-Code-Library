//
//  HDU 1864 最大报销额
//
//  Created by TaoSama on 2015-02-06
//  Copyright (c) 2014 TaoSama. All rights reserved.
//
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
#define CLR(x) memset(x, 0, sizeof(x))

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, sum, dp[3500000], v[35]; //dp[j]表示报销当前额度的最大值 //其实也可以用bool来判断是否可报销
double q;

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);
	while(scanf("%lf%d", &q, &n) == 2 && n) {
		memset(dp,0,sizeof dp);
		sum = q * 100; int ct = 0;
		for(int i = 1; i <= n; ++i) {
			int m; scanf("%d", &m);
			int a = 0, b = 0, c = 0; bool ok = true;
			while(m--) {
				getchar();
				char op; double x; scanf("%c:%lf", &op, &x); x *= 100;
				if(op == 'A') a += x;
				else if(op == 'B') b += x;
				else if(op == 'C') c += x;
				else ok = false;
			}
			if(a + b + c <= 100000 && a <= 60000 && b <= 60000
			        && c <= 60000 && ok)
				v[++ct] = a + b + c;
			//cout<<v[ct]<<endl;
		}
		for(int i = 1; i <= ct; ++i)
			for(int j = sum; j >= v[i]; --j)
				dp[j] = max(dp[j], dp[j - v[i]] + v[i]);
		printf("%.2f\n", dp[sum] / 100.0);
	}
	return 0;
}
