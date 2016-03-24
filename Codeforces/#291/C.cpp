//
//  C. Watto and Mechanism
//
//  Created by TaoSama on 2015-02-15
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
const int N = 3e5 + 10;

int n, m;
string t, dict[N];
set<string> s;

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i) {
		cin >> dict[i];
		s.insert(dict[i]);
	}
	for(int i = 1; i <= m; ++i) {
		cin >> t; bool ok = false;
		if(t.size() <= 100) {
			for(int j = 0; j < t.size(); ++j) {
				char ch = t[j];
				for(int k = 0; k < 3; ++k) {
					if(t[j] == 'a' + k) continue;
					t[j] = 'a' + k;
					if(s.count(t)) ok = true;
					t[j] = ch;
					if(ok) break;
				}
				if(ok) break;
			}
			if(ok) cout << "YES" << endl;
			else   cout << "NO" << endl;
			continue;
		}
		for(int j = 1; j <= n; ++j) {
			if(dict[j].size() != t.size()) continue;
			int diff = 0;
			for(int k = 0; k < t.size(); ++k)
				if(dict[j][k] != t[k]) {
					++diff;
					if(diff > 1) break;
				}
			if(diff == 1) {ok = true; break;}
		}
		if(ok) cout << "YES" << endl;
		else   cout << "NO" << endl;
	}
	return 0;
}
