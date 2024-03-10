#include <stdio.h>

//struct of point which stores coordinates of point
struct Point {
        int x;
        int y;
};

//function which will change coordinates of XY to new ones
void changeXY(struct Point *p, int newX, int newY)
{
p->x=newX;
p->y=newY;
}

//definition of rectangle structure
struct Rectangle
{
    struct Point topleft;
    struct Point bottomright;
};

//function calculating area of rectangle
int calcArea(struct Rectangle rect)
{
    int width = rect.bottomright.x - rect.topleft.x;
    int height = rect.topleft.y - rect.bottomright.y;
    return width * height;
}

int calcPerimeter(struct Rectangle rect)
{
    int width = rect.bottomright.x - rect.topleft.x;
    int height = rect.bottomright.y - rect.topleft.y;
    return 2*(width+height);
}

int main()
{ //creating instance of point and changing coords
    struct Point point;
    changeXY(&point, 1,3);

    printf("New coordinates of point: (%d,%d)\n",point.x,point.y);

    //creating instance of rectangle
    struct Rectangle rectangle = {{2,4}, {6,2}};

    //calculating area and perimeter of rectangle
    int area = calcArea(rectangle);
    int perimeter = calcPerimeter(rectangle);

    printf("Area of rectangle: %d\n", area);
    printf("Perimeter of rectangle: %d\n", perimeter);

    return 0;
}


