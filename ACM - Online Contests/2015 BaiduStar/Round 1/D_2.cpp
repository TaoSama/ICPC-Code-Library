#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>

using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
const int maxn = 10010;

int n, m, sum[maxn], hs[maxn];
char str[10];
map<int, int> mp;
map<int, int> :: iterator it;
queue<int> q;

struct I {
    int k, x;
} op[maxn];

void add(int x, int v) {
    for(int i = x; i <= m; i += (i & -i)) sum[i] += v;
}

int ask(int x) {
    int res = 0;
    for(int i = x; i; i -= (i & -i)) res += sum[i];
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("F:\\ACM\\input\\in.txt", "r", stdin);
//   freopen("F:\\ACM\\input\\out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    int cas = 0;
    while(scanf("%d", &n) != EOF) {
        cas++;
        mp.clear();
        for(int i = 0; i < n; i++) {
            scanf("%s", str);
            if(str[0] == 'i') {
                op[i].k = 1;
                scanf("%d", &op[i].x);
                mp[op[i].x] = 1;
            } else if(str[0] == 'o') {
                op[i].k = 2;
            } else {
                op[i].k = 3;
            }
        }
        m = 0;
        for(it = mp.begin(); it != mp.end(); it++) {
            it->second = ++m;
            hs[m] = it->first;
        }
        while(!q.empty()) q.pop();
        memset(sum, 0, sizeof(sum));
        printf("Case #%d:\n", cas);
        for(int i = 0; i < n; i++) {
            if(op[i].k == 1) {
                add(mp[op[i].x], 1);
                q.push(op[i].x);
            } else if(op[i].k == 2) {
                int x = q.front(); q.pop();
                add(mp[x], -1);
            } else {
                int sz = q.size();
                sz = sz / 2 + 1;
                int l = 1, r = m, mid, ans;
                //    for(int i=1; i<=3; i++) cout<<ask(i)<<' '; cout<<endl;
                while(l <= r) {
                    mid = (l + r) >> 1;
                    int tmp = ask(mid);
                    if(tmp >= sz) r = mid - 1;
                    else l = mid + 1;
                }
                printf("%d\n", hs[l]);
            }
        }
    }
    return 0;
}
