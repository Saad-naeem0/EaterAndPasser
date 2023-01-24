#include <stdio.h>
#include <stdlib.h>

void Board(int rows, int col, char arr[9][9]){

	for(int a=1; a<=rows; a++)
	{
		printf("    %d",a);
		
	}
	
	
	printf("\n");
	
	for(int i=1; i<=rows; i++)
	{
		
		printf("%d ",i);
		
		for(int j=1; j<=col; j++)
		{
			printf("|");
			printf(" %c ", arr[i][j]);
			printf("|");
		}
		printf("\n\n");
	}
}

void Coordinates(int *r, int *c, int bRows, int bCol){
	int loop=0;
	do{
		
	int row, col;
	
	if(loop!=1){
	printf("\nRow: ");
	scanf("%d", &row);
	*r=row;
	
	printf("\nCol: ");
	scanf("%d", &col);
	*c=col;
	
	loop=1;
	
		}
	}
	while(*r>bRows && *c>bCol);
	
	
	printf("\nYou are Exceeding Board Size!");
	
	
}

void EaterWin(char board[][9], int rows, int col){
	//check Vertical win for eater
	int eVCounter=0;
	for(int i=0; i<rows; i++)
	{
		if(board[i][1]=='E'){
			eVCounter++;
		}
	}
	
	//check horizaontal win for Eater
	int eHCounter=0;
	for(int j=0; j<col; j++)
	{
		if(board[1][j]=='E'){
			eHCounter++;
		}
	}
	
	if(eVCounter == rows || eHCounter == col){
		printf("Eater Wins!");
	}
}

void Moves(int size, int col, int rows, char board[][9]){
	
	int count=0, eat=0, pass=1;
	
	while(count != size){
		
	Board(rows,col, board);
	
	int r, c;
	
	if(eat!=1){
		
		printf("\n+++++++Passer Make A Move++++++");
	
		Coordinates(&r,&c, rows, col);
	
	if(board[r][c] == 'E'){
		
		system("cls");
		printf("\nCannot Override Eater!");
		printf("\n    TRY AGAIN!\n\n");
		
	}
	else if(board[r][c] == 'P'){
		
		system("cls");
		printf("\nCannot Override Passer on Passer!");
		printf("\n        TRY AGAIN!\n\n");
		}
		
	else{	
		board[r][c]='P';
	
		eat++;
		pass--;
		count++;
		system("cls");
		
		}
	
	
	}
	else{
	
	printf("\n+++++++Eater Make A Move++++++");
	
	Coordinates(&r, &c, rows, col);
	
	if(board[r][c] != 'E'){
		
		board[r][c]='E';
	
		eat--;
		pass++;
		if(board[r][c] == 'P'){
			count--;
		}else{
			count++;
		}
		
		system("cls");
			
		}
	else{
		system("cls");
		printf("\nCannot Override Eater on Eater!");
		printf("\n        TRY AGAIN!\n\n");
		
		}
	
	}
	
	
	EaterWin(board, rows, col);
	
	}
	Board(rows,col,board);
	printf("Game Ended!");
	
}


main(){
	int rows, col;
	char board[9][9];
	int size = sizeof(board)/sizeof(board[0]);
	
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			board[i][j]=' ';
		}
	}
	
	puts("+++++Enter Size of the board++++++");
	
	printf("\nRows: ");
	scanf("%d",&rows);
	
	printf("\nColumns: ");
	scanf("%d",&col);
	system("cls");
	
	int boardSize = rows*col;
	
	Moves(boardSize,rows, col, board);
	
	
	
	
}
