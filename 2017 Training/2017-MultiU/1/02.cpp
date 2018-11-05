
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
char s[N];
long long pp[N];
string ss[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    pp[0] = 1;
    for(int i = 1; i < N; ++i) pp[i] = pp[i - 1] * 26 % MOD;
    while(scanf("%d", &n) == 1){
        vector<vector<int>> coff(26, vector<int>(N, 0));
        vector<int> canZero(26, 1);
        for(int i = 1; i <= n; ++i){
            scanf("%s", s);
            ss[i] = s;
            for(size_t j = 0; j < ss[i].size(); ++j){
                int x = ss[i][j] - 'a';
                int idx = ss[i].size() - j - 1;
                coff[x][idx]++;
            } 
            if(ss[i].size() > 1) canZero[ss[i][0] - 'a'] = false;
        }
        for(int i = 0; i < 26; ++i){
            for(int j = 0; j < N - 1; ++j){
                coff[i][j + 1] += coff[i][j] / 26;
                coff[i][j] %= 26;
            }
        }
        vector<int> id(26, 0);
        for(int i = 0; i < 26; ++i) id[i] = i;
        sort(id.begin(), id.end(), [&](int x, int y){
            for(size_t i = 0; i < coff[x].size(); ++i){
                int j = coff[x].size() - i - 1;
                if(coff[x][j] > coff[y][j]) return true;
                else if(coff[x][j] < coff[y][j]) return false;
             }
             return x < y;
        });
        int p = 25;
        while(!canZero[id[p]]) --p;
        int t = id[p];
        id.erase(id.begin() + p);
        id.push_back(t);

        long long sum = 0;
        for(int i = 0; i < 26; ++i){
            int j = id[i];
            int x = 26 - i - 1;
            for(size_t k = 0; k < coff[j].size(); ++k){
                sum += coff[j][k] * pp[k] % MOD * x % MOD;
                sum %= MOD;
            }
        }
        static int kase = 0;
        printf("Case #%d: %lld\n", ++kase, sum); 
    } 
    return 0;
}
