#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

string CharToBinary(char c){
    int n = c;
    string binary;
    while(n >= 1){
        char c;
        c = (n % 2) + 48;
        binary.push_back(c);
        n /= 2;
    }

    return binary;
}

int BinaryToDec(string s){
    int decimal = 0;
    int pangkat = 0;
    for(int i = s.length() - 1; i >= 0; i--){
        decimal += (s[i]-48) * pow(2, pangkat);
        pangkat++;
    }

    return decimal;
}

pair<int, int> CariMerahDanBiru(string s){
    string a, b;
    int length = s.length();
    for(int i = 0; i < length; i++){
        string temp = CharToBinary(s[i]); // temp berisi bilangan biner terbalik dari tiap karakter dalam string s
        int length2 = temp.length();
        a.insert(a.begin(), temp[i]);
        b.insert(b.begin(), temp[(i+3) % 6]);
        
    }

    int biru, merah;
    biru = BinaryToDec(a);
    merah = BinaryToDec(b);

    return {biru, merah};
}

int main(){
    int n;
    cin >> n;

    vector<string> hasill;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        vector<string> tup;
        for(int j = 0; j < x; j++){
            string s_tup;
            cin >> s_tup;
            tup.push_back(s_tup);
        }
        string code;
        cin >> code;

        int size = tup.size();
        vector<int> tampung;
        for(int j = 0; j < size; j++){
            pair<int, int> MerahBiru = CariMerahDanBiru(tup[j]);
            tampung.push_back(MerahBiru.first);
            tampung.push_back(MerahBiru.second);
        }

        /* for(auto x : tampung){
            cout << x << ' ';
        } */

        string result;
        for(int j = 0; j < tampung.size(); j++){
            result.push_back(code[tampung[j]]);
        }

        hasill.push_back(result);
    }

    cout << endl;
    for(auto x : hasill){
        cout << x << endl;
    }
}