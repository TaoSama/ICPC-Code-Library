/* ***********************************************
MYID	: Chen Fan
LANG	: G++
PROG	: Go-datamake
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>

using namespace std;

int main()
{
	freopen("Go.in","w",stdout);

	printf("%d\n", 10);

	srand(time(NULL));
	srand(rand());

	for (int t=1;t<=10;t++)
	{
		for (int i=1;i<=19;i++)
		{
			for (int j=1;j<=19;j++)
			{
				int temp=rand()%3;
				if (temp==2) printf("#");
				else if (temp==1) printf("1");
				else printf("0");
			}
			printf("\n");
		}
	}

	return 0;
}
