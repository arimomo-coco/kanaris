#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//field info
#define F_HEIGHT 22
#define F_WIDTH  12

//mino info
#define M_HEIGHT 4
#define M_WIDTH  4
#define M_TYPE	 4
#define M_ANGLE	 4

char playField[F_HEIGHT][F_WIDTH] = {
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},//10
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},//20
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1}
};

char dispBuf[F_HEIGHT][F_WIDTH];

char mino[M_TYPE][M_ANGLE][M_HEIGHT][M_WIDTH] = {	
	//type
	{
		//angle
		{
			0, 1, 0, 0,
			0, 1, 0, 0,
			0, 1, 0, 0,
			0, 1, 0, 0,
		},
	}
};

char mX = 0, mY = 0;
char mType = 0, mAngle = 0;

void display(void);

int main(void){

	int d;
	char x, y, width_count, height_count;

	//show field
/*	for(height_count = 0; height_count < F_HEIGHT; height_count++){
		for(width_count = 0; width_count < F_WIDTH; width_count++){
			switch(playField[height_count][width_count]){
				case 1:
					printf("■ ");
					break;
				case 0:
					printf("　");
					break;
			}
		}
		printf("\n");
	}*/

	display();

	scanf("%d",&d);
}

void display(void){
	memcpy(dispBuf, playField, sizeof(playField));

	for (int i = 0; i < M_HEIGHT; i++)
	{
		for (int j = 0; j < M_WIDTH; j++)
		{
			dispBuf[mY + i][mX + j] |= mino[mType][mAngle][i][j];
		}
	}

	//remove current field 
	system("clear");

	for (int i = 0; i < F_HEIGHT; i++)
	{
		for (int j = 0; j < F_WIDTH; j++)
		{
			printf(dispBuf[i][j] ? "■ " : "　");
		}
		printf("\n");
	}
}
