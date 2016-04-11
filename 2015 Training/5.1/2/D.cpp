//
//  Created by TaoSama on 2015-06-03
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

int n, q, a[N];
string s;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> s) {
        n = s.size();
        for(int i = 1; i < n; ++i) {
            if(s[i] == s[i - 1])
                a[i] = a[i - 1] + 1;
            else a[i] = a[i - 1];
        }
        //for(int i = 0; i < n; ++i) cout<< a[i]<< ' '; cout<<endl;
        cin >> q;
        while(q--) {
            int x, y; cin >> x >> y;
            cout << a[y - 1] - a[x - 1] << '\n';
        }
    }
    return 0;
}
