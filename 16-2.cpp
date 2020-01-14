#include <bits/stdc++.h>
using namespace std;
ifstream fin("16.in");
ofstream fout("16.out");
int k,i,j,v[100000000],nr,sum,lung,pas,faza;
char s[1000];
int main() {
    fin>>s;
    k=strlen(s);
    for (i=0;i<k;i++)
        v[i]=s[i]-'0';
    for (i=0;i<7;i++)
        nr=nr*10+v[i];
    k--;
    lung=k;
    for (pas=1;pas<10000;pas++)
        for (i=0;i<=lung;i++)
            v[++k]=v[i];
    for (faza=1;faza<=100;faza++) {
        sum=0;
        for (i=k;i>=k/2-2;i--) {
            sum+=v[i];
            v[i]=sum%10;
        }
    }
    for (i=nr;i<=nr+7;i++)
        fout<<v[i];
    return 0;
}
