//
//  Created by TaoSama on 2015-04-25
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
//#include <ctime>
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

int m, n, k, cnt[105];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    //time_t st = clock();
    cin >> m;
    while(m--) {
        cin >> n >> k;
        memset(cnt, 0, sizeof cnt);
        for(int i = 1; i <= n; ++i) {
            int x; cin >> x;
            cnt[x] ++ ;
        }

        bool ok = true;
        for(int i = 1; i <= n; ++i) {
            if(!cnt[i]) {
                ok = false;
                break;
            }
            cnt[i + k] += cnt[i] - 1;
        }

        if(ok) cout << "Jerry" << '\n';
        else cout << "Tom" << '\n';
    }
    //time_t ed = clock();
    //cout<<(ed - st + 0.0)/CLOCKS_PER_SEC<<endl;
    return 0;
}
