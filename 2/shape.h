//
// Created by M on 02/12/2022.
//

#ifndef INC_2_SHAPE_H
#define INC_2_SHAPE_H


enum ShapeContent {
    rock = 1,
    paper = 2,
    scissors = 3,
};


class Shape {
private:
    const ShapeContent shapeContent;

public:
    Shape(ShapeContent content);
    static Shape fromReadChar(char readChar);

    unsigned int versus(const Shape & opponent);

    ShapeContent getShapeContent() const;

};


#endif //INC_2_SHAPE_H
