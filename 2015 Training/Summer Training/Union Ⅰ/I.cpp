//
//  Created by TaoSama on 2015-08-22
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

long long d[] = {1, 2, 5, 25, 125};
long long a, b;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    vector<long long> v;
    for(int i = 0; i < 5; ++i) {
        long long t = d[i];
        while(t <= 0x7fffffff) {
            v.push_back(t);
            t *= 10;
        }
    }
    sort(v.begin(), v.end());
//  for(int i = 0; i < v.size(); ++i) cout << v[i] << ' '; cout << endl;

    while(cin >> a >> b) {
        int l = lower_bound(v.begin(), v.end(), a) - v.begin();
        int r = upper_bound(v.begin(), v.end(), b) - v.begin(); --r;
//      cout << l << ' ' << r << '\n';
        cout << r - l + 1 << '\n';
    }
    return 0;
}

/*
1 2 5 10 20 25 50 100 125 200 250 500 1000 1250 2000 2500 5000 10000 12500 20000
25000 50000 100000 125000 200000 250000 500000 1000000 1250000 2000000 2500000
*/
/*
for(long long i = 1; i <= 10000000; ++i) {
    char buf[10]; sprintf(buf, "%d", i);
    int n = strlen(buf);
    bool ok = true;
    long long mul = 1;
    for(int j = 1; j <= n; ++j) mul *= 10;
    for(long long j = 1; j <= 10000; ++j) {
        if((j * mul + i) % i) {
            ok = false;
            break;
        }
    }
    if(ok) printf("%d ", i);
}
printf("\n");
*/

