/*
** Free game server engine
**
** Copyright (C) 2016 Eleven. See Copyright Notice in base.h
*/


#include <cinttypes>
#include <string>
#include <functional>

#include "base.h"
#include "ModuleMgr.h"
#include "Framework.h"
#include "ModuleMgr.h"
#include "Config.h"

#include "ModuleClient.h"
#include "ModuleNetService.h"

namespace ff
{
	namespace demo
	{
		class ServerFramework : public ff::Framework
		{
		private:


		protected:
			virtual bool initialize()
			{
				// ��ע������ģ��
				ff::ModuleMgr& mgr = ff::ModuleMgr::instance();
				SYS_VERIFY_RV(mgr.registerModule<ModuleClient>(), false);
				SYS_VERIFY_RV(mgr.registerModule<ff::ModuleNetService>(), false);

				// ��ʼ��ģ�������
				mgr.initialize();

				return true;
			}

			virtual void finalize()
			{
				ff::ModuleMgr::instance().finalize();
			}
		};

		static ServerFramework app;
	}
}
