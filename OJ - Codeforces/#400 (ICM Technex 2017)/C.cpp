//
//  Created by TaoSama on 2017-02-23
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;


typedef long long LL;
int n, k, a[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> k) {
        map<LL, int> mp;
        LL power[60] = {1};

        int target = 50;
        if(k == 1) target = 1;
        else if(k == -1) target = 2;
        for(int i = 1; i < target; ++i) {
            power[i] = power[i - 1] * k;
            if(power[i] > 1e15) {target = i; break;}
        }

        LL sum = 0; ++mp[sum];
        LL ans = 0;
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
            sum += a[i];
            for(int t = 0; t < target; ++t)
                if(mp.count(sum - power[t]))
                    ans += mp[sum - power[t]];
            ++mp[sum];
        }
//        LL judge = 0;
//        for(int i = 1; i <= n; ++i){
//          LL sum = 0;
//          for(int j = i; j <= n; ++j){
//              sum += a[j];
//              for(int k = 0; k < target; ++k) if(sum == power[k]) ++judge;
//          }
//        }
        cout << ans << endl;
//        cout << judge << endl;
    }

    return 0;
}
