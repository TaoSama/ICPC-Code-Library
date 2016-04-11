//
//
//
//  Created by TaoSama on 2015-04-16
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

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 2e5 + 10;

int n, k, a[N];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	int t; scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; ++i) scanf("%d", a + i);
		long long ans = 0, Max = 0;
		for(int i = 1; i <= n; ++i){
			if(a[i] > k && i > Max) Max = i;
			ans += Max;
			//cout<<i<<": "<<Max<<endl;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
