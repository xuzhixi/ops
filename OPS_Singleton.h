//===============================================
/**
 *  @file OPS_Singleton.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-28 14:56:46
 *  Last   modified:  2012-10-28 21:41:01
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_SINGLETON_H
#define __OPS_SINGLETON_H

namespace OPS
{
	template<class T>
	class Singleton
	{
		public:
			static T *instance()
			{
				return &obj;
			};

		private:
			Singleton();
			Singleton(const Singleton &);
			Singleton &operator=(const Singleton &);

			static T obj;
	};

	template<class T>
	T Singleton<T>::obj;
}

#endif // __OPS_SINGLETON_H

