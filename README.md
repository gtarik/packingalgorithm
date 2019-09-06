# Packing algorithm

This is an algorithm that solves the mathematical bin packing problem.

## How it works
This algorithm uses the Binary Tree Bin Packing approach. It dynamically grows the rectangle in which the rectangles are supposed to be packed. 
The algorithm first sorts all given rectangles by their max height in descendent order. 

Next it starts by packing the rectangles beginning by the biggest one, then it grows the canvas to the right or down depending on what will result with the smaller total area of the canvas.
In this fashion the occupied area is minimized.

## How to use it
U save the given rectangles in the following format as the “csv.txt” file
```
1 2
3 4
1 3
```
Now start the application, it will save the calculated result as the file “output.txt”
```
H W X Y
7 2 0 0
1 2 6 6
7 10 70
```
H – Height
W – Width
X – X-coordinate of the bottom left point of the rectangle
Y – Y-coordinate of the bottom left point of the rectangle
The last line represents the total Width, Height and Area of the calculated canvas.

## Authors

* **Tarik Gruhonjic**  - [Tarik Gruhonjic](https://github.com/gtarik)

## Acknowledgments

* http://codeincomplete.com/posts/bin-packing
