//
// C++
//
#include<stdio.h>
#include <stdlib.h>
void kakukaku(int[][100], int i = 0, int j = 0, int goke = 0);

int most_max, i_max;

int main() {
	int s[100][100] = { 0 };
	int i, j;
	//テキストファイル読み込み
	//read
	FILE *fp;
	errno_t error;
	if (error = fopen_s(&fp, "input.txt", "r") == 0) {
		fscanf_s(fp, "%d", &i_max);
		for (i = 0; i < i_max; i++) {
			for (j = 0; j < i + 1; j++) {
				fscanf_s(fp, "%d", &s[i][j]);
			}
		}
		fclose(fp);
	}
	//読み込み情報表示
	//out
	/*
	printf("%d\n", i_max);
	for (i = 0; i < i_max; i++) {
		for (j = 0; j < i + 1; j++) {
			printf("%d ", s[i][j]);
		}
	printf("\n");
	}
	*/
	kakukaku(s);
	printf("mosut=%d\n", most_max);
	return 0;
}

void kakukaku(int s[][100], int i, int j, int goke) {
	if (i < i_max) {
		for (int m = j; m <= j + 1; m++) {
			kakukaku(s, i + 1, m, goke + s[i][m]);
		}
	} else {
		if (goke > most_max) {
			most_max = goke;
		}
	}
}
