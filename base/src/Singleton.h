/*
** Free game server engine
**
** Copyright (C) 2016 Eleven. See Copyright Notice in base.h
*/


#ifndef _US_SINGLETON_
#define _US_SINGLETON_

#include <assert.h>

namespace ff
{
	// ��������
	template<typename T>
	class Singleton
	{
	private:
		Singleton(const Singleton&) = delete;
		void operator=(const Singleton&) = delete;

	protected:
		Singleton()
		{
			static Singleton*	mInstance = nullptr;
			assert(mInstance == nullptr);
			mInstance = this;
		};
		virtual ~Singleton(){};

	public:
		//  ���е������������߳���ʵ����
		static T& instance()
		{
			static T t;
			return t;
		}

	private:		
	};
}
#endif