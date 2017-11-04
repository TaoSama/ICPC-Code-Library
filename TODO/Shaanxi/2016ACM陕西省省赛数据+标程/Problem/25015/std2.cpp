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
ll a[maxn],ans[maxn];
ll cnt[maxn][maxm],c[maxn][maxm];

ll getf(ll x) { return x == f[x] ? x : (f[x] = getf(f[x])); }

void tarjan(ll i) {
    for (ll j:e[i]) {
        tarjan(j);
        f[j] = i;
    }
    rep(j,1,n) lca[i][j] = lca[j][i] = getf(j);
}

void sigma(ll i) {
    for (ll j:e[i]) {
        sigma(j);
        rep(t,1,1001) {
            cnt[i][t] += cnt[j][t];
            c[i][t]   += c[j][t];
        }
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
        memset(c,0,sizeof(c));
        rep(i,1,n) {
            get(a[i]);
            ++c[i][a[i]];
        }

        rep(i,1,n) f[i] = i;
        tarjan(1);

        memset(cnt,0,sizeof(cnt));
        rep(i,1,n) rep(j,i+1,n) {
            k = lca[i][j];
            t = abs(a[i]-a[j]); tt = min(a[i]+a[j],1001);
            ++cnt[k][t+1]; --cnt[k][tt];
        }
        rep(i,1,n) rep(t,1,1001) cnt[i][t] += cnt[i][t-1];
        sigma(1);
        rep(i,1,n) rep(t,1,1001) c[i][t] += c[i][t-1];

        memset(ans,0,sizeof(ans));
        rep(i,1,n) {
            t = a[i];
            tt = min(t+t,1001);
            for (j=i; j; j=par[j]) ans[j] += cnt[j][t] - c[j][tt-1] + 1;
        }

        printf("Case #%d:\n",T);
        rep(i,1,n) printf("%d\n",ans[i]/3);
    }

    return 0;
}
