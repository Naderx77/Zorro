#pragma once
#ifdef ZR_PLATFORM_WINDOWS

extern Zorro::Application* Zorro::CreateApplication();

int main(int argc, char** argv) {

	auto app = Zorro::CreateApplication();
	app->Run();
	delete app;
}
#endif