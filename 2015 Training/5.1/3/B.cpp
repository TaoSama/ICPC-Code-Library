//
//  Created by TaoSama on 2015-06-04
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

long long x, y, m;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> x >> y >> m) {
        if(x > y) swap(x, y);
        if(x >= m || y >= m) {
            cout << "0\n";
            continue;
        }
        if(x <= 0 && y <= 0) {
            cout << "-1\n";
            continue;
        }
        long long ans = 0;
        if(x < 0 && y > 0) {
            ans += (-x + y - 1) / y;
            x += y * ans;
        }
        //cout << ans << endl;
        while(!(x >= m || y >= m)) {
            ++ans;
            if(x > y) y = x + y;
            else x = x + y;
            // cout<<x<<' '<<y<<endl;
        }
        cout << ans << '\n';
    }
    return 0;
}
