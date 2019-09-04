#pragma once

//Node struct for the rectangles on the plane

struct Node {

	/*
	node constructor:
	-a_X and a_Y are the x and y coordinates of the bottom left point of the rectangle respectively
	-pWidth is the width parameter of the rectangle
	-pHeight is the height parameter of the rectangle
	*/

	Node(int a_X, int a_Y, int aWidth, int aHeight) :
		x(a_X),
		y(a_Y),
		width(aWidth),
		height(aHeight),
		isFree(false),
		rightExpand(nullptr),
		topExpand(nullptr)
	{};

	// coordinate of the rectangle (bottom left)
	int x;
	int y;

	// rectangle parameters
	int width;
	int height;

	// is the Node free or taken?
	bool isFree;

	Node* rightExpand;
	Node* topExpand;


	// __________________________
	// |   top expand            |
	// |                         |
	// |                         |
	// ---------------------------
	// | rectangle| right expand |
	// |		  |				 |
	// |		  |				 |
	// |--------------------------    

};


class ExpandAlgorithm {

public:

	void Start(const int spaceWidth, const int spaceHeight);

	//inserts the rectangle in the tree and returns the pointer to the node that stores the rectangle
	//if the rectangle doesnt fit, a nullptr will be returned
	Node* Insert(const int rectangleWidth, const int rectangleHeight) const;

	//this functions runs after positioning a rectangle
	void Split_Node(Node* afterNode, const int afterWidth, const int afterHeight);

	//starts the function that decides where to expand the space (to the right or to the top)
	Node* ExpandSpace(const int expWidth, const int expHeight);

	//expands the space to the right and returns a ptr to the node with the rectangle
	Node* ExpandSpace_Right(int esrWide, int esrHeight);

	//expands the space to the top and returns a ptr to the node with the rectangle
	Node* ExpandSpace_Top(int estWide, int estHeight);

	//returns the root node
	Node* rootNode()
	{
		return Root_Node;
	};

private:

	//Inserts a rectangle at the given node or a nullptr if it doesnt fit
	Node* Insert(Node* aNode, const int rectangleWidth, const int rectangleHeight) const;
	Node* Root_Node;
};