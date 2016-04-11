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

string s, t;
int sUp[30], sLow[30], tUp[30], tLow[30];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> s >> t) {
		CLR(sUp, 0); CLR(sLow, 0);
		CLR(tUp, 0); CLR(tLow, 0);
		for(int i = 0; i < s.size(); ++i)
			if(isupper(s[i])) sUp[s[i] - 'A']++;
			else  sLow[s[i] - 'a']++;
		for(int i = 0; i < t.size(); ++i)
			if(isupper(t[i])) tUp[t[i] - 'A']++;
			else  tLow[t[i] - 'a']++;
		int ans1 = 0, ans2 = 0;
		for(int i = 0; i < 26; ++i) {
			int t = min(sUp[i], tUp[i]);
			ans1 += t; sUp[i] -= t; tUp[i] -= t;
		}
		for(int i = 0; i < 26; ++i) {
			int t = min(sLow[i], tLow[i]);
			ans1 += t; sLow[i] -= t; tLow[i] -= t;
		}
		for(int i = 0; i < 26; ++i) {
			int t = min(sUp[i], tLow[i]);
			ans2 += t;
		}
		for(int i = 0; i < 26; ++i) {
			int t = min(sLow[i], tUp[i]);
			ans2 += t;
		}
		cout<<ans1<<' '<<ans2<<endl;
	}
	return 0;
}
