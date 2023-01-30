#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 9

void Board(int rows, int col, char arr[9][9]) {

	for(int a=1; a<=col; a++) {
		printf("    %d",a);

	}


	printf("\n");

	for(int i=1; i<=rows; i++) {

		printf("%d ",i);

		for(int j=1; j<=col; j++) {
			printf("|");
			printf(" %c ", arr[i][j]);
			printf("|");

		}
		printf("\n\n");
	}


}

void Coordinates(int *r, int *c, int bRows, int bCol) {
	int loop=0;
	do {
		if(loop==1) {
			printf("\nYou are Exceeding Board Size!");
			loop--;
		}

		int row, col;

		if(loop!=1) {
			printf("\nRow: ");
			scanf("%d", &row);
			*r=row;

			printf("\nCol: ");
			scanf("%d", &col);
			*c=col;

			loop=1;

		}
	} while(*r>bRows || *c>bCol);

}

void PasserWin(char board[][9], int rows, int col, int *pWinning, int *iswin) {
	//check Vertical win for eater
//	int eVCounter=0;
//	for(int i=0; i<rows; i++)
//	{
//		if(board[i][0]=='E'){
//			eVCounter++;
//		}
//	}

	//check horizontal win for Eater
//	int eHCounter=0;
//	for(int i=1; i<=rows; i++)
//	{
//		for(int j=1; j<=col; j++)
//		if(board[i][j]=='E'){
//		eHCounter++;
//		if(eHCounter == col)
//			{
//				system("cls");
//				Board(rows, col, board);
//				printf("Eater Wins!");
//				exit(0);
//			}
//		}
//	}

	int win=0, p=1;

//		for(int i=1; i<=rows; i++)
//		{
//			for(int j=1; j<=col; j++)
//			{
	if( board[rows+1][col] == 'P' || board[rows+1][col+1] == 'P' || board[rows+1][col-1] == 'P' || board[rows][col+1] =='P' || board[rows][col-1] == 'P' || board[rows-1][col] == 'P') 
	{
		p++;
		*pWinning +=1;
		win=1;
		*iswin = win;
		if(board[rows-1][col-1] == 'P' && board[rows+1][col+1] == 'P') {
			*pWinning +=1;
		}

		    printf("\nCounter of WIn = %d\n", win);
	}
//}


//	int lastRow, lastCol;
//	for(int i=1; i<=rows; i++) {
//		for(int j=1; j<=col; j++) {
//			if(board[i][j] == 'P' && i!= 1 && j!= 0) {
//
//				lastRow = i;
//				lastCol = j;
//				if(i == (lastRow + 1) && (j == (lastCol + 1) || j == (lastCol - 1))) {
//					win+=1;
//				}
//
//			}
//		}
//	}
//
//	if(win == rows) {
//		printf("\nWIn\n");
//	}


}

