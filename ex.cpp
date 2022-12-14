/* Processed by ecpg (15.0) */
/* These include files are added by the preprocessor */
//#include <ecpglib.h>
//#include <ecpgerrno.h>
//#include <sqlca.h>
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

#line 19 "ex.txt"


/*
create table exTab(
id int primary key,
name varchar,
date1 timestamp,
date2 timestamp
);
*/

//#pragma comment(lib, "libecpg.lib")
         /*
                EXEC SQL BEGIN DECLARE SECTION;
                EXEC SQL END DECLARE SECTION; - ���� ���������� ��� ���������� ����������,
                ������� ����� ����������������� � ������� �� �������.
                ������ ���� ���������� ������������ ������� �-��������� ���������� �
                            ������������� ����������
            */

        //��� ���������� � ��
        /* exec sql begin declare section */ 
            
            
            
        
#line 41 "ex.txt"
 char ConnectionString [] = "public transport@127.0.0.1:5432" ;
 
#line 42 "ex.txt"
 char Login [] = "postgres" ;
 
#line 43 "ex.txt"
 char Password [] = "20012001a" ;
/* exec sql end declare section */
#line 44 "ex.txt"


        //��� �������������� � ��
        /* exec sql begin declare section */
                 
                 
                 
                 
                  
                  
                  
                  
                 
              
#line 48 "ex.txt"
 int my_id ;
 
#line 49 "ex.txt"
 char my_data [ 256 ] ;
 
#line 50 "ex.txt"
 int my_count ;
 
#line 51 "ex.txt"
 char date1 [ 10 ] ;
 
#line 52 "ex.txt"
 char date2 [ 10 ] ;
 
#line 53 "ex.txt"
 int addr ;
 
#line 54 "ex.txt"
 char title [ 64 ] ;
 
#line 55 "ex.txt"
 int type_st ;
/* exec sql end declare section */
#line 57 "ex.txt"
	

        /*
                ����������, ����������� ������������ ������.
        */
        //void f_error(void);
        //EXEC SQL WHENEVER SQLERROR CALL f_error;	
        /* exec sql whenever sqlerror  sqlprint ; */
#line 64 "ex.txt"
			
        /*
            ����� ���������: 
            EXEC SQL WHENEVER condition action;
                condition - ��� ������, ������� ����� �������������.
                action - ��������, ������� ����� �������������� ��� ������������� ������
                ��������� �������� condition:
                                 SQLERROR - ������ ��� ��������� ����������
                                 SQLWARNING -  �������������� ��� ��������� ����������
                                 NOT FOUND - ������� ������� ������ ������
              ��������� �������� action:   
                                 CONTINUE - ����������� ������ ����������	
                                 GOTO label - ������� �� �����
                                 SQLPRINT - ������ ������ � ����������� ����� ������
                                 STOP - ���������� exit(1) � �
                                 DO BREAK - ���������� break � �. ������������ ������ � switch
                                            ��� � �����.
                                 CALL name (args) - ����� ������� name � ����������� args 
                                 DO name (args)   - ����� ������� name � ����������� args 

        */
