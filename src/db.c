#include "../lib/db.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void db_init_manager(DBManager* manager){
manager->table_count = 0;
}

Table* db_create_table(DBManager* manager, const char* name){
	if (manager->table_count >= MAX_TABLES) return NULL;
	
	Table* new_table = malloc(sizeof(Table));
	strncpy(new_table->schema.table_name, name, 31);
	new_table->schema.col_count = 0;
	new_table->schema.row_size = 0;
	new_table->row_count = 0;

	manager->tables[manager->table_count++] = new_table;
return new_table;
}
	

void db_add_column(Table* table, const char* name, ColumnType type, uint32_t size)
{
Schema* s = &table->schema;
if(s->col_count >= MAX_COLUMNS) return;

	Column* col = &s->columns[s->col_count];
	strncpy(col->name, name, 31);
	col->type = type;
	
	col->size = (type == TYPE_INT) ? sizeof(int32_t) : size;
	col->offset = s->row_size;

	s->row_size += col->size;
	s->col_count++;
}

void db_insert(Table* table, char** values)
{
void* new_row = malloc(table-> schema.row_size);
	for(uint32_t i = 0; i < table->schema.col_count; i++)
	{
	Column* col = &table->schema.columns[i];
	void* field_ptr = (char*)new_row + col -> offset;
	if(col->type == TYPE_INT)
	{
	int32_t val = atoi(values[i]);
	}
	else
	{
	memset(field_ptr, 0, col->size);
	strncpy((char*)field_ptr, values[i], col->size -1);
	}
	}

table->rows[table->row_count++] = new_row;
}

void db_select(Table* table){
printf("\n --Table: %s --\n", table->schema.table_name);
	for(uint32_t i = 0; i < table->row_count; i++)
	{
		for(uint32_t j = 0; j < table->schema.col_count; j++)
		{
		Column* col = &table->schema.columns[j];
		void* field = table->rows[i] + col -> offset;
		if(col->type == TYPE_INT) printf("%d |", *(int32_t*)field);
		else printf ("%s |", (char*)field);
		}
	printf("\n");
	}
}


Table* db_find_table(DBManager *manager, const char* name)
{
	for(uint32_t i=0; i < manager->table_count; i++)
	{
	if(strcmp(manager->tables[i]->schema.table_name, name) == 0)
	return manager->tables[i];
	}
return NULL;
}
