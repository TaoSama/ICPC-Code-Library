//
//  Created by TaoSama on 2015-06-15
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, m, a[N];

bool check(long long x) {
    long long can, left, last;

    int j = n;
    while(!a[j]) j--;
    left = a[j];
    if(x - j <= 0) return false;
//    cout << "j: " << j << " left: " << left << endl;
    for(int i = 1; i <= m; ++i) {
        can = x - j;
//        cout << "i: " <<i << " j: " << j << " left: " << left << endl;
        if(can >= left) can -= left, --j;
        else {
            left -= can;
            continue;
        }
        while(j && can >= a[j]) can -= a[j], --j;
//        cout << can <<endl;
        left = a[j] - can;

        if(j == 0) return true;
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> m) {
        long long sum = n;
        for(int i = 1; i <= n; ++i) cin >> a[i], sum += a[i];

        long long l = 0, r = sum;
//        cout << sum << endl;
        while(l <= r) {
            long long mid = l + r >> 1;
            if(check(mid)) r = mid - 1;
            else l = mid + 1;
//            cout << l << ' ' << mid << ' ' << r << endl;
        }
        cout << l << '\n';
    }
    return 0;
}
//8  52
