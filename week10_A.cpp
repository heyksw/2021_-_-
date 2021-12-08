#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

vector<bool> visit(10000, false);

int reverse(int str){   // 방 번호 뒤집기
    string before = to_string(str);
    
    while(before.length()<4){
        before = "0"+before;
    }
    
    string after = "";
    for(int i=3; i>=0; i--){
        after += before[i];
    }
    
    return stoi(after);
}

void program(){
    int answer = 0;
    
    int A, B;
    cin>>A>>B;
    
    for(int i=0; i<=9999; i++){
        visit[i] = false;
    }
    
    // BFS 시작.
    // 방 번호, 걸린 시간
    queue<pair<int, int>> q;
    q.push(pair<int, int>(A, 0));
    visit[A] = true;
    
    while(!q.empty()){
        int now = q.front().first;
        int time = q.front().second;
        //cout<<"현재 방 번호 : "<<now<<" 걸린 시간 : "<<time<<endl;
        
        if(now == B){
            answer = time;
            break;
        }
        
        q.pop();
        
        int reversed = reverse(now);
        if(!visit[reversed]){   // 뒤집은 번호
            q.push(pair<int, int>(reversed, time+1));
            visit[reversed] = true;
        }
            
        if( (now != 0) && (!visit[now-1]) ){    // 0이 아니라면
            q.push(pair<int, int>(now-1, time+1));
            visit[now-1] = true;
        }
        
        if( (now != 9999) && (!visit[now+1])){  // 9999 가 아니라면
            q.push(pair<int, int>(now+1, time+1));
            visit[now+1] = true;
        }
        
    }
    
    cout<<answer<<'\n';
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
