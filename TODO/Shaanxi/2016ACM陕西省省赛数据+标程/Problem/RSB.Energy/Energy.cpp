/* ***********************************************
MYID	: Chen Fan
LANG	: G++
PROG	: Energy
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int father[40010];

int getfather(int x)
{
	if (father[x]!=x) father[x]=getfather(father[x]);
	return father[x];
}

void link(int x,int y)
{
	father[getfather(x)]=getfather(y);
}

struct node
{
	int a,b,c;
};

node edge[100010];

bool op(node a, node b)
{
	if (a.c==b.c) return a.a<b.a;
	else return a.c>b.c;
}

int main()
{
	//freopen("Energy.sample","r",stdin);
	freopen("Energy.in","r",stdin);
	freopen("Energy.out","w",stdout);

	int t;
	scanf("%d",&t);
	for (int tt=1;tt<=t;tt++)
	{
		printf("Case #%d:\n",tt);

		int n,m;
		scanf("%d%d",&n,&m);

		for (int i=1;i<=2*n;i++) father[i]=i;

		for (int i=1;i<=m;i++)
		scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].c);

		sort(&edge[1],&edge[m+1],op);

		int ans=0;
		for (int i=1;i<=m;i++)
		if (getfather(edge[i].a)!=getfather(edge[i].b))
		{
			link(edge[i].a,edge[i].b+n);
			link(edge[i].b,edge[i].a+n);
		} else
		{
			ans=edge[i].c;
			break;
		}
		printf("%d\n",ans);
	}

	return 0;
}
