// B-1, B-2 둘 다 해결되는 코드.

#include <iostream>
using namespace std;

// 21x31y 21y31x 로 외웠음.
int ccw(pair<int,int> A, pair<int,int> B, pair<int,int> C){
    int result = (B.first-A.first)*(C.second-A.second) - (B.second-A.second)*(C.first-A.first);
    if(result>0) return 1;
    else if(result==0) return 0;
    else return -1;
}

int relation(pair<int,int> A, pair<int,int> B, pair<int,int> C, pair<int,int> D){
    
    int line1_2 = ccw(A,B,C)*ccw(A,B,D);
    int line2_1 = ccw(C,D,A)*ccw(C,D,B);
    
    // 4개의 점이 모두 한 직선위에 존재하는 경우
    if( line1_2 == 0 && line2_1 == 0){
        if(A > B) swap(A, B);
        if(C > D) swap(C, D);
        
        // 만나지 않는 경우 : 관계 1
        if ( (B<C) || (D<A) ) return 1;
        // 한 점에서 만나는 경우 : 관계 2
        if( (A < C && B == C) || (C<A&&D==A) ) return 2;
        // 두 선분의 일부가 겹치는 경우 : 관계 3
        if( (A<C&&C<B&&B<D) || (C<A&&A<D&&D<B) ) return 3;
        // 한 선분이 다른 선분에 포함 됨
        // 여기 등호 꼭 넣어줘야 함 !! 이것 때문에 엄청 헤맸음 !!
        if( (A<=C&&D<=B) || (C<=A&&B<=D) ) return 4;
                                                
    }
    
    // 모두 그렇지는 않은 경우
    if( line1_2 <= 0 && line2_1 <= 0 ) return 2;
    else return 1;
}

void program(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
        
    pair<int, int> A(x1, y1);   pair<int, int> B(x2, y2);
    pair<int, int> C(x3, y3);   pair<int, int> D(x4, y4);
    
    cout<<relation(A, B, C, D)<<'\n';

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
