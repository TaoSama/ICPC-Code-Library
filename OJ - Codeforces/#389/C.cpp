//
//  Created by TaoSama on 2016-12-25
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



int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int n; string s;
    while(cin >> n >> s) {
        char last1 = -1, last2 = -1;
        int ans = 0;
        for(char c : s) {
            if(c == 'L' || c == 'R') {
                if(last1 == -1) last1 = c;
                else if(last1 != c){
                    last1 = c; last2 = -1;
                    ++ans;
                }
            } else {
                if(last2 == -1) last2 = c;
                else if(last2 != c){
                    last1 = -1; last2 = c;
                    ++ans;
                }
            }
//            prln(ans);
        }
        cout << ans  + 1 << endl;
//        return 0;
    }

    return 0;
}

/*
4
RURD

6
RRULDD

26
RRRULURURUULULLLDLDDRDRDLD

3
RLL

4
LRLR
*/
