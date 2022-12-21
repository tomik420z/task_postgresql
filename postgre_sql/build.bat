g++ -c -I/"c:\Program Files\PostgreSQL\15\include" %1.cpp -o %1.o -L/"c:\Program Files\PostgreSQL\15\lib"
g++ -o %1.exe %1.o -lecpg