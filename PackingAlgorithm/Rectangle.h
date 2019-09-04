#pragma once
#include <vector>

class Rectangle {


public:
	Rectangle() {};

	Rectangle(int x, int y) :
		height(x),
		width(y)
	{};

	~Rectangle();

	bool operator< (const Rectangle &other) const {
		return height < other.height;
	}

	bool operator> (const Rectangle &other) const {
		return height > other.height;
	}

	static std::vector<Rectangle> SortRectangles(std::vector<Rectangle> rectangleVector);

	int getHeight();
	int getWidth();

	void setParameters(int a, int b);

private:
	int height;
	int width;
};
