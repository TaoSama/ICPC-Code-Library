#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;
int n,k,p;
long long x;
long long C[20][20];
void dfs(int now,int num,long long lef)
{
	// cout<<now<<' '<<num<<' '<<lef<<endl;
	if (now==k-1)
	{
		if (num==1) cout<<1<<endl;
		else cout<<lef+1<<endl;
		return;
	}
	if (lef==0)
	{
		if (num!=0)
		{
			cout<<1;
			dfs(now+1,num-1,lef);
		}
		else
		{
			cout<<2;
			dfs(now+1,num,lef);
		}
		return;
	}
	long long sum=0;
	int nex=n;
	for (int i=1;i<=n;i++)
	{
		long long temp;
		long long ff1,ff2;
		int t;
		if (i==1) t=num-1; else t=num;
		if (t==-1) continue;
		ff1=C[k-now-1][t];
		ff2=pow(n-1,(k-now-t-1));
		temp=ff1*ff2;
		// cout<<now<<' '<<num<<' '<<lef<<' '<<' '<<ff1<<' '<<ff2<<' '<<temp<<endl;
		if (temp+sum<lef)
		{
			sum+=temp;
			continue;
		}
		else
		{
			nex=i;
			break;
		}
	}
	cout<<nex;
	dfs(now+1,nex==1?num-1:num,lef-sum);
}
int main()
{
	srand(time(0));
	char ch[105]="data.in";
	char ch2[105]="data.out";
	freopen(ch,"r",stdin);
	freopen(ch2,"w",stdout);
	for (int i=0;i<=19;i++)
		for (int j=0;j<=i;j++)
		{
			if (i==0) C[i][j]=1;
			else
			if (j==0 || i==j) C[i][j]=1;
			else
			{
				C[i][j]=C[i-1][j-1]+C[i-1][j];
			}
		}

	while (cin>>n>>k>>p>>x)
	{
		if (C[k][p]*(long long)(pow(n-1,k-p))<x)
			cout<<"poor god wan"<<endl;
		else
			dfs(0,p,x);
	}
}