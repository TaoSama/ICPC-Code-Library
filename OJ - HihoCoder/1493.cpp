//
//  Created by TaoSama on 2017-04-02
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
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

bool notPrime[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    for(int i = 2; i < N; ++i)
        if(!notPrime[i])
            for(int j = i + i; j < N; j += i) notPrime[j] = 1;

    int n; cin >> n;
    for(int i = 2; i <= n; ++i) {
        if(!notPrime[i] && !notPrime[n - i]) {
            cout << i << ' ' << n - i << endl;
            break;
        }
    }

    return 0;
}
