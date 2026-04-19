Lightweight SQL - Lightweight Data Base Engine
Functional and scalable DB, designed with an dynamic scheme architecture. 
Different to the stactic db static, LSQL can define tables, columns and datatypes during
the time of execution using pointers aritmeticals and memory offset to a most efficent
manage of resources.

## main features
* ** Dynamic Schema:** Support to create custom tables with cols from type 'INT' and 'TEXT'.
* ** Memory Administration** Use of 'Void*' and calculated offsets to minimize the padding and maximize the time-access data. 
* ** Modular Architecture** Clear separated between the interface ('lib/'), the logic engine ('src') and the user interface.
* ** Compiler Compatible** Optimized to 'cc 11.1.0' under standards C11.


'''text
Structure of Directories
|_Makefile 	# config file compiler
|_Lib/ 		# headers.h
|_src/		# sourcecode.h
|_Readme.md	# technical docs

	
Compile and Execution 

$: git clone https://github.com/nerdemma/lsql
$: cd lsql
$: make
$: ./lsql
$:>lsql


Commands

CREATE <table_name> <value_1> <value_2>:
Create a new table with a predefined schema.
Initialize a new table in memory.

INSERT
Add registers to the table.

SELECT <table_name> 
Map and show the content of the table.

LIST
Enum all tables created in the current session.

EXIT
Close the engine and free pointers. 

Technical Details 
The engine manage the rows with a structure that calulate with row_size total. 
Each column have a offset that indique where begin their internal data
 in the memory-block.

ColumType: TYPE_INT (4 bytes) and TYPE_TEXT (user defined size var)
Pointers Arithmeticals: the data access is realized by (char*)row_ptr + col->offset

 
 
