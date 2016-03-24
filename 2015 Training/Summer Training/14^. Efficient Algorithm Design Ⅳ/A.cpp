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
#include <ctime>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N], l[N], r[N];
long long sum[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

//  srand(time(0));
//  for(int i = 1; i <= 100; ++i){
//      int n;
//      if(i == 1) n = 100000;
//      else n = rand() % 100000 + 1;
//      cout << n << endl;
//      for(int j = 1; j <= n; ++j){
//          cout << rand() % 1000000 <<' ' ;
//      }
//      cout << endl;
//  } return 0;

    int kase = 0;
    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);

        for(int i = 1; i <= n; ++i) {
            l[i] = r[i] = i;
            sum[i] = sum[i - 1] + a[i];
        }
        a[0] = a[n + 1] = -1;
        for(int i = 1; i <= n; ++i) {
            while(a[l[i] - 1] >= a[i])
                l[i] = l[l[i] - 1];
        }
        for(int i = n; i >= 1; --i) {
            while(a[r[i] + 1] >= a[i])
                r[i] = r[r[i] + 1];
        }

        long long ans = -INF;
        int st = 1, ed = n;
        for(int i = 1; i <= n; ++i) {
            int &L = l[i], &R = r[i];
//            cout << L << ' ' << R << endl;
            long long cur = (sum[R] - sum[L - 1]) * a[i];
            if(cur > ans || cur == ans && R - L < ed - st) {
                ans = cur;
                st = L, ed = R;
            }
        }
        if(kase++) printf("\n");
        if(ans == 0) st = ed = 1;
        printf("%lld\n%d %d\n", ans, st, ed);
    }
    return 0;
}
