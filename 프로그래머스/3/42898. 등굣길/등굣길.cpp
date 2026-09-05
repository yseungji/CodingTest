#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    int cnt[100][100] = {0,};
    for(int i=0;i<puddles.size();i++){
        cnt[puddles[i][1]-1][puddles[i][0]-1] = -1;
    }
    cnt[0][0] = 1;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0 || cnt[i][j] == -1) continue;
            else if(i==0){
                if(cnt[i][j-1] != -1){
                    cnt[i][j] = cnt[i][j-1];
                }
            }
            else if(j==0){
                if(cnt[i-1][j] != -1){
                    cnt[i][j] = cnt[i-1][j];
                
                }
            }
            else if(cnt[i][j-1]==-1){
                cnt[i][j] = cnt[i-1][j];
            }
            else if(cnt[i-1][j]==-1){
                cnt[i][j] = cnt[i][j-1];
                
            }
            else{
                cnt[i][j] = cnt[i][j-1] + cnt[i-1][j];
                
            }
            cnt[i][j] %= 1000000007;
        }
    }
    answer = cnt[n-1][m-1]%1000000007;
    //cout << cnt[n-1][m-1]%1000000007;
    return answer;
}