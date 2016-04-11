//
//  POJ 3181 Dollar Dayz
//
//  Created by TaoSama on 2015-03-05
//  Copyright (c) 2015 TaoSama. All rights reserved.
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
#define CLR(x,y) memset(x, y, sizeof(x))

using namespace std;
const int INF = 0x3f3f3f3f;
const long long MOD = 1e18;
const int N = 1e5 + 10;

int n, k;
long long dph[N], dpl[N]; //高位低位
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n >> k) {
		memset(dph, 0, sizeof dph);
		memset(dpl, 0, sizeof dpl);
		dpl[0] = 1;
		for(int i = 1; i <= k; ++i) {
			for(int j = i; j <= n; ++j) {
				dph[j] = dph[j] + dph[j - i] + (dpl[j] + dpl[j - i]) / MOD;
				dpl[j] = (dpl[j] + dpl[j - i]) % MOD;
			}
		}
		if(!dph[n]) cout<<dpl[n]<<endl;
		else	cout<<dph[n]<<setw(18)<<setfill('0')<<dpl[n]<<endl;
	}
	return 0;
}
