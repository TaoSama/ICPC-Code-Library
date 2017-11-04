//
//  Created by TaoSama on 2015-06-06
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

#define debug(x) printf(#x": %d\n", x);

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 5e5 + 10;

int n, k, d[N];

void init() {
    for(int i = 1; i <= 5e5; ++i) d[i] = 1;
    for(int i = 2; i <= 5e5; ++i)
        for(int j = i; j <= 5e5; j += i)
            d[j]++;
}



int a[N];
char name[N][15];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    //ios_base::sync_with_stdio(0);

    init();
    while(scanf("%d%d", &n, &k) == 2) {
        for(int i = 1; i <= n; ++i) {
            scanf("%s%d", name[i], a + i);
            add(i, 1);
        }
        int ans, p = k, Max = -INF;  //p真实位置 k名次
        for(int i = 1; i <= n; ++i) {
            add(p, -1);
            if(d[i] > Max) Max = d[i], ans = p;
            int mod = n - i;
            if(!mod) break;
//            cout << "mod: " << mod << " p: " << p << ' ' << sum(p) << endl;
            if(a[p] > 0) k = (sum(p) + a[p]) % mod;
            else k = ((sum(p) + a[p]) % mod + mod) % mod + 1;
//            cout << ((sum(p) + a[p]) % mod + mod) % mod << endl;
            if(k == 0) k = mod;
            p = binSearch(k);
//            cout << "k: " << k << " p: " << p << endl;
        }
        printf("%s %d\n", name[ans], Max);
    }
    return 0;
}

/*
7 3
a 3
b 2
c -5
d 4
e 8
f 2
g -6

ans: g 4
*/
