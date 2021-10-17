#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    return a.first > b.first;
}

void game(){
    int N;
    cin>>N;
    
    vector<int> x;
    vector<int> y;
    
    for(int i=0;i<N;i++){
        int a, b;
        cin>>a>>b;
        x.push_back(a);
        y.push_back(b);
    }
    
    vector<pair<int, int>> z;   // 자원 가치, 인덱스
    
    pair<int, int> tmp;
    for(int i=0;i<N;i++){
        tmp.first = x[i]+y[i];
        tmp.second = i;
        z.push_back(tmp);
    }
    
    sort(z.begin(), z.end(), compare);
     
    int inha = 0;
    int biryong = 0;
    
    for(int i=0;i<N;i++){
        if(i%2==0){
            inha += x[z[i].second];
        }
        else{
            biryong += y[z[i].second];
        }
    }
    
    cout<<inha-biryong<<'\n';
    
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin>>T;
    
    while(T>0){
        game();
        
        T--;
    }

    return 0;
}
