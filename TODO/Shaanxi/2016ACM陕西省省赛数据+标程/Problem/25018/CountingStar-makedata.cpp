/* ***********************************************
MYID	: Chen Fan
LANG	: G++
PROG	: CountingStar-makedata
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>

using namespace std;

int main()
{
	freopen("CountingStar.in0","w",stdout);

	srand(time(NULL));
	srand(rand());

	// Case number
	int cases=10;
	printf("%d\n",cases);

	for (int t=1;t<=cases;t++)
	{
		int n=rand()%1000;
		printf("%d\n",n);
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<n;j++) printf("%d ",(rand()*rand())%100000);
			printf("%d\n",(rand()*rand())%100000);
		}

		int m=1000+rand()%(n-1000);
		if (t>=8) m=99999;
		printf("%d\n",m);
		for (int i=1;i<=m;i++)
		{
			printf("%d %d\n",1+rand()%(n-1),1+rand()%(n-1));
		}
	}

	return 0;
}
