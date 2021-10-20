#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> houses, int N, int mid, int M){
    int now = 1;
    int cnt = 1;
    //cout<<mid<<"검사 시작"<<endl;
    
    for(int i=1; i<N; i++){
        //cout<<"houses[i] "<<houses[i]<<" now "<<now<<endl;
        if(houses[i]-now >= mid){
            cnt++;
            now = houses[i];
            //cout<<"now "<<now<<endl;
        }
        if(cnt == M) break;
    }
    
    if(cnt==M) {
        //cout<<mid<<"는 조건에 맞습니다."<<endl;
        return true;
    }
    else return false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    cin>>N>>M;
    
    vector<int> houses;
    int right = 0;
    
    for(int i=0; i<N; i++){
        int num;
        cin>>num;
        houses.push_back(num);
        if(i == N-1) right = num;
    }
    
    int left = 1;
    int mid = int( (left+right)/2 );
    int answer = 0;
    
    while(left<=right)
    {
        mid = int((left+right)/2);
        //cout<<"left mid right "<<left<<" "<<mid<<" "<<right<<endl;
        if(check(houses, N, mid, M)){  // mid가 가장 인접한 거리가 될 수 있음
            answer = mid;
            left = mid+1;
        }
        else{   // mid가 가장 인접한 거리가 될 수 없음. 더 좁은 거리로 해야함.
            right = mid-1;
        }
        
    }
    
    cout<<answer<<'\n';
    
    return 0;
}
