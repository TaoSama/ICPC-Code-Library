//
//
//
//  Created by TaoSama on 2015-03-15
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

long long n, m;
long long cal(long long x) {
	return x * (x - 1) / 2;
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n >> m) {
		long long Min, Max;
		if(m > 1) {
			int left = n % m;
			if(left > 0) {
				Min = cal(n / m + 1) * left +
				      cal(n / m) * (m - left);
			} else {
				Min = cal(n / m) * m;
			}
			Max = cal(n - m + 1);
		} else {
			Min = Max = cal(n);
		}
		cout << Min << ' ' << Max << endl;
	}
	return 0;
}
