/* ***********************************************
MYID	: Chen Fan
LANG	: G++
PROG	: MarsCity-makedata
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>

using namespace std;

bool flag[1010][1010];

int main()
{
	freopen("MarsCity.in","w",stdout);

	srand(time(NULL));
	srand(rand());

	printf("%d\n",8);
	for (int t=1;t<=7;t++)
	{
		int n=100+rand()%900;
		int p=10+rand()%900;
		printf("%d %d\n",n,p);
		memset(flag,0,sizeof(flag));
		for (int i=1;i<=n;i++)
		{
			int x=1+rand()%999,y=1+rand()%999,z=1+rand()%999;
			while (flag[x][y])
			{
				x=1+rand()%999;
				y=1+rand()%999;
			}
			flag[x][y]=true;
			printf("%d %d %d\n",x,y,z);
		}
	}

	printf("%d %d\n",1000,100);
	memset(flag,0,sizeof(flag));
	for (int i=1;i<=1000;i++)
	{
		int x=1+rand()%999,y=1+rand()%999;
		while (flag[x][y])
		{
			x=1+rand()%999;
			y=1+rand()%999;
		}
		flag[x][y]=true;
		printf("%d %d %d\n",x,y,i);
	}

	return 0;
}
