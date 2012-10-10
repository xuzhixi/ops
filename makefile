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
	ops_tcpserver.o\
	ops_socket.o\
	ops_tcpsocket.o\
	ops_rlockguard.o\
	ops_mutex.o\
	ops_mysql.o\
	ky_time.o\
	ops_readwritelock.o\
	ops_database.o\
	ops_condition.o\
	ops_wlockguard.o\
	ops_thread.o\
	ops_udpsocket.o\
	ops_mutexguard.o\
	ky_tool.o\
	ky_log.o\
	ops_semaphore.o\
	ops_parseopt.o\
	
OBJECTS_DEBUG=\
	ops_tcpserver.od\
	ops_socket.od\
	ops_tcpsocket.od\
	ops_rlockguard.od\
	ops_mutex.od\
	ops_mysql.od\
	ky_time.od\
	ops_readwritelock.od\
	ops_database.od\
	ops_condition.od\
	ops_wlockguard.od\
	ops_thread.od\
	ops_udpsocket.od\
	ops_mutexguard.od\
	ky_tool.od\
	ky_log.od\
	ops_semaphore.od\
	ops_parseopt.od\
	
################################################################################
### Project Files ##############################################################
################################################################################
	
all: $(OBJECTS)
	$(CPP_LINKER) libops.so $(OBJECTS) $(LIBS)
ops_tcpserver.o: ./ops_tcpserver.cpp\
	./ops_tcpsocket.h\
	./ops_tcpserver.h\
	./ops_socket.h
	$(CPP) ops_tcpserver.o ./ops_tcpserver.cpp
ops_socket.o: ./ops_socket.cpp\
	./ops_socket.h
	$(CPP) ops_socket.o ./ops_socket.cpp
ops_tcpsocket.o: ./ops_tcpsocket.cpp\
	./ops_tcpsocket.h\
	./ops_socket.h
	$(CPP) ops_tcpsocket.o ./ops_tcpsocket.cpp
ops_rlockguard.o: ./ops_rlockguard.cpp\
	./ops_readwritelock.h\
	./ops_rlockguard.h
	$(CPP) ops_rlockguard.o ./ops_rlockguard.cpp
ops_mutex.o: ./ops_mutex.cpp\
	./ops_mutex.h
	$(CPP) ops_mutex.o ./ops_mutex.cpp
ops_mysql.o: ./ops_mysql.cpp\
	./ops_database.h\
	./ops_mysql.h\
	./ops_algorithm.h
	$(CPP) ops_mysql.o ./ops_mysql.cpp
ky_time.o: ./ky_time.c
	$(CC) ky_time.o ./ky_time.c
ops_readwritelock.o: ./ops_readwritelock.cpp\
	./ops_readwritelock.h
	$(CPP) ops_readwritelock.o ./ops_readwritelock.cpp
ops_database.o: ./ops_database.cpp\
	./ops_database.h
	$(CPP) ops_database.o ./ops_database.cpp
ops_condition.o: ./ops_condition.cpp\
	./ops_mutex.h\
	./ops_condition.h
	$(CPP) ops_condition.o ./ops_condition.cpp
ops_wlockguard.o: ./ops_wlockguard.cpp\
	./ops_wlockguard.h\
	./ops_readwritelock.h
	$(CPP) ops_wlockguard.o ./ops_wlockguard.cpp
ops_thread.o: ./ops_thread.cpp\
	./ops_thread.h
	$(CPP) ops_thread.o ./ops_thread.cpp
ops_udpsocket.o: ./ops_udpsocket.cpp\
	./ops_udpsocket.h\
	./ops_socket.h
	$(CPP) ops_udpsocket.o ./ops_udpsocket.cpp
ops_mutexguard.o: ./ops_mutexguard.cpp\
	./ops_mutexguard.h\
	./ops_mutex.h
	$(CPP) ops_mutexguard.o ./ops_mutexguard.cpp
ky_tool.o: ./ky_tool.c
	$(CC) ky_tool.o ./ky_tool.c
