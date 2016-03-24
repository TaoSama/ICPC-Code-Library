//
//
//
//  Created by TaoSama on 2015-03-30
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

struct ACM
{
	int l, r;
	bool operator<(const ACM& rhs) const{
		return r < rhs.r;
	}
}a[N];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	int n; scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int x, w; scanf("%d%d", &x, &w);
		a[i].l = x - w, a[i].r = x + w;
	}
	sort(a + 1, a + 1 + n);
	int last = 1, ans = 1;
	for(int i = 2; i <= n; ++i){
		if(a[i].l >= a[last].r){
			last = i;
			++ ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}
