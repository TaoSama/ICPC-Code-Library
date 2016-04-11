//
//  POJ 3617 Best Cow Line
//
//  Created by TaoSama on 2015-02-16
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
#define CLR(x,y) memset(x, y, sizeof(x))

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n;

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n) {
		string a;
		for(int i = 1; i <= n; ++i) {
			char c; cin >> c;
			a += c;
		}
		int l = 0, r = n - 1, ct = 0;
		while(l <= r) {
			bool left = false;
			for(int i = 0; l + i <= r; ++i) {
				if(a[l + i] < a[r - i]) {
					left = true;
					break;
				} else if(a[l + i] > a[r - i]) break;
			}
			if(left) cout << a[l++];
			else	cout << a[r--];
			if(++ct % 80 == 0) cout << endl;
		}
		cout << endl;
	}
	return 0;
}
