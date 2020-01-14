#include <bits/stdc++.h>
using namespace std;
ifstream fin("16.in");
ofstream fout("16.out");
int k,i,j,v[10000],w[10000];
char s[10000];
int mult[]={1,0,-1,0};
int solve(int start,int lun) {
    int sol=0, poz=0;
    for (int i=start;i<=k;i+=lun) {
        for (int j=i;j<i+lun;j++)
            sol+=v[j]*mult[poz%4];
        poz++;
    }
    return abs(sol)%10;
}
int main() {
    fin>>s;
    k=strlen(s);
    for (i=0;i<k;i++)
        v[i]=s[i]-'0';
    k--;
    for (i=1;i<=100;i++) {
        for (j=0;j<=k;j++)
            w[j]=solve(j,j+1);
        for (j=0;j<=k;j++)
            v[j]=w[j];
    }
    for (i=0;i<=7;i++)
        fout<<v[i];
    return 0;
}
