//
//  Created by TaoSama on 2015-08-10
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
const int N = 1e7 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int notPrime[N], prime[N], pal[N], pp[N];
double d[N];

bool is(int x) {
    char s[10]; sprintf(s, "%d", x);
    int n = strlen(s);
    for(int i = 0; i < n >> 1; ++i) {
        if(s[i] != s[n - i - 1]) return false;
    }
    return true;
}

void gao() {
    //init primes
    int cnt = 0;
    for(int i = 2; i <= 1e6; ++i) {
        prime[i] = prime[i - 1];
        if(!notPrime[i]) {
            prime[i]++; pp[cnt++] = i;
        }
        for(int j = 0; j < cnt && i * pp[j] <= 1e6; j ++) {
            notPrime[i * pp[j]] = true;
            if(i % pp[j] == 0) break;
        }
    }

    for(int i = 1; i <= 1e6; ++i) {
        pal[i] = pal[i - 1];
        if(is(i)) pal[i]++;
    }
}

int p, q;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    gao();
    while(cin >> p >> q) {
//      for(int i = 1; i <= 90; ++i){
//          cout << i << ' ' << prime[i] << ' ' << pal[i] << endl;
//      }
        bool ok = false;
        for(int i = 1e6; i >= 1; --i) {
            if(q * prime[i] <= p * pal[i]) {
                cout << i << '\n';
                ok = true;
                break;
            }
        }
        if(!ok) cout << "Palindromic tree is better than splay tree\n";
    }
//    cout << clock() << '\n';
    return 0;
}
