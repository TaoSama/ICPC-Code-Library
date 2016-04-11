//
//  Created by TaoSama on 2016-01-28
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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

typedef long long LL;

int n;

bool isPrime(int x) {
    for(LL i = 2; i * i <= x; ++i)
        if(x % i == 0) return false;
    return true;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        if(n < 9) printf("1\n%d\n", n);
        else {
            printf("3\n3");
            for(int i = 2; i <= n - 3; ++i) {
                if(isPrime(i) && isPrime(n - 3 - i)) {
                    printf(" %d %d\n", i, n - 3 - i);
                    break;
                }
            }
        }
    }
    return 0;
}
