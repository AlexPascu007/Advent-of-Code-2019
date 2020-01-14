/*#include <bits/stdc++.h>
using namespace std;
ifstream fin("10.in");
ofstream fout("10.out");
int n,m,i,j,asteroizi[1010][1010],x,y,astmax,cnt;
char a[1010][1010];
set< pair<int,int> > v;
double det(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (x2-x1)*(y3-y1)-(x3-x1)*(y2-y1);
}
double dist(int x1,int y1,int x2,int y2) {
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
bool check(int x1,int y1,int x2,int y2) {
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (x1==i&&y1==j)
                continue;
            if (x2==i&&y2==j)
                continue;
            if (a[x1][y1]=='#') {
                double d=det(x1,y1,x2,y2,i,j);
                if (d==0&&dist(x1,y1,x2,y2)>dist(x1,y1,i,j)&&dist(x1,y1,x2,y2)>dist(x2,y2,i,j))
                    return 0; //sunt coliniare si la o distanta mai mare
            }
        }
    }
    return 1;
}
int main() {
    fin>>n>>m; //citesc dimensiunile mai intai
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++) {
            fin>>a[i][j];
            if (a[i][j]=='#')
                v.insert({i,j});
        }
    for (auto it:v) {
        x=it.first, y=it.second;
        for (i=1;i<=n;i++) {
            for (j=1;j<=m;j++) {
                if (x==i&&y==j)
                    continue;
                if (a[i][j]=='#')
                    if (check(x,y,i,j)==1)
                        asteroizi[x][y]++;
            }
        }
    }
    for (i=1;i<=n;i++) {
        for (j=1;j<=m;j++) {
            astmax=max(astmax,asteroizi[i][j]);
            fout<<asteroizi[i][j]<<" ";
        }
        fout<<"\n";
    }
    fout<<astmax;
    return 0;
}
