//
//
//
//  Created by TaoSama on 2015-04-25
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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
const int N = 1e5 + 10;

bool is_prime[500005], used[1005];
int n, a[1005], prime[42000], n_prime[500005], cnt, ans;

void dfs(int dep)
{
	if(dep == n + 1){
		bool ok = true;
		int now = 0, Max;
		for(int i = n; i >= 1; --i)
			if(used[i]) ++now;
		if(now <= ans) return;
		for(int i = n; i >= 1; --i)
			if(used[i]) {
				Max= i;
				break;
			}
		now = 0;
		for(int i = 1; i <= n; ++i){
			if(used[i]){
				++now;
				for(int j = i + 1; j <= n; ++j){
					if(used[j]){
						for(int k = 1; k <= n_prime[a[Max]]; ++k){
							if(a[i] * prime[k] == a[j]){
								return;
							}
						}
					}
				}
			}
		}
		ans = max(ans, now);
		return;
	}
	used[dep] = true;
	dfs(dep + 1);
	used[dep] = false;
	dfs(dep + 1);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    memset(is_prime, true, sizeof is_prime);
    is_prime[0] = is_prime[1] = false;
    n_prime[0] = n_prime[1] = 0;
    cnt = 0;
    for(int i = 2; i <= 500000; ++i) {
		n_prime[i] = cnt;
        if(is_prime[i]) {
            prime[++cnt] = i;
            n_prime[i] = cnt;
            for(int j = i + i; j <= 500000; j += i)
                is_prime[j] = false;
        }
    }
    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d", &n);
        int sum = 0;
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        sort(a + 1, a + 1 + n);
        ans = -INF;
        dfs(1);
        printf("Case #%d: %d\n", ++kase, ans);
    }
    return 0;
}
