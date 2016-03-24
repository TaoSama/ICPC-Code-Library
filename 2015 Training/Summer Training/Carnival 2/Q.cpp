//
//  Created by TaoSama on 2015-08-02
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

int n, m, k;
string dir, s;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> m >> k) {
        for(int i = 0; i < 2; ++i) cin >> dir;
        cin >> s;
        int dc = dir == "tail" ? 1 : -1;
        int dm = m < k ? 1 : -1;
        bool cwin = true;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '1') dm = dc;
            k += dc;
            if(k == 1 || k == n) {
                if(k == n && dm == -1 || k == 1 && dm == 1) {
                    cout << "Controller " << i + 1 << '\n';
                    cwin = false;
                    break;
                }
                dc = -dc;
            }
        }
        if(cwin) cout << "Stowaway\n";
    }
    return 0;
}
