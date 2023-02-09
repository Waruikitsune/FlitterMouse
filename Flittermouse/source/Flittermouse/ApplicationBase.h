#pragma once
#include "EngineBase.h"

namespace FM {

	class FM_PUBLIC_API ApplicationBase
	{
	public:
		ApplicationBase();

		virtual ~ApplicationBase();

		void Run();

		virtual const char* ApplicationName() = 0;

		//private:
	};


	//to be implemented by client applications for the engine:
	extern ApplicationBase* CreateApplication();

}
