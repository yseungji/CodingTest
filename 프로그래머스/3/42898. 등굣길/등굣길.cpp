#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    int cnt[101][101] = {0,};
    
    for(int i=0;i<puddles.size();i++){
        cnt[puddles[i][1]][puddles[i][0]] = -1;
    }
    cnt[0][1] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(cnt[i][j] == -1) {
                cnt[i][j] = 0;
                continue;
            }
            cnt[i][j] = (cnt[i-1][j] + cnt[i][j-1])%1000000007;
        }
    }
    answer = cnt[n][m];
    return answer;
}