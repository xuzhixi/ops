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
	OPS_Tool.o\
	OPS_Socket.o\
	OPS_Mutex.o\
	OPS_IDatabase.o\
	OPS_Condition.o\
	OPS_ThreadPoolThread.o\
	OPS_TcpSocket.o\
	OPS_IThread.o\
	OPS_ParseOpt.o\
	OPS_ThreadPool.o\
	OPS_Process.o\
	OPS_ReadWriteLock.o\
	OPS_UdpSocket.o\
	OPS_Task.o\
	ky_time.o\
	OPS_TcpServer.o\
	OPS_WlockGuard.o\
	OPS_Mysql.o\
	OPS_RlockGuard.o\
	OPS_MutexGuard.o\
	ky_log.o\
	OPS_Semaphore.o\
	
OBJECTS_DEBUG=\
	OPS_Tool.od\
	OPS_Socket.od\
	OPS_Mutex.od\
	OPS_IDatabase.od\
	OPS_Condition.od\
	OPS_ThreadPoolThread.od\
	OPS_TcpSocket.od\
	OPS_IThread.od\
	OPS_ParseOpt.od\
	OPS_ThreadPool.od\
	OPS_Process.od\
	OPS_ReadWriteLock.od\
	OPS_UdpSocket.od\
	OPS_Task.od\
	ky_time.od\
	OPS_TcpServer.od\
	OPS_WlockGuard.od\
	OPS_Mysql.od\
	OPS_RlockGuard.od\
	OPS_MutexGuard.od\
	ky_log.od\
	OPS_Semaphore.od\
	
################################################################################
### Project Files ##############################################################
################################################################################
	
all: $(OBJECTS)
	$(CPP_LINKER) libops.so $(OBJECTS) $(LIBS)
OPS_Tool.o: ./OPS_Tool.cpp
	$(CPP) OPS_Tool.o ./OPS_Tool.cpp
OPS_Socket.o: ./OPS_Socket.cpp
	$(CPP) OPS_Socket.o ./OPS_Socket.cpp
OPS_Mutex.o: ./OPS_Mutex.cpp
	$(CPP) OPS_Mutex.o ./OPS_Mutex.cpp
OPS_IDatabase.o: ./OPS_IDatabase.cpp
	$(CPP) OPS_IDatabase.o ./OPS_IDatabase.cpp
OPS_Condition.o: ./OPS_Condition.cpp
	$(CPP) OPS_Condition.o ./OPS_Condition.cpp
OPS_ThreadPoolThread.o: ./OPS_ThreadPoolThread.cpp
	$(CPP) OPS_ThreadPoolThread.o ./OPS_ThreadPoolThread.cpp
OPS_TcpSocket.o: ./OPS_TcpSocket.cpp
	$(CPP) OPS_TcpSocket.o ./OPS_TcpSocket.cpp
OPS_IThread.o: ./OPS_IThread.cpp
	$(CPP) OPS_IThread.o ./OPS_IThread.cpp
OPS_ParseOpt.o: ./OPS_ParseOpt.cpp
	$(CPP) OPS_ParseOpt.o ./OPS_ParseOpt.cpp
OPS_ThreadPool.o: ./OPS_ThreadPool.cpp
	$(CPP) OPS_ThreadPool.o ./OPS_ThreadPool.cpp
OPS_Process.o: ./OPS_Process.cpp
	$(CPP) OPS_Process.o ./OPS_Process.cpp
OPS_ReadWriteLock.o: ./OPS_ReadWriteLock.cpp
	$(CPP) OPS_ReadWriteLock.o ./OPS_ReadWriteLock.cpp
OPS_UdpSocket.o: ./OPS_UdpSocket.cpp
	$(CPP) OPS_UdpSocket.o ./OPS_UdpSocket.cpp
OPS_Task.o: ./OPS_Task.cpp
	$(CPP) OPS_Task.o ./OPS_Task.cpp
ky_time.o: ./ky_time.c
	$(CC) ky_time.o ./ky_time.c
OPS_TcpServer.o: ./OPS_TcpServer.cpp
	$(CPP) OPS_TcpServer.o ./OPS_TcpServer.cpp
OPS_WlockGuard.o: ./OPS_WlockGuard.cpp
	$(CPP) OPS_WlockGuard.o ./OPS_WlockGuard.cpp
OPS_Mysql.o: ./OPS_Mysql.cpp
	$(CPP) OPS_Mysql.o ./OPS_Mysql.cpp
