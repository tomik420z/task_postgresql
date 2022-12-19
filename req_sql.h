#pragma once 
#ifndef REQ_SQL_H
#define REQ_SQL_H

#include "C:/Program Files/PostgreSQL/15/include/ecpglib.h"
#include "C:/Program Files/PostgreSQL/15/include/ecpgerrno.h"
#include "C:/Program Files/PostgreSQL/15/include/sqlca.h"

#include <string>
#include <iostream> 

int change_data_table(std::string && req_sql)
{
        std::cout << "req_sql: "<< req_sql << std::endl; 
        /* exec sql begin declare section */ 
                     
        
#line 51 "ex.txt"
 const char * stmt = req_sql.c_str();
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


int show_req(std::string && req_sql)
{
        /* exec sql begin declare section */ 
                        
        std::cout << "req_sql: "<< req_sql << std::endl;            
                
        #line 165 "ex.txt"
        int colcount ;
        
        #line 166 "ex.txt"
        int index ;
        
        #line 167 "ex.txt"
        char str [ 1024 ] ;
        
        #line 168 "ex.txt"
        char colName [ 1024 ] ;
        
        #line 169 "ex.txt"
        const char * stmt = req_sql.c_str();
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

                size_t count = 0;
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

        #line 183 "ex.txt"

        if (sqlca.sqlcode < 0) sqlprint();}
        #line 183 "ex.txt"


                        if(count == 0) {
                                for(index = 1; index <= colcount; index++) {
                                        { ECPGget_desc(__LINE__, "myDescr", index,ECPGd_name,
                ECPGt_char,(colName),(long)1024,(long)1,(1024)*sizeof(char), ECPGd_EODT);

        #line 187 "ex.txt"

        if (sqlca.sqlcode < 0) sqlprint();}
        #line 187 "ex.txt"

                                        std::cout.width(25);
                                        std::cout << colName << " ";
                                        std::cout.width(25);
                                }
                                std::cout << "\n-----------------------------------------------------------------------------------------------------------------------------------\n";
                        }
                        std::cout << std::endl;
                        
                        
                        for(index = 1; index <= colcount; index++) {
                                { ECPGget_desc(__LINE__, "myDescr", index,ECPGd_data,
                ECPGt_char,(str),(long)1024,(long)1,(1024)*sizeof(char), ECPGd_EODT);

        #line 198 "ex.txt"

        if (sqlca.sqlcode < 0) sqlprint();}
        #line 198 "ex.txt"

                                std::cout.width(25);
                                std::cout << str << " ";
                                std::cout.width(25);
                        }
                        std::cout << '\n';
                        ++count;
                }
                ECPGdeallocate_desc(__LINE__, "myDescr");
        #line 206 "ex.txt"

        if (sqlca.sqlcode < 0) sqlprint();
        #line 206 "ex.txt"

                { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close MyCursor", ECPGt_EOIT, ECPGt_EORT);
        #line 207 "ex.txt"

        if (sqlca.sqlcode < 0) sqlprint();}
        #line 207 "ex.txt"

                { ECPGtrans(__LINE__, NULL, "commit");
        #line 208 "ex.txt"

        if (sqlca.sqlcode < 0) sqlprint();}
        #line 208 "ex.txt"

                
                return 0;
}


#endif