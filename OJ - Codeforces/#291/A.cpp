//
//  A. Chewba§ãca and Number
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
const int N = 1e5 + 10;

char a[20];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> a) {
		int n = strlen(a);
		if(a[0] >= '5' && a[0] <= '8') a[0] = '0' + '9' - a[0];
		for(int i = 1; i < n; ++i)
			if(a[i] >= '5') a[i] = '0' + '9' - a[i];
		cout << a << endl;
	}
	return 0;
}
