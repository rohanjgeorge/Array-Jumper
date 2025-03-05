#include "../../header/Player/PlayerView.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Player/PlayerController.h"
#include "../../header/Player/PlayerModel.h"
#include <iostream>



namespace Player
{
	using namespace Global;
	using namespace Level;
	using namespace UI::UIElement;

	PlayerView::PlayerView(PlayerController* controller)
	{
		player_controller = controller;
		player_image = new ImageView();
		game_window = nullptr;
	}

	PlayerView::~PlayerView() {}

	void PlayerView::initialize()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		loadPlayer();
	}

	void PlayerView::update()
	{
		updatePlayerPosition();
	}

	void PlayerView::render()
	{
		switch (player_controller->getPlayerState())
		{
		case PlayerState::ALIVE:
			drawPlayer();
			break;
		}
	}

	void PlayerView::loadPlayer()
	{
		calculatePlayerDimensions();
		initializePlayerImage();
	}

	void PlayerView::initializePlayerImage()
	{

		player_image->initialize(Config::character_texture_path,
			player_width,
			player_height,
			sf::Vector2f(200, 300));
	}

	void PlayerView::calculatePlayerDimensions()
	{
		current_box_dimensions = ServiceLocator::getInstance()->getLevelService()->getBoxDimensions();
		player_height = current_box_dimensions.box_height;
		player_width = current_box_dimensions.box_width;
	}

	void PlayerView::updatePlayerPosition()
	{
		sf::Vector2f pos = calulcatePlayerPosition();
		std::cout << "Player Position: (" << pos.x << ", " << pos.y << ")" << std::endl;
		player_image->setPosition(calulcatePlayerPosition());
	}

	sf::Vector2f PlayerView::calulcatePlayerPosition()
	{
		float xPosition = current_box_dimensions.box_spacing + static_cast<float>(player_controller->getCurrentPosition()) * (current_box_dimensions.box_width + current_box_dimensions.box_spacing);
		float yPosition = static_cast<float>(game_window->getSize().y) - current_box_dimensions.box_height - current_box_dimensions.bottom_offset - player_height;
		return sf::Vector2f(xPosition, yPosition);
	}


	void PlayerView::drawPlayer()
	{
		/*sf::Texture player_texture;
		player_texture.loadFromFile(Config::character_texture_path);*/

		//sample to check if draw is working
		//sf::Sprite tempSprite;
		//tempSprite.setTexture(player_texture);
		//tempSprite.setPosition(900.f, 500.f);
		//tempSprite.setScale(0.5f, 0.5f);
		//game_window->draw(tempSprite);  // Directly render the sprite

		//sf::Sprite tempSpriteForce;
		//tempSpriteForce.setTexture(player_image->getTexture());
		//tempSpriteForce.setPosition(200.f, 500.f);  // Move to center of screen
		//tempSpriteForce.setScale(0.5f, 0.5f);  // Scale down if needed

		//player_image->setTexture(Config::character_texture_path); //check if texture issue
		//player_image->setPosition(sf::Vector2f(500.0f, 500.0f));
		//player_image->setScale(0.5f, 0.5f);  // Scale down if needed
		
		//player_image->setSprite(tempSpriteForce); // //check if texture issue
		player_image->render();
	}

}