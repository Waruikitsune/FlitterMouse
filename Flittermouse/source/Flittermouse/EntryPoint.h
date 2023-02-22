#pragma once

#ifdef FM_PLATFORM_WINDOWS

extern FM::ApplicationBase* FM::CreateApplication();

int main(int argc, char** argv) {

	auto app = FM::CreateApplication();
	FM::Log::Init(app->ApplicationName());
	FM_APPLICATION_LOG_INFO("Test Info log from outside init functions");
	app->Run();
	delete app;
	return 0;
	}
#endif 

