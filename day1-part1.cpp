#include <bits/stdc++.h>
using namespace std;
ifstream fin("1.in");
ofstream fout("1.out");
long long s,x,y;
int main() {
    while (fin>>x) {
        x/=3;
        x-=2;
        if (x>0)
            s+=x;
    }
    fout<<s;
    return 0;
}

