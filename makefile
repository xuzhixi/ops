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
	ops_tool.o\
	ops_readwritelock.o\
	ops_reactor.o\
	ops_threadpoolthread.o\
	ops_udpsocket.o\
	ops_dbconnectpool.o\
	OPS_NoMutex.o\
	OPS_XmlNode.o\
	ops_idatabase.o\
	ops_iprocess.o\
	ops_string.o\
	ops_tcpsocket.o\
	ops_ithread.o\
	ops_semaphore.o\
	ops_parseopt.o\
	OPS_MultiProcess.o\
	ops_socket.o\
	ops_wlockguard.o\
	ops_threadpool.o\
	ops_mutex.o\
	ops_parseini.o\
	ky_time.o\
	OPS_IDbResult.o\
	ops_rlockguard.o\
	OPS_MysqlResult.o\
	ops_mutexguard.o\
	OPS_XmlDocument.o\
	ky_log.o\
	ops_condition.o\
	OPS_IBuffer.o\
	ops_mysql.o\
	
OBJECTS_DEBUG=\
	ops_task.od\
	ops_tcpserver.od\
	ops_tool.od\
	ops_readwritelock.od\
	ops_reactor.od\
	ops_threadpoolthread.od\
	ops_udpsocket.od\
	ops_dbconnectpool.od\
	OPS_NoMutex.od\
	OPS_XmlNode.od\
	ops_idatabase.od\
	ops_iprocess.od\
	ops_string.od\
	ops_tcpsocket.od\
	ops_ithread.od\
	ops_semaphore.od\
	ops_parseopt.od\
	OPS_MultiProcess.od\
	ops_socket.od\
	ops_wlockguard.od\
	ops_threadpool.od\
	ops_mutex.od\
	ops_parseini.od\
	ky_time.od\
	OPS_IDbResult.od\
	ops_rlockguard.od\
	OPS_MysqlResult.od\
	ops_mutexguard.od\
	OPS_XmlDocument.od\
	ky_log.od\
	ops_condition.od\
	OPS_IBuffer.od\
	ops_mysql.od\
	
################################################################################
### Project Files ##############################################################
################################################################################
	
all: $(OBJECTS)
	$(CPP_LINKER) libops.so $(OBJECTS) $(LIBS)
ops_task.o: ./ops_task.cpp
	$(CPP) ops_task.o ./ops_task.cpp
ops_tcpserver.o: ./ops_tcpserver.cpp\
	./OPS_IBuffer.h
	$(CPP) ops_tcpserver.o ./ops_tcpserver.cpp
ops_tool.o: ./ops_tool.cpp\
	./OPS_IProcess.h
	$(CPP) ops_tool.o ./ops_tool.cpp
ops_readwritelock.o: ./ops_readwritelock.cpp
	$(CPP) ops_readwritelock.o ./ops_readwritelock.cpp
ops_reactor.o: ./ops_reactor.cpp\
	./OPS_Reactor.h
	$(CPP) ops_reactor.o ./ops_reactor.cpp
ops_threadpoolthread.o: ./ops_threadpoolthread.cpp
	$(CPP) ops_threadpoolthread.o ./ops_threadpoolthread.cpp
ops_udpsocket.o: ./ops_udpsocket.cpp
	$(CPP) ops_udpsocket.o ./ops_udpsocket.cpp
ops_dbconnectpool.o: ./ops_dbconnectpool.cpp\
	./OPS_IDbResult.h\
	./OPS_DbConnectPool.h\
	./OPS_XmlNode.h\
	./OPS_XmlDocument.h\
	./OPS_MysqlResult.h
	$(CPP) ops_dbconnectpool.o ./ops_dbconnectpool.cpp
OPS_NoMutex.o: ./OPS_NoMutex.cpp\
	./OPS_NoMutex.h
	$(CPP) OPS_NoMutex.o ./OPS_NoMutex.cpp
OPS_XmlNode.o: ./OPS_XmlNode.cpp\
	./OPS_XmlNode.h
	$(CPP) OPS_XmlNode.o ./OPS_XmlNode.cpp
ops_idatabase.o: ./ops_idatabase.cpp
	$(CPP) ops_idatabase.o ./ops_idatabase.cpp
ops_iprocess.o: ./ops_iprocess.cpp\
	./OPS_IProcess.h
	$(CPP) ops_iprocess.o ./ops_iprocess.cpp
ops_string.o: ./ops_string.cpp
	$(CPP) ops_string.o ./ops_string.cpp
ops_tcpsocket.o: ./ops_tcpsocket.cpp\
	./OPS_IBuffer.h
	$(CPP) ops_tcpsocket.o ./ops_tcpsocket.cpp
