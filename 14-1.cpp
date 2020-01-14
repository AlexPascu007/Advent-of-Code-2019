
#include <deque>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using std::map;
using std::pair;
using std::string;
using std::vector;
using Number = unsigned long long;

struct Ingredient {
  int amountRequired;
  string ingredientName;
};

struct Reaction {
  int makes;
  vector<Ingredient> ingredients;
};

void topoHelper(const string &name, const map<string, Reaction> &reactions,
                std::set<string> &visited, std::deque<string> &order) {
  if (name == "ORE")
    return;
  visited.insert(name);
  const auto &[howmuch, ingredients] = reactions.at(name);
  for (const auto &[used, ingredientName] : ingredients)
    if (!visited.count(ingredientName))
      topoHelper(ingredientName, reactions, visited, order);
  order.push_front(name);
}

std::deque<string> topoSort(const string &name,
                            const map<string, Reaction> &reactions) {
  std::set<string> visited;
  std::deque<string> order;
  topoHelper(name, reactions, visited, order);
  return order;
}

map<string, Reaction> readInput(std::istream &ifile) {
  map<string, Reaction> reactions;
  string line;
  while (getline(ifile, line)) {
    Ingredient i;
    vector<Ingredient> ingredients;
    std::istringstream iline(line);
    bool done = false;
    while (!done) {
      iline >> i.amountRequired >> i.ingredientName;
      if (i.ingredientName.back() == ',')
        i.ingredientName.pop_back();
      else
        done = true;
      ingredients.push_back(i);
    }
    string arrow;
    iline >> arrow >> i.amountRequired >> i.ingredientName; // "=>" num reagent
    reactions[i.ingredientName] = {i.amountRequired, ingredients};
  }
  return reactions;
}

void day14() {
  std::ifstream ifile("../day14.txt");
  //    istringstream ifile("9 ORE => 2 A\n"
  //                        "8 ORE => 3 B\n"
  //                        "7 ORE => 5 C\n"
  //                        "3 A, 4 B => 1 AB\n"
  //                        "5 B, 7 C => 1 BC\n"
  //                        "4 C, 1 A => 1 CA\n"
  //                        "2 AB, 3 BC, 4 CA => 1 FUEL");
  //  istringstream ifile(
  //      "157 ORE => 5 NZVS\n"
  //      "165 ORE => 6 DCFZ\n"
  //      "44 XJWVT, 5 KHKGT, 1 QDVJ, 29 NZVS, 9 GPVTF, 48 HKGWZ => 1 FUEL\n"
  //      "12 HKGWZ, 1 GPVTF, 8 PSHF => 9 QDVJ\n"
  //      "179 ORE => 7 PSHF\n"
  //      "177 ORE => 5 HKGWZ\n"
  //      "7 DCFZ, 7 PSHF => 2 XJWVT\n"
  //      "165 ORE => 2 GPVTF\n"
  //      "3 DCFZ, 7 NZVS, 5 HKGWZ, 10 PSHF => 8 KHKGT");

  auto reactions = readInput(ifile);

  auto intDivRoundUp = [](Number num, Number den) {
    return (num + den - 1) / den;
  };

  auto chemicalsInOrder = topoSort("FUEL", reactions);

  auto oreNeededForFuel = [&](Number fuel) {
    map<string, Number> amountNeeded{{"FUEL", fuel}};
    for (const auto &chemical : chemicalsInOrder) {
      const auto &[amountReactionMakes, ingredients] = reactions[chemical];
      for (const auto &[reactionRequires, name] : ingredients) {
        auto timesToRunReaction =
            intDivRoundUp(amountNeeded[chemical], amountReactionMakes);
        amountNeeded[name] += reactionRequires * timesToRunReaction;
      }
    }
    return amountNeeded["ORE"];
  };

  std::cout << "Day 14 star 1 = " << oreNeededForFuel(1) << "\n";
  auto lower = 0ull;
  auto upper = 1000000000000ull;
  while (lower != upper) {
    auto mid = lower + (upper - lower) / 2;

    if (oreNeededForFuel(mid) <= 1000000000000ull)
      lower = mid + 1;
    else
      upper = mid;
  }

  std::cout << "Day 14 star 2 = " << lower - 1 << "\n";
}
/*#include <bits/stdc++.h>
using namespace std;
ifstream fin("14.in");
ofstream fout("14.out");
int x,y,k[5],id,nr[5],l,i;
struct material{
    int val, ing;
};
material mat[10000];
char s[10000];
string v[3];
void nivel(long long nod) {
    for (long long i=0;i<L[nod].size();i++) {
        long long  vecin=L[nod][i];
        niv[vecin]=max(niv[vecin],niv[nod]+1);
        nivel(vecin);
    }
}
int main() {
    m["ORE"]=1;
    m["FUEL"]=2;
    elem=2;
    while (fin.getline(s,10000)) {
        l=strlen(s);
        id=1;
        k[1]=k[2]=0;
        for (i=0;i<l;i++) {
            if (s[i]>='0'&&s[i]<='9') {
                nr=0;
                while (s[i]>='0'&&s[i]<='9') {
                    nr=nr*10+s[i]-'0';
                    i++;
                }
                if (id==1)
                    mat[++k].val=nr;
            }
            if (s[i]==','||s[i]==' ')
                continue;
            if (s[i]=='=') {
                id=2;
                i+=2;
            }
            if (s[i]>='A'&&s[i]<='Z') {
                v.clear();
                while (s[i]>='A'&&s[i]<='Z') {
                    v+=s[i];
                    i++;
                }
                if (m[v]==0)
                    m[v]=++elem;
                if (id==1)
                    mat[k].ing=m[v];
                else {
                    cant[m[v]]=nr;
                    for (j=1;j<=k;j++) { //punem muchie intre elementele din reactie
                        int x=m[v], y=mat[j].ing, c=mat[j].val;
                        L[x].push_back({y,c});
                        n[y]++;
                        if (y==1)  //ORE
                            out.push_back(x);
                        cost[x][y]=c;
                    }
                }
            }
        }
    }
    niv[1]=1;
    nivel(2);

    return 0;
}
*/
