/* ***********************************************
MYID	: Chen Fan
LANG	: G++
PROG	: CountingStar-duipai
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int map[1010][1010];

int main()
{
	//freopen("CountingStar.in0","r",stdin);
    //freopen("result-duipai","w",stdout);
    
    int t;
    scanf("%d",&t);
    for (int tt=1;tt<=t;tt++)
    {
        printf("Case #%d:\n",tt);
        
        int n;
        scanf("%d",&n);
        int totp=0;
        for (int i=n;i>=1;i--)
        for (int j=1;j<=n;j++)
        scanf("%d",&map[j][i]);
        
        int m;
        scanf("%d",&m);
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            long long sum=0;
            for (int i=1;i<=x;i++)
            {
            	int temp=i*y/x;
            	for (int j=1;j<=temp;j++) sum+=map[i][j];
            }
        	printf("%lld\n", sum);
        }
    }
    
    return 0;
}
