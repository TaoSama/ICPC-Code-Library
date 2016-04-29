//
//	B. Drazil and His Happy Friends
//
//  Created by TaoSama on 2015-02-18
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

int n, m;
bool a[105];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n >> m) {
		memset(a, 0, sizeof a);
		int gcd = __gcd(n, m);
		int t; cin >> t;
		while(t-- > 0) {
			int x; cin >> x;
			a[x % gcd] = 1;
		}
		cin >> t;
		while(t-- > 0) {
			int x; cin >> x;
			a[x % gcd] = 1;
		}
		string ans = "Yes";
		for(int i = 0; i < gcd; ++i) {
			if(!a[i]) ans = "No";
		}
		cout << ans << endl;
	}
	return 0;
}