ops_ithread.o: ./ops_ithread.cpp
	$(CPP) ops_ithread.o ./ops_ithread.cpp
ops_semaphore.o: ./ops_semaphore.cpp
	$(CPP) ops_semaphore.o ./ops_semaphore.cpp
ops_parseopt.o: ./ops_parseopt.cpp
	$(CPP) ops_parseopt.o ./ops_parseopt.cpp
OPS_MultiProcess.o: ./OPS_MultiProcess.cpp\
	./OPS_IProcess.h
	$(CPP) OPS_MultiProcess.o ./OPS_MultiProcess.cpp
ops_socket.o: ./ops_socket.cpp
	$(CPP) ops_socket.o ./ops_socket.cpp
ops_wlockguard.o: ./ops_wlockguard.cpp
	$(CPP) ops_wlockguard.o ./ops_wlockguard.cpp
ops_threadpool.o: ./ops_threadpool.cpp
	$(CPP) ops_threadpool.o ./ops_threadpool.cpp
ops_mutex.o: ./ops_mutex.cpp
	$(CPP) ops_mutex.o ./ops_mutex.cpp
ops_parseini.o: ./ops_parseini.cpp\
	./OPS_ParseIni.h
	$(CPP) ops_parseini.o ./ops_parseini.cpp
ky_time.o: ./ky_time.c
	$(CC) ky_time.o ./ky_time.c
OPS_IDbResult.o: ./OPS_IDbResult.cpp\
	./OPS_IDbResult.h
	$(CPP) OPS_IDbResult.o ./OPS_IDbResult.cpp
ops_rlockguard.o: ./ops_rlockguard.cpp
	$(CPP) ops_rlockguard.o ./ops_rlockguard.cpp
OPS_MysqlResult.o: ./OPS_MysqlResult.cpp\
	./OPS_IDbResult.h\
	./OPS_MysqlResult.h
	$(CPP) OPS_MysqlResult.o ./OPS_MysqlResult.cpp
ops_mutexguard.o: ./ops_mutexguard.cpp
	$(CPP) ops_mutexguard.o ./ops_mutexguard.cpp
OPS_XmlDocument.o: ./OPS_XmlDocument.cpp\
	./OPS_XmlNode.h\
	./OPS_XmlDocument.h
	$(CPP) OPS_XmlDocument.o ./OPS_XmlDocument.cpp
ky_log.o: ./ky_log.c
	$(CC) ky_log.o ./ky_log.c
ops_condition.o: ./ops_condition.cpp
	$(CPP) ops_condition.o ./ops_condition.cpp
OPS_IBuffer.o: ./OPS_IBuffer.cpp\
	./OPS_IBuffer.h
	$(CPP) OPS_IBuffer.o ./OPS_IBuffer.cpp
ops_mysql.o: ./ops_mysql.cpp\
	./OPS_IDbResult.h\
	./OPS_MysqlResult.h
	$(CPP) ops_mysql.o ./ops_mysql.cpp
	
debug: $(OBJECTS_DEBUG)
	$(CPP_LINKER_DEBUG) libops.so $(OBJECTS_DEBUG) $(LIBS)
ops_task.od: ./ops_task.cpp
	$(CPP_DEBUG) ops_task.od ./ops_task.cpp
ops_tcpserver.od: ./ops_tcpserver.cpp\
	./OPS_IBuffer.h
	$(CPP_DEBUG) ops_tcpserver.od ./ops_tcpserver.cpp
ops_tool.od: ./ops_tool.cpp\
	./OPS_IProcess.h
	$(CPP_DEBUG) ops_tool.od ./ops_tool.cpp
ops_readwritelock.od: ./ops_readwritelock.cpp
	$(CPP_DEBUG) ops_readwritelock.od ./ops_readwritelock.cpp
ops_reactor.od: ./ops_reactor.cpp\
	./OPS_Reactor.h
	$(CPP_DEBUG) ops_reactor.od ./ops_reactor.cpp
ops_threadpoolthread.od: ./ops_threadpoolthread.cpp
	$(CPP_DEBUG) ops_threadpoolthread.od ./ops_threadpoolthread.cpp
ops_udpsocket.od: ./ops_udpsocket.cpp
	$(CPP_DEBUG) ops_udpsocket.od ./ops_udpsocket.cpp
ops_dbconnectpool.od: ./ops_dbconnectpool.cpp\
	./OPS_IDbResult.h\
	./OPS_DbConnectPool.h\
	./OPS_XmlNode.h\
	./OPS_XmlDocument.h\
	./OPS_MysqlResult.h
	$(CPP_DEBUG) ops_dbconnectpool.od ./ops_dbconnectpool.cpp
