#include <bits/stdc++.h>
using namespace std;
ifstream fin("5.in");
ofstream fout("5.out");
bitset<12345> f;
int nr,n,i,j,k,l,v[12345],poz1,poz2,poz3,cnt,x,sgn;
int *p[10];
char s[12345];
int nrcif(int n) {
    int cif=0;
    while (n) {
        cif++;
        n/=10;
    }
    return cif;
}
int verif(int x,int poz) {
    int cod=x%10+((x/10)%10)*10; //ultimele 2 cifre
    if (cod==0)
        cin>>cod;
    f.reset();
    poz=i;
    x/=100;
    int param=0;
    while (x) {
        f[++param]=x%10;
        x/=10;
    }
    for (j=1;j<=4;j++) {
        if (f[j]==0)
            p[j]=&v[v[poz+j]];
        else
            p[j]=&v[poz+j];
    }
    if (cod==99) {
        cout<<"finish";
        return -1;
    }
    if (cod==1) {
        *p[3]=*p[1]+*p[2];
        i+=4;
    }
    else if (cod==2) {
        *p[3]=(*p[1])*(*p[2]);
        i+=4;
    }
    else if (cod==3) {
        cin>>*p[1];
        i+=2;
    }
    else if (cod==4) {
        cout<<*p[1]<<" ";
        i+=2;
    }
    else
        cout<<cod<<" ";
}
int main() {
    fin>>s;
    l=strlen(s);
    sgn=1;
    for (i=0;i<l;i++) {
        if (s[i]==',') {
            v[k++]=nr*sgn;
            sgn=1;
            nr=0;
            continue;
        }
        if (s[i]=='-') {
            sgn=-1; continue;
        }
        nr*=10;
        nr+=s[i]-'0';
    }
    v[k++]=nr*sgn;
    i=0;
    while (i<=k) {
        if (v[i]==99)
            break;
        else { //e cod
            if (verif(v[i],i)==-1)
                return 0;
        }
    }
    return 0;
}
