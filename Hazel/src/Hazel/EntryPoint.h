#pragma once

#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();

int main(int arg, char** argv) {
	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
}

#endif