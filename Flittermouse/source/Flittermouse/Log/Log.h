#pragma once
#include <memory>
#include "Flittermouse/EngineBase.h"

//#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
//#pragma warning(pop)

namespace FM {



	class FM_PUBLIC_API Log
	{

	public:

		static void Init(const std::string& pAppName);

		static inline spdlog::logger& GetEngineLogger() {return *Log::sEngineLogger;};
		static inline spdlog::logger& GetClientLogger() {return *Log::sClientLogger;};
	private:

		static spdlog::logger* sEngineLogger;
		static spdlog::logger* sClientLogger;
		static const std::string EngineName();
	};	

}

#define FM_ENGINE_LOG_CRITICAL(...)		::FM::Log::GetEngineLogger().critical(__VA_ARGS__)
#define FM_ENGINE_LOG_ERROR(...)		::FM::Log::GetEngineLogger().error(__VA_ARGS__)
#define FM_ENGINE_LOG_WARN(...)			::FM::Log::GetEngineLogger().warn(__VA_ARGS__)
#define FM_ENGINE_LOG_INFO(...)			::FM::Log::GetEngineLogger().info(__VA_ARGS__)
#define FM_ENGINE_LOG_TRACE(...)		::FM::Log::GetEngineLogger().trace(__VA_ARGS__)

#define FM_APPLICATION_LOG_CRITICAL(...)		::FM::Log::GetClientLogger().critical(__VA_ARGS__)
#define FM_APPLICATION_LOG_ERROR(...)			::FM::Log::GetClientLogger().error(__VA_ARGS__)
#define FM_APPLICATION_LOG_WARN(...)			::FM::Log::GetClientLogger().warn(__VA_ARGS__)
#define FM_APPLICATION_LOG_INFO(...)			::FM::Log::GetClientLogger().info(__VA_ARGS__)
#define FM_APPLICATION_LOG_TRACE(...)			::FM::Log::GetClientLogger().trace(__VA_ARGS__)