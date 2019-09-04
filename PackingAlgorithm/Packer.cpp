#include "Packer.h"
#include <vector>                      
#include <string>                     
#include <fstream>                     
#include <iostream>                   

//constructor
Packer::Packer(std::string path) :
	Path(path),
	expandAlgorithm(new ExpandAlgorithm)

{};

//destructor
Packer::~Packer()
{
	delete expandAlgorithm;
	expandAlgorithm = nullptr;

};


std::vector<Rectangle> Packer::load()
{
	std::vector<Rectangle> loadedRectangles;

	int a, b;
	Rectangle R;

	// ---------------------
	// |                   |
	// |                   |a
	// |                   |
	// |                   |
	// ---------------------
	//           b

	std::ifstream file(filep);

	if (FILE *fp = fopen(filep, "r")) {

		while (file >> a >> b) {
			R.setParameters(a, b);
			loadedRectangles.push_back(R);

		}
	}

	return loadedRectangles;
}

void Packer::writeFile(std::vector<std::vector<int>> file, std::string filename) {

	std::ofstream output_file(filename);

	// H = Height
	// W = Width
	// X = X Coordinate left bottom of the rectangle
	// Y = Y Coordinate left bottom of the rectangle
	// The last line represents the Height Width and Area of the total rectangle

	output_file << "H W X Y\n";
	for (auto x : file) {
		for (int i = 0; i < x.size(); i++) {

			output_file << x.at(i);
			if (i < x.size() - 1) { output_file << " "; }
		}
		output_file << "\n";
	}

	output_file.close();
}



//run the packer
void Packer::Run()
{
	std::vector<std::vector<int>> atlas = Packing();

	
	writeFile(atlas, "output.txt");

}

//rectangle loader
void Packer::loadRectangles()
{
	filep = Path.c_str();

	SortedRectangles = load();

	SortedRectangles = Rectangle::SortRectangles(SortedRectangles);

}


//packing algorithm
std::vector<std::vector<int>> Packer::Packing()
{
	std::vector<std::vector<int>> data;

	loadRectangles();

	//set the parameters to the first rectangle element's
	const int initialWidth = SortedRectangles[0].getWidth();
	const int initialHeight = SortedRectangles[0].getHeight();

	std::vector<Node*> nodesSave;

	expandAlgorithm->Start(initialWidth, initialHeight);

	for (auto i = 0; i != SortedRectangles.size(); ++i)
	{
		int width = SortedRectangles[i].getWidth();
		int height = SortedRectangles[i].getHeight();

		Node* node = expandAlgorithm->Insert(width, height);
		if (node)
			expandAlgorithm->Split_Node(node, width, height);
		else    // no space left -> expand the space
			node = expandAlgorithm->ExpandSpace(width, height);
		nodesSave.push_back(node);
	}

	//the height and width of the space
	int width = expandAlgorithm->rootNode()->width;
	int height = expandAlgorithm->rootNode()->height;

	for (int i = 0; i < SortedRectangles.size(); i++) {
		std::vector<int> tempdata;
		tempdata.push_back(SortedRectangles.at(i).getHeight());
		tempdata.push_back(SortedRectangles.at(i).getWidth());
		tempdata.push_back(nodesSave.at(i)->x);
		tempdata.push_back(nodesSave.at(i)->y);
		data.push_back(tempdata);
	}

	std::vector<int> maxArea;
	maxArea.push_back(height);
	maxArea.push_back(width);
	maxArea.push_back(height*width);

	data.push_back(maxArea);

	return  data;
}
