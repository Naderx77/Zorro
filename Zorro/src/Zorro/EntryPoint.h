#pragma once
#ifdef ZR_PLATFORM_WINDOWS

extern Zorro::Application* Zorro::CreateApplication();

int main(int argc, char** argv) {

	Zorro::Log::Init();
	ZR_CORE_WARN("Initialized Log!");
	ZR_INFO("Initialized Log!");

	auto app = Zorro::CreateApplication();
	app->Run();
	delete app;
}
#endif