
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

char s[N];
int ok[N][N], minv[N][N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(cin >> (s + 1)) {
        int n = strlen(s + 1);
        long long ans = 0;
        for(int i = 1; i <= n; ++i) {
            int sum1 = 0, sum2 = 0;
            ok[i][i - 1] = 0, minv[i][i - 1] = INF;
            for(int j = i; j <= n; ++j) {
                sum1 += s[j] == '?' ? 1 : (s[j] == '(' ? 1 : -1); 
                sum2 += s[j] == '?' ? -1 : (s[j] == '(' ? 1 : -1); 
                ok[i][j] = ok[i][j - 1];
                minv[i][j] = minv[i][j - 1];
                if(ok[i][j] >= 0) ok[i][j] = sum1;
                minv[i][j] = min(minv[i][j], sum2);
            }
        }

        for(int i = 1; i <= n; ++i) {
            vector<int> pos;
            pos.emplace_back(i - 1);
            int sum = 0;
            for(int j = i; j <= n; ++j) {
                sum += s[j] == '?' ? 0 : s[j] == '(' ? 1 : -1; 
                if(s[j] == '?') pos.emplace_back(j);
                if((j - i + 1) & 1) continue;
                if(pos.size() < abs(sum)) continue;
                int o = sum > 0 ? (pos.size() - sum) / 2 : -sum + (pos.size() + sum) / 2;
                // printf("%d %d -> sum=%d (=%d ", i, j, sum, o);
                o = pos[o];
                ans += (ok[i][o] >= 0 && ok[i][o] + minv[o + 1][j] >= 0);
                // printf("ok[%d][%d]=%d min[%d][%d]=%d\n", i, o, ok[i][o], o + 1, j, minv[o + 1][j]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
