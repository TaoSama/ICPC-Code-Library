//
//  Created by TaoSama on 2016-08-07
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

int k;
char s[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> k >> (s + 1)) {
        vector<int> cnt(26, 0);
        for(int i = 1; s[i]; ++i) {
            cnt[s[i] - 'a']++;
        }
        bool ok = true;
        string ans;
        for(int i = 0; i < 26 && ok; ++i) {
            if(!cnt[i]) continue;
            if(cnt[i] % k) {
                ok = false;
            }
            ans += string(cnt[i] / k, 'a' + i);
        }
        if(!ok) puts("-1");
        else {
            for(int i = 0; i < k; ++i) cout << ans;
            cout << endl;
        }
    }

    return 0;
}
