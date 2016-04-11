//
//  Created by TaoSama on 2015-05-08
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

string a, ans[30];
int k;
char first[30];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> k >> a) {
        if(k > a.size()) cout << "NO\n";
        else {
            if(k == 1) cout << "YES\n" << a << '\n';
            else {
                int cnt = 1, idx = 0;
                first[1] = a[0];
                for(int i = 1; i < a.size(); ++i) {
                    bool ok = true;
                    for(int j = 1; j <= cnt; ++j) {
                        if(a[i] == first[j]) {
                            ok = false;
                            break;
                        }
                    }
                    if(!ok) continue;
                    else {
                        ans[cnt++] = a.substr(idx, i - idx);
                        first[cnt] = a[i];
                        idx = i;
                        if(cnt == k) break;
                    }
                }
                if(cnt == k) {
                    ans[cnt] = a.substr(idx, a.size() - idx);
                    cout << "YES\n";
                    for(int i = 1; i <= k; ++i)
                        cout << ans[i] << '\n';
                } else cout << "NO\n";
            }
        }
    }
    return 0;
}
