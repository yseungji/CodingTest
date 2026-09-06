#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(int N, int number) {
    int answer = 100;
    
    vector<set<int>> dp(9);
    
    dp[1].insert(N);
    dp[2].insert(N*10+N);
    dp[2].insert(N*N);
    dp[2].insert(N/N);
    dp[2].insert(N+N);
 
    for(int k=3;k<=8;k++){
        int v = N;
        for(int i=1;i<k;i++){
            v= v*10+N;
        }
        dp[k].insert(v);
        for(int i=1;i<k;i++){
            int j=k-i;
            for(int icur:dp[i]){
                for(int jcur:dp[j]){
                    dp[k].insert(icur+jcur);
                    dp[k].insert(icur-jcur);
                    dp[k].insert(icur*jcur);
                    if(jcur!=0)
                    dp[k].insert(icur/jcur);
                }
            }
        }
    }
    
    for(int k=1;k<=8;k++){
        for(int icur: dp[k]){
            if(icur == number && k < answer){
             answer = k;   
            }
        }

    }
    if(answer > 8) return -1;
    else return answer;
}