################################################################################
### Compilers ##################################################################
################################################################################
	
INCLUDEPATH=
LIBS=-fPIC -lpthread -lrt -L/usr/lib/mysql -lmysqlclient -shared
	
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
	ops_task.o\
	ops_tcpserver.o\
	ops_threadpoolthread.o\
	ops_udpsocket.o\
	ops_mysql.o\
	ops_readwritelock.o\
	ops_idatabase.o\
	ops_tcpsocket.o\
	ops_ithread.o\
	ops_semaphore.o\
	ops_parseopt.o\
	ops_tool.o\
	ops_socket.o\
	ops_wlockguard.o\
	ops_threadpool.o\
	ops_mutex.o\
	ky_time.o\
	ops_rlockguard.o\
	ops_mutexguard.o\
	ops_process.o\
	ops_condition.o\
	ky_log.o\
	
OBJECTS_DEBUG=\
	ops_task.od\
	ops_tcpserver.od\
	ops_threadpoolthread.od\
	ops_udpsocket.od\
	ops_mysql.od\
	ops_readwritelock.od\
	ops_idatabase.od\
	ops_tcpsocket.od\
	ops_ithread.od\
	ops_semaphore.od\
	ops_parseopt.od\
	ops_tool.od\
	ops_socket.od\
	ops_wlockguard.od\
	ops_threadpool.od\
	ops_mutex.od\
	ky_time.od\
	ops_rlockguard.od\
	ops_mutexguard.od\
	ops_process.od\
	ops_condition.od\
	ky_log.od\
	
################################################################################
### Project Files ##############################################################
################################################################################
	
all: $(OBJECTS)
	$(CPP_LINKER) libops.so $(OBJECTS) $(LIBS)
ops_task.o: ./ops_task.cpp\
	./ops_task.h
	$(CPP) ops_task.o ./ops_task.cpp
ops_tcpserver.o: ./ops_tcpserver.cpp\
	./ops_tcpserver.h\
	./ops_tcpsocket.h\
	./ops_socket.h
	$(CPP) ops_tcpserver.o ./ops_tcpserver.cpp
ops_threadpoolthread.o: ./ops_threadpoolthread.cpp\
	./ops_mutex.h\
	./ops_ithread.h\
	./ops_priorityqueue.h\
	./ops_condition.h\
	./ops_mutexguard.h\
	./ops_threadpoolthread.h\
	./ops_threadpool.h\
	./ops_task.h
	$(CPP) ops_threadpoolthread.o ./ops_threadpoolthread.cpp
ops_udpsocket.o: ./ops_udpsocket.cpp\
	./ops_socket.h\
	./ops_udpsocket.h
	$(CPP) ops_udpsocket.o ./ops_udpsocket.cpp
ops_mysql.o: ./ops_mysql.cpp\
	./ops_mysql.h\
	./ops_algorithm.h\
	./ops_idatabase.h
	$(CPP) ops_mysql.o ./ops_mysql.cpp
ops_readwritelock.o: ./ops_readwritelock.cpp\
	./ops_readwritelock.h
	$(CPP) ops_readwritelock.o ./ops_readwritelock.cpp
ops_idatabase.o: ./ops_idatabase.cpp\
	./ops_idatabase.h
	$(CPP) ops_idatabase.o ./ops_idatabase.cpp
ops_tcpsocket.o: ./ops_tcpsocket.cpp\
	./ops_tcpsocket.h\
	./ops_socket.h
	$(CPP) ops_tcpsocket.o ./ops_tcpsocket.cpp
ops_ithread.o: ./ops_ithread.cpp\
	./ops_ithread.h
	$(CPP) ops_ithread.o ./ops_ithread.cpp
ops_semaphore.o: ./ops_semaphore.cpp\
	./ops_semaphore.h
	$(CPP) ops_semaphore.o ./ops_semaphore.cpp
ops_parseopt.o: ./ops_parseopt.cpp\
	./ops_parseopt.h
	$(CPP) ops_parseopt.o ./ops_parseopt.cpp
ops_tool.o: ./ops_tool.cpp\
	./ops_process.h\
	./ops_mutex.h\
	./ops_tool.h
	$(CPP) ops_tool.o ./ops_tool.cpp
ops_socket.o: ./ops_socket.cpp\
	./ops_socket.h
	$(CPP) ops_socket.o ./ops_socket.cpp
ops_wlockguard.o: ./ops_wlockguard.cpp\
	./ops_readwritelock.h\
	./ops_wlockguard.h
	$(CPP) ops_wlockguard.o ./ops_wlockguard.cpp
ops_threadpool.o: ./ops_threadpool.cpp\
	./ops_mutex.h\
	./ops_ithread.h\
	./ops_priorityqueue.h\
	./ops_condition.h\
	./ops_mutexguard.h\
	./ops_threadpoolthread.h\
	./ops_threadpool.h\
	./ops_task.h
	$(CPP) ops_threadpool.o ./ops_threadpool.cpp
ops_mutex.o: ./ops_mutex.cpp\
	./ops_mutex.h
	$(CPP) ops_mutex.o ./ops_mutex.cpp
ky_time.o: ./ky_time.c
	$(CC) ky_time.o ./ky_time.c
ops_rlockguard.o: ./ops_rlockguard.cpp\
	./ops_readwritelock.h\
	./ops_rlockguard.h
	$(CPP) ops_rlockguard.o ./ops_rlockguard.cpp
