#include "hzpch.h"
#include "OrthographicCamera.h"


#include <glm/gtc/matrix_transform.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/rotate_vector.hpp>


namespace Hazel {
	void dump(const glm::mat4& matrix)
	{
		for (int i = 0; i < 4;i++)
		{
			HZ_TRACE("[ {0} \t{1} \t{2} \t{3}]", matrix[i][0], matrix[i][1], matrix[i][2], matrix[i][3]);
		}
	}

	OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top)
		: m_ProjectionMatrix(glm::ortho(left, right, bottom, top, -1.0f, 1.0f)), m_ViewMatrix(1.0f)
	{
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
	}

	void OrthographicCamera::Left()
	{
		auto vec = m_Position + glm::rotate(glm::vec3(-0.1f, 0.f, 0.f), glm::radians(m_Rotation), glm::vec3(0, 0, 1));
		SetPosition(vec);
	}

	void OrthographicCamera::RecalculateViewMatrix()
	{
		glm::mat4 transform = glm::translate(glm::mat4(1.0f), m_Position) * 
							  glm::rotate(glm::mat4(1.0f), glm::radians(m_Rotation), glm::vec3(0, 0, 1));

		m_ViewMatrix = glm::inverse(transform);
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
	}


}