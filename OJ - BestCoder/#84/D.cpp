//
//  Created by TaoSama on 2016-07-23
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

bool vis[N];
vector<int> primes;
int f[N], g[N];
void gao() {
    for(int i = 2; i < N; ++i) {
        if(!vis[i]) {
            g[i] = i;
            primes.push_back(i);
        }
        for(int j = 0; j < primes.size() && i * primes[j] < N; ++j) {
            vis[i * primes[j]] = true;
            g[i * primes[j]] = primes[j];
            if(i % primes[j] == 0) break;
        }
    }
    for(int i = 2; i < N; ++i) f[i] = f[i - 1] + !vis[i];
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    gao();
    int t; scanf("%d", &t);
    while(t--) {
        int n, d; scanf("%d%d", &n, &d);
        n = (n - 1) / d;
        if(d < N) n = min(n, g[d]);
        else {
            int first = -1;
            for(int i = 0; i < primes.size(); ++i) {
                if(!(primes[i] * primes[i] <= d && primes[i] <= n)) break;
                if(d % primes[i] == 0) {
                    first = primes[i];
                    break;
                }
            }
            if(first == -1) first = d;
            n = min(n, first);
        }
        printf("%d\n", f[n]);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
