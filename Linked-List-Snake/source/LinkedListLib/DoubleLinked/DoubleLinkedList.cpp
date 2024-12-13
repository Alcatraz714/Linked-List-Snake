#include "LinkedListLib/DoubleLinked/DoubleLinkedList.h"
#include "Player/BodyPart.h"
#include "Level/LevelView.h"
#include <iostream>

namespace LinkedListLib
{
	namespace DoubleLinked
	{
		Node* DoubleLinkedList::createNode()
		{
			return new DoubleNode();
		}

		DoubleLinkedList::DoubleLinkedList() = default;

		DoubleLinkedList::~DoubleLinkedList() = default;

		void DoubleLinkedList::insertNodeAtTail()
		{
			linked_list_size++;
			Node* new_node = createNode();// we need a head node for adding the next node
			Node* cur_node = head_node;

			if (cur_node == nullptr)
			{
				head_node = new_node;
				initializeNode(new_node, nullptr, Operation::TAIL);
				return;
			}

			while (cur_node->next != nullptr)
			{
				cur_node = cur_node->next;
			}

			cur_node->next = new_node;
			initializeNode(new_node, cur_node, Operation::TAIL);
		}

		void DoubleLinkedList::insertNodeAtHead()
		{
			linked_list_size++;
			Node* new_node = createNode();

			if (head_node == nullptr)
			{
				head_node = new_node;
				static_cast<DoubleNode*>(new_node)->previous = nullptr;
				initializeNode(new_node, nullptr, Operation::HEAD);
				return;
			}

			initializeNode(new_node, head_node, Operation::HEAD);

			new_node->next = head_node;
			static_cast<DoubleNode*>(head_node)->previous = new_node;

			head_node = new_node;
		}

		void DoubleLinkedList::insertNodeAtMiddle()
		{
			if (head_node == nullptr)
			{
				insertNodeAtHead();
				return;
			}
			int midIndex = findMiddleNode();
			insertNodeAtIndex(midIndex);
		}

		void DoubleLinkedList::insertNodeAtIndex(int index)
		{
			if (index < 0 || index >= linked_list_size) return;

			if (index == 0)
			{
				insertNodeAtHead();
				return;
			}

			Node* new_node = createNode();

			int current_index = 0;
			Node* cur_node = head_node;
			Node* prev_node = nullptr;

			while (cur_node != nullptr && current_index < index)
			{
				prev_node = cur_node;
				cur_node = cur_node->next;
				current_index++;
			}

			prev_node->next = new_node;
			new_node->next = cur_node;
			initializeNode(new_node, prev_node, Operation::TAIL);
			linked_list_size++;
			shiftNodesAfterInsertion(new_node, cur_node, prev_node);
		}

		void DoubleLinkedList::shiftNodesAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node)
		{
			
		}

		void DoubleLinkedList::removeNodeAtTail()
		{
			if (head_node == nullptr) return;
			linked_list_size--; //Decrement linked list size when you are deleting a node

			Node* cur_node = head_node;

			if (cur_node->next == nullptr) //If there is only 1 node in the linked list
			{
				removeNodeAtHead();
				return;
			}

			while (cur_node->next->next != nullptr) //If there is more than 1 node in the linked list
			{
				cur_node = cur_node->next;
			}

			delete (cur_node->next);
			cur_node->next = nullptr;
		}

		void DoubleLinkedList::removeNodeAtHead()
		{
			Node* cur_node = head_node;
			head_node = head_node->next;

			cur_node->next = nullptr;
			delete (cur_node);
			linked_list_size--; //decrement the size
		}

		void DoubleLinkedList::removeNodeAtMiddle()
		{
			if (head_node == nullptr) return; // If the list is empty, there's nothing to remove

			int midIndex = findMiddleNode();  // Use the existing function to find the middle index
			removeNodeAt(midIndex);
		}

		void DoubleLinkedList::removeNodeAt(int index)
		{
			if (index < 0 || index >= linked_list_size) return;

			if (index == 0)
			{
				removeNodeAtHead();
			}
			else
			{
				removeNodeAtIndex(index);
			}
		}

		void DoubleLinkedList::removeNodeAtIndex(int index)
		{
			
		}

		void DoubleLinkedList::removeAllNodes()
		{
			if (head_node == nullptr) return;

			while (head_node != nullptr)
			{
				removeNodeAtHead();
			}
		}

		void DoubleLinkedList::removeHalfNodes()
		{
			if (linked_list_size <= 1) return;
			int half_length = linked_list_size / 2;
			int new_tail_index = half_length - 1;

			Node* prev_node = findNodeAtIndex(new_tail_index);
			Node* cur_node = prev_node->next;

			while (cur_node != nullptr)
			{
				Node* node_to_delete = cur_node;
				cur_node = cur_node->next;

				delete (node_to_delete);
				linked_list_size--;
			}

			prev_node->next = nullptr;
		}

		void DoubleLinkedList::shiftNodesAfterRemoval(Node* cur_node)
		{
			
		}

		Direction DoubleLinkedList::reverse()
		{
			Node* cur_node = head_node;
			Node* prev_node = nullptr;
			Node* next_node = nullptr;

			while (cur_node != nullptr)
			{
				next_node = cur_node->next;
				cur_node->next = prev_node;

				prev_node = cur_node;
				cur_node = next_node;
			}

			head_node = prev_node;

			reverseNodeDirections();
			return head_node->body_part.getDirection();
		}
	}
}
