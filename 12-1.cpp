#include <bits/stdc++.h>
using namespace std;
ifstream fin("12.in");
ofstream fout("12.out");
unsigned long long n,i,j,pas,kin,pot,sol,m,X,Y,Z;
struct luna{
    long long x,y,z;
};
luna poz[5],v[5],init[5];
int main() {
    for (i=1;i<=4;i++) {
        fin>>poz[i].x>>poz[i].y>>poz[i].z;
        init[i]=poz[i];
    }
    for (pas=1;;pas++) {
        for (i=1;i<=4;i++)
            for (j=1;j<=4;j++) {
                if (i==j)
                    continue;
                if (poz[i].x<poz[j].x)
                    v[i].x++;
                else if (poz[i].x>poz[j].x)
                    v[i].x--;
                if (poz[i].y<poz[j].y)
                    v[i].y++;
                else if (poz[i].y>poz[j].y)
                    v[i].y--;
                if (poz[i].z<poz[j].z)
                    v[i].z++;
                else if (poz[i].z>poz[j].z)
                    v[i].z--;
            }
        int eg=0;
        for (i=1;i<=4;i++) {
            poz[i].x+=v[i].x;
            poz[i].y+=v[i].y;
            poz[i].z+=v[i].z;
            if (poz[i].x==init[i].x&&v[i].x==0)
                eg++;
        }
        if (eg==4) { //avem ciclu la x
            X=pas;
            break;
        }
    }
    for (i=1;i<=4;i++) {
        poz[i].x=init[i].x;
        poz[i].y=init[i].y;
        poz[i].z=init[i].z;
        v[i].x=v[i].y=v[i].z=0;
    }
    for (pas=1;;pas++) {
        for (i=1;i<=4;i++)
            for (j=1;j<=4;j++) {
                if (i==j)
                    continue;
                if (poz[i].x<poz[j].x)
                    v[i].x++;
                else if (poz[i].x>poz[j].x)
                    v[i].x--;
                if (poz[i].y<poz[j].y)
                    v[i].y++;
                else if (poz[i].y>poz[j].y)
                    v[i].y--;
                if (poz[i].z<poz[j].z)
                    v[i].z++;
                else if (poz[i].z>poz[j].z)
                    v[i].z--;
            }
        int eg=0;
        for (i=1;i<=4;i++) {
            poz[i].x+=v[i].x;
            poz[i].y+=v[i].y;
            poz[i].z+=v[i].z;
            if (poz[i].y==init[i].y&&v[i].y==0)
                eg++;
        }
        if (eg==4) { //avem ciclu la y
            Y=pas;
            break;
        }
    }
    for (i=1;i<=4;i++) {
        poz[i].x=init[i].x;
        poz[i].y=init[i].y;
        poz[i].z=init[i].z;
        v[i].x=v[i].y=v[i].z=0;
    }
    for (pas=1;;pas++) {
        for (i=1;i<=4;i++)
            for (j=1;j<=4;j++) {
                if (i==j)
                    continue;
                if (poz[i].x<poz[j].x)
                    v[i].x++;
                else if (poz[i].x>poz[j].x)
                    v[i].x--;
                if (poz[i].y<poz[j].y)
                    v[i].y++;
                else if (poz[i].y>poz[j].y)
                    v[i].y--;
                if (poz[i].z<poz[j].z)
                    v[i].z++;
                else if (poz[i].z>poz[j].z)
                    v[i].z--;
            }
        int eg=0;
        for (i=1;i<=4;i++) {
            poz[i].x+=v[i].x;
            poz[i].y+=v[i].y;
            poz[i].z+=v[i].z;
            if (poz[i].z==init[i].z&&v[i].z==0)
                eg++;
        }
        if (eg==4) { //avem ciclu la z
            Z=pas;
            break;
        }
    }
    fout<<X<<" "<<Y<<" "<<Z<<"\n";
    m=1LL*X*Y/__gcd(X,Y); //cmmmc(X+1,Y+1)
    m=1LL*m*Z/__gcd(m,Z); //cmmmc(X+1,Y+1,Z+1)
    fout<<m;
    return 0;
}
//1860280 X
//1930520 Y
//1446240 Z
