#include <bits/stdc++.h>
using namespace std;
ifstream fin("2.in");
ofstream fout("2.out");
int nr,i,j,k,l,v[12345],poz1,poz2,poz3,cnt,w[12345],noun,verb;
char s[12345];
int main() {
    fin>>s;
    l=strlen(s);
    for (i=0;i<l;i++) {
        if (s[i]==',') {
            v[k++]=nr;
            nr=0;
            continue;
        }
        nr*=10;
        nr+=s[i]-'0';
    }
    v[k++]=nr;
    v[1]=12, v[2]=2;
    i=0;
    while (i<=k) {
        if (v[i]==99)
            break;
        else if (v[i]==1) {
            v[v[i+3]]=v[v[i+1]]+v[v[i+2]];
            i+=4;
        }
        else if (v[i]==2) {
            v[v[i+3]]=v[v[i+1]]*v[v[i+2]];
            i+=4;
        }
    }
    fout<<v[0];
    return 0;
}

