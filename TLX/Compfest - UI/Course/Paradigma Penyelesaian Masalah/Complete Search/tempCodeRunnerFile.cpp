int32_t main(){
//     // c_p_c();
//     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//     int n, m; cin >> n >> m;

//     vii agent (n, vi (n));

//     REP(i, n){
//         int x, y; cin >> x >> y;
//         x--, y--;

//         agent[x][y] = agent[y][x] = 1;
//     }

//     if (m == 0){
//         cout << 1 << '\n';
//         return 0;
//     }

//     int ans = 2;

//     FOR(i, 1, 1 << n){
//         vi v (25);
//         REP(j, n){
//             bool flag = true;
//             for(auto it : v){
//                 if (!agent[j][it]){
//                     flag = false;
//                     break;
//                 }
//             }

//             if(!flag) break;
//             v.pb(j);
//             ans = max(ans, (int) v.size());
//         }
//     }

//     cout << ans << '\n';
//     return 0;
// }