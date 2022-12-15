/* Processed by ecpg (15.0) */
/* These include files are added by the preprocessor */

/* End of automatic include section */

#line 1 "ex.txt"
/*
ecpg ex.txt
cc -I/usr/include/postgresql -c ex.c
cc -o ex ex.o -L/usr/lib/x86_64-linux-gnu -lecpg,
��� -L/usr/lib/x86_64-linux-gnu ���� ��� ����� libecpg.so
-I/usr/include/postgresql ���� ��� ����� ecpgtype.h, ecpglib.h, ecpgerrno.h, sqlca.h.
*/


#include "C:/Program Files/PostgreSQL/15/include/ecpglib.h"
#include "C:/Program Files/PostgreSQL/15/include/ecpgerrno.h"
#include "C:/Program Files/PostgreSQL/15/include/sqlca.h"
//#include "db_public_station.h"

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

#line 20 "ex.txt"


/* exec sql begin declare section */ 
            
            
            

#line 23 "ex.txt"
 char ConnectionString [] = "public transport@127.0.0.1:5432" ;
 
#line 24 "ex.txt"
 char Login [] = "postgres" ;
 
#line 25 "ex.txt"
 char Password [] = "20012001a" ;
/* exec sql end declare section */
#line 26 "ex.txt"


/* exec sql begin declare section */
        //int my_id;
        //char my_data[256];
        //int my_count;
        //char date1[10];
        //char date2[10];
         
         
         

#line 34 "ex.txt"
 int addr ;
 
#line 35 "ex.txt"
 char title [ 64 ] ;
 
#line 36 "ex.txt"
 int type_st ;
/* exec sql end declare section */
#line 37 "ex.txt"
	

/* exec sql whenever sqlerror  sqlprint ; */
#line 39 "ex.txt"
	

class table_station {
public:
using id_t = int;
    using title_t = std::string;
    using station_t = int;
protected:
/* exec sql begin declare section */  

         
         
         

#line 49 "ex.txt"
 int address_id ;
 
#line 50 "ex.txt"
 char title [ 64 ] ;
 
#line 51 "ex.txt"
 int type_station ;
/* exec sql end declare section */
#line 52 "ex.txt"


public:

    table_station() = default;
    ~table_station() = default;
    
    const char* insert() const noexcept {
        return "INSERT INTO t_stop(address_id, title, type_station) VALUES(?, ?, ?);"; 
    }

