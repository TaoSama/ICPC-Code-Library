//
//  Created by TaoSama on 2015-06-19
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
const int N = 1e5 + 10;

long long n, a[10];

long long ten(int x){
	long long ret = 1;
	for(int i = 1; i <= x; ++i)
		ret *= 10;
	return ret;
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n){
		long long x = 9;
		for(int i = 1; i <= 9; ++i){
			a[i] = a[i - 1] + x * i;
			x *= 10;
//			cout << a[i] << endl;
		}
		int d = log10(n) + 1;
//		cout << d << endl;
		long long ans = a[d - 1] + (n - ten(d - 1) + 1) * d;
		cout << ans << endl;
	}
	return 0;
}
