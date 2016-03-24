//
//  B1.Permuatation
//
//  Created by TaoSama on 2015-02-08
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
bool cmp(pair<int, int> x, pair<int, int> y) {
	if(x.first == y.first) return x.second < y.second;
	return x.first > y.first;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n >> m) {
		vector<int> a, b[N];
		vector<pair<int, int> > ans;
		for(int i = 1; i <= n; ++i) a.push_back(i);
		int t = 1; b[1] = a;
		while(next_permutation(a.begin(), a.end()))
			b[++t] = a;

		for(int i = 1; i <= t; ++i) {
			int sum = 0;
			for(int j = 0; j < n; ++j) {
				for(int k = j; k < n; ++k) {
					int Min = INF;
					for(int l = j; l <= k; ++l)
						Min = min(Min, b[i][l]);
					sum += Min;
				}
			}
			ans.push_back(make_pair(sum, i));
//			cout << sum << ' ' << i << endl;
		}
		sort(ans.begin(), ans.end(), cmp);
		int x = ans[m - 1].second;
		for(int i = 0; i < n - 1; ++i)
			cout << b[x][i] << ' ';
		cout << b[x][n - 1] << endl;
	}
	return 0;
}
