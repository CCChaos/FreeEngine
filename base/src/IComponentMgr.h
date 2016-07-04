/*
** Free game server engine
**
** Copyright (C) 2016 Eleven. See Copyright Notice in base.h
*/


#ifndef _US_MODULE_COMPONENT_MGR_
#define _US_MODULE_COMPONENT_MGR_

#include <cinttypes>
#include <string>
#include "IModule.h"
namespace ff
{
	/*
		ģ�����������
	*/
	class IComponentMgr
	{
	public:
		/*���߳�ÿ������tick*/
		virtual void tick(int32_t delta) = 0;
		virtual bool registerModule(std::string name, IModule* module) = 0;
		virtual bool initialize() = 0;
		virtual void finalize() = 0;
	};
}

#endif