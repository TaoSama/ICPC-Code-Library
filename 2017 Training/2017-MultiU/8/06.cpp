#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=100000+5;
struct SAM
{
    int step[MAXN*2],pre[MAXN*2],nxt[MAXN*2][26];
    int tot,last;
    inline int newNode(int cnt)
    {
        step[++tot]=cnt;
        pre[tot]=0;
        for (int i=0;i<26;i++) nxt[tot][i]=0;
        return tot;
    }
    
    inline void extend(int x)
    {
        int p=last;
        int np=newNode(step[p]+1);
        while (p && !nxt[p][x]) nxt[p][x]=np,p=pre[p];
        if (!p) pre[np]=1;
        else
        {
            int q=nxt[p][x];
            if (step[q]==step[p]+1) pre[np]=q;
            else 
            {
                int nq=newNode(step[p]+1);
                for (int i=0;i<26;i++) nxt[nq][i]=nxt[q][i];
                pre[nq]=pre[q];
                pre[q]=pre[np]=nq;
                while (p&&nxt[p][x]==q) nxt[p][x]=nq,p=pre[p]; 
            }
    
        }
        last=np;
    }
    
    inline void clear()
    {
        int tot=0;
        last=newNode(tot);
    }
    
    inline int Query(const string& s)
    {  
        int ret=0,cnt=0;  
        int p=1;  
        for(char c : s)
        {  
            int index=c-'a';
            if(nxt[p][index]) p=nxt[p][index],cnt++;
            else
            {    
                while (p && !nxt[p][index]) p=pre[p];
                if(!p) p=1,cnt=0;  
                    else cnt=step[p]+1,p=nxt[p][index];
                    /*由于沿着pre返回得到的字符串是当前字符串的后缀，所以第一个拥有index孩子的就是最长满足的后缀，长度即为step+1*/  
            }
            ret=max(ret,cnt);  
        }  
        return ret;  
    }  
}suf;

int n;
char str[MAXN];
string s[MAXN];

int main()
{
    // init(); 
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            scanf("%s", str);
            s[i] = string(str);
        }
        int q; scanf("%d", &q);
        while(q--){
            int x, y; scanf("%d%d", &x, &y);
            if(s[x].size() < s[y].size()) swap(x, y);
            suf.clear();
            // printf("%d %d\n", x, y);
            for(char c : s[x]) suf.extend(c - 'a');
            printf("%d\n", suf.Query(s[y]));            
        }
    }
    return 0;
}
