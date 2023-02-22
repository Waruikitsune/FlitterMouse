#include "FM_pch.h"
#include <Flittermouse/Log/Log.h>

namespace FM {

	//not using smart pointers here because otherwise the compiler complains about
	//standard library objects not being dll-exportable1
	spdlog::logger* Log::sEngineLogger = nullptr;
	spdlog::logger* Log::sClientLogger = nullptr;

	const std::string Log::EngineName()  {
		return std::string("Flittermouse");
	} 

	/// <summary>
	/// 
	/// </summary>
	/// <param name="pAppName">The name of the client application to be used for logging application logs</param>
	void Log::Init(const std::string& pAppName) {
		spdlog::set_pattern("%^[%T] %n: %v%$");

		//This looks scary, but spdlog maintains ownership of the pointers to the loggers internally,
		//so we ought never to see dangling pointers here.
		sEngineLogger = spdlog::stdout_color_mt(EngineName()).get();
		sEngineLogger->set_level(spdlog::level::trace);
		sEngineLogger->info("Initialised Engine Log");

		sClientLogger = spdlog::stdout_color_mt(pAppName).get();
		sClientLogger->set_level(spdlog::level::trace);
		sClientLogger->info("Initialised Client Log");
		

	}
}
