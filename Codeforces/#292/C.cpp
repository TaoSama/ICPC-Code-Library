//
//	C. Drazil and Factorial
//
//  Created by TaoSama on 2015-02-18
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

int n; char a[20];
map<int, int> ans;

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n >> (a + 1)) {
		ans.clear();
		for(int i = 1; i <= n; ++i) {
			if(a[i] == '2') ++ans[2];
			if(a[i] == '3') ++ans[3];
			if(a[i] == '4') ++ans[3], ans[2] += 2;
			if(a[i] == '5') ++ans[5];
			if(a[i] == '6') ++ans[5], ++ans[3];
			if(a[i] == '7') ++ans[7];
			if(a[i] == '8') ++ans[7], ans[2] += 3;
			if(a[i] == '9') ++ans[7], ++ans[2], ans[3] += 2;
		}
		for(int i = 9; i > 0; --i) {
			if(ans.count(i)) {
				int t = ans[i];
				for(int j = 1; j <= t; ++j)
					cout << i;
			}
		}
		cout << endl;
	}
	return 0;
}
