//
//  Created by TaoSama on 2016-05-02
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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

int A[30];
int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    A[0]=1;
    A[1]=2;
    for(int j=2;j<=44;j++) A[j]=A[j-1]+A[j-2];
    int n;
    while(scanf("%d",&n)&&n){
		//printf("n = %d\n",n);
		int ok=0;
		for(int j=1;j<=44&&A[j]<=n;j++){
			//if(n==13) printf("%d\n",A[j]);
			if(A[j]==n){
				ok=1;
				break;
			}
		}
		if(!ok) printf("First win\n");
		else printf("Second win\n");
    }
    return 0;
}
