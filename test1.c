#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main() {
	int my[3], my1;
	int com[3];
	int s, b,k;
	
	//랜덤 난수 생성(중복없이)
	srand(time(NULL));
	for (int i = 0; i < 3; i++) {
		com[i] = (rand() % 10);
		for (int j = 0; j < i; j++) {
			if (com[i] == com[j]) i--;
		}
	}

	for (k = 10; k > 0; k--) {
		//남은 기회 출력
		printf("%d번의 기회가 남았습니다.\n", k);

		//사용자에게 입력받기
		printf("세자리 수 입력(중복 불가):");scanf_s("%d", &my1);
		my[0] = my1 / 100;
		my[1] = (my1 / 10) % 10;
		my[2] = my1 % 10;

		s = 0, b = 0;
		for (int i = 0; i < 3; i++) {
			if (com[i] == my[i]) {
				s++;
			}
			for (int j = 0; j < 3; j++) {
				if (com[i] == my[j]) {
					b++;
				}
			}
		}
		if (s == 3) {
			printf("게임 종료");
			break;
		}
		printf("S%d B%d\n", s, b-s);
		printf("\n");
	}
	if (k == 0) {
		printf("기회가 모두 소진되었습니다.\n");
		printf("com : %d%d%d\n", com[0], com[1], com[2]);
	}
}