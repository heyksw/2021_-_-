#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    cin>>N>>M;
    // counter가 일하고 있는 상황을 저장한 힙
    // 걸리는 시간, 계산대 번호
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> cHeap;
    
    // 손님이 모두 계산하는데 걸리는 시간
    int totalTime = 0;
    
    // 카운터 번호 : 계산한 값 -> counter[2] = 30 이면 2번 카운터가 계산한 값은 30
    vector<int> counter(N,0);
    // 걸리는 시간, 가격
    vector<pair<int, int>> customer;
    
    // 손님들의 정보 입력
    for(int i=0; i<M; i++){
        int time, price;
        cin>>time>>price;
        customer.push_back(pair<int, int>(time, price));
    }
    
    // 손님 수보다 계산대 수가 많다면, 다 보내고 바로 끝내버림.
    if(M <= N){
        for(int i=0; i<M; i++){
            counter[i] += customer[i].second;
            totalTime = max(totalTime, customer[i].first);
        }
        
        // 결과 출력
        cout<<totalTime<<'\n';
        for(int i=0; i<N; i++){
            cout<<counter[i]<<'\n';
        }
        return 0;
    }
    
    // 로직 시작
    // 맨 처음 비어있는 계산대들에 손님을 모두 보냄
    for(int i=0; i<N; i++){
        counter[i] += customer[i].second;
        // i번 손님의 걸리는 시간, 계산대 번호를 힙에 삽입
        cHeap.push(pair<int, int>(customer[i].first, i));
        totalTime = max(totalTime, customer[i].first);
    }

    
    for(int i=N; i<M; i++){
        //cout<<"i 인덱스 , customer[i] 가 걸리는 시간, 가격 : "<<i<<" "<<customer[i].first<<" "<<customer[i].second<<endl;
        int popTime = cHeap.top().first;
        int popNum = cHeap.top().second;
        
        cHeap.pop();
        //cout<<"popTime: "<<popTime<<", 몇번 계산대 ? : "<<popNum<<endl;
            
        totalTime = max(totalTime, popTime + customer[i].first);
        counter[popNum] += customer[i].second;
        cHeap.push(pair<int, int>(popTime + customer[i].first, popNum));
        //cout<<popTime + customer[i].first<<" "<<popNum<<" 이 푸시됩니다."<<endl;
    }
    
    cout<<totalTime<<'\n';
    
    for(int i=0; i<N; i++){
        cout<<counter[i]<<'\n';
    }
    
    
    return 0;
}

