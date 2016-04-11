//
//
//
//  Created by TaoSama on 2015-03-18
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

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n >> m) {
		long long ans = 0;
		while(n != m) {
			long long t = n % m;
			if(t == 0) {
				ans += n/m;
				break;
			} else {
				ans += n / m;
				n = t;
				if(n < m) swap(n, m);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
