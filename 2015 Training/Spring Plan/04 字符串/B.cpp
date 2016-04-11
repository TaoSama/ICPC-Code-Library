//
//  Created by TaoSama on 2015-05-04
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

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

char a[105];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	int t; scanf("%d", &t);
	while(t--){
		scanf("%s", a + 1);
		int sz = strlen(a + 1), ans = 0;
		for(int i = 1; i <= sz; ++i){
			if(a[i] == 'A') {
				int t = 1;
				for(int j = i + 1; j <= sz; ++j){
					if(a[j] == 'A') ++t;
					else break;
				}
				ans = max(ans, t);
			}
		}
		for(int i = 0; i <= ans; ++i)
			putchar('A');
		putchar('\n');
	}
    return 0;
}
