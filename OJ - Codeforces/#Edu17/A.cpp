//
//  Created by TaoSama on 2017-01-25
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

long long n, k;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> k) {
        vector<long long> d1, d2;
        for(long long i = 1; i * i <= n; ++i) {
            if(n % i == 0) {
                d1.push_back(i);
                if(i * i != n) d2.push_back(n / i);
            }
        }
        reverse(d2.begin(), d2.end());
        if(k > d1.size() + d2.size()) cout << "-1\n";
        else {
            if(k <= d1.size()) cout << d1[k - 1] << endl;
            else cout << d2[k - d1.size() - 1] << endl;
        }
    }

    return 0;
}
