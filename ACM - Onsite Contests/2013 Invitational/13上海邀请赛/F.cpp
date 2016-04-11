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

int a[15];
string s = "pqruvwxyz";

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t;  cin >> t;
    while(t--) {
        bool first = true, yes = false;
        for(int i = 1; i <= 10; ++i) {
            int x; cin >> x;
            if(i != 10) {
                if(x != 0) {
                    yes = true;
                    if(x > 0 && !first) cout << "+";
                    first = false;
                    if(x > 0) {
                        if(x != 1) cout << x << s[i - 1];
                        else cout << s[i - 1];
                    } else {
                        if(x != -1) cout << x << s[i - 1];
                        else cout << "-" << s[i - 1];
                    }
                }
            } else {
                if(x != 0) {
                    yes = true;
                    if(x > 0 && !first) cout << "+";
                    cout << x;
                }
            }
        }
        if(yes) cout << '\n';
        else cout << "0\n";
    }
    return 0;
}
