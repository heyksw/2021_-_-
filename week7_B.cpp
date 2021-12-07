#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

struct Position{
    int x;
    int y;
    double distance;
};

struct compare{
    bool operator()(Position p1, Position p2){
        if(p1.distance != p2.distance){
            return p1.distance < p2.distance;
        }
        else{   // 거리가 같다면
            if(p1.x != p2.x){
                return p1.x < p2.x;
            }
            else{   // 거리도 같고 x 좌표도 같다면
                return p1.y < p2.y;
            }
        }
    }
};

void program(){
    int M, N, K;
    cin>>M>>N>>K;
  
    priority_queue<Position, vector<Position>, compare> hamburgers;
    
    for(int i=0; i<M; i++){
        int x, y;
        cin>>x>>y;
        hamburgers.push(Position{x, y, sqrt( pow(x,2) + pow(y,2) )});
        if(hamburgers.size() > K){
            hamburgers.pop();
        }
    }
    
    for(int i=0; i<N; i++){
        int x, y;
        cin>>x>>y;
        hamburgers.push(Position{x, y, sqrt( pow(x,2) + pow(y,2) )});
        hamburgers.pop();
        cout<<hamburgers.top().x<<" "<<hamburgers.top().y<<'\n';
    }
    
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
