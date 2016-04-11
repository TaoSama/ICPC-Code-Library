//
//	ACdream 1864 娜娜梦游仙境系列——莫名其妙的插曲
//
//  Created by TaoSama on 2015-04-11
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

int a[1005];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		for(int i = 1; i <= n; ++i) cin>>a[i];
		int Min, Max, gcd;
		Min = Max = gcd = a[1];
		for(int i = 2; i <= n; ++i){
			gcd = __gcd(gcd, a[i]);
			if(Max < a[i]) Max = a[i];
			if(Min > a[i]) Min = a[i];
 		}
 		int ans = (Max - min(gcd, Min)) / gcd + 1;
 		ans -= n;
 		if(ans & 1) cout<<"Win"<<endl;
 		else cout<<"Lose"<<endl;
	}
	return 0;
}
