#pragma once

#include "Hazel.h"

class Sandbox2D: public Hazel::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;
	virtual void OnAttach() override;
	virtual void OnDetach() override;

	virtual void OnUpdate(Hazel::Timestep) override;
	virtual void OnImGuiRender() override;
	virtual void OnEvent(Hazel::Event& e) override;

private:
	Hazel::OrthographicCameraController m_CameraController;

	Hazel::Ref<Hazel::Texture2D> m_CheckerBoardTexture;

	glm::vec4 m_SquareColor = { 0.1f, 0.1f, 0.8f, 0.2f };

};