int menu();
int main() {

        { ECPGconnect(__LINE__, 0, ConnectionString , Login , Password , NULL, 0); 
#line 88 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 88 "ex.txt"


                /*
                   ���������� sqlca - ���������. ���� sqlcode - ����� ������������ ��� 
                   ��������� ������. 
                   sqlstate - ���������� �� 5 ��������. ���� ������ ��� 00, �� �� ���������
                */

        if( sqlca.sqlcode != 0 || strncmp(sqlca.sqlstate,"00",2))
        {
                printf("connect -- NoOK\n");
               // exit(-1);
               return 0;
        }
        else
        {
                printf("connect --OK\n");	
                menu();
        }	
        { ECPGdisconnect(__LINE__, "CURRENT");
#line 107 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 107 "ex.txt"

        printf("disconnect --OK\n");
}



int Dynamic_sql_insert()
{
/* exec sql begin declare section */ 
       
  
        
#line 117 "ex.txt"
 char stmt [] = "INSERT INTO exTab(id,name) VALUES(?, ?);" ;
/* exec sql end declare section */
#line 118 "ex.txt"


       { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select count ( * ) from exTab", ECPGt_EOIT, 
	ECPGt_int,&(my_count),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 120 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 120 "ex.txt"

        if(my_count==0)
        {	
                my_id=1;
        }
        else
        {
                { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select max ( id ) from exTab", ECPGt_EOIT, 
	ECPGt_int,&(my_id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 127 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 127 "ex.txt"

                my_id=my_id+1;
        }

     

       { ECPGprepare(__LINE__, NULL, 0, "mystmt", stmt);
#line 133 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 133 "ex.txt"

 
       { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_execute, "mystmt", 
	ECPGt_int,&(my_id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_const,"'123'",(long)5,(long)1,strlen("'123'"), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 135 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 135 "ex.txt"

       { ECPGtrans(__LINE__, NULL, "commit");
#line 136 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 136 "ex.txt"

        return 0;
}

int Dynamic_sql_select_1()
{
     /* exec sql begin declare section */           
             
             
                  
     
#line 143 "ex.txt"
 char * stmt = "SELECT name " "  FROM exTab " "  WHERE id=?" ;
/* exec sql end declare section */
#line 146 "ex.txt"




     { ECPGprepare(__LINE__, NULL, 0, "sqlstmt", stmt);
#line 150 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 150 "ex.txt"

     

    printf("select 'id' >");
        scanf("%d", &my_id);

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_execute, "sqlstmt", 
	ECPGt_int,&(my_id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_char,(my_data),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 156 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 156 "ex.txt"

    printf("name=%s\n", my_data);	



    { ECPGtrans(__LINE__, NULL, "commit");
#line 161 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 161 "ex.txt"

    return 0;
}


int Dynamic_sql_select_2()
{
     /* exec sql begin declare section */           
             
             
             
      
      
     
#line 169 "ex.txt"
 char * stmt = "SELECT name " "  FROM exTab " "  WHERE id>=? and id<=?" ;
 
#line 172 "ex.txt"
 int id_min ;
 
#line 173 "ex.txt"
 int id_max ;
/* exec sql end declare section */
#line 174 "ex.txt"




     { ECPGprepare(__LINE__, NULL, 0, "sqlstmt", stmt);
#line 178 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 178 "ex.txt"


     /* declare my_cursor cursor for $1 */
#line 180 "ex.txt"


printf("select 'id_min' >");
        scanf("%d", &id_min);

printf("select 'id_max' >");
        scanf("%d", &id_max);

     { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare my_cursor cursor for $1", 
	ECPGt_char_variable,(ECPGprepared_statement(NULL, "sqlstmt", __LINE__)),(long)1,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(id_min),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(id_max),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 188 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 188 "ex.txt"




     while (1)
     {
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch my_cursor", ECPGt_EOIT, 
	ECPGt_char,(my_data),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 194 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 194 "ex.txt"
    
        if (sqlca.sqlcode == ECPG_NOT_FOUND || strncmp(sqlca.sqlstate,"00",2)) break;
        printf("name=%s\n", my_data);	
     }

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close my_cursor", ECPGt_EOIT, ECPGt_EORT);
#line 199 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 199 "ex.txt"


    { ECPGtrans(__LINE__, NULL, "commit");
#line 201 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 201 "ex.txt"

    return 0;
}

int InsertValues()
{		
        
        
        std::cout << "enter new 'address_id' >"; 
        std::cin >> addr;
        std::cout << "enter new 'title' >";
        std::cin >> title;
        std::cout << "enter new 'stantion type' >"; 
        std::cin >> type_st;

        //printf("enter new 'data' >");
        
        //scanf("%c", my_data);
         
        // my_data[0]='\0';
        //scanf("%[ a-zA-Z0-9+,�-��-�/-.]",my_data);
        

        //printf("enter new 'date1' >");
       
        //scanf("%c", date1);
      
        //    date1[0]='\0';
        //scanf("%[ a-zA-Z0-9+,�-��-�/-.]",date1);

        //printf("enter new 'date2' >");
        //scanf("%c", date2);
        
        //    date2[0]='\0';
        //scanf("%[ a-zA-Z0-9+,�-��-�/-.]",date2);
        
        
        
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into t_stop ( address_id , title , type_station ) values ( $1  , $2  , $3  )", 
	ECPGt_int,&(addr),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(title),(long)64,(long)1,(64)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(type_st),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 253 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 253 "ex.txt"


        { ECPGtrans(__LINE__, NULL, "commit");
#line 255 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 255 "ex.txt"

        return 0;
}



int ReadAllRecord()
{
        /* declare MyCursor cursor for select address_id , title , type_station from t_stop order by address_id */
#line 264 "ex.txt"

        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare MyCursor cursor for select address_id , title , type_station from t_stop order by address_id", ECPGt_EOIT, ECPGt_EORT);
#line 265 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 265 "ex.txt"

    
        while(1)
        {
            /*
                        ������ �� �������.
                        ����� ���������: EXEC SQL FETCH <cursor_name> INTO <var_list>;,
                                   ��� <var_list> - ������ ����������	
            */
                { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch MyCursor", ECPGt_EOIT, 
	ECPGt_int,&(addr),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(title),(long)64,(long)1,(64)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(type_st),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 274 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 274 "ex.txt"

                if (sqlca.sqlcode == ECPG_NOT_FOUND || strncmp(sqlca.sqlstate,"00",2)) break;
                std::cout << addr << " " << title << " " << type_st << std::endl;		
                //printf("\t %d \t %s \t %s \t %s\n", my_id, my_data, date1, date2);
        }
        /*
                �������� �������.
                ����� ���������: EXEC SQL CLOSE <cursor_name>;
        */
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close MyCursor", ECPGt_EOIT, ECPGt_EORT);
#line 286 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 286 "ex.txt"

        { ECPGtrans(__LINE__, NULL, "commit");
#line 287 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 287 "ex.txt"

        return 0;
}







int SelectValues()
{		
        printf("select 'id' >");
        scanf("%d", &my_id);
        /*
                ��������� ������ �� ������� � ���������� my_id, my_data
        */
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select id , name from exTab where id = $1 ", 
	ECPGt_int,&(my_id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_int,&(my_id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(my_data),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 304 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 304 "ex.txt"

        printf("id: %d, data: %s \n", my_id, my_data);
        return 0;
}
int UpdateValues()
{	
        printf("select updatable 'id' >");
        scanf("%d", &my_id);
        printf("enter new  'data' >");
        scanf("%s", my_data);

        /*
                ���������� ������ data � ������� 
        */
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update exTab set name = $1  where id = $2 ", 
	ECPGt_char,(my_data),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(my_id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 318 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 318 "ex.txt"
	

        { ECPGtrans(__LINE__, NULL, "commit");
#line 320 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 320 "ex.txt"

        return 0;
}
int DeleteValues()
{
        printf("select deleted 'id' >");
        scanf("%d", &my_id);

        /*
                �������� ������ �� �������
        */
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from exTab where id = $1 ", 
	ECPGt_int,&(my_id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 331 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 331 "ex.txt"

        /*
                ��������� ����������, �.� ������� ������ �� ����
        */
        { ECPGtrans(__LINE__, NULL, "commit");
#line 335 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 335 "ex.txt"

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
                               Dynamic_sql_select_1();
                               break;
                        }
                         case '8':
                        {
                               Dynamic_sql_select_2();
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
