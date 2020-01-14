#include <bits/stdc++.h>
using namespace std;
ifstream fin("4.in");
ofstream fout("4.out");
int a,b,i,x,v[10],ok1,ok2,j,cnt;
char s[20];
int main() {
    fin>>s;
    for (i=0;s[i]!='-';i++)
        a=a*10+s[i]-'0';
    i++;
    for (;s[i]!=0;i++)
        b=b*10+s[i]-'0';
    for (i=a;i<=b;i++) {
        for (j=1;j<=10;j++)
            v[j]=0;
        x=i;
        j=0;
        while (x!=0) {
            v[++j]=x%10;
            x/=10;
        }
        ok1=0, ok2=1;
        for (j=1;j<=6;j++) {
            if (v[j]==v[j+1]&&v[j-1]!=v[j]&&v[j+1]!=v[j+2])
                ok1=1;
            if (v[j]<v[j+1])
                ok2=0;
        }
        if (ok1==1&&ok2==1)
            cnt++;
    }
    fout<<cnt;
    return 0;
}
