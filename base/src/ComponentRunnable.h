
/*
** Free game server engine
**
** Copyright (C) 2016 Eleven. See Copyright Notice in base.h
*/

#ifndef _US_MODULECOMPONENT_RUNNABLE_
#define _US_MODULECOMPONENT_RUNNABLE_

#include <map>
#include <string>
#include <vector>
#include <cinttypes>
#include <thread>

#include "IModule.h"
#include "IComponentMgr.h"

namespace ff
{
	/*
		ģ��ʵ�ִ˽ӿں�runOnce������һ���߳��е��ã�����ֵ������runOnce�����߼��
	*/
	class ComponentRunnable
	{
	public:
		virtual int32_t runOnce() = 0;
	};

	class ComponentRunnableMgr : public IComponentMgr
	{
	public:
		virtual void tick(int32_t delta);
		virtual bool registerModule(std::string name, IModule* module);
		virtual bool initialize();
		virtual void finalize();

	private:
		struct ComRunnable
		{
			bool running;
			std::thread worker;
			ComponentRunnable*	runnable;
		};
		static int32_t	worker(ComRunnable* com);

		// ���̵߳�ģ��
		std::vector<ComRunnable*>	mRunnables;
	};
}

#endif