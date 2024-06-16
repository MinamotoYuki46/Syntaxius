#include <bits/stdc++.h>
using namespace std;

struct arith{
    long long number1, number2, result;
    char operand;
    int display;
};

void addition(long long a, long long b){
    cout << 
};

int countDigits(int number) {
    return (number == 0) ? 1 : static_cast<int>(log10(abs(number)) + 1);
}

int main(){
    int t;
    cin >> t;
    string sentence[t];
    arith math[t];

    for (int i = 0; i < t; i++){
        cin >> sentence[i];
        for(int j = 0; j < sentence[i].length() ; j++){
            if (sentence[i][j] == '+' || sentence[i][j] == '-' || sentence[i][j] == '*'){
                math[i].number1 = stoll(sentence[i].substr(0, j));
                math[i].operand = sentence[i][j];
                math[i].number2 = stoll(sentence[i].substr(j+1, sentence[i].length()-(j+1)));
                break;
            }
        }
    }

    for (int i = 0; i < t; i++){
        if (math[i].operand == '+'){
            math[i].result = math[i].number1 + math[i].number2;
        }
        else if (math[i].operand == '-'){
            math[i].result = math[i].number1 - math[i].number2;
        }
        else if (math[i].operand == '*'){
            math[i].result = math[i].number1 * math[i].number2;
        }

        math[i].display = max({countDigits(math[i].number1), countDigits(math[i].number2) + 1, countDigits(math[i].result)});
    }


    
}