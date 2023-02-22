#pragma once
#include <Flittermouse.h>

class SandboxGame : public FM::ApplicationBase {
public:
	SandboxGame() {
		
	}

	~SandboxGame() {

	}
	
	const inline std::string& FM::ApplicationBase::ApplicationName() {
		return sAppName;
	}
private:
	static inline const std::string sAppName = "TrainingApplication";
	
};


FM::ApplicationBase* FM::CreateApplication() {
	//FM::WindowClosedEvent wc() = FM::WindowClosedEvent();
	return new SandboxGame();
}