OPS_NoMutex.od: ./OPS_NoMutex.cpp\
	./OPS_NoMutex.h
	$(CPP_DEBUG) OPS_NoMutex.od ./OPS_NoMutex.cpp
OPS_XmlNode.od: ./OPS_XmlNode.cpp\
	./OPS_XmlNode.h
	$(CPP_DEBUG) OPS_XmlNode.od ./OPS_XmlNode.cpp
ops_idatabase.od: ./ops_idatabase.cpp
	$(CPP_DEBUG) ops_idatabase.od ./ops_idatabase.cpp
ops_iprocess.od: ./ops_iprocess.cpp\
	./OPS_IProcess.h
	$(CPP_DEBUG) ops_iprocess.od ./ops_iprocess.cpp
ops_string.od: ./ops_string.cpp
	$(CPP_DEBUG) ops_string.od ./ops_string.cpp
ops_tcpsocket.od: ./ops_tcpsocket.cpp\
	./OPS_IBuffer.h
	$(CPP_DEBUG) ops_tcpsocket.od ./ops_tcpsocket.cpp
ops_ithread.od: ./ops_ithread.cpp
	$(CPP_DEBUG) ops_ithread.od ./ops_ithread.cpp
ops_semaphore.od: ./ops_semaphore.cpp
	$(CPP_DEBUG) ops_semaphore.od ./ops_semaphore.cpp
ops_parseopt.od: ./ops_parseopt.cpp
	$(CPP_DEBUG) ops_parseopt.od ./ops_parseopt.cpp
OPS_MultiProcess.od: ./OPS_MultiProcess.cpp\
	./OPS_IProcess.h
	$(CPP_DEBUG) OPS_MultiProcess.od ./OPS_MultiProcess.cpp
ops_socket.od: ./ops_socket.cpp
	$(CPP_DEBUG) ops_socket.od ./ops_socket.cpp
ops_wlockguard.od: ./ops_wlockguard.cpp
	$(CPP_DEBUG) ops_wlockguard.od ./ops_wlockguard.cpp
ops_threadpool.od: ./ops_threadpool.cpp
	$(CPP_DEBUG) ops_threadpool.od ./ops_threadpool.cpp
ops_mutex.od: ./ops_mutex.cpp
	$(CPP_DEBUG) ops_mutex.od ./ops_mutex.cpp
ops_parseini.od: ./ops_parseini.cpp\
	./OPS_ParseIni.h
	$(CPP_DEBUG) ops_parseini.od ./ops_parseini.cpp
ky_time.od: ./ky_time.c
	$(CC_DEBUG) ky_time.od ./ky_time.c
OPS_IDbResult.od: ./OPS_IDbResult.cpp\
	./OPS_IDbResult.h
	$(CPP_DEBUG) OPS_IDbResult.od ./OPS_IDbResult.cpp
ops_rlockguard.od: ./ops_rlockguard.cpp
	$(CPP_DEBUG) ops_rlockguard.od ./ops_rlockguard.cpp
OPS_MysqlResult.od: ./OPS_MysqlResult.cpp\
	./OPS_IDbResult.h\
	./OPS_MysqlResult.h
	$(CPP_DEBUG) OPS_MysqlResult.od ./OPS_MysqlResult.cpp
ops_mutexguard.od: ./ops_mutexguard.cpp
	$(CPP_DEBUG) ops_mutexguard.od ./ops_mutexguard.cpp
OPS_XmlDocument.od: ./OPS_XmlDocument.cpp\
	./OPS_XmlNode.h\
	./OPS_XmlDocument.h
	$(CPP_DEBUG) OPS_XmlDocument.od ./OPS_XmlDocument.cpp
ky_log.od: ./ky_log.c
	$(CC_DEBUG) ky_log.od ./ky_log.c
ops_condition.od: ./ops_condition.cpp
	$(CPP_DEBUG) ops_condition.od ./ops_condition.cpp
OPS_IBuffer.od: ./OPS_IBuffer.cpp\
	./OPS_IBuffer.h
	$(CPP_DEBUG) OPS_IBuffer.od ./OPS_IBuffer.cpp
ops_mysql.od: ./ops_mysql.cpp\
	./OPS_IDbResult.h\
	./OPS_MysqlResult.h
	$(CPP_DEBUG) ops_mysql.od ./ops_mysql.cpp
	
install:
	echo 'install command not set'
	
clean:
	rm -f libops.so libops.so
	rm -rf *.o *.od
