//Copy in the csv.txt file all the rectangle parameters in the following format
//Height Width
//example for 3 rectangles with the parameters (3,0) (2,1) and (1,1)
//3 0
//2 1
//1 1
//
//the program will output the result as a .txt file named "output.txt"
//the result will be saved in the following format
// H W X Y
// 
// H = Height
// W = Width
// X = X Coordinate left bottom of the rectangle
// Y = Y Coordinate left bottom of the rectangle


#include <iostream>
#include "Rectangle.h"
#include "ExpandAlgorithm.h"
#include "Packer.h"
#include <algorithm>


int main()
{

	std::string path = "csv.txt";
	Packer Test(path);
	Test.Run();
	std::cout << "Sorting rectangles done.\n";

}
