//
//	A. Drazil and Date
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

long long a, b, s;

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> a >> b >> s) {
		if(s - abs(a) - abs(b) >= 0 &&
		        (s - abs(a) - abs(b)) % 2 == 0) cout << "Yes" << endl;
		else	cout << "No" << endl;
	}
	return 0;
}
