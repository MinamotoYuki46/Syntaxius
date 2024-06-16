#include<bits/stdc++.h>
using namespace std;

int cntCase(string str){
	int count = 0;
	for(int i = 0; i < str.size(); i++){
		if(isupper(str[i])){
            count++;
        }
	}
	return count;
}

int main(){
    string str;
    cin >> str;

    int upper = cntCase(str), lower = str.size() - upper;

    if(upper > lower){
        for (int i = 0; i < str.size(); i++){
            str[i] = toupper(str[i]);
        }
    }
    else{
        for (int i = 0; i < str.size(); i++){
            str[i] = tolower(str[i]);
        }
    }

    cout << str;

    return 0;
}