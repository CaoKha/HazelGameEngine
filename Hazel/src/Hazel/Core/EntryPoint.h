#pragma once

#include "Hazel/Core/Base.h"
#include "Hazel/Core/Application.h"

#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();

int main(int arg, char** argv) 
{
	Hazel::Log::Init();
	HZ_CORE_WARN("Initialized Log!");
	int a = 5;
	HZ_INFO("Hello! Var={0}", a);
	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
}

#endif