//
//  Created by TaoSama on 2015-09-24
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

int n;

bool isPrime(int x) {
    for(int i = 2; i * i <= x; ++i)
        if(x % i == 0) return false;
    return true;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        set<int> s;
        while(true) {
            if(s.count(n)) {
                n = -1;
                break;
            }
            s.insert(n);
            if(isPrime(n)) break;
            else {
                int t = n, sum = 0;
                for(int i = 2; i * i <= n; ++i) {
                    while(t % i == 0) {
                        sum += i;
                        t /= i;
                    }
                    if(t == 1) break;
                }
                if(t > 1) sum += t;
                n = sum;
            }
        }
        printf("%d\n", n);
    }
    return 0;
}
