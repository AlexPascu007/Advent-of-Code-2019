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
    for (noun=0;noun<99;noun++) {
        for (verb=0;verb<99;verb++) {
            w[1]=noun, w[2]=verb;
            for (cnt=0;cnt<k;cnt+=4) {
                if (w[cnt]==1) {
                    poz1=v[cnt+1], poz2=v[cnt+2], poz3=v[cnt+3];
                    w[poz3]=w[poz1]+w[poz2];
                }
                if (w[cnt]==2) {
                    poz1=v[cnt+1], poz2=v[cnt+2], poz3=v[cnt+3];
                    w[poz3]=w[poz1]*w[poz2];
                }
                if (w[cnt]==99)
                    break;
            }
            if (w[0]==19690720) {
                fout<<100*noun+verb;
                return 0;
            }
            for (cnt=0;cnt<k;cnt++)
                w[cnt]=v[cnt];
        }
    }
    return 0;
}
