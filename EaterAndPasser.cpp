#include <stdio.h>
main()
{
	char board[9][9], row, col;
	do{
	
	
	for(int i=0; i<3; i++)
	{
		printf("%d",i);
		for(int j=0; j<3; j++)
		{
			printf("| %c |",board[i][j]);
		}
		printf("\n");
	}
	printf("Enter next move: ");
	scanf("%d %d", &row, &col);
	}
	while(board!='/0');	
	printf("board is full");
}
