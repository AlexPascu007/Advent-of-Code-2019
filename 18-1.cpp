#include <bits/stdc++.h>
using namespace std;
ifstream fin("18.in");
ofstream fout("18.out");
int di[]={-1,0,1,0};
int dj[]={0,1,0,-1};
int n, m, starti, startj, i, j;
map <int, int> dist[1005][1005];
pair <int, int> sol;
vector <string> a;
string s;
deque<pair <pair <int, int>, int> > q;
int bfs(int x, int y) {
    int xi, yi, d2, dir, nr;
    q.push_back({{x, y}, 0});
    dist[x][y][0] = 0;
    while(!q.empty()) {
        int i = q.front().first.first, j = q.front().first.second, d = q.front().second;
        q.pop_front();
        for(dir=0;dir<4;dir++) {
            xi=i+di[dir];
            yi=j+dj[dir];
            if ((xi>=n||xi<0||yi>=m||yi<0)||(a[xi][yi]=='#'))
                continue;
            nr=a[xi][yi]-'A';
            if(nr>=0&&nr<=26)
                if ((d&(1<<nr))==0)
                    continue;
            d2=d;
            nr=a[xi][yi]-'a';
            if(nr>=0&&nr<=26)
                d2|=(1<<nr);
            if (dist[xi][yi].count(d2))
                continue;
            dist[xi][yi][d2]=dist[i][j][d]+1;
            sol=min(sol,{-d2,dist[xi][yi][d2]});
            q.push_back({{xi,yi},d2});
        }
    }
    return sol.second;
}
int main() {
    while (fin>>s)
        a.push_back(s);
    n=a.size();
    m=a[0].size();
    for(i=0;i<n;i++){
        for(j=0;j<m;j++) {
            if(a[i][j]=='@'){
                starti=i, startj=j;
                fout<<bfs(starti, startj);
                return 0;
            }
        }
    }
}
