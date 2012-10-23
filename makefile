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
	ops_tcpserver.o\
	OPS_Tool.o\
	OPS_IDatabase.o\
	OPS_ThreadPoolThread.o\
	OPS_IThread.o\
	ops_udpsocket.o\
	OPS_ThreadPool.o\
	OPS_Process.o\
	OPS_DbConnectPool.o\
	ops_readwritelock.o\
	OPS_XmlNode.o\
	ops_tcpsocket.o\
	ops_semaphore.o\
	ops_parseopt.o\
	OPS_Task.o\
	ops_socket.o\
	ops_wlockguard.o\
	ops_mutex.o\
	ky_time.o\
	OPS_IDbResult.o\
	ops_rlockguard.o\
	OPS_MysqlResult.o\
	ops_mutexguard.o\
	OPS_XmlDocument.o\
	OPS_Mysql.o\
	ops_condition.o\
	ky_log.o\
	
OBJECTS_DEBUG=\
	ops_tcpserver.od\
	OPS_Tool.od\
	OPS_IDatabase.od\
	OPS_ThreadPoolThread.od\
	OPS_IThread.od\
	ops_udpsocket.od\
	OPS_ThreadPool.od\
	OPS_Process.od\
	OPS_DbConnectPool.od\
	ops_readwritelock.od\
	OPS_XmlNode.od\
	ops_tcpsocket.od\
	ops_semaphore.od\
	ops_parseopt.od\
	OPS_Task.od\
	ops_socket.od\
	ops_wlockguard.od\
	ops_mutex.od\
	ky_time.od\
	OPS_IDbResult.od\
	ops_rlockguard.od\
	OPS_MysqlResult.od\
	ops_mutexguard.od\
	OPS_XmlDocument.od\
	OPS_Mysql.od\
	ops_condition.od\
	ky_log.od\
	
################################################################################
### Project Files ##############################################################
################################################################################
	
all: $(OBJECTS)
	$(CPP_LINKER) libops.so $(OBJECTS) $(LIBS)
ops_tcpserver.o: ./ops_tcpserver.cpp\
	./OPS_TcpSocket.h\
	./OPS_TcpServer.h\
	./OPS_Socket.h
	$(CPP) ops_tcpserver.o ./ops_tcpserver.cpp
OPS_Tool.o: ./OPS_Tool.cpp\
	./OPS_Mutex.h\
	./OPS_Process.h\
	./OPS_Tool.h
	$(CPP) OPS_Tool.o ./OPS_Tool.cpp
OPS_IDatabase.o: ./OPS_IDatabase.cpp\
	./OPS_IDatabase.h
	$(CPP) OPS_IDatabase.o ./OPS_IDatabase.cpp
OPS_ThreadPoolThread.o: ./OPS_ThreadPoolThread.cpp\
	./OPS_MutexGuard.h\
	./OPS_ThreadPool.h\
	./OPS_ThreadPoolThread.h\
	./OPS_IThread.h\
	./OPS_Mutex.h\
	./OPS_Task.h
	$(CPP) OPS_ThreadPoolThread.o ./OPS_ThreadPoolThread.cpp
OPS_IThread.o: ./OPS_IThread.cpp\
	./OPS_IThread.h
	$(CPP) OPS_IThread.o ./OPS_IThread.cpp
ops_udpsocket.o: ./ops_udpsocket.cpp\
	./OPS_UdpSocket.h\
	./OPS_Socket.h
	$(CPP) ops_udpsocket.o ./ops_udpsocket.cpp
OPS_ThreadPool.o: ./OPS_ThreadPool.cpp\
	./OPS_MutexGuard.h\
	./OPS_ThreadPool.h\
	./OPS_ThreadPoolThread.h\
	./OPS_IThread.h\
	./OPS_Mutex.h\
	./OPS_Task.h
	$(CPP) OPS_ThreadPool.o ./OPS_ThreadPool.cpp
OPS_Process.o: ./OPS_Process.cpp\
	./OPS_Process.h
	$(CPP) OPS_Process.o ./OPS_Process.cpp
OPS_DbConnectPool.o: ./OPS_DbConnectPool.cpp\
	./OPS_MutexGuard.h\
	./OPS_DbConnectPool.h\
	./OPS_Mutex.h\
	./OPS_IDatabase.h\
	./OPS_Queue.h
	$(CPP) OPS_DbConnectPool.o ./OPS_DbConnectPool.cpp
ops_readwritelock.o: ./ops_readwritelock.cpp\
	./OPS_ReadWriteLock.h
	$(CPP) ops_readwritelock.o ./ops_readwritelock.cpp
OPS_XmlNode.o: ./OPS_XmlNode.cpp\
	./OPS_XmlNode.h
	$(CPP) OPS_XmlNode.o ./OPS_XmlNode.cpp