OPS_RlockGuard.o: ./OPS_RlockGuard.cpp
	$(CPP) OPS_RlockGuard.o ./OPS_RlockGuard.cpp
OPS_MutexGuard.o: ./OPS_MutexGuard.cpp
	$(CPP) OPS_MutexGuard.o ./OPS_MutexGuard.cpp
ky_log.o: ./ky_log.c
	$(CC) ky_log.o ./ky_log.c
OPS_Semaphore.o: ./OPS_Semaphore.cpp
	$(CPP) OPS_Semaphore.o ./OPS_Semaphore.cpp
	
debug: $(OBJECTS_DEBUG)
	$(CPP_LINKER_DEBUG) libops.so $(OBJECTS_DEBUG) $(LIBS)
OPS_Tool.od: ./OPS_Tool.cpp
	$(CPP_DEBUG) OPS_Tool.od ./OPS_Tool.cpp
OPS_Socket.od: ./OPS_Socket.cpp
	$(CPP_DEBUG) OPS_Socket.od ./OPS_Socket.cpp
OPS_Mutex.od: ./OPS_Mutex.cpp
	$(CPP_DEBUG) OPS_Mutex.od ./OPS_Mutex.cpp
OPS_IDatabase.od: ./OPS_IDatabase.cpp
	$(CPP_DEBUG) OPS_IDatabase.od ./OPS_IDatabase.cpp
OPS_Condition.od: ./OPS_Condition.cpp
	$(CPP_DEBUG) OPS_Condition.od ./OPS_Condition.cpp
OPS_ThreadPoolThread.od: ./OPS_ThreadPoolThread.cpp
	$(CPP_DEBUG) OPS_ThreadPoolThread.od ./OPS_ThreadPoolThread.cpp
OPS_TcpSocket.od: ./OPS_TcpSocket.cpp
	$(CPP_DEBUG) OPS_TcpSocket.od ./OPS_TcpSocket.cpp
OPS_IThread.od: ./OPS_IThread.cpp
	$(CPP_DEBUG) OPS_IThread.od ./OPS_IThread.cpp
OPS_ParseOpt.od: ./OPS_ParseOpt.cpp
	$(CPP_DEBUG) OPS_ParseOpt.od ./OPS_ParseOpt.cpp
OPS_ThreadPool.od: ./OPS_ThreadPool.cpp
	$(CPP_DEBUG) OPS_ThreadPool.od ./OPS_ThreadPool.cpp
OPS_Process.od: ./OPS_Process.cpp
	$(CPP_DEBUG) OPS_Process.od ./OPS_Process.cpp
OPS_ReadWriteLock.od: ./OPS_ReadWriteLock.cpp
	$(CPP_DEBUG) OPS_ReadWriteLock.od ./OPS_ReadWriteLock.cpp
OPS_UdpSocket.od: ./OPS_UdpSocket.cpp
	$(CPP_DEBUG) OPS_UdpSocket.od ./OPS_UdpSocket.cpp
OPS_Task.od: ./OPS_Task.cpp
	$(CPP_DEBUG) OPS_Task.od ./OPS_Task.cpp
ky_time.od: ./ky_time.c
	$(CC_DEBUG) ky_time.od ./ky_time.c
OPS_TcpServer.od: ./OPS_TcpServer.cpp
	$(CPP_DEBUG) OPS_TcpServer.od ./OPS_TcpServer.cpp
OPS_WlockGuard.od: ./OPS_WlockGuard.cpp
	$(CPP_DEBUG) OPS_WlockGuard.od ./OPS_WlockGuard.cpp
OPS_Mysql.od: ./OPS_Mysql.cpp
	$(CPP_DEBUG) OPS_Mysql.od ./OPS_Mysql.cpp
OPS_RlockGuard.od: ./OPS_RlockGuard.cpp
	$(CPP_DEBUG) OPS_RlockGuard.od ./OPS_RlockGuard.cpp
OPS_MutexGuard.od: ./OPS_MutexGuard.cpp
	$(CPP_DEBUG) OPS_MutexGuard.od ./OPS_MutexGuard.cpp
ky_log.od: ./ky_log.c
	$(CC_DEBUG) ky_log.od ./ky_log.c
OPS_Semaphore.od: ./OPS_Semaphore.cpp
	$(CPP_DEBUG) OPS_Semaphore.od ./OPS_Semaphore.cpp
	
install:
	echo 'install command not set'
	
clean:
	rm -f libops.so libops.so
	rm -rf *.o *.od
