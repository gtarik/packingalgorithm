#pragma once
#include <string>
#include <vector>
#include "Rectangle.h"
#include "ExpandAlgorithm.h"

class Packer {

public:

	Packer(std::string path);
	~Packer();
	void Run();
	void loadRectangles();

	
	std::vector<Rectangle> load();
	static void writeFile(std::vector<std::vector<int>> file, std::string filename);

private:

	std::vector<std::vector<int>> Packing();
	std::vector<Rectangle> SortedRectangles;

	std::string Path;

	ExpandAlgorithm* expandAlgorithm;
	const char * filep;


};