#include "SatirListesiNode.hpp"


SatirListesiNode::SatirListesiNode(const int data, SatirListesiNode *next, SatirListesiNode *prev)
{
	this->data = data;
	this->next = next;
	this->prev = prev;
}
