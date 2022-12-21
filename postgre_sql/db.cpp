/* Processed by ecpg (15.0) */
/* These include files are added by the preprocessor */

/* End of automatic include section */

#line 1 "ex.txt"
#include "C:/Program Files/PostgreSQL/15/include/ecpglib.h"
#include "C:/Program Files/PostgreSQL/15/include/ecpgerrno.h"
#include "C:/Program Files/PostgreSQL/15/include/sqlca.h"
#include "p_transport.h"
#include "menu.h"
#include "req_sql.h"

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <windows.h>


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
 char Password [] = "20012001a";
/* exec sql end declare section */
#line 17 "ex.txt"



/* exec sql whenever sqlerror  sqlprint ; */
#line 20 "ex.txt"



int main() {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
        { ECPGconnect(__LINE__, 0, ConnectionString , Login , Password , NULL, 0); 
#line 27 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 27 "ex.txt"


        if( sqlca.sqlcode != 0 || strncmp(sqlca.sqlstate,"00",2))
        {
                std::cout << "connect -- NoOK" << std::endl;
                return 0;
        }
        else
        {
                std::cout << "connect --OK" << std::endl;	
                menu m;
                m.exec();
        }	
        { ECPGdisconnect(__LINE__, "CURRENT");
#line 39 "ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 39 "ex.txt"

        printf("disconnect --OK\n");

        return 0;
}




