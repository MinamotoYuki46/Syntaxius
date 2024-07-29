#include <iostream>
#include <vector>
#define pb push_back
using namespace std;

vector<vector<string>> tabel1 = {{"AB","DC","CC","CB"},
                                 {"CA","DA","CD","DD"},
                                 {"BC","AA","BA","DB"},
                                 {"BD","AD","BB","AC"}};

vector<vector<string>> tabel2 = {{"CD","BB","AC","CC"},
                                 {"CB","DB","AD","DD"},
                                 {"DA","DC","BC","BD"},
                                 {"AA","BA","CA","AB"}};

string Solve(int x, int y){
   string s;

   s += (x == 0 ? 'A' : x == 1 ? 'B' : x == 2 ? 'C' : 'D');
   s += (y == 0 ? 'A' : y == 1 ? 'B' : y == 2 ? 'C' : 'D');

   return s;
}

void Decode(string s){
   int x2 = 0;
   int y2 = 0;

   for(int i = 0; i < 4; i++){
      for(int j = 0; j < 4; j++){
         if(tabel2[i][j] == s){
            x2 = i;
            y2 = j;
         }
      }
   }

   string pos2 = Solve(x2, y2);

   int x1 = 0;
   int y1 = 0;

   for(int i = 0; i < 4; i++){
      for(int j = 0; j < 4; j++){
         if(tabel1[i][j] == pos2){
            x1 = i;
            y1 = j;
         }
      }
   }

   string pos1 = Solve(x1, y1);

   cout << pos1;
}

int main() {
   string s;
   cin >> s;
   
   vector<string> inp;
   if(s.length() > 2){
      for(int i = 0; i < s.length(); i+= 2){
         inp.pb(s.substr(i, 2));
      }
   } else{
      inp.pb(s);
   }

   for(auto x : inp){
      Decode(x);
   }

   
}