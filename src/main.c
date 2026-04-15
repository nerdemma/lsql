#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 256
#define MAX_ROWS 100

typedef struct{
char data[MAX_ROWS][5][50];
int row_count;
}Database;


void handle_insert(Database *db, char *args)
{
char *token = strtok(args, " ");
int col = 0;

	while(token != NULL && col < 5)
	{
	strcpy(db->data[db->row_count][col], token);
	token = strtok(NULL, " ");
	col ++;
	}

db->row_count++;
printf("OK Row inserted on: %d\n", db->row_count);
}


void handle_select(Database *db)
{
printf("----- RESULTS ----\n");
for(int i = 0; i<db->row_count;i++)
{
	for(int j = 0; j < 5; j++)
	{
	if(strlen(db->data[i][j]) > 0)
	{
	printf("%s |", db->data[i][j]);
	}
	printf("\n");
	}
}

}


int main()
{
Database db = { .row_count = 0 };
char input[MAX_BUFFER];
printf("----LSQL v0.1 ----\n sql>");

	while(fgets(input, MAX_BUFFER, stdin))
	{
	input[strcspn(input,"\n")] = 0;
	char *cmd = strtok(input, " ");
	char *args = strtok(NULL, " ");

	if(strcmp(cmd, "INSERT")== 0){handle_insert(&db, args);}
	else if(strcmp(cmd, "SELECT")== 0){handle_select(&db);}
	else if(strcmp(cmd, "EXIT")== 0){ break;}
	printf("sql>");	
	}
return 0;

}

