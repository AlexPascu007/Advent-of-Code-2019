#include <bits/stdc++.h>
using namespace std;
ifstream fin("8.in");
ofstream fout("8.out");
int layer,cnt,i,j,a[150][200],zero[200],zmin,ind,unu,doi;
char c;
int main() {
    layer=1;
    while (fin>>c) {
        cnt++;
        a[layer][cnt]=c-'0';
        if (cnt==150) {
            layer++;
            cnt=0;
        }
    }
    zmin=200;
    for (i=1;i<=layer-1;i++) {
        for (j=1;j<=150;j++) {
            if (a[i][j]==0)
                zero[i]++;
        }
        if (zero[i]<zmin) {
            zmin=zero[i], ind=i;
        }
    }
    for (j=1;j<=150;j++) {
        if (a[ind][j]==1)
            unu++;
        if (a[ind][j]==2)
            doi++;
    }
    fout<<unu*doi;
    return 0;
}
