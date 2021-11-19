#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void program(){
    int N;
    cin>>N;
    vector<vector<int>> graph(N+1, vector<int>());

    
    for(int i=1; i<=N; i++){
        int A;
        for(int j=1; j<=i; j++){
            cin>>A;
            graph[i].push_back(A);
        }
    }
    
        
    vector<vector<int>> dp(N+1, vector<int>());
    for(int i=0; i<=N; i++){
        for(int j=1; j<=i; j++){
            dp[i].push_back(0);
        }
    }
    
    dp[1][0] = graph[1][0];
    for(int x=1; x<N; x++){
        for(int y=0; y<=x; y++){
            if(y == 0){
                dp[x+1][y] = dp[x][y] + graph[x+1][y];
            }
            else if(y==x){
                dp[x+1][y] = dp[x][y-1] + graph[x+1][y];
            }
            else{
                dp[x+1][y] = min(dp[x][y-1], dp[x][y]) + graph[x+1][y];
            }
        }
    }
    
    int answer = dp[N][0];
    for(int i=1; i<N; i++){
        answer = min(answer, dp[N][i]);
    }
    cout<<answer<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin>>T;
    while(T > 0){
        program();
        T--;
    }
    return 0;
}
