#include <bits/stdc++.h>
using namespace std;
ifstream fin("3.in");
ofstream fout("3.out");
int nr,i,j,k,p,dir,x,y,xant,yant,dx,dy,distmin,sol;
char s[5010],t[5010];
pair<int,int> v[500010],w[500010];
int main() {
    cin.getline(s,5000);
    x=y=0;
    v[1]={x,y}, k=1;
    for (i=0;i<strlen(s);i++) {
        if (s[i]=='R')
            dx=0, dy=1;
        if (s[i]=='L')
            dx=0, dy=-1;
        if (s[i]=='U')
            dx=-1, dy=0;
        if (s[i]=='D')
            dx=1, dy=0;
        if (s[i]>='0'&&s[i]<='9') {
            nr=0;
            while (s[i]>='0'&&s[i]<='9')
                nr=nr*10+s[i++]-'0';
            xant=v[k].first, yant=v[k].second;
            for (j=1;j<=nr;j++) {
                v[++k]={xant+dx*j,yant+dy*j};
            }
        }
    }
    cin.getline(t,5000);
    x=y=0;
    w[++p]={x,y};
    for (i=0;i<strlen(t);i++) {
        if (t[i]=='R')
            dx=0, dy=1;
        if (t[i]=='L')
            dx=0, dy=-1;
        if (t[i]=='U')
            dx=-1, dy=0;
        if (t[i]=='D')
            dx=1, dy=0;
        if (t[i]>='0'&&t[i]<='9') {
            nr=0;
            while (t[i]>='0'&&t[i]<='9')
                nr=nr*10+t[i++]-'0';
            xant=w[p].first, yant=w[p].second;
            for (j=1;j<=nr;j++) {
                w[++p]={xant+dx*j,yant+dy*j};
            }
        }
    }
    distmin=INT_MAX;
    for (i=2;i<=k;i++) {
        for (j=2;j<=p;j++) {
            if (v[i].first==w[j].first&&v[i].second==w[j].second) {
                fout<<i+j-2;
                return 0;
            }
        }
    }
    fout<<distmin;
    return 0;
}
