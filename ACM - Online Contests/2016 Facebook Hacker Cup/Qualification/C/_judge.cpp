#include<iostream>
#include<windows.h>
using namespace std;
int main() {
    int t = 100;
    for(int i = 1; ; ++i) {
		cout << "Test: " << i << endl;
        system("_gene > in.txt");
        system("_me < in.txt > 1.txt");
        system("_check < in.txt > 2.txt");
        if(system("fc 1.txt 2.txt")) break;
    }
    return 0;
}
