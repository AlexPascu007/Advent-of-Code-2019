#include <bits/stdc++.h>
#define DIM 5010
using namespace std;
ifstream fin("5.in");
ofstream fout("5.out");
int cnt=1,x,y,i,d[DIM],sol,f[DIM],start,sfarsit,dist,niv[DIM],t[DIM];
map<string,int> m;
vector<int> L[DIM];
char v[3],w[3],c;
string s;
void dfs(int nod,int nivel) {
    f[nod]=1;
    niv[nod]=nivel;
    for (int i=0;i<L[nod].size();i++) {
        int vecin=L[nod][i];
        if (f[vecin]==0) {
            t[vecin]=nod;
            dfs(vecin,nivel+1);
        }
    }
}
int main() {
    while (fin>>v) {
        s.clear();
        for (i=0;v[i]!=')';i++)
            s+=v[i];
        if (s=="COM")
            m[s]=1;
        else {
            if (m[s]==0)
                m[s]=++cnt;
        }
        x=m[s];
        s.clear();
        i++;
        for (;i<strlen(v);i++)
            s+=v[i];
        if (m[s]==0)
            m[s]=++cnt;
        y=m[s];
        if (s=="YOU")
            start=x;
        if (s=="SAN")
            sfarsit=x;
        L[x].push_back(y);
        L[y].push_back(x);
    }
    dfs(1,0);
    while (start!=sfarsit) {
        dist++;
        if (niv[start]>niv[sfarsit])
            start=t[start];
        else
            sfarsit=t[sfarsit];
    }
    fout<<dist;
    return 0;
}
