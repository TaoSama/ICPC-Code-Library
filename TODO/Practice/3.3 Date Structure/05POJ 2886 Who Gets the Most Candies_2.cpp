//
//  Created by TaoSama on 2015-06-11
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 5e5 + 10;

typedef long long LL;

int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
map<LL, LL> mp, rmp; //divisors .. anti-prime
LL a[100], b[100], ct; //a: anti-prime b: its divisors

void dfs(int k, LL cur, LL cnt, int limit) {
    if(cur > N) return;
    if(!mp.count(cnt)) mp[cnt] = cur;
    else mp[cnt] = min(cur, mp[cnt]);
    for(int i = 1; i <= limit; ++i) {
        if(1.0 * cur * p[k] > N) break;
        dfs(k + 1, cur *= p[k], cnt * (i + 1), i);
    }
}

//when try to iterate, do not forget to control the bound (< ct)
void init() {
    dfs(0, 1, 1, 60);
    map<LL, LL>::iterator i = mp.begin();
    for(; i != mp.end(); ++i) rmp.insert(make_pair(i->second, i->first));
    i = rmp.begin();
    for(; i != rmp.end(); ++i) {
        if(ct > 0 && i->second < b[ct - 1]) continue;
        a[ct] = i->first;
        b[ct++] = i->second;
    }
}

int n, k, v[N];
char name[N][10];

int bit[N];

void add(int i, int x) {
    for(; i <= n; i += i & -i) bit[i] += x;
}

int find_kth(int k) {
    int m = 31 - __builtin_clz(n);  //求32位log2(n)
    int cnt = 0, ret = 0;
    for(int i = m; i >= 0; --i) {
        ret += 1 << i;
        if(ret >= n || cnt + bit[ret] >= k) ret -= 1 << i;
        //可能会有很多个数都满足cnt+bit[ret]>=k 找的最大的ret满足cnt+bit[ret]<k
        else cnt += bit[ret];
        //cnt累加比当前ret小的总数
    }
    //ret是cnt（即小于等于ret的数的个数）小于k的情况的最大值 ret+1即第k大的数
    return ret + 1;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    init();
    while(scanf("%d%d", &n, &k) == 2) {
        memset(bit, 0, sizeof bit);
        for(int i = 1; i <= n; ++i) {
            scanf("%s%d", name[i], v + i);
            add(i, 1);
        }

        int ans, idx = 0;
        while(a[idx] <= n && idx < ct) idx++;
        int cnt = a[idx - 1], Max = b[idx - 1]; //第cnt个就是最大的
        for(int i = 1; i <= cnt; ++i) {
            int mod = n - i;
            ans = find_kth(k);
            if(mod == 0) break;
            add(ans, -1);
            if(v[ans] > 0) k = (k - 1 + v[ans]) % mod;
            else k = ((k - 1 + v[ans]) % mod + mod) % mod + 1;
            if(k == 0) k = mod;
        }
        printf("%s %d\n", name[ans], Max);
    }
    return 0;
}
