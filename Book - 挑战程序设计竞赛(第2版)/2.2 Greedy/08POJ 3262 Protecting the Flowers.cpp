//
//  POJ 3262 Protecting the Flowers
//
//  Created by TaoSama on 2015-02-22
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

int n;
struct ACM {
	int t, c;
	bool operator<(const ACM& r) const {
		return t * r.c > r.t * c;
		//(t1,c1) (t2,c2) 赶1造成的损失t1*c2 赶2损失t2*c1
	}
} a[N];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n) {
		for(int i = 1; i <= n; ++i) cin >> a[i].t >> a[i].c;
		sort(a + 1, a + 1 + n);

		long long ans = 0, sum = 0;
		for(int i = 1; i <= n; ++i) {
			ans += 2LL * a[i].t * sum;
			sum += a[i].c;
		}
		cout << ans << endl;
	}
	return 0;
}
