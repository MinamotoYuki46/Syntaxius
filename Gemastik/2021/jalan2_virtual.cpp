#include <iostream>
#include <vector>
using namespace std;

pair<int, int> PosisiAkhir(int langkah)
{
    int x = 0;
    int y = 0;
    int arah = 0;
    int count = 1;

    while (langkah > 0)
    {
        int move = min(langkah, count);

        if(arah == 0)
            x += move;
        else if(arah == 1)
            y += move;
        else if(arah == 2)
            x -= move;
        else if(arah == 3)
            y -= move;
        
        langkah -= move;
        arah = (arah + 1) % 4;
        count++;
    }
    
    return {x, y};
}

int main()
{
    int n, steps;
    vector<pair<int, int>> hasil;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> steps;
        hasil.push_back(PosisiAkhir(steps));
    }

    for(auto x : hasil)
    {
        cout << x.first << ' ' << x.second << endl;
    }
}