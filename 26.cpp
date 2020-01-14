#include <bits/stdc++.h>
using namespace std;
ifstream fin("26.in");
ofstream fout("26.out");
int n,i,j,k,a[1000],b[1000];
char s[100000];
int main() {
    fin>>(s+1);
    n=strlen(s+1);
    for (i=1;i<=n/i;i++) {
        if (n%i==0) {
            a[++k]=i;
            b[k]=n/i;
        }
    }
    while (k--) {
        for (i=1;i<=a[k];i++) {
            for (j=1;j<=b[k];j++)
                fout<<s[j+(i-1)*b[k]];
            fout<<"\n";
        }
        fout<<"\n\n";
    }
    return 0;
}
