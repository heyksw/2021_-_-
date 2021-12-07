## CSE-3309 (인하대학교 4학년 2학기 - 문제 해결 기법)

### Week1_A : 지그재그 문자열 
집중해서 연산 실수 안하면 되는 문제

### Week1_B : 블록 탑
multiset과 iterator 개념을 숙지해야 하는 문제

```cpp
// 삽입
block.push(x);
total.insert(x);
            
cout<<*total.begin()<<" "<<*total.rbegin()<<'\n';

// 삭제
int now = block.top();
block.pop();
            
multiset<int>::iterator it = total.find(now);
total.erase(it);
```
multiset을 사용해야 중복되는 값중에 한 개만 지워짐.   
set을 사용하면 중복된 값이 한꺼번에 함께 삭제됨.
### Week2_A : 시험 준비 (문장 맞추기)
vector와 queue의 개념.   
queue는 선언할때 <> 꺽쇠안에 타입도 지정 해줘야함.

### Week2_B : 자원 확보 
vector의 정렬, pair 개념.   
C++ 에서 Python과 마찬가지로 sort() 내장 함수를 제공한다.   
#include <algorithm> 을 해주면 사용할 있다.   
한편, 반대로 정렬하고 싶다면?   
#include <functional> 을 추가해주고,   
sort(a.begin(), a.end(), greater<int>()) 해주면 된다.   
또는, compare 함수를 커스텀한다.   

### Week3_A : 디렉토리 (파일 이름)
parent를 일일이 찾아나서면 시간초과가 발생하는 문제.   
문법적으로 많이 고생했기 때문에 반드시 다시 풀어봐야 한다.   
DFS 보다는 BFS 로 푸는 것이 나은 것 같다 !

### Week3_B : 좋은 이웃 (가장 사이가 먼 이웃 찾기)
"트리의 지름" 이라는 개념을 알게된 문제.   
BFS로 푸는게 괜찮았다. BFS를 두 번 돌려야 한다.

### Week4_A : E 스포츠 경기
서로를 뺀 값이 가장 큰 최소공배수가 될 수 있다는 개념을 탑재하면 쉬운 문제.   
lowerA와 lowerB가 둘 다 0이 되는 순간을 체크해줘야 한다.

### Week4_B : 두 선분의 관계
CCW의 개념을 활용하면 좋은 문제.   
C++ 의 pair를 활용해야 점의 대소비교가 하기 쉬워진다.

### Week5_A : 외계 신호 해석
O(N^2) time의 Naive 알고리즘을 작성하면 통과 못하는 문제.   
KMP 알고리즘으로 풀어야할 것 같지만,   
Rabin-Karp 알고리즘으로 풀고 싶다.   
pow() 함수는 cmath 에 있다.

  
### Week5_B : 마을 재개발
이진탐색 + 그리디 알고리즘.  
가능한 거리를 mid로 잡고 와리가리 치면됨.   
check 함수를 greedy 하게 떠올려야 하는 문제.   

### Week6_A : 계산대 이용하기
priority_queue 문법을 잘 알아야 하는 문제.   
우선순위큐로 힙 연산을 실수없이 진행하면 어렵지 않게 풀 수 있다.   
functional을 include 하고 greater<pair<int,int>> 를 사용해서 대소 비교.
            
### Week6_B : 탈출
BFS 문제. 8방향 잘 생각해주고, 소총수와 검사의 범위만 잘 고려하면 된다.

***

### Week7_A : 양팔 저울
BFS 활용해서 푸는 문제   
   
### Week7_B : 햄버거 가게

N 일 마다 K 번째로 가까운 가게를 선택해야 하는데, 매일 정렬을 하면 타임리밋이 난다.   
그래서 계속 정렬을 하는 것보다는 힙 자료구조를 사용하는 것이 좋다.  
c++ 에서는 queue 를 include 하고 priority_queue를 사용할 수 있다.   
기본 문법 : <code>priority_queue< Position, vector<<Position>>, compare > pq; </code>
그냥 vector 의 sort 에서는 bool compare() 함수를 만들어서 사용해도 됐었지만,   
priority_queue 에서는 struct compare 안에 bool operator()(Position p1, Position p2) 이렇게 해줘야한다.
그리고 우선순위 큐의 크기는 K 만큼만 고정해서 풀어야 타임리밋이 안난다.   
참고로, queue 는 front() 이지만 priority_queue 는 top() 이다.

### Week10_B : 마트료시카
dp table 값을 0이 아니라 1로 초기화 해줘야한다.

