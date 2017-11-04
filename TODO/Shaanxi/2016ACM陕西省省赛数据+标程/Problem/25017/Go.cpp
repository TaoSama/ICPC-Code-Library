/* ***********************************************
MYID	: Chen Fan
LANG	: G++
PROG	: Go
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	//freopen("Go.in","r",stdin);
	//freopen("Go.out","w",stdout);

	int t;
	scanf("%d",&t);
	for (int tt=1;tt<=t;tt++)
	{
		printf("Case #%d:\n",tt);

		int b=0,w=0;
		for (int i=1;i<=19;i++)
		for (int j=1;j<=19;j++)
		{
			char c;
			c=getchar();
			while (c!='#'&&c!='1'&&c!='0') c=getchar();
			if (c=='1') b++;
			else if (c=='0') w++;
		}

		if (b>w) printf("Black\n");
		else if (b==w) printf("Equal\n");
		else printf("White\n");
	}

	return 0;
}
