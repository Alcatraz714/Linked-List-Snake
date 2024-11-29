#include "Player/BodyPart.h"
#include "Global/ServiceLocator.h"
#include "Level/LevelView.h"
#include "Level/LevelModel.h"
#include "Global/Config.h"

namespace Player
{
	using namespace Global;
	using namespace Level;
	using namespace UI::UIElement;

	void BodyPart::createBodyPartImage()
	{
		bodypart_image = new ImageView();
	}

	void BodyPart::initializeBodyPartImage()
	{
		bodypart_image->initialize(Config::snake_body_texture_path, bodypart_width, bodypart_height, getBodyPartScreenPosition());
		bodypart_image->setOriginAtCentre();
	}

	sf::Vector2f BodyPart::getBodyPartScreenPosition()
	{
		return sf::Vector2f();
	}

	void BodyPart::destroy()
	{
		delete (bodypart_image);
	}

	BodyPart::BodyPart()
	{
		grid_position = sf::Vector2i(0, 0);
		createBodyPartImage();
	}

	BodyPart::~BodyPart()
	{
		destroy();
	}

	void BodyPart::initialize(float width, float height, sf::Vector2i pos, Direction dir)
	{
		bodypart_width = width;
		bodypart_height = height;
		direction = dir;
		grid_position = pos;

		initializeBodyPartImage();
	}

	void BodyPart::render()
	{
		bodypart_image->render();
	}
}