#include "Gameplay/Components/Winning.h"
#include "Gameplay/Components/ComponentManager.h"
#include "Gameplay/GameObject.h"


EnemyTriggers::EnemyTriggers() :
	IComponent()
{ }
EnemyTriggers::~EnemyTriggers() = default;

void EnemyTriggers::OnTriggerVolumeEntered(const std::shared_ptr<Gameplay::Physics::RigidBody>&trigger)
{
		std::cout << "You win!!" << std::endl;
		std::cout << "Game have Reset!!" << std::endl;
		trigger->GetGameObject()->SetPostion(glm::vec3(4.0f, 0.0f, 3.0f));
}

void EnemyTriggers::OnTriggerVolumeLeaving(const std::shared_ptr<Gameplay::Physics::RigidBody>&trigger) 
{
	
}

void EnemyTriggers::RenderImGui() { }

nlohmann::json EnemyTriggers::ToJson() const {
	return { };
}

EnemyTriggers::Sptr EnemyTriggers::FromJson(const nlohmann::json & blob) {
	EnemyTriggers::Sptr result = std::make_shared<EnemyTriggers>();
	return result;
}