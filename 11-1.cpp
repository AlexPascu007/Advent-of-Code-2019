#include <bits/stdc++.h>
using namespace std;
ifstream fin("11.in");
ofstream fout("11.out");
long long f[123450];
long long nr,n,i,j,k,l,v[123450],a,b,dir,cnt,x,sgn,base,vizitate,pas;
long long *p[10];
int di[]={-1,0,1,0};
int dj[]={0,1,0,-1};
map< pair<int,int>, int> viz,cul;
deque<int> moves;
char s[123450];
long long nrcif(long long n) {
    long long cif=0;
    while (n) {
        cif++;
        n/=10;
    }
    return cif;
}
long long verif(long long x,long long poz) {
    long long cod=x%10+((x/10)%10)*10; //ultimele 2 cifre
    for (j=1;j<=100;j++)
        f[j]=0;
    poz=i;
    x/=100;
    long long param=0;
    while (x) {
        f[++param]=x%10;
        x/=10;
    }
    for (j=1;j<=4;j++) {
        if (f[j]==0)
            p[j]=&v[v[poz+j]];
        else if (f[j]==1)
            p[j]=&v[poz+j];
        else
            p[j]=&v[v[poz+j]+base];
    }
    if (cod==99)
        return -1;
    if (cod==1) {
        *p[3]=*p[1]+*p[2];
        i+=4;
    }
    else if (cod==2) {
        *p[3]=(*p[1])*(*p[2]);
        i+=4;
    }
    else if (cod==3) {
        *p[1]=cul[{a,b}];
        i+=2;
    }
    else if (cod==4) {
        moves.push_back(*p[1]);
        i+=2;
    }
    else if (cod==5) {
        if (*p[1]==0)
            i+=3;
        else
            i=*p[2];
    }
    else if (cod==6) {
        if (*p[1]==0)
            i=*p[2];
        else
            i+=3;
    }
    else if (cod==7) {
        if (*p[1]<*p[2])
            *p[3]=1;
        else
            *p[3]=0;
        i+=4;
    }
    else if (cod==8) {
        if (*p[1]==*p[2])
            *p[3]=1;
        else
            *p[3]=0;
        i+=4;
    }
    else if (cod==9) {
        base+=*p[1];
        i+=2;
    }
    while (moves.size()>=2) {
        cul[{a,b}]=moves.front();
        moves.pop_front();
        if (viz[{a,b}]==0)
            vizitate++;
        viz[{a,b}]=1;
        int urm=moves.front();
        moves.pop_front();
        if (urm==0) //in stanga
            dir+=3;
        if (urm==1) //in dreapta
            dir++;
        dir%=4;
        a+=di[dir];
        b+=di[dir];
    }
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
    //cul[{0,0}]=1;
    while (i<=k) {
        if (v[i]==99)
            break;
        else { //e cod
            if (verif(v[i],i)==-1)
                break;
        }
    }
    fout<<vizitate;
    return 0;
}
