#include <iostream>
#include <queue>
#include <vector>
using namespace std;

pair<int, int> bfs(vector<pair<int, int>>* graph, bool *visit, int start){
    // 노드 번호, 거리
    queue<pair<int, int>> q;
    // start번 에서 시작
    q.push(pair<int, int>(start, 0));
    visit[start] = true;
    // start번에서 가장 먼 노드 번호, 거리
    pair<int, int> far;
    far.first = 0;
    far.second = 0;
    
    while(!q.empty()){
        int num = q.front().first;
        int dist = q.front().second;
        
        q.pop();
        //cout<<"num의 자식 크기 "<<graph[num].size()<<endl;
        for(int i=0; i<graph[num].size(); i++){
            int now = graph[num][i].first;
            //cout<<"now visit[now] "<<now<<" "<<visit[now]<<endl;
            if(!visit[now]){
                q.push(pair<int, int>(now, dist + graph[num][i].second));
                visit[now] = true;
                if(dist + graph[num][i].second > far.second){
                    far.first = now;
                    far.second = dist + graph[num][i].second;
                }
            }
            
        }
    }
    
    //cout<<"far : "<<far.first<<" "<<far.second<<endl;
    return far;
}

void neighbor(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 이웃 노드 번호, 거리
    vector<pair<int, int>> graph[20001];
    // bfs 방문 여부
    bool visit[20001];
    for(int i=0; i<20001; i++){
        visit[i] = false;
    }
    
    int n;
    cin>>n;
    
    // graph 세팅
    for(int i=0; i<n-1; i++){
        int u, v, d;
        cin>>u>>v>>d;
        graph[u].push_back(pair<int, int>(v, d));
        graph[v].push_back(pair<int, int>(u, d));
    }
    
//    cout<<"graph"<<endl;
//    for(int i=0;i<n+1;i++){
//        cout<<i<<": ";
//        for(int j=0;j<graph[i].size();j++){
//            cout<<graph[i][j].first<<" ";
//        }
//        cout<<endl;
//    }
    
    // 임의의 노드 1번에서 가장 먼 노드 탐색
    pair<int, int> one = bfs(graph, visit, 1);
    
    // 그 노드에서 한번 더 bfs 탐색
    for(int i=0; i<20001; i++)
    {
        visit[i] = false;
    }
    
    pair<int, int> two = bfs(graph, visit, one.first);
    
    cout<<two.second<<'\n';
}



int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin>>T;
    
    while(T > 0){
        neighbor();
        T--;
    }
    
}
