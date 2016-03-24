//
//  Created by TaoSama on 2015-06-19
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int N = 1e5 + 10;

int n, a[105][105];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

    while(cin >> n){
		memset(a, 0, sizeof a);
		int maxx = -INF, maxy = -INF;
		for(int i = 1; i <= n; ++i){
			int x1, y1, x2, y2; cin >> y1 >> x1 >> y2 >> x2;
			maxx = max(max(maxx, x1), x2);
			maxy = max(max(maxy, y1), y2);
			for(int dx = x1; dx <= x2; ++dx)
				for(int dy = y1; dy <= y2; ++dy)
					a[dx][dy]++;
		}
		int ret = 0;
		for(int i = 1; i <= maxx; ++i)
			for(int j = 1; j <= maxy; ++j)
				ret += a[i][j];
		cout << ret << '\n';
    }
	return 0;
}
