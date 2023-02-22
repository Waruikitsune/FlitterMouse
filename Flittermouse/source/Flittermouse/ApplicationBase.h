#pragma once
#include "EngineBase.h"
#include "Events/BaseEvent.h"
#include "Events/ApplicationEvent.h"


namespace FM {

	class FM_PUBLIC_API ApplicationBase
	{
	public:
		ApplicationBase();

		virtual ~ApplicationBase();

		void Run();

		virtual const std::string& ApplicationName() = 0;

		private:

	};


	//to be implemented by client applications for the engine:
	extern ApplicationBase* CreateApplication();
	extern std::string& ApplicationName();

}
