#include <bits/stdc++.h>
using namespace std;
int main() {
	system("g++ -O2 -std=c++11 gene.cpp -o gene");
	puts("gene compiled successfully...");
	system("g++ -O2 -std=c++11 std.cpp -o std");
	puts("std compiled successfully...");
	system("g++ -O2 -std=c++11 me.cpp -o me");
	puts("mycpp compiled successfully...");
	puts("\ntest begins...");

    int t = 300;
    for(int i = 1; i <= t; ++i) {
        cout << "Test: " << i << endl;
        system("gene > 1.in");
        clock_t st = clock();
        system("me < 1.in > 1.out");
        system("std < 1.in > std.out");
        double cost = 1.0 * (clock() - st) / CLOCKS_PER_SEC;
        if(system("fc /n 1.out std.out")) break;
    }
	system("del *.o & del *.exe");
    return 0;
}
