#include "hzpch.h"
#include "Platform/Windows/WindowsWindow.h"

#include "Hazel/Core/Input.h"

#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/Events/MouseEvent.h"
#include "Hazel/Events/KeyEvent.h"

#include "Hazel/Renderer/Renderer.h"

#include "Platform/OpenGL/OpenGLContext.h"

namespace Hazel
{
	//static uint8_t s_GLFWWindowCount = 0;
	static bool s_GLFWInitialized = false;

	//static void GLFWErrorCallback(int error, const char* description)
	//{
	//	HZ_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	//}

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		//HZ_PROFILE_FUNCTION();

		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		//HZ_PROFILE_FUNCTION();

		Shutdown();
	}
	void WindowsWindow::Shutdown()
	{
		/*	HZ_PROFILE_FUNCTION();

			glfwDestroyWindow(m_Window);
			--s_GLFWWindowCount;

			if (s_GLFWWindowCount == 0)
			{
				glfwTerminate();
			}*/
		glfwDestroyWindow(m_Window);
	}
	void WindowsWindow::OnUpdate()
	{
		HZ_PROFILE_FUNCTION();

		glfwPollEvents();
		glfwSwapBuffers(m_Window);
		//m_Context->SwapBuffers();
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		HZ_PROFILE_FUNCTION();

		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}



	void WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		HZ_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized) 
		{
			int success = glfwInit();
			//HZ_CORE_ASSERT(glfwInit(), "Could not initialize GLFW!");
			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow(
			(int)props.Width,
			(int)props.Height,
			m_Data.Title.c_str(),
			nullptr,
			nullptr);

		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
	}


	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}
}