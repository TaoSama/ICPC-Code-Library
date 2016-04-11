//
//
//
//  Created by TaoSama on 2015-04-15
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
const string a[20] = {"zero", "one", "two", "three", "four",
                      "five", "six", "seven", "eight", "nine", "ten",
                      "eleven", "twelve", "thirteen", "fourteen",
                      "fifteen", "sixteen", "seventeen", "eighteen",
                      "nineteen"
                     };
const string b[10] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty",
                      "seventy", "eighty", "ninety"
                     };

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        if(n < 20) cout << a[n] << endl;
        else {
            int x = n / 10, y = n % 10;
            cout << b[x];
            if(y) cout << '-' << a[y] ;
            cout << endl;
        }
    }
    return 0;
}
