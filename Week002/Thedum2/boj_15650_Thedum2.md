[##_Image|kage@cApqus/btrgC7w4OlC/Use3vH6plZwt8z2SzIgsN0/img.png|alignCenter|data-origin-width="1500" data-origin-height="375" data-filename="4.png" data-ke-mobilestyle="widthOrigin"|||_##]

#### **난이도**

[##_Image|kage@bGENsd/btrgD3U16Pl/VGS2uBU459CjSKQcONcQnk/img.jpg|alignLeft|width="64" data-origin-width="400" data-origin-height="512" data-ke-mobilestyle="widthOrigin"|||_##]

**Silver3**

---

**문제 링크**

**[https://www.acmicpc.net/problem/15650](https://www.acmicpc.net/problem/15649)**

---

## **문제 해결 과정**

**N과M(1)에서 이전 숫자보다 현재 숫자가 큰 경우에만 출력한다.**

**저장된 배열을 확인해서** **탐색 조건으로 배열에 저장된 이전 수보다** 

**현재 탐색하는 수가 더 큰 경우를 추가한다.** 

---

## **주의할 점**

**1.현재 경우를 모두 탐색했다면, 다음 경우의 수를 위해 꼭 방문처리를 false로 바꿔주어야 한다.**

**2.최초의 경우에는 nm\_array\[0\] 를 검사하므로 1보다 작은 수를 넣어주어야 한다.****(최초로 0으로 초기화되니 ㄱㅊ)**

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
		if (!nm_isvisit[i]&& nm_array[now-1]<i) {
			//n과m(2)의 경우에는 이전 숫자보다 지금 숫자가 더 커야 한다.
			//저번 함수에서 이미 저장된 숫자보다 현재가 더 큰 경우에만 탐색해준다.
			//최초의 경우는 이미 0으로 배열이 초기화 되었기 때문에 OK.
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
	N_and_M(N, M, 1);
}
```

---

---

**잘못된 부분이나 오해할 수 있는 부분이 있다면 언제든지** 

**댓글 남겨주시기 바랍니다!**

![](https://t1.daumcdn.net/keditor/emoticon/niniz/large/006.gif)