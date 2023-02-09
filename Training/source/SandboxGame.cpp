#pragma once
#include <Flittermouse.h>


class SandboxGame : public FM::ApplicationBase {
public:
	SandboxGame() {

	}

	~SandboxGame() {

	}

	const char* ApplicationName() override {
		return "Sandbox";
	}
};


FM::ApplicationBase* FM::CreateApplication() {
	return new SandboxGame();
}