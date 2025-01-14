#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define vii             vector<vi>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void c_p_c(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int minOp(string str1, string str2){
    int n = str1.length();

    unordered_map<char, int> count;

    // Count characters in str1
    for(char c : str1){
        count[c]++;
    }

    int swaps = 0, changes = 0;

    // Calculate number of swaps and changes
    for(int i = 0; i < n; i++){
        if (str1[i] != str2[i]){
            bool found = false;
            // Check if we can swap str1[i] with str2[i]
            for (int j = i + 1; j < n; j++) {
                if (str1[j] == str2[i] && str1[j] != str2[j]) {
                    swap(str1[i], str1[j]);
                    swaps++;
                    found = true;
                    break;
                }
            }
            if (!found) {
                changes++;
            }
        } else {
            changes++;
        }
    }


    return swaps + changes;
};


pair<int, int> lcs_with_swap(string str1, string str2) {
    int m = str1.size();
    int n = str2.size();
    
    // Single vector to store the previous row
    vector<int> dp(n + 1, 0);
    
    // To store number of swaps
    vector<int> swaps(n + 1, 0);

    for (int i = 1; i <= m; i++) {
        int prev = 0;
        int prev_swap = 0; // Previous swap count
        
        for (int j = 1; j <= n; j++) {
            int temp = dp[j];
            int temp_swap = swaps[j];
            
            if (str1[i - 1] == str2[j - 1]) {
                dp[j] = prev + 1;
                swaps[j] = prev_swap;
            } else {
                if (dp[j] < dp[j - 1] || (dp[j] == dp[j - 1] && swaps[j] > swaps[j - 1] + 1)) {
                    dp[j] = dp[j - 1];
                    swaps[j] = swaps[j - 1] + 1;
                }
            }
            
            prev = temp;
            prev_swap = temp_swap;
        }
    }
    
    return make_pair(dp[n], swaps[n]);
    // Return the length of the LCS and number of swaps
}


int32_t main(){
    c_p_c();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string str1, str2;
    cin >> str1 >> str2;

    //cout << minOp(str1, str2) << endl;
    auto res = lcs_with_swap(str1, str2);
    cout << res.ss << endl;

    return 0;
}