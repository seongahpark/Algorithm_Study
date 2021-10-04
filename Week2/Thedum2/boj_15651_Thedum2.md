[##_Image|kage@wjq9C/btrgMzZSwGe/zrepKPKIkHllNhKdxwExtk/img.png|alignCenter|data-origin-width="1500" data-origin-height="375" data-filename="5.png" data-ke-mobilestyle="widthOrigin"|||_##]

#### **난이도**

[##_Image|kage@WxYSt/btrgBDwhX56/U0v3Zvg0i34PM8hzbw1RI1/img.jpg|alignLeft|width="64" data-origin-width="400" data-origin-height="512" data-ke-mobilestyle="widthOrigin"|||_##]

**Silver3**

---

**문제 링크**

**[https://www.acmicpc.net/problem/15651](https://www.acmicpc.net/problem/15650)**

---

## **문제 해결 과정**

**N과M(1)에서 중복을 허용하는 경우를 출력한다.**

**간단하다. **N과M(1)에서** if문을 통해 방문했는지 안했는지에 대한 코드를 삭제해주면**

**중복을 허용하는 코드로 바뀐다.**

**출력해본다면, 이전과는 비교도 안되게 경우의 수가 많아진 것을 볼 수 있다.**

**백트래킹이 필요한 이유를 체감할 수 있다.**

## **주의할 점**

**1.현재 경우를 모두 탐색했다면, 다음 경우의 수를 위해 꼭 방문처리를 false로 바꿔주어야 한다.**

**2.이상한거 삭제하지 말고, if문만 삭제하자. 이상한거 삭제하다가 큰일난다.**

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
	/*n과m(1)에 이자리에 있었던 if문은 같은 숫자 들어가는 것을
	방지하는 역할을 했다.그 if문만 삭제해주면, 중복을 허용하고,
	사전순으로 출력된다.*/
			nm_array[now] = i;//현재 자릿수를 저장
			nm_isvisit[i] = true;//방문 처리
			N_and_M(number, digit, now + 1);//다음 경우의 수 탐색
			nm_isvisit[i] = false;//다음 경우의 수를 위해 현재 경우의 수가 끝났다면,방문 취소 처리
		
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

