//
//
//
//  Created by TaoSama on 2015-03-27
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

long long n, k, ct[N];
char a[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> (a + 1)) {
		memset(ct,0,sizeof ct);
        n = strlen(a + 1);
        cin >> k;
        while(k--) {
            int x; cin >> x;
            ct[x]++;
        }
		for(int i = 2; i <= n/2; ++i)
			ct[i] += ct[i-1];
		for(int i = 1; i <= n/2; ++i){
			if(ct[i] & 1) swap(a[i],a[n-i+1]);
		}
        cout << (a + 1) << endl;
    }
    return 0;
}
