#include <bits/stdc++.h>
using namespace std;
ifstream fin("8.in");
ofstream fout("8.out");
int layer,cnt,lin,col,i,j,k,a[150][100][10],img[100][10],f[100][10];
char c;
int main() {
    layer=1;
    lin=1, col=0;
    while (fin>>c) {
        col++, cnt++;
        a[layer][lin][col]=c-'0';
        if (col==25) {
            col=0, lin++;
        }
        if (cnt==150)
            layer++, cnt=0, lin=1, col=0;
    }
    layer--, lin=6, col=25;
    for (i=1;i<=layer;i++) {
        for (j=1;j<=lin;j++) {
            for (k=1;k<=col;k++) {
                if (a[i][j][k]!=2&&f[j][k]==0) {
                    img[j][k]=a[i][j][k];
                    f[j][k]=1;
                }
            }
        }
    }
    for (i=1;i<=lin;i++) {
        for (j=1;j<=col;j++) {
            if (img[i][j]==0)
                fout<<" ";
            else
                fout<<"*";
        }
        fout<<"\n";
    }
    return 0;
}

