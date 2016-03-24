//
//  Created by TaoSama on 2015-08-15
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
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

long long n;

vector<int> prime;
void gao() {
    bool vis[N] = {};
    for(int i = 2; i < N; ++i) {
        if(vis[i]) continue;
        prime.push_back(i);
        for(int j = i + i; j < N; j += i) vis[j] = 1;
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    gao();
    while(scanf("%lld", &n) == 1 && n) {
        long long t = abs(n); //fuck negative number!
        vector<int> e;
        for(int i = 0; i < prime.size(); ++i) {
            int &p = prime[i], cnt = 0;
            if(p > abs(n)) break;
            while(t % p == 0) {
                ++cnt;
                t /= p;
            }
            e.push_back(cnt);
            if(t == 1) break;
        }
        if(t > 1) {
            puts("1");
            continue;
        }
        int Max = *max_element(e.begin(), e.end());
        int sub = 1;
        if(n < 0) {
            sub = 2;
            if(Max % 2 == 0) Max--;
        }
        for(int i = Max; i >= 1; i -= sub) {
//          printf("i = %d\n", i);
            bool ok = true;
            for(auto &d : e) {
                if(d % i) {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                printf("%d\n", i);
                break;
            }
        }
//        puts("end");
    }
    return 0;
}
