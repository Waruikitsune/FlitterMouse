#pragma once
#include <memory>

#include "EngineBase.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"


namespace FM {

	class FM_PUBLIC_API Log
	{

	public:
		static void Init(const char* pAppName);
		static const std::string cstrEngineName;

		static inline std::shared_ptr<spdlog::logger>& GetEngineLogger();
		static inline std::shared_ptr<spdlog::logger>& GetClientLogger();
	private:
		static std::shared_ptr<spdlog::logger> sEngineLogger;
		static std::shared_ptr<spdlog::logger> sClientLogger;
	};	

}

#define FM_ENGINE_LOG_CRITICAL(...)		FM::Log::GetEngineLogger()->critical(__VA_ARGS__)
#define FM_ENGINE_LOG_ERROR(...)		FM::Log::GetEngineLogger()->error(__VA_ARGS__)
#define FM_ENGINE_LOG_WARN(...)			FM::Log::GetEngineLogger()->warn(__VA_ARGS__)
#define FM_ENGINE_LOG_INFO(...)			FM::Log::GetEngineLogger()->info(__VA_ARGS__)
#define FM_ENGINE_LOG_TRACE(...)		FM::Log::GetEngineLogger()->trace()

#define FM_APPLICATION_LOG_CRITICAL(...)		FM::Log::GetClientLogger()->critical(__VA_ARGS__)
#define FM_APPLICATION_LOG_ERROR(...)			FM::Log::GetClientLogger()->error(__VA_ARGS__)
#define FM_APPLICATION_LOG_WARN(...)			FM::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FM_APPLICATION_LOG_INFO(...)			FM::Log::GetClientLogger()->info(__VA_ARGS_)
#define FM_APPLICATION_LOG_TRACE(...)			FM::Log::GetClientLogger()->trace(__VA_ARGS__)