//
//
//
//  Created by TaoSama on 2015-03-18
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
const int N = 2e5 + 10;

int n, ansx, ansy;
char s[N], t[N];
int a[26][26], ss[26], tt[26];

bool check() {
	for(int i = 0; i < 26; ++i) {
		for(int j = i + 1; j < 26; ++j) {
			if(a[i][j] && a[j][i]) {
				ansx = a[i][j], ansy = a[j][i];
				return true;
			}
		}
	}
	return false;
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(~scanf("%d%s%s", &n, s + 1, t + 1)) {
		int diff = 0;
		memset(ss, 0, sizeof ss);
		memset(tt, 0, sizeof tt);
		for(int i = 1; i <= n; ++i) {
			if(s[i] != t[i]) {
				a[s[i] - 'a'][t[i] - 'a'] = i;
				ss[s[i] - 'a'] = tt[t[i] - 'a']= i;
				++diff;
			}
		}
		int ok = false;
		if(diff <= 1) {
			printf("%d\n-1 -1\n", diff);
		} else {
			for(int i = 0; i < 26; ++i) {
				if(check()) {
					diff -= 2;
					ok = true;
					break;
				}
			}
			if(!ok) {
				for(int i = 0; i < 26; ++i) {
					if(ss[i]&& tt[i]) {
						ansx = ss[i], ansy = tt[i];
						diff -= 1;
						ok = true;
						break;
					}
				}
			}
			if(!ok) ansx = -1, ansy = -1;
			printf("%d\n%d %d\n", diff, ansx, ansy);
		}
	}
	return 0;
}
