//
//
//
//  Created by TaoSama on 2015-03-02
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
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, a[5];
string s;
long long ksm(long long x) {
	long long ret = 1;
	while(n) {
		if(n & 1) ret = ret * x % MOD;
		x = x * x % MOD;
		n >>= 1;
	}
	return ret;
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n >> s) {
		memset(a, 0, sizeof a);
		int Max = 0;
		for(int i = 0; i < n; ++i) {
			if(s[i] == 'A') a[1]++, Max = max(a[1], Max);
			if(s[i] == 'G') a[2]++, Max = max(a[2], Max);
			if(s[i] == 'C') a[3]++, Max = max(a[3], Max);
			if(s[i] == 'T') a[4]++, Max = max(a[4], Max);
		}
		int Big = 0;
		for(int i = 1; i < 5; ++i)
			if(a[i] == Max) ++Big;

		cout<<ksm(Big)<<endl;
	}
	return 0;
}
