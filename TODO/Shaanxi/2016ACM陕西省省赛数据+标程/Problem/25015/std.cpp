#include<bits/stdc++.h>
#define rep(i,s,t) for (ll i=(s); i<=(t); ++i)
#define dep(i,t,s) for (ll i=(t); i>=(s); --i)
#define i first
#define j second
#define sz(x) ll((x).size())

using namespace std;

template<class T>
inline void get(T &n) {
	char c = getchar();
	while (c!='-' && (c<'0' || c>'9')) c = getchar();
	n = 0; T s = 1; if (c=='-') s = -1,c = getchar();
	while (c>='0' && c<='9') n*=10,n+=c-'0',c=getchar();
	n *= s;
}

typedef int ll;
typedef pair<ll,ll> PII;

const ll maxn = 1010,maxm = 1010;
ll n,par[maxn],lca[maxn][maxn],f[maxn];
vector<ll> e[maxn];
PII v[maxn];
ll a[maxn],opt[maxn],ans[maxn];
ll sum[maxn],low,cnt[maxn][maxm];

ll getf(ll x) { return x == f[x] ? x : (f[x] = getf(f[x])); }

void tarjan(ll i) {
    for (ll j:e[i]) {
        tarjan(j);
        f[j] = i;
    }
    rep(j,1,n) lca[i][j] = lca[j][i] = getf(j);
}

void upd(ll i,ll l,ll r) {
    rep(t,l+1,r) sum[i] -= cnt[i][t];
    for (ll j:e[i]) upd(j,l,r);
}

void sigma(ll i) {
    opt[i] = sum[i];
    for (ll j:e[i]) {
        sigma(j);
        opt[i] += opt[j];
    }
}

int main() {
    ll i,j,k,t,tt,Test,tmp;
    get(Test);
    rep(T,1,Test) {
        get(n);
        rep(i,1,n) e[i].clear();
        rep(i,2,n) {
            get(par[i]);
            e[par[i]].push_back(i);
        }
        rep(i,1,n) {
            get(a[i]);
            v[i] = {a[i],i};
        }
        low = 0;
        sort(v+1,v+n+1);

        rep(i,1,n) f[i] = i;
        tarjan(1);

        memset(cnt,0,sizeof(cnt)); memset(sum,0,sizeof(sum));
        memset(ans,0,sizeof(ans));
        rep(x,1,n) {
            t = v[x].i; i = v[x].j;
            if (t > low) upd(1,low,t),low = t;
            sigma(1);
            for (j=i; j; j=par[j]) {
                ans[j] += opt[j];
            }
            rep(y,1,x-1) {
                tt = v[y].i; j = v[y].j;
                tmp = min(t + tt,1001);
                if (tmp > low) {
                    k = lca[i][j];
                    ++cnt[k][tmp]; ++sum[k];
                }
            }
        }

        printf("Case #%d:\n",T);
        rep(i,1,n) printf("%d\n",ans[i]);
    }

    return 0;
}
