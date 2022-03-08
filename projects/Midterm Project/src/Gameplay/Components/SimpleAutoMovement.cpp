#include "Gameplay/Components/SimpleAutoMovement.h"
#include <GLFW/glfw3.h>
#define  GLM_SWIZZLE
#include <GLM/gtc/quaternion.hpp>

#include "Gameplay/GameObject.h"
#include "Gameplay/Scene.h"
#include "Utils/JsonGlmHelpers.h"
#include "Utils/ImGuiHelper.h"
#include "Gameplay/InputEngine.h"
#include "Application/Application.h"

SimpleAutoMovement::SimpleAutoMovement() :
	IComponent(),
	_moveSpeeds(glm::vec3(5.0f))
{}

SimpleAutoMovement::~SimpleAutoMovement() = default;

void SimpleAutoMovement::Update(float deltaTime)
{
	if (Application::Get().IsFocused) {

		glm::vec3 _moveVector = glm::vec3(0.0f);

		glm::vec3 Position = GetGameObject()->GetPosition();

		if (Position.y <= 0.0f)
		{
			GetGameObject()->SetPostion(glm::vec3(3.2f, 20.0f, 5.0f));
			
		}

		if (Position.y >= 10.0f)
		{
			_moveSpeeds.y = -5.0f;
		}
		_moveVector.y += _moveSpeeds.y;

		_moveVector *= deltaTime;

		std::cout << Position.y << std::endl;

		GetGameObject()->SetPostion(GetGameObject()->GetPosition() + _moveVector);
	}
}

void SimpleAutoMovement::RenderImGui()
{
}

nlohmann::json SimpleAutoMovement::ToJson() const
{
	return nlohmann::json();
}

SimpleAutoMovement::Sptr SimpleAutoMovement::FromJson(const nlohmann::json& blob)
{
	return SimpleAutoMovement::Sptr();
}
