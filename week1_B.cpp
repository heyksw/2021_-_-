#include <iostream>
#include <stack>
#include <algorithm>
#include <set>
using namespace std;

void blockGame(){
    int N;
    cin>>N;
    
    multiset<int> total;
    stack<int> s;
    
    for(int i=0; i<N; i++){
        int query;
        cin>>query;
        
        if(query==1){
            int x;
            cin>>x;

            s.push(x);
            total.insert(x);
            cout<<*total.begin()<<" "<<*total.rbegin()<<'\n';
        }
        else if(query==2){
            if(total.empty()){
                continue;
            }
            else{
                int x = s.top();
                multiset<int>::iterator it = total.find(x);
                s.pop();
                total.erase(it);
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin>>T;

    while(T>0){
        blockGame();
        T--;
    }
     
}

