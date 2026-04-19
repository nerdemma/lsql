#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/db.h"

int main()
{

DBManager manager;
db_init_manager(&manager);
char input[256];
printf("---- LSQL V 0.1 ---- \n");

	while(1)
	{
	printf("lsql> ");	
	if(!fgets(input, sizeof(input), stdin)) break;		
	input[strcspn(input,"\n")] = 0;
	char *cmd = strtok(input, " ");
	if (!cmd) continue;
	
	if(strcmp(cmd, "CREATE")== 0)
	{ 
		char *t_name = strtok(NULL, " ");
		Table* t = db_create_table(&manager, t_name);
		// add two default columns
		db_add_column(t, "ID", TYPE_INT, 0);
		db_add_column(t, "DATA", TYPE_TEXT, 20);
		printf("Table '%s' created \n", t_name); 
	}
		
	else if(strcmp(cmd, "INSERT")== 0)
	{
	char *t_name = strtok(NULL, " ");
	Table* t = db_find_table(&manager, t_name);
		if(t)
		{
		char *v1 = strtok(NULL, " ");
		char *v2 = strtok(NULL, " ");
		char *vals[] = {v1, v2};
		db_insert(t, vals);
		}
	}
	
	else if(strcmp(cmd, "SELECT")== 0)
	{
	char *t_name = strtok(NULL, " ");
	Table* t = db_find_table(&manager, t_name);	
	if(t) db_select(t);
	}
	
	else if(strcmp(cmd, "LIST")== 0)
	{
	printf("Tables Available: %d\n", manager.table_count);
		for (uint32_t i=0; i < manager.table_count; i++)
		{ printf("- %s\n", manager.tables[i]->schema.table_name);}
	}
	
	else if(strcmp(cmd, "EXIT")== 0)
	{
	break;
	}
	
}	
return 0;

}
