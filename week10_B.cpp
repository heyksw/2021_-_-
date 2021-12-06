#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void program(){
    int N;
    cin >> N;
    vector<int> matryoshika;
    
    for(int i=0; i<N; i++){
        int x;
        cin >> x;
        matryoshika.push_back(x);
    }
    
    vector<int> dp(N, 1);
    
    for(int i=0; i<N; i++){
        if(i==0){
            dp[i] = 1;
        }
        else{
            for(int j=0; j<i; j++){
                if(matryoshika[j] < matryoshika[i]){
                    dp[i] = max(dp[j]+1, dp[i]);
                }
            }
        }
    }
    
    //cout<<"dp table check"<<endl;
    int answer = 0;
    for(int i=0; i<N; i++){
        answer = max(answer, dp[i]);
    }
    cout<<answer<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin >> T;
    while(T>0){
        program();
        T--;
    }
    
    return 0;
}


