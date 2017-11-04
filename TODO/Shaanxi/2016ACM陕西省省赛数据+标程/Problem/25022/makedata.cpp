#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;
int main()
{
	srand(time(0));
	char ch[105]="data.in";
	freopen(ch,"w",stdout);
	for (int i=1;i<=80;i++)
	{
		int n,k,p;
		long long x;
		n=rand()%10+1;
		k=rand()%18+1;
		p=rand()%k+1;
		x=(long long)rand()*rand();
		if (rand()%10!=0) x=x%((long long)(pow(n,k)));
		if (x<=0) x=rand()+1;

		cout<<n<<' '<<k<<' '<<p<<' '<<x<<endl;
	}
}