ky_log.o: ./ky_log.c
	$(CC) ky_log.o ./ky_log.c
ops_semaphore.o: ./ops_semaphore.cpp\
	./ops_semaphore.h
	$(CPP) ops_semaphore.o ./ops_semaphore.cpp
ops_parseopt.o: ./ops_parseopt.cpp\
	./ops_parseopt.h
	$(CPP) ops_parseopt.o ./ops_parseopt.cpp
	
debug: $(OBJECTS_DEBUG)
	$(CPP_LINKER_DEBUG) libops.so $(OBJECTS_DEBUG) $(LIBS)
ops_tcpserver.od: ./ops_tcpserver.cpp\
	./ops_tcpsocket.h\
	./ops_tcpserver.h\
	./ops_socket.h
	$(CPP_DEBUG) ops_tcpserver.od ./ops_tcpserver.cpp
ops_socket.od: ./ops_socket.cpp\
	./ops_socket.h
	$(CPP_DEBUG) ops_socket.od ./ops_socket.cpp
ops_tcpsocket.od: ./ops_tcpsocket.cpp\
	./ops_tcpsocket.h\
	./ops_socket.h
	$(CPP_DEBUG) ops_tcpsocket.od ./ops_tcpsocket.cpp
ops_rlockguard.od: ./ops_rlockguard.cpp\
	./ops_readwritelock.h\
	./ops_rlockguard.h
	$(CPP_DEBUG) ops_rlockguard.od ./ops_rlockguard.cpp
ops_mutex.od: ./ops_mutex.cpp\
	./ops_mutex.h
	$(CPP_DEBUG) ops_mutex.od ./ops_mutex.cpp
ops_mysql.od: ./ops_mysql.cpp\
	./ops_database.h\
	./ops_mysql.h\
	./ops_algorithm.h
	$(CPP_DEBUG) ops_mysql.od ./ops_mysql.cpp
ky_time.od: ./ky_time.c
	$(CC_DEBUG) ky_time.od ./ky_time.c
ops_readwritelock.od: ./ops_readwritelock.cpp\
	./ops_readwritelock.h
	$(CPP_DEBUG) ops_readwritelock.od ./ops_readwritelock.cpp
ops_database.od: ./ops_database.cpp\
	./ops_database.h
	$(CPP_DEBUG) ops_database.od ./ops_database.cpp
ops_condition.od: ./ops_condition.cpp\
	./ops_mutex.h\
	./ops_condition.h
	$(CPP_DEBUG) ops_condition.od ./ops_condition.cpp
ops_wlockguard.od: ./ops_wlockguard.cpp\
	./ops_wlockguard.h\
	./ops_readwritelock.h
	$(CPP_DEBUG) ops_wlockguard.od ./ops_wlockguard.cpp
ops_thread.od: ./ops_thread.cpp\
	./ops_thread.h
	$(CPP_DEBUG) ops_thread.od ./ops_thread.cpp
ops_udpsocket.od: ./ops_udpsocket.cpp\
	./ops_udpsocket.h\
	./ops_socket.h
	$(CPP_DEBUG) ops_udpsocket.od ./ops_udpsocket.cpp
ops_mutexguard.od: ./ops_mutexguard.cpp\
	./ops_mutexguard.h\
	./ops_mutex.h
	$(CPP_DEBUG) ops_mutexguard.od ./ops_mutexguard.cpp
ky_tool.od: ./ky_tool.c
	$(CC_DEBUG) ky_tool.od ./ky_tool.c
ky_log.od: ./ky_log.c
	$(CC_DEBUG) ky_log.od ./ky_log.c
ops_semaphore.od: ./ops_semaphore.cpp\
	./ops_semaphore.h
	$(CPP_DEBUG) ops_semaphore.od ./ops_semaphore.cpp
ops_parseopt.od: ./ops_parseopt.cpp\
	./ops_parseopt.h
	$(CPP_DEBUG) ops_parseopt.od ./ops_parseopt.cpp
	
install:
	echo 'install command not set'
	
clean:
	rm -f libops.so libops.so
	rm -rf *.o *.od
