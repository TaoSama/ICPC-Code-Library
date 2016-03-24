//
//
//
//  Created by TaoSama on 2015-04-17
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

map<string, int> mp;
const string month[] = {"", "January", "February", "March", "April",
                        "May", "June", "July", "August", "September",
                        "October", "November" , "December"
                       };
char s[100], t[100];

bool check(int x) {
    return x % 4 == 0 && x % 100 != 0 || x % 400 == 0;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    //ios_base::sync_with_stdio(0);

    int kase = 0;
    for(int i = 1; i <= 12; ++i)
        mp[month[i]] = i;
    int T; scanf("%d ", &T);
    while(T--) {
        int ans = 0;
        gets(s); gets(t);
        //printf("%s\n", s);
        //printf("%s\n", t);
        char sm[20], tm[20]; int sd, sy, td, ty;
        sscanf(s, "%s%d,%d", sm, &sd, &sy);
        sscanf(t, "%s%d,%d", tm, &td, &ty);
        //printf("%s %d %d\n", sm, sd, sy);
        //printf("%s %d %d\n", tm, td, ty);

        int m = mp[string(sm)];
        if((m == 1 || m == 2 && sd <= 29) && check(sy)) ++ ans;
        m = mp[string(tm)];
        if((m == 2 && td == 29 || m > 2) && check(ty)) ++ ans;
        if(sy == ty && check(sy)) --ans;

        while(!check(++sy)); sy -= 2000;
        while(!check(--ty)); ty -= 2000;
        int l = sy / 4 - sy / 100 + sy / 400;
        int r = 0;
        if(ty >= 0) r = ty / 4 - ty / 100 + ty / 400;
        //cout << sy << ' ' << l << endl;
        //cout << ty << ' ' << r << endl;
        int t = r - l + 1;
        if(t < 0) t = 0;
        ans += t;
        printf("Case #%d: %d\n", ++kase, ans);
    }
    return 0;
}
