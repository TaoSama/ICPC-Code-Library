#include <bits/stdc++.h>

using namespace std;

const int maxn = 30;
int n, m;
int a[maxn + 5];
bool solve() {
  int half = n / 2, lft = n - half;
    vector<bool> have(m);
    for(int s = 1; s < 1 << half; ++s){
        int mod = 0;
        for(int i = 0; i < half; ++i)
            if(s >> i & 1) mod = (mod + a[i]) % m;
        if(mod == 0) return true;
        have[mod] = true;
    }

    for(int s = 1; s < 1 << lft; ++s){
        int mod = 0;
        for(int i = 0; i < lft; ++i){
            if(s >> i & 1) mod = (mod + a[half + i]) % m;
        }
        if(mod == 0) return true;
        if(have[m - mod]) return true;
    }
    return false;
    vector<int> cur(m), nxt(m);
    cur[0] = 1;
    for(int i = 0; i < n; ++i) {
        nxt = cur;
        for(int j = 0; j < m; ++j)
            nxt[(j + a[i]) % m] += cur[j];
        swap(cur, nxt);
    }
    return cur[0] > 1;
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    if(solve()) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
