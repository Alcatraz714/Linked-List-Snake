#pragma once
#include "Player/BodyPart.h"

namespace Player
{
	struct Node
	{
		BodyPart body_part;
		Node* next = nullptr;
	};
}