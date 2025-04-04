#include "hzpch.h"
#include "Shader.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace Hazel
{
	Shader* Shader::Create(const std::string& path)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: HZ_CORE_ASSERT(false, "RendererAPI::None in not supported"); return nullptr;
		case RendererAPI::API::OpenGL: return new OpenGLShader(path);
		}

		HZ_CORE_ASSERT(false, "Uknown RendererAPI");
		return nullptr;
	}
	Shader* Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: HZ_CORE_ASSERT(false, "RendererAPI::None in not supported"); return nullptr;
		case RendererAPI::API::OpenGL: return new OpenGLShader(vertexSrc, fragmentSrc);
		}

		HZ_CORE_ASSERT(false, "Uknown RendererAPI");
		return nullptr;
	}
}