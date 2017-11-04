/*****************************************
Author: lizi
Email: lzy960601@outlook.com
****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))


struct FastIO {
    static const int S = 5 << 20; //MB
    int wpos; char wbuf[S];
    FastIO() : wpos(0) {}
    inline int xchar() {
        static char buf[S];
        static int len = 0, pos = 0;
        if(pos == len)
            pos = 0, len = fread(buf, 1, S, stdin);
        if(pos == len) return -1;
        return buf[pos ++];
    }
    inline int xuint() {
        int c = xchar(), x = 0;
        while(~c && c <= 32) c = xchar();
        for(; '0' <= c && c <= '9'; c = xchar()) x = x * 10 + c - '0';
        return x;
    }
    inline int xint() {
        int s = 1, c = xchar(), x = 0;
        while(c <= 32) c = xchar();
        if(c == '-') s = -1, c = xchar();
        for(; '0' <= c && c <= '9'; c = xchar()) x = x * 10 + c - '0';
        return x * s;
    }
    inline void xstring(char* s) {
        int c = xchar();
        while(c <= 32) c = xchar();
        for(; c > 32; c = xchar()) * s++ = c;
        *s = 0;
    }
    inline void wchar(int x) {
        if(wpos == S) fwrite(wbuf, 1, S, stdout), wpos = 0;
        wbuf[wpos ++] = x;
    }
    inline void wint(int x) {
        if(x < 0) wchar('-'), x = -x;

        char s[24];
        int n = 0;
        while(x || !n) s[n ++] = '0' + x % 10, x /= 10;
        while(n--) wchar(s[n]);
    }
    inline void wstring(const char* s) {
        while(*s) wchar(*s++);
    }
    ~FastIO() {
        if(wpos) fwrite(wbuf, 1, wpos, stdout), wpos = 0;
    }
} io;

const int maxn=100005;
struct node
{
    LL a,b,c,d;
    int ans;
    void read()
    {
        a=io.xuint();
        b=io.xuint();
        c=io.xuint();
        d=io.xuint();
    }
}dat[maxn];
int n,m;

LL mi(LL x,int y,LL mod)
{
    LL ret=1;
    while(y>0)
    {
        if(y&1)ret=ret*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ret;
}

void solve(int l,int r,int lo,int hi)
{
    int mid=(l+r)>>1,flag;
    struct node num=dat[mid];
    LL ma=num.d+1;
    LL now=mi(num.b,lo-1,num.d);
    for(int i=lo;i<=hi;i++)
    {
        now=now*num.b%num.d;
        LL temp=(num.a*now%num.d+num.c)%num.d;
        if(temp<ma)
        {
            ma=temp;
            flag=i;
        }
    }
    dat[mid].ans=flag;
    if(l<mid)solve(l,mid-1,lo,flag);
    if(r>mid)solve(mid+1,r,flag,hi);
}

int main()
{
    int _=0;
    n=io.xuint();m=io.xuint();
    while(n>0 && m>0)
    {
        _++;
        for(int i=1;i<=n;i++)dat[i].read();
        solve(1,n,1,m);
        prrn(_);
        for(int i=1;i<=n;i++)printf("%d\n",dat[i].ans);
        n=io.xuint();m=io.xuint();
    }
    return 0;
}
