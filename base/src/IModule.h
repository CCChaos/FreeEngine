/*
** Free game server engine
**
** Copyright (C) 2016 Eleven. See Copyright Notice in base.h
*/


#ifndef _US_MODULE_
#define _US_MODULE_

namespace ff
{
	/*
		����ģ��Ļ���
	*/
	class IModule
	{
	public:
		virtual ~IModule() {}
		/*ģ������ĳ�ʼ���������˺����ڲ�Ҫ��������ģ��ĳ�Ա����*/
		virtual bool initialize()	= 0;
		/*ϵͳ�����ر�ʱ����*/
		virtual	void finalize()		= 0;
		/*ϵͳ��ѭ����ʼǰ����*/
		virtual void preStartLoop() {};
	};
}
#endif