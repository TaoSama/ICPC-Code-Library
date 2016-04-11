//
//  Created by TaoSama on 2016-01-21
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 3e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

	while(scanf("%d", &n) == 1){
		set<int> s;
		vector<pair<int, int> > ans;
		for(int i = 1; i <= n; ++i) scanf("%d", a + i);
		int l = 1, r = 1;
		while(r <= n){
			if(s.count(a[r])) {
				s.clear();
				ans.push_back({l, r});
				l = r = r + 1;
			}
			else s.insert(a[r++]);
		}
		if(ans.size()){
			printf("%d\n", ans.size());
			for(int i = 0; i < ans.size(); ++i){
				if(i == ans.size() - 1 && ans[i].second != n)
					ans[i].second = n;
				printf("%d %d\n", ans[i].first, ans[i].second);
			}
		}
		else puts("-1");
	}
    return 0;
}
