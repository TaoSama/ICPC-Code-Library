//
//  Created by TaoSama on 2016-03-30
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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

char s[105];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(gets(s)) {
        if(*s == 0) {puts("Unknown!"); continue;}
        int n = strlen(s);
        bool isCpp = s[0] != '_' && s[n - 1] != '_';
        for(int i = 0; i < n; ++i) {
            if(isupper(s[i]) || s[i] != '_' && !isalpha(s[i])
                    || s[i] == '_' && s[i + 1] == '_') {
                isCpp = false;
                break;
            }
        }
        bool isJava = islower(s[0]);
        for(int i = 0; i < n; ++i) {
            if(s[i] == '_' || !isalpha(s[i])) {
                isJava = false;
                break;
            }
        }
        if(!isCpp && !isJava) {puts("Unknown!"); continue;}

        string t = s;
        if(isCpp) {
            for(int i = 0; i < t.size(); ++i) {
                if(t[i] == '_') {
                    t.erase(i, 1);
                    t[i] = toupper(t[i]);
                }
            }
        }
        if(isJava) {
            for(int i = 0; i < t.size(); ++i) {
                if(isupper(t[i])) {
                    t[i] = tolower(t[i]);
                    t.insert(i, "_");
                    ++i;
                }
            }
        }
        puts(t.c_str());
    }
    return 0;
}
