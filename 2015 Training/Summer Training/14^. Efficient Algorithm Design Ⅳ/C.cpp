//
//  Created by TaoSama on 2015-08-04
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

int n, a[505];

int p[505];
int Atoint() {
    int res = 0;
    for(int i = 0; i < n; ++i) {
        int x = a[i];
        for(int j = 0; j < i; ++j)
            if(a[j] < a[i]) --x;
        res += p[n - i - 1] * x;
    }
    return res;
}

void print(int res) {
    bool u[505] = {};
    for(int i = 0; i < n; ++i) {
        int x = res / p[n - i - 1];
        for(int j = 0; j < n; ++j) {
            if(!u[j]) {
                if(x == 0) {
                    printf("%d%c", j, " \n"[i + 1 == n]);
                    u[j] = 1;
                    break;
                }
                --x;
            }
            res %= p[n - i - 1];
        }
    }
}

void work() {
    int i, j, k;
    n = 9; p[0] = 1;
    for(int i = 1; i <= n; ++i)
        p[i] = i * p[i - 1];
    set<int> H;
    for(int k = 0; k < n; ++k) {
        for(int i = 0; i < n; ++i) a[i] = (i + k) % n;
        for(int j = 0; j < 1000000; ++j) {
            i = rand() % n;
            swap(a[i], a[(i + 3) % n]);
            swap(a[(i + 1) % n], a[(i + 2) % n]);
            H.insert(Atoint());
        }
    }
    if(H.size() < 40) {
        for(auto &i : H) print(i);
    }
    printf("cnt = %d\n", H.size());
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
//  ios_base::sync_with_stdio(0);

//  work();

    int t; cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> a[i];
        int cnt = 0;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j < i; ++j)
                if(a[j] > a[i]) ++cnt;
        if(n % 2 == 0 || cnt % 2 == 0) cout << "possible\n";
        else cout << "impossible\n";
    }
    return 0;
}
