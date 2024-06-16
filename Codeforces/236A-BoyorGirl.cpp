#include<bits/stdc++.h>
using namespace std;

int cntDistinct(string str){
	map<char, int> count;
	for(int i = 0; i < str.size(); i++){
		count[str[i]]++;
	}
	return count.size();
}
int main(){
	string str;
    cin >> str;
	int ans = cntDistinct(str);

	if(ans & 1){
        cout << "IGNORE HIM!";
    }
    else{
        cout << "CHAT WITH HER!";
    }
	return 0;
}
