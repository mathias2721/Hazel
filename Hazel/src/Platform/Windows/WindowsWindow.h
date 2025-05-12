#pragma once

#include "Hazel/Core/Window.h" 
#include "Hazel/Renderer/GraphicsContext.h"


struct GLFWwindow;

namespace Hazel {
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		unsigned int GetWidth() const override { return m_Data.Width; }
		unsigned int GetHeight() const override { return m_Data.Height; }

		void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		virtual void* GetNativeWindow() const override { return m_Window; }

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

		GLFWwindow* m_Window;

		struct WindowData : public WindowProps
		{
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
		GraphicsContext* m_Context;
	};
}