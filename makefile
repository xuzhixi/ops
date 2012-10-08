################################################################################
### Compilers ##################################################################
################################################################################
	
INCLUDEPATH=
LIBS=-lpthread -L/usr/lib/mysql -lmysqlclient -shared
	
CC=gcc -c $(INCLUDEPATH) -W -Wall -Wpointer-arith -pipe -D_REENTRANT -O3 -o
CC_DEBUG=gcc -g -c $(INCLUDEPATH) -W -Wall -Wpointer-arith -pipe -D_REENTRANT -o
CC_LINKER=gcc $(INCLUDEPATH) -W -Wall -Wpointer-arith -pipe -D_REENTRANT -O3 -o
CC_LINKER_DEBUG=gcc -g $(INCLUDEPATH) -W -Wall -Wpointer-arith -pipe -D_REENTRANT -o
	
CPP=g++ -c $(INCLUDEPATH) -W -Wall -Wpointer-arith -pipe -D_REENTRANT -O3 -o
CPP_DEBUG=g++ -g -c $(INCLUDEPATH) -W -Wall -Wpointer-arith -pipe -D_REENTRANT -o
CPP_LINKER=g++ $(INCLUDEPATH) -W -Wall -Wpointer-arith -pipe -D_REENTRANT -O3 -o
CPP_LINKER_DEBUG=g++ -g $(INCLUDEPATH) -W -Wall -Wpointer-arith -pipe -D_REENTRANT -o
	
AR=ar  cqs
AR_DEBUG=ar  cqs
	
################################################################################
### Generated object files #####################################################
################################################################################
	
OBJECTS=\
	ops_database.o\
	ops_mysql.o\
	ky_time.o\
	ky_log.o\
	ops_parseopt.o\
	
OBJECTS_DEBUG=\
	ops_database.od\
	ops_mysql.od\
	ky_time.od\
	ky_log.od\
	ops_parseopt.od\
	
################################################################################
### Project Files ##############################################################
################################################################################
	
all: $(OBJECTS)
	$(CPP_LINKER) libops.so $(OBJECTS) $(LIBS)
ops_database.o: ./ops_database.cpp\
	./ops_database.h
	$(CPP) ops_database.o ./ops_database.cpp
ops_mysql.o: ./ops_mysql.cpp\
	./ops_mysql.h\
	./ops_algorithm.h\
	./ops_database.h
	$(CPP) ops_mysql.o ./ops_mysql.cpp
ky_time.o: ./ky_time.c
	$(CC) ky_time.o ./ky_time.c
ky_log.o: ./ky_log.c
	$(CC) ky_log.o ./ky_log.c
ops_parseopt.o: ./ops_parseopt.cpp\
	./ops_parseopt.h
	$(CPP) ops_parseopt.o ./ops_parseopt.cpp
	
debug: $(OBJECTS_DEBUG)
	$(CPP_LINKER_DEBUG) libops.so $(OBJECTS_DEBUG) $(LIBS)
ops_database.od: ./ops_database.cpp\
	./ops_database.h
	$(CPP_DEBUG) ops_database.od ./ops_database.cpp
ops_mysql.od: ./ops_mysql.cpp\
	./ops_mysql.h\
	./ops_algorithm.h\
	./ops_database.h
	$(CPP_DEBUG) ops_mysql.od ./ops_mysql.cpp
ky_time.od: ./ky_time.c
	$(CC_DEBUG) ky_time.od ./ky_time.c
ky_log.od: ./ky_log.c
	$(CC_DEBUG) ky_log.od ./ky_log.c
ops_parseopt.od: ./ops_parseopt.cpp\
	./ops_parseopt.h
	$(CPP_DEBUG) ops_parseopt.od ./ops_parseopt.cpp
	
install:
	echo 'install command not set'
	
clean:
	rm -f libops.so libops.so
	rm -rf *.o *.od