ops_tcpsocket.o: ./ops_tcpsocket.cpp\
	./OPS_TcpSocket.h\
	./OPS_Socket.h
	$(CPP) ops_tcpsocket.o ./ops_tcpsocket.cpp
ops_semaphore.o: ./ops_semaphore.cpp\
	./OPS_Semaphore.h
	$(CPP) ops_semaphore.o ./ops_semaphore.cpp
ops_parseopt.o: ./ops_parseopt.cpp\
	./OPS_ParseOpt.h
	$(CPP) ops_parseopt.o ./ops_parseopt.cpp
OPS_Task.o: ./OPS_Task.cpp\
	./OPS_Task.h
	$(CPP) OPS_Task.o ./OPS_Task.cpp
ops_socket.o: ./ops_socket.cpp\
	./OPS_Socket.h
	$(CPP) ops_socket.o ./ops_socket.cpp
ops_wlockguard.o: ./ops_wlockguard.cpp\
	./OPS_WlockGuard.h\
	./OPS_ReadWriteLock.h
	$(CPP) ops_wlockguard.o ./ops_wlockguard.cpp
ops_mutex.o: ./ops_mutex.cpp\
	./OPS_Mutex.h
	$(CPP) ops_mutex.o ./ops_mutex.cpp
ky_time.o: ./ky_time.c
	$(CC) ky_time.o ./ky_time.c
OPS_IDbResult.o: ./OPS_IDbResult.cpp\
	./OPS_IDbResult.h
	$(CPP) OPS_IDbResult.o ./OPS_IDbResult.cpp
ops_rlockguard.o: ./ops_rlockguard.cpp\
	./OPS_ReadWriteLock.h\
	./OPS_RlockGuard.h
	$(CPP) ops_rlockguard.o ./ops_rlockguard.cpp
OPS_MysqlResult.o: ./OPS_MysqlResult.cpp\
	./OPS_IDbResult.h\
	./OPS_MysqlResult.h
	$(CPP) OPS_MysqlResult.o ./OPS_MysqlResult.cpp
ops_mutexguard.o: ./ops_mutexguard.cpp\
	./OPS_MutexGuard.h\
	./OPS_Mutex.h
	$(CPP) ops_mutexguard.o ./ops_mutexguard.cpp
OPS_XmlDocument.o: ./OPS_XmlDocument.cpp\
	./OPS_XmlNode.h\
	./OPS_XmlDocument.h
	$(CPP) OPS_XmlDocument.o ./OPS_XmlDocument.cpp
OPS_Mysql.o: ./OPS_Mysql.cpp\
	./OPS_IDbResult.h\
	./OPS_Mysql.h\
	./OPS_algorithm.h\
	./OPS_IDatabase.h\
	./OPS_MysqlResult.h
	$(CPP) OPS_Mysql.o ./OPS_Mysql.cpp
ops_condition.o: ./ops_condition.cpp\
	./OPS_Mutex.h
	$(CPP) ops_condition.o ./ops_condition.cpp
ky_log.o: ./ky_log.c
	$(CC) ky_log.o ./ky_log.c
	
debug: $(OBJECTS_DEBUG)
	$(CPP_LINKER_DEBUG) libops.so $(OBJECTS_DEBUG) $(LIBS)
ops_tcpserver.od: ./ops_tcpserver.cpp\
	./OPS_TcpSocket.h\
	./OPS_TcpServer.h\
	./OPS_Socket.h
	$(CPP_DEBUG) ops_tcpserver.od ./ops_tcpserver.cpp
OPS_Tool.od: ./OPS_Tool.cpp\
	./OPS_Mutex.h\
	./OPS_Process.h\
	./OPS_Tool.h
	$(CPP_DEBUG) OPS_Tool.od ./OPS_Tool.cpp
OPS_IDatabase.od: ./OPS_IDatabase.cpp\
	./OPS_IDatabase.h
	$(CPP_DEBUG) OPS_IDatabase.od ./OPS_IDatabase.cpp
OPS_ThreadPoolThread.od: ./OPS_ThreadPoolThread.cpp\
	./OPS_MutexGuard.h\
	./OPS_ThreadPool.h\
	./OPS_ThreadPoolThread.h\
	./OPS_IThread.h\
	./OPS_Mutex.h\
	./OPS_Task.h
	$(CPP_DEBUG) OPS_ThreadPoolThread.od ./OPS_ThreadPoolThread.cpp
OPS_IThread.od: ./OPS_IThread.cpp\
	./OPS_IThread.h
	$(CPP_DEBUG) OPS_IThread.od ./OPS_IThread.cpp
ops_udpsocket.od: ./ops_udpsocket.cpp\
	./OPS_UdpSocket.h\
	./OPS_Socket.h
	$(CPP_DEBUG) ops_udpsocket.od ./ops_udpsocket.cpp
