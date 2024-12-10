#pragma once
#include <SFML/System/Vector2.hpp>
#include "LinkedListLib/Node.h"

namespace LinkedList
{
	using namespace LinkedListLib;
	enum class Operation
	{
		HEAD,
		MID,
		TAIL,
	};

	class SingleLinkedList
	{
	private:
		Node* head_node;

		float node_width;
		float node_height;

		sf::Vector2i default_position;
		Direction default_direction;
		int linked_list_size;

		// setup
		Node* createNode();
		sf::Vector2i getNewNodePosition(Node* reference_node, Operation operation);
		void initializeNode(Node* new_node, Node* reference_node, Operation operation);

	public:
		SingleLinkedList();
		~SingleLinkedList();

		void initialize(float width, float height, sf::Vector2i position, Direction direction);
		void render();
		// Public funcs for external
		void insertNodeAtTail();
		void insertNodeAtHead();
		void insertNodeAtIndex(int index);
		void insertNodeAtMiddle();
		void removeNodeAtHead();
		void removeNodeAtMiddle();
		void removeNodeAtTail();
		void removeNodeAt(int index);
		void removeNodeAtIndex(int index);
		void shiftNodesAfterRemoval(Node* cur_node);
		void removeAllNodes();
		void removeHalfNodes();
		Node* findNodeAtIndex(int index);
		Direction reverse();
		void reverseNodeDirections();
		Direction getReverseDirection(Direction reference_direction);
		void updateNodePosition();
		void updateNodeDirection(Direction direction_to_set);
		void shiftNodesAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node);
		int findMiddleNode();
		std::vector<sf::Vector2i> getNodesPositionList();
		int getLinkedListSize();
		// Collision and getters/setters
		bool processNodeCollision();
		Node* getHeadNode();
	};
}