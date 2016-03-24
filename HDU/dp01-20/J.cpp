//
//  HDU 1069 Monkey and Banana
//
//  Created by TaoSama on 2015-02-12
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

struct Cuboid {
	int l, w, h;
	Cuboid(int l, int w, int h): l(l), w(w), h(h) {}
	bool operator< (const Cuboid& c) const {return l * w > c.l * c.w;}
};
int n, dp[100];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	int kase = 0;
	while(cin >> n && n) {
		vector<Cuboid> v;
		for(int i = 1; i <= n; ++i) {
			int x, y, z; cin >> x >> y >> z;
			v.push_back(Cuboid(x, y, z));
			v.push_back(Cuboid(x, z, y));
			v.push_back(Cuboid(y, z, x));
		}
		sort(v.begin(), v.end());
		memset(dp, 0, sizeof dp);
		int ans = -INF;
		for(int i = 0; i < v.size(); ++i) {
			dp[i] = v[i].h;
			for(int j = 0; j < i; ++j) {
				if(v[i].l < v[j].l && v[i].w < v[j].w || v[i].w < v[j].l
				        && v[i].l < v[j].w)
					dp[i] = max(dp[i], dp[j] + v[i].h);
			}
			ans = max(ans, dp[i]);
		}
		cout << "Case " << ++kase << ": maximum height = ";
		cout << ans << endl;
	}
	return 0;
}
