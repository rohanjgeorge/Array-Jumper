#include "../../header/Player/PlayerService.h"
#include "../../header/Player/PlayerController.h"


namespace Player
{
	PlayerService::PlayerService() { player_controller = new PlayerController(); }

	PlayerService::~PlayerService() { destroy(); }

	void PlayerService::initialize()
	{
		player_controller->initialize();
	}

	void PlayerService::update()
	{
		player_controller->update();
	}

	void PlayerService::render()
	{
		player_controller->render();
	}

	int PlayerService::getCurrentLives()
	{
		return player_controller->getCurrentLives();
	}

	void PlayerService::takeDamage()
	{
		player_controller->takeDamage();
	}

	void PlayerService::resetPlayer() { player_controller->resetPlayer(); }

	void PlayerService::levelComplete() { player_controller->resetPlayer(); }

	void PlayerService::destroy() { delete(player_controller); }

}