OPS_ThreadPool.od: ./OPS_ThreadPool.cpp\
	./OPS_MutexGuard.h\
	./OPS_ThreadPool.h\
	./OPS_ThreadPoolThread.h\
	./OPS_IThread.h\
	./OPS_Mutex.h\
	./OPS_Task.h
	$(CPP_DEBUG) OPS_ThreadPool.od ./OPS_ThreadPool.cpp
OPS_Process.od: ./OPS_Process.cpp\
	./OPS_Process.h
	$(CPP_DEBUG) OPS_Process.od ./OPS_Process.cpp
OPS_DbConnectPool.od: ./OPS_DbConnectPool.cpp\
	./OPS_MutexGuard.h\
	./OPS_DbConnectPool.h\
	./OPS_Mutex.h\
	./OPS_IDatabase.h\
	./OPS_Queue.h
	$(CPP_DEBUG) OPS_DbConnectPool.od ./OPS_DbConnectPool.cpp
ops_readwritelock.od: ./ops_readwritelock.cpp\
	./OPS_ReadWriteLock.h
	$(CPP_DEBUG) ops_readwritelock.od ./ops_readwritelock.cpp
OPS_XmlNode.od: ./OPS_XmlNode.cpp\
	./OPS_XmlNode.h
	$(CPP_DEBUG) OPS_XmlNode.od ./OPS_XmlNode.cpp
ops_tcpsocket.od: ./ops_tcpsocket.cpp\
	./OPS_TcpSocket.h\
	./OPS_Socket.h
	$(CPP_DEBUG) ops_tcpsocket.od ./ops_tcpsocket.cpp
ops_semaphore.od: ./ops_semaphore.cpp\
	./OPS_Semaphore.h
	$(CPP_DEBUG) ops_semaphore.od ./ops_semaphore.cpp
ops_parseopt.od: ./ops_parseopt.cpp\
	./OPS_ParseOpt.h
	$(CPP_DEBUG) ops_parseopt.od ./ops_parseopt.cpp
OPS_Task.od: ./OPS_Task.cpp\
	./OPS_Task.h
	$(CPP_DEBUG) OPS_Task.od ./OPS_Task.cpp
ops_socket.od: ./ops_socket.cpp\
	./OPS_Socket.h
	$(CPP_DEBUG) ops_socket.od ./ops_socket.cpp
ops_wlockguard.od: ./ops_wlockguard.cpp\
	./OPS_WlockGuard.h\
	./OPS_ReadWriteLock.h
	$(CPP_DEBUG) ops_wlockguard.od ./ops_wlockguard.cpp
ops_mutex.od: ./ops_mutex.cpp\
	./OPS_Mutex.h
	$(CPP_DEBUG) ops_mutex.od ./ops_mutex.cpp
ky_time.od: ./ky_time.c
	$(CC_DEBUG) ky_time.od ./ky_time.c
OPS_IDbResult.od: ./OPS_IDbResult.cpp\
	./OPS_IDbResult.h
	$(CPP_DEBUG) OPS_IDbResult.od ./OPS_IDbResult.cpp
ops_rlockguard.od: ./ops_rlockguard.cpp\
	./OPS_ReadWriteLock.h\
	./OPS_RlockGuard.h
	$(CPP_DEBUG) ops_rlockguard.od ./ops_rlockguard.cpp
OPS_MysqlResult.od: ./OPS_MysqlResult.cpp\
	./OPS_IDbResult.h\
	./OPS_MysqlResult.h
	$(CPP_DEBUG) OPS_MysqlResult.od ./OPS_MysqlResult.cpp
ops_mutexguard.od: ./ops_mutexguard.cpp\
	./OPS_MutexGuard.h\
	./OPS_Mutex.h
	$(CPP_DEBUG) ops_mutexguard.od ./ops_mutexguard.cpp
OPS_XmlDocument.od: ./OPS_XmlDocument.cpp\
	./OPS_XmlNode.h\
	./OPS_XmlDocument.h
	$(CPP_DEBUG) OPS_XmlDocument.od ./OPS_XmlDocument.cpp
OPS_Mysql.od: ./OPS_Mysql.cpp\
	./OPS_IDbResult.h\
	./OPS_Mysql.h\
	./OPS_algorithm.h\
	./OPS_IDatabase.h\
	./OPS_MysqlResult.h
	$(CPP_DEBUG) OPS_Mysql.od ./OPS_Mysql.cpp
ops_condition.od: ./ops_condition.cpp\
	./OPS_Mutex.h
	$(CPP_DEBUG) ops_condition.od ./ops_condition.cpp
ky_log.od: ./ky_log.c
	$(CC_DEBUG) ky_log.od ./ky_log.c
	
install:
	echo 'install command not set'
	
clean:
	rm -f libops.so libops.so
	rm -rf *.o *.od
