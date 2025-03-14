#include <Hazel.h>

#include "imgui.h"

class ExampleLayer : public Hazel::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		//HZ_INFO("ExampleLayer::Update");
	}

	void OnEvent(Hazel::Event& event) override
	{
		//HZ_TRACE("{0}", event);
	}

	void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello worlds");
		ImGui::End();
	}
};

class SandBox : public Hazel::Application
{
public:
	SandBox()
	{
		PushLayer(new ExampleLayer());
	}

	~SandBox()
	{

	}
};

Hazel::Application* Hazel::CreateApplication()
{
	return new SandBox();
}