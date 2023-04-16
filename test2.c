#include <stdio.h>
#include <time.h>

int main() {
	int my[25];
	int com[5][5], com1[25];
	int test[5][5];
	int cnt, score;


	srand(time(NULL));
	for (int i = 0; i < 25; i++) {
		com1[i] = (rand() % 25)+1;
		for (int j = 0; j < i; j++) {
			if (com1[i] == com1[j]) {
				i--;
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++){
			com[i][j] = com1[j + (i * 5)];
		}
	}

	printf("<빙고판 입력>\n\n");
	for (int i = 0; i < 25; i++) {
		printf("→"); scanf_s("%d", &my[i]);

		for (int j = 0; j < i; j++) {
			if (my[i] == my[j]) {
				printf("이미 입력한 수 입니다.\n다시 입력해주세요\n");
				i--;
			}
			if (my[i] > 25 ||  my[i] < 1) {
				printf("범위 밖의 수 입니다.\n다시 입력해주세요\n");
				i--;
			}
		}

		for (int x = 0; x < 5; x++) {
			for (int y = 0; y < 5; y++) {
				if (com[x][y] == my[i] || test[x][y] == 1) {
					test[x][y] = 1;
				}
				else {
					test[x][y] = 0;
				}
			}
		}

		for (int x = 0; x < 5; x++) {
			for (int y = 0; y < 5; y++) {
				if (test[x][y] == 1) {
					printf("■");
				}
				else {
					printf("□");
				}
			}
			printf("\n");
		}


		cnt = 0;
		score = 0;

		for (int x = 0; x < 5; x++) {
			for (int y = 0; y < 5; y++) {
				cnt += (test[x][y] == 1);
				if (cnt == 5) {
					score++;
				}
			}
			cnt = 0;
		}

		for (int x = 0; x < 5; x++) {
			for (int y = 0; y < 5; y++) {
				cnt += (test[y][x] == 1);
				if (cnt == 5) {
					score++;
				}
			}
			cnt = 0;
		}

		for (int x = 0; x < 5; x++) {
			cnt += (test[x][x] == 1);
			if (cnt == 5) {
				score++;
			}
		}
		cnt = 0;

		for (int x = 0; x < 5; x++) {
			cnt += (test[x][4-x] == 1);
			if (cnt == 5) {
				score++;
			}
		}
		cnt = 0;
		
		printf("\n");
		for (int a = 0; a < score; a++) {
			printf("♥");
		}
		for (int a = 0; a < 3-score; a++) {
			printf("♡");
		}

		if (score == 3) {
			printf("\n[%d번 만에 빙고 완성!]\n",i+1);
			break;
		}

		printf("\n\n");

		

	}
	

}