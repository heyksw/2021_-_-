#include <iostream>
#include <string>
#include <queue>
using namespace std;

vector<int> graph[50001];   // 인접 리스트 그래프
int fileName[50001];        // 파일 이름 길이. root = 4
bool visit[50001];          // 방문 처리
int result[50001];          // 최종 결과

void program(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    // 초기 세팅
    for(int i=0; i<50001; i++){
        graph[i].clear();
        fileName[i] = 0;
        visit[i] = false;
        result[i] = 0;
    }
    
    int N;
    cin >> N;
    
    // 그래프 세팅
    for (int i=0; i < N-1; i++){
        int a, b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    
    // 파일 이름 세팅
    for (int i=1; i < N+1; i++){
        string s;
        cin>>s;
        fileName[i] = s.length();
    }
    
    
    // BFS 시작
    // 노드 번호, 파일 이름 길이
    queue<pair<int,int>> q;
    q.push(pair<int, int>(1, 4));
    visit[1] = true;
    result[1] = 4;
    
    while(!q.empty()){
        int num = q.front().first;
        int len = q.front().second;
        q.pop();
        //cout<<"bfs num : "<<num<<" "<<len<<endl;
        
        for(int i=0; i<graph[num].size(); i++){
            int now = graph[num][i];
            //cout<<"now fileName[now] : "<<now<<" "<<fileName[now]<<endl;
            if( !visit[now] ){
                q.push(pair<int, int>(now, len + 1 + fileName[now]));
                visit[now] = true;
                result[now] = len + 1 + fileName[now];
            }
        }
    }
    
    for(int i=1; i<N+1; i++){
        cout<<result[i]<<'\n';
    }
    
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin >> T;
    
    while(T>0){
        program();
        T--;
    }
    
    return 0;
}
