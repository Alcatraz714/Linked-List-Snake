#pragma once
#include "Player/BodyPart.h"

namespace LinkedList
{
	using namespace Player;

	struct Node
	{
		BodyPart body_part;
		Node* next = nullptr;
	};
}