ops_mutexguard.o: ./ops_mutexguard.cpp\
	./ops_mutexguard.h\
	./ops_mutex.h
	$(CPP) ops_mutexguard.o ./ops_mutexguard.cpp
ops_process.o: ./ops_process.cpp\
	./ops_process.h
	$(CPP) ops_process.o ./ops_process.cpp
ops_condition.o: ./ops_condition.cpp\
	./ops_mutex.h\
	./ops_condition.h
	$(CPP) ops_condition.o ./ops_condition.cpp
ky_log.o: ./ky_log.c
	$(CC) ky_log.o ./ky_log.c
	
debug: $(OBJECTS_DEBUG)
	$(CPP_LINKER_DEBUG) libops.so $(OBJECTS_DEBUG) $(LIBS)
ops_task.od: ./ops_task.cpp\
	./ops_task.h
	$(CPP_DEBUG) ops_task.od ./ops_task.cpp
ops_tcpserver.od: ./ops_tcpserver.cpp\
	./ops_tcpserver.h\
	./ops_tcpsocket.h\
	./ops_socket.h
	$(CPP_DEBUG) ops_tcpserver.od ./ops_tcpserver.cpp
ops_threadpoolthread.od: ./ops_threadpoolthread.cpp\
	./ops_mutex.h\
	./ops_ithread.h\
	./ops_priorityqueue.h\
	./ops_condition.h\
	./ops_mutexguard.h\
	./ops_threadpoolthread.h\
	./ops_threadpool.h\
	./ops_task.h
	$(CPP_DEBUG) ops_threadpoolthread.od ./ops_threadpoolthread.cpp
ops_udpsocket.od: ./ops_udpsocket.cpp\
	./ops_socket.h\
	./ops_udpsocket.h
	$(CPP_DEBUG) ops_udpsocket.od ./ops_udpsocket.cpp
ops_mysql.od: ./ops_mysql.cpp\
	./ops_mysql.h\
	./ops_algorithm.h\
	./ops_idatabase.h
	$(CPP_DEBUG) ops_mysql.od ./ops_mysql.cpp
ops_readwritelock.od: ./ops_readwritelock.cpp\
	./ops_readwritelock.h
	$(CPP_DEBUG) ops_readwritelock.od ./ops_readwritelock.cpp
ops_idatabase.od: ./ops_idatabase.cpp\
	./ops_idatabase.h
	$(CPP_DEBUG) ops_idatabase.od ./ops_idatabase.cpp
ops_tcpsocket.od: ./ops_tcpsocket.cpp\
	./ops_tcpsocket.h\
	./ops_socket.h
	$(CPP_DEBUG) ops_tcpsocket.od ./ops_tcpsocket.cpp
ops_ithread.od: ./ops_ithread.cpp\
	./ops_ithread.h
	$(CPP_DEBUG) ops_ithread.od ./ops_ithread.cpp
ops_semaphore.od: ./ops_semaphore.cpp\
	./ops_semaphore.h
	$(CPP_DEBUG) ops_semaphore.od ./ops_semaphore.cpp
ops_parseopt.od: ./ops_parseopt.cpp\
	./ops_parseopt.h
	$(CPP_DEBUG) ops_parseopt.od ./ops_parseopt.cpp
ops_tool.od: ./ops_tool.cpp\
	./ops_process.h\
	./ops_mutex.h\
	./ops_tool.h
	$(CPP_DEBUG) ops_tool.od ./ops_tool.cpp
ops_socket.od: ./ops_socket.cpp\
	./ops_socket.h
	$(CPP_DEBUG) ops_socket.od ./ops_socket.cpp
ops_wlockguard.od: ./ops_wlockguard.cpp\
	./ops_readwritelock.h\
	./ops_wlockguard.h
	$(CPP_DEBUG) ops_wlockguard.od ./ops_wlockguard.cpp
ops_threadpool.od: ./ops_threadpool.cpp\
	./ops_mutex.h\
	./ops_ithread.h\
	./ops_priorityqueue.h\
	./ops_condition.h\
	./ops_mutexguard.h\
	./ops_threadpoolthread.h\
	./ops_threadpool.h\
	./ops_task.h
	$(CPP_DEBUG) ops_threadpool.od ./ops_threadpool.cpp
ops_mutex.od: ./ops_mutex.cpp\
	./ops_mutex.h
	$(CPP_DEBUG) ops_mutex.od ./ops_mutex.cpp
ky_time.od: ./ky_time.c
	$(CC_DEBUG) ky_time.od ./ky_time.c
ops_rlockguard.od: ./ops_rlockguard.cpp\
	./ops_readwritelock.h\
	./ops_rlockguard.h
	$(CPP_DEBUG) ops_rlockguard.od ./ops_rlockguard.cpp
ops_mutexguard.od: ./ops_mutexguard.cpp\
	./ops_mutexguard.h\
	./ops_mutex.h
	$(CPP_DEBUG) ops_mutexguard.od ./ops_mutexguard.cpp
ops_process.od: ./ops_process.cpp\
	./ops_process.h
	$(CPP_DEBUG) ops_process.od ./ops_process.cpp
ops_condition.od: ./ops_condition.cpp\
	./ops_mutex.h\
	./ops_condition.h
	$(CPP_DEBUG) ops_condition.od ./ops_condition.cpp
ky_log.od: ./ky_log.c
	$(CC_DEBUG) ky_log.od ./ky_log.c
	
install:
	echo 'install command not set'
	
clean:
	rm -f libops.so libops.so
	rm -rf *.o *.od
