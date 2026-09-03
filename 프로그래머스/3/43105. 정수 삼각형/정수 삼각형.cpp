#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int size = triangle.size(); //예제의 경우 5
    
    for(int i=1;i<size;i++){
        for(int j=0;j<i+1;j++){
            if(j==0){
                triangle[i][j] += triangle[i-1][j];
            }
            else if(j==i) {
                triangle[i][j] += triangle[i-1][j-1];
            }
            else {
                triangle[i][j] += max(triangle[i-1][j-1],triangle[i-1][j]);
            }
        }
    }
    
    answer = triangle[size-1][0];
    
    for(int i=1;i<size;i++){
        if(answer < triangle[size-1][i]){
            answer = triangle[size-1][i];
        }
    }
        
    return answer;
}