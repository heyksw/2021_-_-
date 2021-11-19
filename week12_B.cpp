#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Room {
    int score;
    int distance;
};

bool compare(Room r1, Room r2){
    return r1.distance < r2.distance;
}

void program(){
    int N;
    cin>>N;
    vector<Room> rooms;
    
    int score, distance;
    for(int i=0; i<N; i++){
        cin>>score>>distance;
        Room room;
        room.score = score;
        room.distance = distance;
        rooms.push_back(room);
    }
    
    sort(rooms.begin(), rooms.end(), compare);
    
    int standardScore = rooms[0].score;
    int answer = int(rooms.size());
    
    for(int i=0; i<rooms.size(); i++){
        if(rooms[i].score < standardScore){
            answer -= 1;
        }
        standardScore = max(standardScore, rooms[i].score);
    }
    
    cout<<answer<<'\n';
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin>>T;
    while(T>0){
        program();
        T--;
    }
    return 0;
}
