#include <cstdio>


using namespace std;


int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
#endif

    long long n, k;
    while(scanf("%lld%lld", &n, &k) == 2){
       long long d = n / 2 / (k + 1);
       long long c = k * d;
       printf("%lld %lld %lld\n", d, c, n - d - c);
    }
    return 0;
}
