#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int N=1e5+10;

int n,c;
struct Acm
{
	string id,name;
	int sco;
}a[N];
bool cmp(Acm x,Acm y)
{
	if(c==1)
		return atoi(x.id.c_str())<atoi(y.id.c_str());
	else if(c==2){
		if(x.name==y.name) return atoi(x.id.c_str())<atoi(y.id.c_str());
		return x.name<=y.name;
	}
	else{
		if(x.sco==y.sco) return atoi(x.id.c_str())<atoi(y.id.c_str());
		return x.sco<=y.sco;
	}
}

int main(int argc, char const *argv[])
{
	//freopen("in.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	int kase=0;
	while(cin>>n>>c&&n)
	{
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i].id>>a[i].name>>a[i].sco;
		}
		sort(a,a+n,cmp);
		cout<<"Case "<<++kase<<":"<<endl;
		for (int i = 0; i < n; ++i)
		{
			cout<<a[i].id<<' '<<a[i].name<<' '<<a[i].sco<<endl;

		}
	}
	return 0;
}
