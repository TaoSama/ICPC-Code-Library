//
//  Created by TaoSama on 2015-07-27
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

int n, k;
char s[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> k) {
        cin >> (s + 1);
        int n = strlen(s + 1);
        for(int i = 1; i < n; ++i) {
			if(k == 0) break;
            if(s[i] == '4' && s[i + 1] == '7') {
                if(i & 1) {
                    if(i + 2 <= n && s[i] == '4' && s[i + 1] == '7' && s[i + 2] == '7') {
                        if(k & 1) s[i + 1] = '4';
                        break;
                    }
                    s[i + 1] = '4';
                } else {
                    s[i] = '7';
                    i -= 2;
                }
//                cout << (s + 1) << endl;
                if(--k == 0) break;
            }
        }
        cout << (s + 1) << '\n';
    }
    return 0;
}