    void exec_3args() {
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_execute, "mystmt", 
	ECPGt_int,&(address_id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(title),(long)64,(long)1,(64)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(type_station),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 64 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 64 "ex.txt"

    }

    void exec_fetch() {        
        //EXEC SQL FETCH MyCursor INTO :address_id, :title, :type_station;
    }



    void input() {
        std::cout << "enter new 'address_id' >"; 
        std::cin >> address_id;
        std::cout << "enter new 'title' >";
        std::cin >> title;
        std::cout << "enter new 'stantion type' >"; 
        std::cin >> type_station;
    }

    void enter_id() {
        std::cout << "enter new 'address_id' >"; 
        std::cin >> address_id;
    }
/*
    void exec_select() {
            EXEC SQL EXECUTE sqlstmt INTO : address_id, title, type_station USING : address_id;
    }
*/
    const char* select_show() const noexcept {
        return "SELECT address_id, title, type_station FROM t_stop ORDER BY address_id";
    }

    void print() const noexcept {
        std::cout << address_id << " "  << title << " " << type_station << std::endl;
     }




};


   
int menu();
int main() {

        { ECPGconnect(__LINE__, 0, ConnectionString , Login , Password , NULL, 0); 
#line 109 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 109 "ex.txt"



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
#line 122 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 122 "ex.txt"

        printf("disconnect --OK\n");
}



int Dynamic_sql_insert()
{
table_station table;
/* exec sql begin declare section */ 
             

#line 132 "ex.txt"
 const char * stmt = table . insert () ;
/* exec sql end declare section */
#line 133 "ex.txt"


        { ECPGprepare(__LINE__, NULL, 0, "mystmt", stmt);
#line 135 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 135 "ex.txt"

        table.input();
        
        table.exec_3args();
       // EXEC SQL EXECUTE mystmt USING :address_id, :title, :type_station;
        { ECPGtrans(__LINE__, NULL, "commit");
#line 140 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 140 "ex.txt"

        return 0;
}

int Dynamic_sql_select_1(const char * request_sql)
{
        /* exec sql begin declare section */
                 
                 
                 
                 
                     
        
#line 147 "ex.txt"
 int colcount ;
 
#line 148 "ex.txt"
 int index ;
 
#line 149 "ex.txt"
 char str [ 1024 ] ;
 
#line 150 "ex.txt"
 char colName [ 1024 ] ;
 
#line 151 "ex.txt"
 const char * stmt = request_sql ;
/* exec sql end declare section */
#line 152 "ex.txt"


        { ECPGprepare(__LINE__, NULL, 0, "sqlstmt", stmt);
#line 154 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 154 "ex.txt"


        ECPGallocate_desc(__LINE__, "my_descr");
#line 156 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();
#line 156 "ex.txt"
   

        /* declare my_cursor cursor for $1 */
#line 158 "ex.txt"

        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare my_cursor cursor for $1", 
	ECPGt_char_variable,(ECPGprepared_statement(NULL, "sqlstmt", __LINE__)),(long)1,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 159 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 159 "ex.txt"



        
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch next from my_cursor", ECPGt_EOIT, 
	ECPGt_descriptor, "my_descr", 1L, 1L, 1L, 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 163 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 163 "ex.txt"

        
        { ECPGget_desc_header(__LINE__, "my_descr", &(colcount));

#line 165 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 165 "ex.txt"

        for(index = 1; index <= colcount; index++) {
                { ECPGget_desc(__LINE__, "my_descr", index,ECPGd_data,
	ECPGt_char,(str),(long)1024,(long)1,(1024)*sizeof(char), ECPGd_EODT);

#line 167 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 167 "ex.txt"

                { ECPGget_desc(__LINE__, "my_descr", index,ECPGd_name,
	ECPGt_char,(colName),(long)1024,(long)1,(1024)*sizeof(char), ECPGd_EODT);

#line 168 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 168 "ex.txt"

                std::cout << str << " ";
        }
        std::cout << '\n';
        ECPGdeallocate_desc(__LINE__, "my_descr");
#line 172 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();
#line 172 "ex.txt"

        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close my_cursor", ECPGt_EOIT, ECPGt_EORT);
#line 173 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 173 "ex.txt"

        { ECPGtrans(__LINE__, NULL, "commit");
#line 174 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 174 "ex.txt"

        

        
        
        
        
        
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

int InsertValues()
{	
               
        std::cout << "enter new 'address_id' >"; 
        std::cin >> addr;
        std::cout << "enter new 'title' >";
        std::cin >> title;
        std::cout << "enter new 'stantion type' >"; 
        std::cin >> type_st;
        
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into t_stop ( address_id , title , type_station ) values ( $1  , $2  , $3  )", 
	ECPGt_int,&(addr),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(title),(long)64,(long)1,(64)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(type_st),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 239 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 239 "ex.txt"


        { ECPGtrans(__LINE__, NULL, "commit");
#line 241 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 241 "ex.txt"

        return 0;
}


int ReadAllRecord()
{
        /* exec sql begin declare section */ 
                 
                 
                 
                 
                     
        
#line 249 "ex.txt"
 int colcount ;
 
#line 250 "ex.txt"
 int index ;
 
#line 251 "ex.txt"
 char str [ 1024 ] ;
 
#line 252 "ex.txt"
 char colName [ 1024 ] ;
 
#line 253 "ex.txt"
 const char * stmt = "SELECT address_id, title, type_station FROM t_stop ORDER BY address_id" ;
/* exec sql end declare section */
#line 254 "ex.txt"

 
        { ECPGprepare(__LINE__, NULL, 0, "sqlstmt", stmt);
#line 256 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 256 "ex.txt"


        ECPGallocate_desc(__LINE__, "myDescr");
#line 258 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();
#line 258 "ex.txt"
   

        /* declare MyCursor cursor for $1 */
#line 260 "ex.txt"

        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare MyCursor cursor for $1", 
	ECPGt_char_variable,(ECPGprepared_statement(NULL, "sqlstmt", __LINE__)),(long)1,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 261 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 261 "ex.txt"

        
        while(1)
        {                        
                { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch next from MyCursor", ECPGt_EOIT, 
	ECPGt_descriptor, "myDescr", 1L, 1L, 1L, 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 265 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 265 "ex.txt"

                
                if (sqlca.sqlcode == ECPG_NOT_FOUND || strncmp(sqlca.sqlstate,"00",2)) break;
                { ECPGget_desc_header(__LINE__, "myDescr", &(colcount));

#line 268 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 268 "ex.txt"

                for(index = 1; index <= colcount; index++) {
                        { ECPGget_desc(__LINE__, "myDescr", index,ECPGd_data,
	ECPGt_char,(str),(long)1024,(long)1,(1024)*sizeof(char), ECPGd_EODT);

#line 270 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 270 "ex.txt"

                        { ECPGget_desc(__LINE__, "myDescr", index,ECPGd_name,
	ECPGt_char,(colName),(long)1024,(long)1,(1024)*sizeof(char), ECPGd_EODT);

#line 271 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 271 "ex.txt"

                        std::cout << str << " ";
                }
                std::cout << '\n';
        }
        ECPGdeallocate_desc(__LINE__, "myDescr");
#line 276 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();
#line 276 "ex.txt"

        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close MyCursor", ECPGt_EOIT, ECPGt_EORT);
#line 277 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 277 "ex.txt"

        { ECPGtrans(__LINE__, NULL, "commit");
#line 278 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 278 "ex.txt"

        
        return 0;
}







int SelectValues()
{	

        
        std::cout << "select 'address_id' >";
        std::cin >> addr;
        
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select address_id , title , type_station from t_stop where address_id = $1 ", 
	ECPGt_int,&(addr),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_int,&(addr),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(title),(long)64,(long)1,(64)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(type_st),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 296 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 296 "ex.txt"

        std::cout << addr << " " << title << " " << type_st << std::endl;
        return 0;
}

int UpdateValues()
{	

        std::cout << "select updatable 'address_id' >";
        std::cin >> addr;
        std::cout << "enter new 'title' >";
        std::cin >> title;
        std::cout << "enter new 'type_station' >";
        std::cin >> type_st;
         
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update t_stop set title = $1  , type_station = $2  where address_id = $3 ", 
	ECPGt_char,(title),(long)64,(long)1,(64)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(type_st),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(addr),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 311 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 311 "ex.txt"
	

        { ECPGtrans(__LINE__, NULL, "commit");
#line 313 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 313 "ex.txt"

        return 0;
}

int DeleteValues()
{
        std::cout << "select deleted 'address_id' >";
        std::cin >> addr;
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from t_stop where address_id = $1 ", 
	ECPGt_int,&(addr),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 321 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 321 "ex.txt"

        { ECPGtrans(__LINE__, NULL, "commit");
#line 322 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 322 "ex.txt"

}

int menu()
{
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
                                ReadAllRecord();
                                printf("_____________________\n");
                                break;
                        }
                        case '2':
                        {
                                printf("_____________________\n");
                                printf("2. select values\n");
                                SelectValues();
                                printf("_____________________\n");
                                break;
                        }
                        case '3':
                        {
                                printf("_____________________\n");
                                printf("3. update values\n");
                                UpdateValues();
                                printf("_____________________\n");
                                break;
                        }
                        case '4':
                        {
                                printf("_____________________\n");
                                printf("4. insert values\n");	
                                InsertValues();
                                printf("_____________________\n");
                                break;
                        }
                        case '5':
                        {
                                printf("_____________________\n");
                                printf("5. delete values\n");
                                DeleteValues();
                                printf("_____________________\n");
                                break;
                        }
                        case '6':
                        {
                               Dynamic_sql_insert();
                               break;
                        }
                        case '7':
                        {       
                                std::string str;
                                std::cin >> str;
                                std::string req = "SELECT address_id, title, type_station FROM t_stop WHERE address_id=" + str;
                               Dynamic_sql_select_1(req.c_str());
                               break;
                        }
                         case '8':
                        {
                               //Dynamic_sql_select_2();
                               break;
                        }
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
