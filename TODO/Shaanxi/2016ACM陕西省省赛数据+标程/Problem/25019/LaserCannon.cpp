/* ***********************************************
MYID	: Chen Fan
LANG	: G++
PROG	: LaserCannon
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

#define PI 3.1415926

struct node
{
	int x,y,v,m;
	double yy;
};

bool op(node a, node b)
{
	if (a.yy==b.yy) return a.x<a.y;
	else return a.yy<b.yy;
}

node ufo[2010];
double f[2010];

int main()
{
	//freopen("LaserCannon.in","r",stdin);
	//freopen("LaserCannon.out","w",stdout);

	int t;
	scanf("%d",&t);

	for (int tt=1;tt<=t;tt++)
	{
		printf("Case #%d:\n", tt);

		int n,a;
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		scanf("%d%d%d%d",&ufo[i].x,&ufo[i].y,&ufo[i].v,&ufo[i].m);
		scanf("%d",&a);

		if (a==0||a==180) 
			for (int i=1;i<=n;i++) ufo[i].yy=ufo[i].y;
		else if (a==90)
			for (int i=1;i<=n;i++) ufo[i].yy=ufo[i].x;
		else
			for (int i=1;i<=n;i++) ufo[i].yy=ufo[i].y-ufo[i].x*tan((double)a/180*PI);

		sort(&ufo[1],&ufo[n+1],op);

		memset(f,0,sizeof(f));
		for (int i=0;i<n;i++)
		{
			int sumv=0,summ=0;
			for (int j=i+1;j<=n;j++)
			{
				sumv+=ufo[j].v;
				summ+=ufo[j].m;
				double temp=f[i]+(double)sumv*summ/(j-i);
				if (f[j]<temp) f[j]=temp;
			}
		}

		printf("%.3lf\n", f[n]);
	}

	return 0;
}
