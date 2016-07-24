#include <bits/stdc++.h>
using namespace std;
int main() {
    int t = 1e5;
    for(int i = 1; i <= t; ++i) {
        cout << "Test: " << i << endl;
//        system("tree");
        system("tree > in.txt");
//        puts("start");
        clock_t st = clock();
//        system("\"HDU 5732\"");
        system("1010std < in.txt > out.txt");
//        system("std < in.txt > 2.txt");
        double cost = 1.0 * (clock() - st) / CLOCKS_PER_SEC;
        printf("Time cost: %.2f\n", cost);
//        if(system("fc /n 1.txt 2.txt")) break;
    }
    return 0;
}
