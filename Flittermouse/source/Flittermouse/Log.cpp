#include "Log.h"

namespace FM {

	const std::string Log::cstrEngineName = "Flittermouse";

	std::shared_ptr<spdlog::logger>& Log::GetClientLogger() {
		return sClientLogger;
	}

	std::shared_ptr<spdlog::logger>& Log::GetEngineLogger() {
		return sEngineLogger;
	}

	std::shared_ptr<spdlog::logger> Log::sClientLogger;
	std::shared_ptr<spdlog::logger> Log::sEngineLogger;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="pAppName">The name of the client application to be used for logging application logs</param>
	void Log::Init(const char* pAppName) {
		spdlog::set_pattern("%^[%T] %n: %v%$");

		sClientLogger = spdlog::stdout_color_mt(pAppName);
		sClientLogger->set_level(spdlog::level::trace);
		sClientLogger->info("Initialised Client Log");
		

		sEngineLogger = spdlog::stdout_color_mt(FM::Log::cstrEngineName);
		sEngineLogger->set_level(spdlog::level::trace);
		sEngineLogger->info("Initialised Engine Log");
	}
}
