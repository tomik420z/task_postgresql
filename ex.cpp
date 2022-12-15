/* Processed by ecpg (15.0) */
/* These include files are added by the preprocessor */

/* End of automatic include section */

#line 1 "ex.txt"
#include "C:/Program Files/PostgreSQL/15/include/ecpglib.h"
#include "C:/Program Files/PostgreSQL/15/include/ecpgerrno.h"
#include "C:/Program Files/PostgreSQL/15/include/sqlca.h"
#include "db_public_station.h"

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>


#line 1 "C:/Program Files/PostgreSQL/15/include/sqlca.h"
#ifndef POSTGRES_SQLCA_H
#define POSTGRES_SQLCA_H

#ifndef PGDLLIMPORT
#if  defined(WIN32) || defined(__CYGWIN__)
#define PGDLLIMPORT __declspec (dllimport)
#else
#define PGDLLIMPORT
#endif							/* __CYGWIN__ */
#endif							/* PGDLLIMPORT */

#define SQLERRMC_LEN	150

#ifdef __cplusplus
extern "C"
{
#endif

struct sqlca_t
{
	char		sqlcaid[8];
	long		sqlabc;
	long		sqlcode;
	struct
	{
		int			sqlerrml;
		char		sqlerrmc[SQLERRMC_LEN];
	}			sqlerrm;
	char		sqlerrp[8];
	long		sqlerrd[6];
	/* Element 0: empty						*/
	/* 1: OID of processed tuple if applicable			*/
	/* 2: number of rows processed				*/
	/* after an INSERT, UPDATE or				*/
	/* DELETE statement					*/
	/* 3: empty						*/
	/* 4: empty						*/
	/* 5: empty						*/
	char		sqlwarn[8];
	/* Element 0: set to 'W' if at least one other is 'W'	*/
	/* 1: if 'W' at least one character string		*/
	/* value was truncated when it was			*/
	/* stored into a host variable.             */

	/*
	 * 2: if 'W' a (hopefully) non-fatal notice occurred
	 */	/* 3: empty */
	/* 4: empty						*/
	/* 5: empty						*/
	/* 6: empty						*/
	/* 7: empty						*/

	char		sqlstate[5];
};

struct sqlca_t *ECPGget_sqlca(void);

#ifndef POSTGRES_ECPG_INTERNAL
#define sqlca (*ECPGget_sqlca())
#endif

#ifdef __cplusplus
}
#endif

#endif

#line 11 "ex.txt"


/* exec sql begin declare section */ 
            
            
            

#line 14 "ex.txt"
 char ConnectionString [] = "public transport@127.0.0.1:5432" ;
 
#line 15 "ex.txt"
 char Login [] = "postgres" ;
 
#line 16 "ex.txt"
 char Password [] = "20012001a" ;
/* exec sql end declare section */
#line 17 "ex.txt"



/* exec sql whenever sqlerror  sqlprint ; */
#line 20 "ex.txt"
	


int menu();

