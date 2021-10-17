## CSE-3309 (인하대학교 4학년 2학기에 수강한 문제 해결 기법)

### Week1_A
집중해서 연산 실수 안하면 되는 문제

### Week1_B
multiset과 iterator 개념을 숙지해야 하는 문제

```cpp
multiset<int> ms;   

multiset<int>::iterator it = ms.find(value);   

ms.erase(it);
```
이렇게 해야 중복되는 값중에 한 개만 지워짐.

### Week2_A
vector와 queue의 개념.   
queue는 선언할때 <> 꺽쇠안에 타입도 지정 해줘야함.

### Week2_B
vector의 정렬, pair 개념.   
C++ 에서 Python과 마찬가지로 sort() 내장 함수를 제공한다.   
#include <algorithm> 을 해주며 사용할 있다.   
한편, 반대로 정렬하고 싶다면?   
#include <functional> 을 추가해주고,   
sort(a.begin(), a.end(), greater<int>()) 해주면 된다.   
또는, compare 함수르 커스텀한다.   

### Week3_A
parent를 일일이 찾아나서면 시간초과가 발생하는 문제.   
문법적을 많이 고생했기 때문에 반드시 다시 풀어봐야 한다.
