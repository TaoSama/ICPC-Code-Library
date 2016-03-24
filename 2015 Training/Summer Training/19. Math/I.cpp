//
//  Created by TaoSama on 2015-08-14
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

string s;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> s) {
        // "00"/"0" > "0"/n
        int two = 0, one = 0, n = s.size();
        for(int i = 0; i < s.size(); ++i) { //It is a circle
            if(s[i] == '0') {
                one++;
                if(s[(i + 1) % n] == '0') two++;
            }
        }
        if(two * n > one * one) cout << "SHOOT\n";
        else if(two * n == one * one) cout << "EQUAL\n";
        else cout << "ROTATE\n";
    }
    return 0;
}
