#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

void matchingTest(){
    int N, M;
    cin>>N>>M;
    
    vector<string> words;
    for(int i=0;i<M;i++){
        string s;
        cin>>s;
        words.push_back(s);
    }
    
    vector<queue<string>> friends;
    
    for(int i=0;i<N;i++){
        int K;
        cin>>K;
        queue<string> q;
        for(int j=0;j<K;j++){
            string s;
            cin>>s;
            q.push(s);
        }
        friends.push_back(q);
    }
    
    int i=0;
    
    while(i<words.size()){
        bool flag = false;
        string now = words[i];
        
        for(int i=0; i<N; i++){
            if(now == friends[i].front()){
                friends[i].pop();
                flag = true;
                break;
            }
        }
        
        if(!flag){
            cout<<0<<'\n';
            return;
        }
        i++;
    }
    
    cout<<1<<'\n';
}


int main(){
    int T;
    cin>>T;
    
    while(T>0){
        matchingTest();
 
        T--;
    }
 
    return 0;
}
