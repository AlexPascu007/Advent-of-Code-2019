#include <bits/stdc++.h>
using namespace std;
ifstream fin("13.in");
ofstream fout("13.out");
long long f[123450];
long long nr,n,i,j,k,l,v[123450],sgn,base,sol,x,y,a,b,id,ball,paddle,scor;
long long *p[10];
map< pair<long long,long long>, long long> viz,cul;
deque<long long> in,out;
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
        if (in.size()==0)
            return -2;
        *p[1]=in.front();
        in.pop_front();
        i+=2;
    }
    else if (cod==4) {
        out.push_back(*p[1]);
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
    return 0;
}
int main() {
    fin>>s;
    l=strlen(s);
    sgn=1;
    in.push_back(0);
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
        while (verif(v[i],i)==0);
        while (out.size()!=0) {
            a=out.front();
            out.pop_front();
            b=out.front();
            out.pop_front();
            id=out.front();
            out.pop_front();
            if (id==3)  //paddle
                paddle=x;
            else if (id==4) //ball
                ball=x;
            if (x==-1&&y==0) { //scor
                fout<<id<<"\n";
                scor=max(scor,id);
            }
        }
        if (paddle<ball)
            in.push_back(1); //in dreapta
        else if (paddle<ball)
            in.push_back(-1); //in stanga
        else
            in.push_back(0); //neutral
    }
    //fout<<scor;
    return 0;
}
