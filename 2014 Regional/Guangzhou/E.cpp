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
const int N = 205, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
struct node{
	string name;
	int kill;
}A[N];
int B[N],C[N];
bool cmp(node a,node b){
	if(a.kill!=b.kill) return a.kill>b.kill;
	else return a.name<b.name;
}
int main() {
#ifdef LOCAL
    //freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    //ios_base::sync_with_stdio(0);
    int n;
    while(scanf("%d",&n)!=EOF){
		if(n==0) break;
		int j,k;
		for(j=1;j<=n;j++){
			cin>>A[j].name>>A[j].kill;
		}
		sort(A+1,A+1+n,cmp);
		int b=1,c=1;
		B[1]=1;C[1]=1;
        for(j=2;j<=n;j++){
			b++;
			if(A[j].kill==A[j-1].kill) c++;
			else c=1;
			if(c>1) B[j]=B[j-1];
			else B[j]=b;
			C[j]=c;
        }
        for(j=1;j<=n;j++){
        	cout<<A[j].name<<" "<<A[j].kill<<endl;
        }
        int m;
        scanf("%d",&m);
        string a;
        for(j=1;j<=m;j++){
			cin>>a;
			for(k=1;k<=n;k++){
				if(A[k].name==a) break;
			}
			if(C[k]>1) printf("%d %d\n",B[k],C[k]);
			else printf("%d\n",B[k]);
        }
    }
    return 0;
}