int main() {

        { ECPGconnect(__LINE__, 0, ConnectionString , Login , Password , NULL, 0); 
#line 27 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 27 "ex.txt"


        if( sqlca.sqlcode != 0 || strncmp(sqlca.sqlstate,"00",2))
        {
                printf("connect -- NoOK\n");
                return 0;
        }
        else
        {
                printf("connect --OK\n");	
                menu();
        }	
        { ECPGdisconnect(__LINE__, "CURRENT");
#line 39 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 39 "ex.txt"

        printf("disconnect --OK\n");

        return 0;
}



int change_data_table(const char * req_sql)
{

        /* exec sql begin declare section */ 
                     
        
#line 51 "ex.txt"
 const char * stmt = req_sql ;
/* exec sql end declare section */
#line 52 "ex.txt"


        { ECPGprepare(__LINE__, NULL, 0, "sqlstmt", stmt);
#line 54 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 54 "ex.txt"

        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_execute, "sqlstmt", ECPGt_EOIT, ECPGt_EORT);
#line 55 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 55 "ex.txt"

        { ECPGtrans(__LINE__, NULL, "commit");
#line 56 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 56 "ex.txt"

        return 0;
}

int Dynamic_sql_select_1(const char * request_sql)
{
        /* exec sql begin declare section */
                 
                 
                 
                 
                     
        
#line 63 "ex.txt"
 int colcount ;
 
#line 64 "ex.txt"
 int index ;
 
#line 65 "ex.txt"
 char str [ 1024 ] ;
 
#line 66 "ex.txt"
 char colName [ 1024 ] ;
 
#line 67 "ex.txt"
 const char * stmt = request_sql ;
/* exec sql end declare section */
#line 68 "ex.txt"


        { ECPGprepare(__LINE__, NULL, 0, "sqlstmt", stmt);
#line 70 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 70 "ex.txt"


        ECPGallocate_desc(__LINE__, "my_descr");
#line 72 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();
#line 72 "ex.txt"
   

        /* declare my_cursor cursor for $1 */
#line 74 "ex.txt"

        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare my_cursor cursor for $1", 
	ECPGt_char_variable,(ECPGprepared_statement(NULL, "sqlstmt", __LINE__)),(long)1,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 75 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 75 "ex.txt"



        
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch next from my_cursor", ECPGt_EOIT, 
	ECPGt_descriptor, "my_descr", 1L, 1L, 1L, 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 79 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 79 "ex.txt"

        
        { ECPGget_desc_header(__LINE__, "my_descr", &(colcount));

#line 81 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 81 "ex.txt"

        for(index = 1; index <= colcount; index++) {
                { ECPGget_desc(__LINE__, "my_descr", index,ECPGd_data,
	ECPGt_char,(str),(long)1024,(long)1,(1024)*sizeof(char), ECPGd_EODT);

#line 83 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 83 "ex.txt"

                { ECPGget_desc(__LINE__, "my_descr", index,ECPGd_name,
	ECPGt_char,(colName),(long)1024,(long)1,(1024)*sizeof(char), ECPGd_EODT);

#line 84 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 84 "ex.txt"

                std::cout << str << " ";
        }
        std::cout << '\n';
        ECPGdeallocate_desc(__LINE__, "my_descr");
#line 88 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();
#line 88 "ex.txt"

        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close my_cursor", ECPGt_EOIT, ECPGt_EORT);
#line 89 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 89 "ex.txt"

        { ECPGtrans(__LINE__, NULL, "commit");
#line 90 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 90 "ex.txt"

        

        
        
        
        
        
        //EXEC SQL EXECUTE sqlstmt INTO : address_id, title, type_station USING : address_id;
  
    return 0;
}


/*
int Dynamic_sql_select_2()
{
     EXEC SQL BEGIN DECLARE SECTION;           
          char *stmt = "SELECT name "
             "  FROM exTab "
             "  WHERE id>=? and id<=?";
     int id_min;
     int id_max;
     EXEC SQL END DECLARE SECTION;



     EXEC SQL PREPARE sqlstmt FROM :stmt;

     EXEC SQL DECLARE my_cursor CURSOR FOR sqlstmt ;

printf("select 'id_min' >");
        scanf("%d", &id_min);

printf("select 'id_max' >");
        scanf("%d", &id_max);

     EXEC SQL OPEN my_cursor USING :id_min,:id_max;



     while (1)
     {
        EXEC SQL FETCH my_cursor INTO :my_data;    
        if (sqlca.sqlcode == ECPG_NOT_FOUND || strncmp(sqlca.sqlstate,"00",2)) break;
        printf("name=%s\n", my_data);	
     }

    EXEC SQL CLOSE my_cursor;

    EXEC SQL COMMIT;
    return 0;
}
*/
/*
int InsertValues()
{	
               
        std::cout << "enter new 'address_id' >"; 
        std::cin >> addr;
        std::cout << "enter new 'title' >";
        std::cin >> title;
        std::cout << "enter new 'stantion type' >"; 
        std::cin >> type_st;
        
        EXEC SQL INSERT INTO t_stop( address_id , title , type_station) VALUES(:addr, :title, :type_st);

        EXEC SQL COMMIT;
        return 0;
}
*/

int ReadAllRecord(const char * req_sql)
{
        /* exec sql begin declare section */ 
                 
                 
                 
                 
                     
        
#line 165 "ex.txt"
 int colcount ;
 
#line 166 "ex.txt"
 int index ;
 
#line 167 "ex.txt"
 char str [ 1024 ] ;
 
#line 168 "ex.txt"
 char colName [ 1024 ] ;
 
#line 169 "ex.txt"
 const char * stmt = req_sql ;
/* exec sql end declare section */
#line 170 "ex.txt"

 
        { ECPGprepare(__LINE__, NULL, 0, "sqlstmt", stmt);
#line 172 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 172 "ex.txt"


        ECPGallocate_desc(__LINE__, "myDescr");
#line 174 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();
#line 174 "ex.txt"
   

        /* declare MyCursor cursor for $1 */
#line 176 "ex.txt"

        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare MyCursor cursor for $1", 
	ECPGt_char_variable,(ECPGprepared_statement(NULL, "sqlstmt", __LINE__)),(long)1,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 177 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 177 "ex.txt"

        
        while(1)
        {                        
                { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch next from MyCursor", ECPGt_EOIT, 
	ECPGt_descriptor, "myDescr", 1L, 1L, 1L, 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 181 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 181 "ex.txt"

                
                if (sqlca.sqlcode == ECPG_NOT_FOUND || strncmp(sqlca.sqlstate,"00",2)) break;
                { ECPGget_desc_header(__LINE__, "myDescr", &(colcount));

#line 184 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 184 "ex.txt"

                for(index = 1; index <= colcount; index++) {
                        { ECPGget_desc(__LINE__, "myDescr", index,ECPGd_data,
	ECPGt_char,(str),(long)1024,(long)1,(1024)*sizeof(char), ECPGd_EODT);

#line 186 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 186 "ex.txt"

                        { ECPGget_desc(__LINE__, "myDescr", index,ECPGd_name,
	ECPGt_char,(colName),(long)1024,(long)1,(1024)*sizeof(char), ECPGd_EODT);

#line 187 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 187 "ex.txt"

                        std::cout << str << " ";
                }
                std::cout << '\n';
        }
        ECPGdeallocate_desc(__LINE__, "myDescr");
#line 192 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();
#line 192 "ex.txt"

        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close MyCursor", ECPGt_EOIT, ECPGt_EORT);
#line 193 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 193 "ex.txt"

        { ECPGtrans(__LINE__, NULL, "commit");
#line 194 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 194 "ex.txt"

        
        return 0;
}






/*
int SelectValues()
{	

        
        std::cout << "select 'address_id' >";
        std::cin >> addr;
        
        EXEC SQL SELECT address_id, title, type_station INTO :addr, :title, :type_st FROM t_stop WHERE address_id = :addr;
        std::cout << addr << " " << title << " " << type_st << std::endl;
        return 0;
}*/

/*
int UpdateValues()
{	

        UPDATE films SET kind = 'Dramatic' WHERE kind = 'Drama';
        std::cout << "select updatable 'address_id' >";
        std::cin >> addr;
        std::cout << "enter new 'title' >";
        std::cin >> title;
        std::cout << "enter new 'type_station' >";
        std::cin >> type_st;
         
        EXEC SQL UPDATE t_stop SET title = :title, type_station = :type_st WHERE address_id = :addr;	

        EXEC SQL COMMIT;
        return 0;
}
*/
/*
int DeleteValues()
{
        std::cout << "select deleted 'address_id' >";
        std::cin >> addr;
        EXEC SQL DELETE FROM t_stop WHERE address_id = :addr;
        EXEC SQL COMMIT;
}*/

int menu()
{
        table_station table;
        char sitem[512];
        while(1)
        {
            printf("1. show\n");
            printf("2. select values\n");
            printf("3. update values\n");
            printf("4. insert values\n");
            printf("5. delete values\n");
            printf("6. Dynamic sql insert\n");
            printf("7. Dynamic sql select one\n");
            printf("8. Dynamic sql select more than one\n");
            printf("9. quit\n");
            printf("choose menu item > ");
            if(scanf("%s", &sitem)!=1) break;
         
            if (strlen(sitem)>1) continue;   
           
                switch(sitem[0])
                {
                        case '1':
                        {
                                printf("_____________________\n");
                                printf("1. show\n");
                                ReadAllRecord(table.req_show());
                                printf("_____________________\n");
                                break;
                        }
                        case '2':
                        {
                                printf("_____________________\n");
                                printf("2. select values\n");
                                ReadAllRecord(table.req_select());
                                //SelectValues();
                                printf("_____________________\n");
                                break;
                        }
                        case '3':
                        {
                                printf("_____________________\n");
                                printf("3. update values\n");
                                change_data_table(table.req_update());
                                //UpdateValues();
                                printf("_____________________\n");
                                break;
                        }
                        case '4':
                        {
                                printf("_____________________\n");
                                printf("4. insert values\n");
                                change_data_table(table.req_insert());	
                                //InsertValues();
                                printf("_____________________\n");
                                break;
                        }
                        case '5':
                        {
                                printf("_____________________\n");
                                printf("5. delete values\n");
                                change_data_table(table.req_delete_id());
                                //DeleteValues();
                                printf("_____________________\n");
                                break;
                        }
                        /*
                        case '6':
                        {
                               change_data_table();
                               break;
                        }
                        case '7':
                        {       
                                Dynamic_sql_select_1();
                                break;
                        }
                         case '8':
                        {
                               //Dynamic_sql_select_2();
                               break;
                        }
                        */
                        case '9':
                        {
                                return 0;
                        }
                        default: break;
                }
        }
        return 0;
}

/*void f_error(void)
{
   printf("\n% .70s \n", sqlca.sqlerrm.sqlerrmc);
}*/
