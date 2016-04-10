//
//  HDU 1171 Big Event in HDU
//
//  Created by TaoSama on 2015-02-07
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
const int N = 2e5 + 10;

int n, w[55], ct[55], dp[N];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin>>n && n >= 0){
		int sum = 0; CLR(dp,0);
		for(int i=1;i<=n;++i) {
			cin>>w[i]>>ct[i];
			sum += w[i] * ct[i];
		}

		for(int i=1;i<=n;++i)
			for(int k=1;k<=ct[i];++k)
				for(int j=sum/2;j>=w[i]*k;--j)
					dp[j] = max(dp[j],dp[j-k*w[i]]+k*w[i]);
		cout<<sum - dp[sum/2]<<' '<<dp[sum/2]<<endl;
	}
	return 0;
}
