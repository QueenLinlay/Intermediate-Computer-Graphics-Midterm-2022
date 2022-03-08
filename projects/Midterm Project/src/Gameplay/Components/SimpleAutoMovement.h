#pragma once
#include "IComponent.h"

struct GLFWwindow;

/// <summary>
/// A simple behaviour that allows movement of a gameobject with WASD, mouse,
/// and ctrl + space
/// </summary>
class SimpleAutoMovement : public Gameplay::IComponent {
public:
	typedef std::shared_ptr<SimpleAutoMovement> Sptr;

	SimpleAutoMovement();
	virtual ~SimpleAutoMovement();

	virtual void Update(float deltaTime) override;

public:
	virtual void RenderImGui() override;
	MAKE_TYPENAME(SimpleAutoMovement);
	virtual nlohmann::json ToJson() const override;
	static SimpleAutoMovement::Sptr FromJson(const nlohmann::json& blob);

protected:
	glm::vec3 _moveSpeeds;
};