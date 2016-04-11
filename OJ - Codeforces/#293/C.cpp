//
//
//
//  Created by TaoSama on 2015-02-25
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

int n, m, k;
int a[N], l[N], r[N], wh[N];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	//ios_base::sync_with_stdio(0);

	while(cin >> n >> m >> k) {
		memset(a, 0, sizeof a);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		for(int i = 0; i < n; i++) {
			if(i == 0)
				l[a[i]] = -1;
			else
				l[a[i]] = a[i - 1];
			if(i == n - 1)
				r[a[i]] = -1;
			else
				r[a[i]] = a[i + 1];
			wh[a[i]] = i + 1;
		}
		long long sum = 0;
		for(int i = 0; i < m; i++) {
			int x; cin >> x;
			sum += (wh[x] - 1) / k + 1;
			if(l[x] == -1) continue;
			else {
				int p = l[x];
				int ne = r[x];
				int ll = l[p];
				l[x] = l[p];
				l[p] = x;
				if(ne != -1) l[ne] = p;
				r[p] = ne;
				r[x] = p;
				if(ll != -1) r[ll] = x;
				wh[x]--, wh[p]++;
			}
		}
		cout << sum << endl;
	}
	return 0;
}
