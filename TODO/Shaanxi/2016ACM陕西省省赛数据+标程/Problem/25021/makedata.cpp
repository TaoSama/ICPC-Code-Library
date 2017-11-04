#include <iostream>
#include <time.h>
#include <math.h>
#include <map>
using namespace std;
int vis[1200];
int main()
{
	srand(time(0));
	char ch[105]="data.in";
	freopen(ch,"w",stdout);
	int n;
	cout<<100<<endl;
	for (int i=1;i<=100;i++)
	{
		int l1,l2;
		l1=rand()%200+1;
		l2=rand()%200+1;
		if (l1>l2) swap(l1,l2);
		if (l1==l2) l2++;
		l1--;
		cout<<rand()%9+1;
		while (l1--)
		{
			cout<<rand()%10;
		}
		cout<<' ';
		l2--;
		cout<<rand()%9+1;
		while (l2--)
		{
			cout<<rand()%10;
		}
		cout<<endl;
	}
}