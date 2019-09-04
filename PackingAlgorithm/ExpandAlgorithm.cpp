#include "ExpandAlgorithm.h"

#include <iostream>                 



//starts the process and initializes the root node with the bottom left coordinate
//and the height and width parameters
void ExpandAlgorithm::Start(const int spaceWidth, const int spaceHeight)
{
	Root_Node = new Node(0, 0, spaceWidth, spaceHeight);
}


//inserts the rectangle or returns nullptr if the rectangle doesnt fit in the node
Node* ExpandAlgorithm::Insert(const int rectangleWidth, const int rectangleHeight) const
{
	return Insert(Root_Node, rectangleWidth, rectangleHeight);
}


//inserts the rectangle or returns nullptr if the rectangle doesnt fit in the node
Node* ExpandAlgorithm::Insert(Node* aNode, const int rWidth, const int rHeight) const
{
	if (aNode->isFree)
	{
		// recursively try aNode's children branchs
		if (Node* here = Insert(aNode->rightExpand, rWidth, rHeight))
			return here;
		else if (Node* there = Insert(aNode->topExpand, rWidth, rHeight))
			return there;
		else
			return nullptr;
	}
	// the image fits in this node
	else if (rWidth <= aNode->width && rHeight <= aNode->height)
		return aNode;
	else    // the image can not fit in this node
		return nullptr;
}


//triggers every time after positioning a rectangle
void  ExpandAlgorithm::Split_Node(Node* afterNode, const int afterWidth, const int afterHeight)
{
	afterNode->rightExpand = new Node(afterNode->x + afterWidth, afterNode->y, afterNode->width - afterWidth, afterHeight);
	afterNode->topExpand = new Node(afterNode->x, afterNode->y + afterHeight, afterNode->width, afterNode->height - afterHeight);

	afterNode->isFree = true;

}


//algorithm that decides where the space should expand (up/top or right)
Node*  ExpandAlgorithm::ExpandSpace(const int rWidth, const int rHeight)
{
	bool canExpandRight = (rHeight <= Root_Node->height);
	bool canExpandUp = (rWidth <= Root_Node->width);

	bool shouldExpandRight = canExpandRight && (Root_Node->height >= (Root_Node->width + rWidth));
	bool shouldExpandUp = canExpandUp && (Root_Node->width >= (Root_Node->height + rHeight));

	if (shouldExpandRight)
		return ExpandSpace_Right(rWidth, rHeight);
	else if (shouldExpandUp)
		return ExpandSpace_Top(rWidth, rHeight);
	else if (canExpandRight)
		return ExpandSpace_Right(rWidth, rHeight);
	else if (canExpandUp)
		return ExpandSpace_Top(rWidth, rHeight);
	else
		return nullptr;
}


//expand right function, returns a pointer to the node that stores the newly alligned rectangle
Node*  ExpandAlgorithm::ExpandSpace_Right(int esrWidth, int esrHeight/*, const int aImgID*/)
{
	Node* newRoot = new Node(0, 0, Root_Node->width + esrWidth, Root_Node->height);
	newRoot->isFree = true;

	// for new image
	newRoot->rightExpand = new Node(Root_Node->width, 0, esrWidth, Root_Node->height);
	newRoot->topExpand = Root_Node;

	Root_Node = newRoot;

	// insert the new image in the new root node
	if (Node* node = Insert(Root_Node, esrWidth, esrHeight))
	{
		Split_Node(node, esrWidth, esrHeight/*, aImgID*/);
		return node;
	}
	else
		return nullptr;
}


//expand top function, returns a pointer to the node that stores the newly alligned rectangle
Node*  ExpandAlgorithm::ExpandSpace_Top(int estWidth, int estHeight)
{
	Node* newRoot = new Node(0, 0, Root_Node->width, Root_Node->height + estHeight);
	newRoot->isFree = true;

	newRoot->rightExpand = Root_Node;
	newRoot->topExpand = new Node(0, Root_Node->height, Root_Node->width, estHeight);

	Root_Node = newRoot;

	if (Node* node = Insert(Root_Node, estWidth, estHeight))
	{
		Split_Node(node, estWidth, estHeight/*, aImgID*/);
		return node;
	}
	else
		return nullptr;
}
