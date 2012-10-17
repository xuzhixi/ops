//===============================================
/**
 *  @file OPS_algorithm.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:18:35
 *  Last   modified:  2012-10-17 08:18:35
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_ALGORITHM_H
#define __OPS_ALGORITHM_H

namespace OPS
{

/**
 * @brief 容器中是否包含某个值, 是返回 true, 否则返回 false
 */
template<class InputIterator, class ValueType>
bool contain(InputIterator first, InputIterator last, const ValueType &value)
{
	while ( first != last )
	{
		if ( (*first) == value )
		{
			return true;
		}
		first++;
	}

	return false;
}

/**
 * @brief 容器中是否包含某个键，是返回 true, 否则返回 false
 */
template<class InputIterator, class KeyType>
bool has_key(InputIterator first, InputIterator last, const KeyType &key)
{
	while ( first != last )
	{
		if ( first->first == key )
		{
			return true;
		}
		first++;
	}

	return false;
}

}

#endif // __OPS_ALGORITHM_H
