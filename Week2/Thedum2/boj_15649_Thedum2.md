[##_Image|kage@6LWFK/btrgBD323tF/tXYg9HbtgGTsAGmdYm6K1K/img.png|alignCenter|data-origin-width="1500" data-origin-height="375" data-filename="3.png" data-ke-mobilestyle="widthOrigin"|||_##]

#### **난이도**

[##_Image|kage@ZuJu8/btrgGrOP9wO/KWTC0iHXwzcrxHSbLna4SK/img.jpg|alignLeft|data-origin-width="400" data-origin-height="512" width="64" data-ke-mobilestyle="widthOrigin"|||_##]

**Silver3**

---

**문제 링크**

**[https://www.acmicpc.net/problem/15649](https://www.acmicpc.net/problem/9093)**

---

## **문제 해결 과정**

**DFS, 백트래킹 기법을 이용해서 풀었다.**

**사전순 출력은, 반복문을 1부터 시작하면 자연스럽게 해결된다.**

**N\_and\_M 함수의 인자로 ~까지의 수, 자릿수, 현재 탐색하는 순번 을 인자로 두어**

**~까지의 수까지 반복문을 진행하며, 다음 탐색 수가 방문했던 수면 PASS,** 

**현재 탐색하는 순번이 자릿수가 될 때까지 결과를 저장했다가 출력한다.**

---

## **주의할 점**

**1.현재 경우를 모두 탐색했다면, 다음 경우의 수를 위해 꼭 방문처리를 false로 바꿔주어야 한다.**

**2.뒤에 나오는 N과M 시리즈의 베이스가 되는 코드이기 때문에 깔끔하고, 잘 알아볼수 있게 짜야 한다.**

---

## **코드**

```cpp
#include <iostream>
using namespace std;

int nm_array[9];
bool nm_isvisit[9];

void N_and_M(int number,int digit,int now) {

	//만약 현재 호출한 횟수가 출력할 자릿수보다 많다면
	if (now > digit) {
		//입력받은 자릿수만큼까지에 저장된 배열을 출력한다.
		for (int i = 1; i <= digit; i++)
			cout << nm_array[i] << " ";
		cout << "\n";
		return;
	}

	//아직 자릿수가 다 채워지지 않은 경우이다
	//number까지의 숫자 모두를 포함해야 한다
	for (int i = 1; i <= number; i++){
		//중복을 허용하지 않기 때문에 방문되지 않은 경우만 허용
		if (!nm_isvisit[i]) {
			nm_array[now] = i;//현재 자릿수를 저장
			nm_isvisit[i] = true;//방문 처리
			N_and_M(number, digit, now + 1);//다음 경우의 수 탐색
			nm_isvisit[i] = false;//다음 경우의 수를 위해 현재 경우의 수가 끝났다면,방문 취소 처리
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	N_and_M(N, M, 1);//1번부터 시작
}
```

---

---

**잘못된 부분이나 오해할 수 있는 부분이 있다면 언제든지** 

**댓글 남겨주시기 바랍니다!**

![](https://t1.daumcdn.net/keditor/emoticon/niniz/large/006.gif)