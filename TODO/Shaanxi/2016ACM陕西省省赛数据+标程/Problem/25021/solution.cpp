#include <iostream>
#include <stdio.h>
#include <string.h>
#define mod 1000000007
using namespace std;
long long dp[255][3][8][2][2][2];
long long mi[255];
//第i位，是否比原数字大，0表示小，1表示等，2表示大，mod7的余数，上一位是否是8，这一位是不是0
long long cal(string s)
{
	int wei=0;
	int arr[255];
	for (int i=s.size()-1;i>=0;i--)
	{
		wei++;
		arr[wei]=s[i]-'0';
	}

	memset(dp,0,sizeof(dp));
	dp[0][1][0][0][0][0]=1;
	for (int i=0;i<wei;i++)
	for (int j=0;j<=2;j++)
	for (int k=0;k<=6;k++)
	for (int p=0;p<=1;p++)
	for (int l=0;l<=1;l++)
	for (int x=0;x<=1;x++)
	if (dp[i][j][k][p][l][x])
	{
		//第i位，是否比原数字大，0表示小，1表示等，2表示大，mod7的余数，上一位是否是8，这一位是不是0
		for (int nex=0;nex<=9;nex++)
		{
			int I,J,K,P,L,X;
			I=i+1;
			if (nex>arr[I] || (nex==arr[I] && j==2))
				J=2;
			if (nex==arr[I] && j==1)
				J=1;
			if (nex<arr[I] || (nex==arr[I] && j==0))
				J=0;
			K=(k+mi[i]*nex)%7;
			if (p==1 && nex==1) continue;
			if (nex==8)
				P=1;
			else
				P=0;
			if (nex==0)
				L=1;
			else
				L=0;
			if (x || nex==2 || nex==3 || nex==5)
				X=1;
			else
				X=0;
			dp[I][J][K][P][L][X]+=dp[i][j][k][p][l][x];
			dp[I][J][K][P][L][X]%=mod;
		}
	}
	long long ans=0;
	for (int i=wei;i<=wei;i++)
	for (int j=0;j<=1;j++)
	for (int k=0;k<=0;k++)
	for (int p=0;p<=1;p++)
	for (int l=0;l<=1;l++)
	{
		ans+=dp[i][j][k][p][l][1];
		ans%=mod;
	}
	return ans;
}

string sub(string str1,string str2)//高精度减法
{
    string str;
    int tmp=str1.length()-str2.length();
    int cf=0;
    for(int i=str2.length()-1;i>=0;i--)
    {
        if(str1[tmp+i]<str2[i]+cf)
        {
            str=char(str1[tmp+i]-str2[i]-cf+'0'+10)+str;
            cf=1;
        }
        else
        {
            str=char(str1[tmp+i]-str2[i]-cf+'0')+str;
            cf=0;
        }
    }
    for(int i=tmp-1;i>=0;i--)
    {
        if(str1[i]-cf>='0')
        {
            str=char(str1[i]-cf)+str;
            cf=0;
        }
        else
        {
            str=char(str1[i]-cf+10)+str;
            cf=1;
        }
    }
    str.erase(0,str.find_first_not_of('0'));//去除结果中多余的前导0
    return str;
}

int main()
{
	mi[0]=1;
	for (int i=1;i<=254;i++)
		mi[i]=mi[i-1]*10%mod;
	int s;
	cin>>s;
	while (s--)
	{
		string n,m;
		cin>>n>>m;
		n=sub(n,"1");
		if (n=="") n="0";
		long long ans1,ans2;
		ans1=cal(n);
		ans2=cal(m);
		cout<<n<<' '<<m<<endl;
		cout<<(ans2-ans1+mod)%mod<<endl;
	}
}
