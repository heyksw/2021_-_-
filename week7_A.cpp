#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void program(){
    int N, M;
    cin>>N>>M;
    
    vector< vector<int> > ball(N+1, vector<int>());
    vector<int> light(N+1, 0);
    
    for(int i=0; i<M; i++){
        int A, B;
        cin>>A>>B;
        ball[A].push_back(B);
    }
    
    // i번 공보다 작은 공들 탐색
    for(int i=1; i<=N; i++){
        int lightBalls = 0;
    
        vector<bool> visit (N+1, false);
        queue<int> q;
        q.push(i);
        visit[i] = true;
        
        while(!q.empty()){
            int now = q.front();
            q.pop();
            
            for(int j=0; j<ball[now].size(); j++){
                int next = ball[now][j];
                if(!visit[next]){
                    lightBalls++;
                    q.push(next);
                    visit[next] = true;
                }
            }
        }
        
        light[i] += lightBalls;
        
    }
    
    for(int i=1; i<=N; i++){
        cout<<light[i]<<" ";
    }
    cout<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin>>T;
    
    while(T>0){
        program();
        T--;
    }
    
    return 0;
}
