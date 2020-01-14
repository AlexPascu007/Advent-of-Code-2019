#include <bits/stdc++.h>
using namespace std;
ifstream fin("17.in");
ofstream fout("17.out");
long long n,k=-1,nr,i,a,b,pozx,pozy;
char c;
long long v[100000];

long long vect[100000];
string s[100000];
int fr[20];
long long *param[10];
long long baza;
void citire()
{
    long long semn=1;
    while(fin>>c)
    {
        if(c==',')
        {
            v[++k]=nr*semn;
            semn=1;
            nr=0;
        }
        else if(c>='0'&&c<='9')
        {
            s[k+1]+=c;
            nr*=10LL;
            nr+=c-'0';
        }
        else if(c=='-')
        {
            semn=-1;
        }
    }
    v[++k]=nr;
}
long long solve(string s,long long poz)
{
    long long l=s.size()-1;
    long long cod;
    if(s.size()>=2)
        cod=s[l]-'0'+(s[l-1]-'0')*10;
    else
        cod=s[0]-'0';
    if(cod==0)
        cin>>cod;
    for(int i=0; i<=10; i++)
        fr[i]=0;
    l-=2;
    long long parametrii=0;
    while(l>=0)
    {
        fr[++parametrii]=s[l]-'0';
        l--;
    }
    for(long long index=1; index<=4; index++)
    {
        if(fr[index]==0)
            param[index]=&v[v[poz+index]];
        else if(fr[index]==1)
            param[index]=&v[poz+index];
        else
            param[index]=&v[v[poz+index]+baza];
    }
    { /// colapsabil
        if(cod==99)
        {
          //  fout<<"finish";
            return -1;
        }
        if(cod==1)
        {
            *param[3]=*param[1]+*param[2];
            i+=4;
        }
        if(cod==2)
        {
            *param[3]=*param[1]* *param[2];
            i+=4;
        }
        if(cod==5)
        {
            if(*param[1]==0)
            {
                i+=3;
            }
            else
                i=*param[2];
        }
        if(cod==6)
        {
            if(*param[1]!=0)
            {
                i+=3;
            }
            else
                i=*param[2];
        }
        if(cod==7)
        {
            if(*param[1]<*param[2])
            {
                *param[3]=1;
            }
            else *param[3]=0;
            i+=4;
        }
        if(cod==8)
        {
            if(*param[1]==*param[2])
            {
                *param[3]=1;
            }
            else *param[3]=0;
            i+=4;
        }
        if(cod==9)
        {
            baza+=*param[1];
            i+=2;
        }
    } /// colapsat
    /**
     *
     *
     *
     *
     *
     */

    if(cod==3)
    {
        cin>>*param[1];
        i+=2;
    }
    else if(cod==4)
    {
       fout<<(char)*param[1];
        i+=2;
    }
}
int main()
{
    /*citire();
    for(i=0; i<=k;)
    {
        int ret=solve(s[i],i);
        if( ret==-1)
            break;
    }*/
        fout.close();
        fin.close();
    ifstream fin("17.in");
    ofstream fout("17.out");
    string mat[1000];
    int sz=0;
    int sum=0;
    while(fin>>mat[sz++]);
    for(i=1;i<sz-1;i++){
        for(int j=1;j<mat[1].size();j++){
            if(
               j<mat[1].size()-1&&
                mat[i][j]=='#'
               &&mat[i-1][j]=='#'
               &&mat[i][j-1]=='#'
               &&mat[i+1][j]=='#'
               &&mat[i][j+1]=='#'){
                sum+=i*j;
               }
            if(mat[i][j]=='^'){
                pozx=i;
                pozy=j;
            }
        }
    }
    fout<<sum<<endl;
    i=pozx;
    int j=pozy;
    j--;
    fout<<i<<" "<<j<<endl;;
    int lin[]={-1,0,1,0};
    int col[]={0,1,0,-1};
   int dir=3+400; // L
   nr=1;
   fout<<endl;
        fout<<"L,";
    while(mat[i+lin[dir%4]][j+col[dir%4]]=='#'){
        while(
              i+lin[dir%4]>=0&&j+col[dir%4]>=0&&i<sz&&j<mat[1].size()&&
              (mat[i+lin[dir%4]][j+col[dir%4]]=='#')
              ){
            i=i+lin[dir%4];
            j=j+col[dir%4];
            nr++;
        }
        fout<<nr<<",";
//        fout<<mat[i-1][j-1]<<mat[i-1][j]<<mat[i-1][j+1]<<endl;
//        fout<<mat[i][j-1]<<mat[i][j]<<mat[i][j+1]<<endl;
//        fout<<mat[i+1][j-1]<<mat[i+1][j]<<mat[i+1][j+1]<<endl;
        dir++;
        if(i+lin[dir%4]>=0&&j+col[dir%4]>=0&&i<sz&&j<mat[1].size()&&mat[i+lin[dir%4]][j+col[dir%4]]=='#'){
            fout<<"R,";
            nr=0;
            continue;
        }
        dir-=2;
        if(i+lin[dir%4]>=0&&j+col[dir%4]>=0&&i<sz&&j<mat[1].size()&&mat[i+lin[dir%4]][j+col[dir%4]]=='#'){
            fout<<"L,";
            nr=0;
            continue;
        }
    }
}
/*#include <bits/stdc++.h>
using namespace std;
ifstream fin("17.in");
ofstream fout("17.out");
long long f[12345];
long long nr,n,i,j,k,l,v[12345],poz1,poz2,poz3,cnt,x,sgn,base,m,sol;
long long *p[10];
char s[12345],a[100][100];
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
    if (cod==99) {
        fout<<"finish";
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
        fin>>*p[1];
        i+=2;
    }
    else if (cod==4) {
        fout<<(char)*p[1];
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
    while (fin>>a[++n]);
    m=strlen(a[1]);
    for (i=1;i<=n;i++) {
        for (j=0;j<m;j++) {
            if (a[i][j]=='#'&&a[i-1][j]=='#'&&a[i+1][j]=='#'&&a[i][j-1]=='#'&&a[i][j+1]=='#') //intersectie
                sol+=(i-1)*j;
  //          if (a[i][j]=='^')
//                startx=i, starty=j;
            //fout<<a[i][j];
        }
        //fout<<"\n";
    }
    /
    A=L,6,L,4,R,12
    B=L,6,R,12,R,12,L,8
    C=L,6,L,10,L,10,L,6
    drum
    A,B,A,C,B,A,C,B,A,C
    fout<<"sol: "<<sol;
    return 0;
}*/
