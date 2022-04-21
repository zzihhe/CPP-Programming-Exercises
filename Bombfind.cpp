﻿#include "MineSweeper.h"
#define DEM 9

enum LabelType{ Empty = 0, Bomb = 9 };
enum MaskType {Hide = 0, Open, Flag};
static int MineMapMask[DIM][DIM];
static int MinMapLabel[DIM][DIM];
static int nx = DIM, ny = DIM;
static int nBomb = DIM;

//여러 가지 작은 함수들, 매우 중요함
inline int& mask(int x, int y) { return MineMapMask[y][x]; }
inline int& label(int x, int y) { return MineMapLabel[y][x]; }
inline bool isValid(int x, int y){ return (x >= 0 && x < nx&& y >= 0 && y < ny);  }
inline bool isBomb(int x, int y) { return isValid(x, y) && label(x, y) == Bomb; }
inline bool isEmpty(int x, int y) { return isValid(x, y) && label(x, y) == Empty; }
static void dig(int x, int y){                 //(x,y)를 파는(여는) 함수
	if (isValid(x, y && mask(x, y) != Open{
		mask(x,y) = Open;
	if (label(x, y) == 0) {
		dig(x - 1, y - 1);
		dig(x - 1, y);
		dig(x - 1, y + 1);
		dig(x, y - 1);
		dig(x, y + 1);
		dig(x + 1, y - 1);
		dig(x + 1, y);
		dig(x + 1, y + 1);
       }
	} 
}
static void mark(int x, int y) {                   //(x,y)에 깃발을 꽂는 함수
	if (isValid(x, y) && mask(x, y) == Hide)
		mask(x, y) = Flag;
}
static int getBombCount() {                         //깃발의 수를 계산하는 함수
	int count = 0;
	for (int y = 0; y < ny; y++)
		for (int x = 0; x < nx; x++)
			if (mask(x, y) == Flag) count++;
	return count;
}
static void print() {                  //지뢰 앱의 화면 출력 함수
	system("cls");
	printf(" 발견:%2d 전체:%2d\n", getBombCount(), nBomb);
	printf(" ➀②③④⑤⑥⑦⑧⑨\n");
	for (int y = 0; y < ny; y++) {
		printf("%2c ", 'A' + y);
		for (int x = 0; x < nx; x++) {
			if (mask(x, y) == Hide) printf("ㅁ");           //파지 않은 곳
			else if (mask(x, y) == Flag) printf("ㅁ");     // 지뢰예상 자리
			else {                                         //판 자리
				if (isBomb(x, y)) printf("※");            //9: 폭발!!
				else if (isEmpty(x, y)) printf(" ");       //0: 빈칸 표시
				else printf("%2d", label(x, y));           //1~8: 숫자 표시
			}
		}
		printf("\n");
	}
}
static int countNbrBombs(int x, int y) {  //인접한 지뢰의 수 계산 함수
	int count = 0;
	for (int yy = y - 1; yy <= y + 1; yy++)
		for (int xx = x - 1; xx <= x + 1; xx++)
			if (isValid(xx, yy) && label(xx, yy) == Bomb)
				count++;
	return count;
}
static void init(int total = 9) {
	srand((unsigned int)time(NULL));
	for (int y = 0; y < ny; y++)
		for (int x = 0; x < nx; x++) {                //지뢰 맵, 마스크 초기화
			mask(x, y) = Hide;
			label(x, y) = 0;
		}
	nBomb = total;
	for (int i = 0; i < nBomb; i++) {           //지뢰 매설(total개)
		int x, y;
		do {
			x = rand() % nx;
			y = rand() % ny;
		} while (label(x, y) != Empty);
		label(x, y) = Bomb;
	}
	for (int y = 0; y < ny; y++)
		for (int x = 0; x < nx; x++)
			if (label(x, y) == Empty)
				label(x, y) = countNorBombs(x, y);
}
static bool getPos(int& x, int& y) {              //키보드 좌표 입력 함수
	printf("\n지뢰(P)행(A-I)열(1-9)\n 입력 --> ");
	bool isBomb = false;
}