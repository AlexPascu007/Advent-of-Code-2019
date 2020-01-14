#include <bits/stdc++.h>
using namespace std;
ifstream fin("1.in");
ofstream fout("1.out");
long long s,x,y;
int main() {
    while (fin>>x) {
        y=x;
        while (y>0) {
            y/=3;
            y-=2;
            s+=y;
        }
    }
    fout<<s;
    return 0;
}
