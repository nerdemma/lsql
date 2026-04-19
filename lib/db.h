#ifndef DB_H
#define DB_H
#include<stdint.h>

#define MAX_TABLES 10
#define MAX_COLUMNS 10

typedef enum{ TYPE_INT, TYPE_TEXT } ColumnType;

typedef struct{
char name[32];
ColumnType type;
uint32_t size;
uint32_t offset;
} Column;

typedef struct{
char table_name[32];
Column columns[MAX_COLUMNS];
uint32_t col_count;
uint32_t row_size;
} Schema;

typedef struct {
Schema schema;
void* rows[100];
uint32_t row_count;
} Table;


typedef struct{
Table* tables[MAX_TABLES];
uint32_t table_count;
}DBManager;


// prototypes
void db_init_manager(DBManager* manager);
Table* db_create_table(DBManager* manager, const char* name);
void db_add_column(Table* table, const char* name, ColumnType type, uint32_t size);
void db_insert(Table* table, char** values);
void db_select(Table* table);
Table*	db_find_table(DBManager* manager, const char* name);

#endif
