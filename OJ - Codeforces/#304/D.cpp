//
//  Created by TaoSama on 2015-05-23
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
const int N = 5e6;

long long fact[N];
int prime[N], p;
bool is[N];

void seive() {
    memset(is, true, sizeof is);
    for(int i = 2; i <= N; ++i) {
        if(is[i]) {
            prime[p++] = i;
            for(int j = i + i; j <= N; j += i) is[j] = false;
        }
    }
}

void init() {
    seive();
    for(int i = 2; i <= N; ++i) {
        int t = i;
        //cout<<i<<":"<<endl;
        for(int j = 0; j < p; ++j) {
            if(prime[j] * prime[j] > t) break;
            while(t % prime[j] == 0) {
                fact[i]++;
                //cout<<j<<' ';
                t /= prime[j];
            }
        }
        //cout<<endl;
        if(t != 1) fact[i] ++;
    }
    /*for(int i = 1; i <= 10; ++i)
        cout << i << ' ';
    cout << endl;
    for(int i = 1; i <= 10; ++i)
        cout << fact[i] << ' ';
    cout << endl;*/
    for(int i = 2; i <= N; ++i)
        fact[i] += fact[i - 1];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    //time_t st = clock();
    init();
    int t; scanf("%d", &t);
    while(t--) {
        int x, y; scanf("%d%d", &x, &y);
        //cout << fact[x] << ' ' << fact[y] << endl;
        printf("%I64d\n", fact[x] - fact[y]);
    }
    //time_t ed = clock();
    //printf("%.3fs\n", (ed - st + 0.0) / CLOCKS_PER_SEC);
    return 0;
}
