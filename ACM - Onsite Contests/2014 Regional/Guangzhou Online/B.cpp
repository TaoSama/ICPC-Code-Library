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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

struct node{
	int L,R,id;
	int color;
}tree[N*4];
void up(int p){
	tree[p].id=tree[p*2].id|tree[p*2+1].id;
}
void down(int p){
	if(tree[p].color){
		tree[p*2].color=tree[p*2+1].color=tree[p].color;
		tree[p*2].id=tree[p*2+1].id=(1<<(tree[p].color-1));
		tree[p].color=0;
	}
}
void build(int x,int y,int p){
	tree[p].L=x;tree[p].R=y;tree[p].id=2;tree[p].color=0;
	if(x==y) return;
	int mid=(x+y)>>1;
	build(x,mid,p*2);build(mid+1,y,p*2+1);
}
void update(int x,int y,int z,int p){
	//printf("%d %d\n",x,y);
	if(tree[p].L==x&&tree[p].R==y){
		//printf("%d %d\n",x,y);
		tree[p].color=z;
		tree[p].id=0;
		tree[p].id|=(1<<(z-1));
		return;
	}
	down(p);
	int mid=(tree[p].L+tree[p].R)>>1;
    if(y<=mid) update(x,y,z,p*2);
    else if(x>mid) update(x,y,z,p*2+1);
    else{
    	update(x,mid,z,p*2);update(mid+1,y,z,p*2+1);
    }
    up(p);
}
int query(int x,int y,int p){
	if(tree[p].L==x&&tree[p].R==y) return tree[p].id;
	int mid=(tree[p].L+tree[p].R)>>1;
	//printf("%d %d %d %d\n",tree[p].L,tree[p].R,tree[p].id,tree[p].color);
	down(p);
	int t;
	if(y<=mid) t=query(x,y,p*2);
	else if(x>mid) t=query(x,y,p*2+1);
	else t=query(x,mid,p*2)|query(mid+1,y,p*2+1);
	up(p);
	return t;
}
int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0&&m==0) break;
		int j,k;
		build(1,n,1);
		char s[5];
		//printf("1\n");
		for(j=1;j<=m;j++){
			scanf("%s",s);
			//printf("%c\n",s[0]);
			if(s[0]=='P'){
				int a,b,c;
				scanf("%d%d%d",&a,&b,&c);
				update(a,b,c,1);
			}
			else{
				int a,b;
				scanf("%d%d",&a,&b);
				int t=query(a,b,1);
				for(k=30;k>=1;k--) if(t&(1<<(k-1))) break;
				int q=k;
				for(k=1;k<q;k++){
					if(t&(1<<(k-1))) printf("%d ",k);
				}
				printf("%d\n",q);
			}
		}
    }
    return 0;
}