void Moves(int size, int col, int rows, char board[][9], int choice) {

	int count=0, eat=0, pass=1, winCounter=1, pWinning=1, iswin=0;
	bool smart = false;

	switch(choice) {
		case 0:
			while(count != size) {

				printf("\ncounter %d\n",count);
				Board(rows,col, board);

				int r, c;

				if(eat!=1) {

					printf("\n+++++++Passer Make A Move++++++");

					Coordinates(&r,&c, rows, col);

					if(board[r][c] == 'E') {

						system("cls");
						printf("\nCannot Override Eater!");
						printf("\n    TRY AGAIN!\n\n");

					} else if(board[r][c] == 'P') {

						system("cls");
						printf("\nCannot Override Passer on Passer!");
						printf("\n        TRY AGAIN!\n\n");
					}

					else {
						board[r][c]='P';

						eat++;
						pass--;
						count++;

						PasserWin(board, r, c, &pWinning, &iswin);
						if(iswin == 1) {
							winCounter++;

							if(winCounter == rows || pWinning == rows) {
								system("cls");
								Board(rows, col, board);
								printf("\nPasser Win!");
								exit(0);
							}


						}



//		system("cls");

						printf("iswin %d\n", iswin);
						printf("pWinning %d\n", pWinning);
						printf("winCounter %d",winCounter);

					}


				} else {

					printf("\n+++++++Eater Make A Move++++++");

					Coordinates(&r, &c, rows, col);

					if(board[r][c] != 'E') {

						if(board[r][c] == 'P') {

							board[r][c]='E';

							eat--;

						} else {

							board[r][c]='E';

							eat--;
							pass++;
							count++;

						}

						system("cls");
					} else {
						system("cls");
						printf("\nCannot Override Eater on Eater!");
						printf("\n        TRY AGAIN!\n\n");

					}

				}
			}
			Board(rows,col,board);
			printf("\nEater Win!");
			printf("Game Ended!");
			break;

		case 1:
			count = 0;
			while(count != size) {

				printf("\ncounter %d\n",count);
				Board(rows,col, board);

				int r, c;

				if(eat!=1) {

					printf("\n+++++++Passer Make A Move++++++");

					Coordinates(&r,&c, rows, col);

					if(board[r][c] == 'E') {

						system("cls");
						printf("\nCannot Override Eater!");
						printf("\n    TRY AGAIN!\n\n");

					} else if(board[r][c] == 'P') {

						system("cls");
						printf("\nCannot Override Passer on Passer!");
						printf("\n        TRY AGAIN!\n\n");
					}

					else {
						board[r][c]='P';

						eat++;
						pass--;
						count++;

						PasserWin(board, r, c, &pWinning, &iswin);
						if(iswin == 1) {
							winCounter++;

							if(winCounter == rows || pWinning == rows) {
								system("cls");
								Board(rows, col, board);
								printf("\nPasser Win!");
								exit(0);
							}
						}

						system("cls");

						printf("iswin %d\n", iswin);
						printf("pWinning %d\n", pWinning);
						printf("winCounter %d",winCounter);

					}


				} else {

					r = rand() % (rows + 1 - 1) + 1;
					c = rand() % (rows + 1 - 1) + 1;

					if(board[r][c] != 'E') {

						if(board[r][c] == 'P') {

							board[r][c]='E';

							eat--;

						} else {

							board[r][c]='E';

							eat--;
							pass++;
							count++;

						}
						system("cls");
					}
				}

			}
			Board(rows,col,board);
			printf("\nEater Win!");
			printf("Game Ended!");
			break;

		case 2:
			while(count != size) {

				printf("\ncounter %d\n",count);
				Board(rows,col, board);

				int r, c;

				if(eat!=1) {

					if(!smart) {
						r = rand() % (rows + 1 - 1) + 1;
						c = rand() % (rows + 1 - 1) + 1;
					}
					if(smart) {
						r = rand() % ((r + 1) + 1 - c) + c;
						c = rand() % ((r + 1) + 1 - c) + c;
					}


					if(board[r][c] == 'E') {

						system("cls");
						printf("\nCannot Override Eater!");
						printf("\n    TRY AGAIN!\n\n");

					} else if(board[r][c] == 'P') {

						system("cls");
						printf("\nCannot Override Passer on Passer!");
						printf("\n        TRY AGAIN!\n\n");
					}

					else {
						board[r][c]='P';

						eat++;
						pass--;
						count++;

						PasserWin(board, r, c, &pWinning, &iswin);
						if(iswin == 1) {
							winCounter++;

							if(winCounter == rows || pWinning == rows) {
								system("cls");
								Board(rows, col, board);
								printf("\nPasser Win!");
								exit(0);
							}


						}
						system("cls");

					}


				} else {

					printf("\n+++++++Eater Make A Move++++++");

					Coordinates(&r, &c, rows, col);

					if(board[r][c] != 'E') {

						if(board[r][c] == 'P') {

							board[r][c]='E';

							eat--;

						} else {

							board[r][c]='E';

							eat--;
							pass++;
							count++;

						}

						system("cls");
					} else {
						system("cls");
						printf("\nCannot Override Eater on Eater!");
						printf("\n        TRY AGAIN!\n\n");

					}

				}
			}
			Board(rows,col,board);
			printf("\nEater Win!");
			printf("Game Ended!");
			break;

	}


}



main() {
	int rows, col, bSize;
	int choice;
	char board[MAX_SIZE][MAX_SIZE];
	int size = sizeof(board);

	for(int i=1; i <= MAX_SIZE; i++) {
		for(int j=1; j <= MAX_SIZE; j++) {
			board[i][j]=' ';
		}
	}

	int ask=1;

	printf("\n+++++++++++WELCOME!+++++++++++++\n\n");
	printf("\nSelect Your Choice!\n");
	printf("\n1. Player 1 VS Player 2\n2. Player VS CPU\n");
	printf("\nMake Your Choice: ");
	scanf("%d",&choice);
	switch(choice) {
		case 1:
			do {
				if(ask!=1) {
					printf("OUT OF RANGE!\n");
					printf("\nTRY AGAIN!\n");
					ask++;
				}

				puts("+++++Enter Size of the board++++++");
				printf("\nRows: ");
				scanf("%d",&rows);

				printf("\nColumns: ");
				scanf("%d",&col);
				bSize = rows*col;
				ask--;
				system("cls");
			} while(rows > MAX_SIZE || col > MAX_SIZE);

			Moves(bSize, rows, col, board, 0);

			break;
		case 2:
			system("cls");
			int dChoice;
			printf("\n++++++++++MAKE YOUR CHOICE+++++++++++");
			printf("\n1. Passer");
			printf("\n2. Eater\n");
			printf("\nYour Choice: ");
			scanf("%d",&dChoice);
			do {
				if(ask!=1) {
					printf("OUT OF RANGE!\n");
					printf("\nTRY AGAIN!\n");
					ask++;
				}

				puts("+++++Enter Size of the board++++++");
				printf("\nRows: ");
				scanf("%d",&rows);

				printf("\nColumns: ");
				scanf("%d",&col);
				bSize = rows*col;
				ask--;
				system("cls");
			} while(rows > MAX_SIZE || col > MAX_SIZE);
			switch(dChoice) {
				case 1:
					Moves(bSize, rows, col, board, 1);
					break;

				case 2:
					Moves(bSize, rows, col, board, 2);
					break;
			}

			break;
		default:
			printf("OUT OF RANGE!");
	}
}
