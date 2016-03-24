//
//
//
//  Created by TaoSama on 2015-03-08
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

int n;
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n) {
		int ans;
		if(n & 1) {
			cout << ((n + 1) >> 1)*((n + 1) >> 1) + (n >> 1)*(n >> 1) << endl;
			for(int i = 1; i <= n; ++i) {
				for(int j = 1; j <= n; ++j) {
					if(i & 1) {
						if(j & 1) cout << 'C';
						else	cout << '.';
					} else {
						if(j & 1) cout << '.';
						else	cout << 'C';
					}
				}
				cout<<'\n';
			}
		} else {
			cout << n * (n >> 1) << endl;
			for(int i = 1; i <= n; ++i) {
				for(int j = 1; j <= n; ++j) {
					if(i & 1) {
						if(j & 1) cout << 'C';
						else	cout << '.';
					} else {
						if(j & 1) cout << '.';
						else	cout << 'C';
					}
				}
				cout<<'\n';
			}

		}
	}
	return 0;
}
