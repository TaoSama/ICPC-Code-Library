//
//  Created by TaoSama on 2015-10-23
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
double a[15],dp[1<<15];

double solve(int i,int j,int k){
	double p=(a[i]+a[j]+a[k])/2;
	return sqrt(p*(p-a[i])*(p-a[j])*(p-a[k]));
}

bool check(double x,double y,double z){
	if(x+y>z+1e-6 && y+z>x+1e-6 && z+x>y+1e-6) return 1;
	return 0;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
	int i,j,k; //printf("%d\n",sizeof(dp)/1024);
	while(~scanf("%d",&n) && n){
		for(i=0;i<n;i++)
			scanf("%lf",&a[i]);
		memset(dp,0,sizeof(dp));
		double ans=0.0; //printf("%f\n",dp[100]);
		for(int S=0;S<(1<<n);S++){
			for(i=0;i<n;i++){
				if((S&(1<<i))) continue;
				for(j=0;j<n;j++){
					if((S&(1<<j)) || i==j) continue;
					for(k=0;k<n;k++){
						if((S&(1<<k)) || i==k || j==k) continue;
						if(!check(a[i],a[j],a[k])) continue;
						dp[S|(1<<i)|(1<<j)|(1<<k)]=max(dp[S|(1<<i)|(1<<j)|(1<<k)],dp[S]+solve(i,j,k));
						ans=max(ans,dp[S|(1<<i)|(1<<j)|(1<<k)]);
					}
				}
			}
		}
		printf("%.2f\n",ans);
	}

    return 0;
}
