//
//  Created by TaoSama on 2015-05-20
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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

int n;
bool over[105];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        memset(over, false, sizeof over);
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                int x; cin >> x;
                if(x == 1) over[i] = true;
                else if(x == 2) over[j] = true;
                else if(x == 3) over[i] = over[j] = true;
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; ++i) if(!over[i]) ++ans;
        cout << ans << '\n';
        for(int i = 1; i <= n; ++i)
            if(!over[i]) cout << i << ' ';
        cout << '\n';
    }
    return 0;
}
