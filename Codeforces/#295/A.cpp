//
//
//
//  Created by TaoSama on 2015-03-02
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

int n, a[30];
string s;

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n >> s) {
		memset(a, 0, sizeof a);
		for(int i = 0; i < n; ++i) {
			s[i] = tolower(s[i]);
			a[s[i] - 'a']++;
		}
		bool ok = true;
		for(int i = 0; i < 26; ++i)
			if(!a[i]) ok = false;

		if(ok) cout << "YES" << endl;
		else 	cout << "NO" << endl;
	}
	return 0;
}
