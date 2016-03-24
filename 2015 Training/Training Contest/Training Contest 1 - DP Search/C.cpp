//
//
//
//  Created by TaoSama on 2015-03-08
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
const int N = 1e6 + 10;

int k, sum, cnt[N];
string s;

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> k >> s) {
		long long ans = 0;
		memset(cnt, 0, sizeof cnt);
		cnt[0] = 1, sum = 0;
		for(int i = 0; i < s.size(); ++i) {
			if(s[i] == '1')	++sum;
			if(sum >= k)	ans += cnt[sum - k];
			++cnt[sum];
		}
		cout << ans << endl;
	}
	return 0;
}
