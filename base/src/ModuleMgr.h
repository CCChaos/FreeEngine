/*
** Free game server engine
**
** Copyright (C) 2016 Eleven. See Copyright Notice in base.h
*/


#ifndef _US_MODULE_MGR_
#define _US_MODULE_MGR_

#include <map>
#include <string>
#include <vector>
#include <cinttypes>
#include <thread>

#include "Singleton.h"
#include "IModule.h"
#include "IComponentMgr.h"

namespace ff
{
	/*
		ģ�������
	*/
	class ModuleMgr : public Singleton<ModuleMgr>
	{
	public:
		void tick(int32_t delta);

		// ���������ģ��ǰ�����ģ�������
		template<typename CMPMGR>
		bool addComponentMgr()
		{
			CMPMGR* mgr = new CMPMGR();
			mComponentMgrs.push_back(mgr);
			return true;
		}

		/*ע��ģ��*/
		template<typename MODULE>
		MODULE*	registerModule()
		{
			MODULE* mod = new MODULE();
			SYS_VERIFY_RV(mod != nullptr, nullptr);

			std::string name = typeid(MODULE).name();
			SYS_VERIFY_RV(registerModule(name, mod, 0) != nullptr, nullptr);

			return mod;
		}

		/*��ȡע���ģ��*/
		template<typename MODULE>
		MODULE*	getModule()
		{
			return dynamic_cast<MODULE*>(getModule(typeid(MODULE).name()));
		}

		IModule*	getModule(std::string name);
		/*ע��ģ�飬order����ģ��initialize�ĵ���˳��*/
		IModule*	registerModule(std::string name, IModule* module, int32_t order);

		bool initialize();
		void finalize();

		void preStartLoop();

	private:
		// ע�������ģ��
		std::map<std::string, IModule*>	mModules;
		std::multimap<int32_t, IModule*>	mOrderModules;

		std::vector<IComponentMgr*>	mComponentMgrs;
	};
}

#endif