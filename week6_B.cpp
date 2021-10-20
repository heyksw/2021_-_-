#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

// 8방향
pair<int, int> direction[8] = {pair<int, int>(-1, 0), pair<int, int>(1, 0), pair<int, int>(0, -1), pair<int, int>(0, 1), pair<int, int>(-1, -1), pair<int, int>(-1, 1), pair<int, int>(1, -1), pair<int, int>(1, 1) };

struct Node{
    int x;
    int y;
    int d;
};

// 절대값 함수
int abs(int x){
    if(x>=0) return x;
    else return x*(-1);
}

// 검사의 공격을 받으면 true 아니면 false
bool sword(int x, int y, int cx, int cy){
    int dx = cx - x;
    int dy = cy - y;
    
    for(int i=0; i<8; i++){
        if( dx==direction[i].first && dy==direction[i].second ) return true;
    }
    return false;
}

// 소총수의 공격을 받으면 true 아니면 false
bool gun(int x, int y, int cx, int cy, int swordX, int swordY){
    // 대각선 판별
    int dx = abs(x-cx);
    int dy = abs(y-cy);
    
    // 소총수와 현재좌표간의 방향벡터 구하기
    int ux = cx-x;
    int uy = cy-y;
    int n = max(abs(ux),abs(uy));
    
    ux /= n;
    uy /= n;
    
    // 소총수한테 대각선으로 맞는 경우
    if( dx==dy ){
        for(int i=1; i<=n; i++){    // 경로에 검사가 있으면 안됨
            if( (x + ux*i) == swordX && (y + uy*i) == swordY ) return false;
        }
        return true;
    }
    // 소총수한테 직선으로 맞는 경우
    if( x==cx ){
        // 경로에 검사가 있으면 안됨
        if( x == swordX && (min(y,cy) < swordY && swordY < max(y,cy) ) ) return false;
        return true;
    }
    if( y==cy ){
        if( y == swordY && (min(x,cx) < swordX && swordX < max(x,cx))) return false;
        return true;
    }
    
    return false;
}


void program(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    int ax=0, ay=0, bx=0, by=0;
    int cx=0, cy=0, dx=0, dy=0;

    cin>>ax>>ay>>bx>>by;
    cin>>cx>>cy>>dx>>dy;
    
    ax-=1; ay-=1; bx-=1; by-=1;
    cx-=1; cy-=1; dx-=1; dy-=1;

    // 그래프와 방문처리
    vector<vector<int>> graph(N, vector<int>(N, 0));
    vector<vector<bool>> visit(N, vector<bool>(N, false));
    
    // 탈출 거리
    int distance = 0;
    // BFS 수행
    // tuple : x,y,거리
    queue<Node> q;
    q.push(Node{ax,ay,0});
    visit[ax][ay] = true;
    
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int d = q.front().d;
        
        //cout<<"x y d "<<x<<" "<<y<<" "<<d<<endl;
        
        q.pop();
        
        if(x == bx && y == by){
            distance = d;
            break;
        }
        
        for(int i=0; i<8; i++){
            int nx = x + direction[i].first;
            int ny = y + direction[i].second;
            
            // 그래프 범위 안에서
            if( (0<=nx&&nx<N) && (0<=ny&&ny<N) ){
                // 방문하지 않은 노드 중
                // 검사와 소총수 공격을 피해간다면 큐에 삽입
                if( !visit[nx][ny] && !sword(nx, ny, cx, cy) && !gun(nx, ny, dx, dy, cx, cy) ){
                    q.push(Node{nx,ny,d+1});
                    visit[nx][ny] = true;
                }
            }
        }
    }   // while 종료
    
    cout<<distance<<'\n';
    
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin>>T;
    
    while(T>0){
        program();
        T--;
    }
    return 0;
}
