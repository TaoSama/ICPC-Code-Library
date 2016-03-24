#include <iostream>
#include <cstdio>

using namespace std;

const int Mod=7;

int a,b,n;
struct Matrix
{
	int matrix[2][2];
	Matrix()
	{
		matrix[0][0]=matrix[1][1]=1;
		matrix[1][0]=matrix[0][1]=0;
	}
	Matrix operator*(Matrix x)
	{
		Matrix ret;
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < 2; ++j)
			{
				long long a=0;
				for (int k = 0; k < 2; ++k)
				{
					a=(a+(long long)matrix[i][k]*x.matrix[k][j]%Mod)%Mod;
				}
				ret.matrix[i][j]=a;
			}
		}
		return ret;
	}
	Matrix operator^(int n)
	{
		Matrix ret,x=*this;
		if(n==0) return ret;
		--n;
		while(n){
			if(n&1) ret=ret*x;
			x=x*x;
			n>>=1;
		}
		return ret;
	}
};

int Fun(int n,int a,int b)
{
	if(n<=1) return 1;
	Matrix x;
	x.matrix[0][0]=a;x.matrix[0][1]=1;
	x.matrix[1][0]=b;x.matrix[1][1]=0;
	x=x^(n-1);
	// cout<<"M:"<<endl;
	// cout<<x.matrix[0][0]<<' '<<x.matrix[0][1]<<endl;
	// cout<<x.matrix[1][0]<<' '<<x.matrix[1][1]<<endl;
	return (x.matrix[0][0]+x.matrix[1][0])%Mod;
}
int main(int argc, char const *argv[])
{
	//freopen("in.txt","r",stdin);
	while(cin>>a>>b>>n&&a){
		cout<<Fun(n,a,b)<<endl;
	}
	return 0;
}