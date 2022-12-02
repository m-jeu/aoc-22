//
// Created by M on 02/12/2022.
//

#include "shape.h"

#include <stdexcept>


ShapeContent Shape::getShapeContent() const {
    return shapeContent;
}


Shape::Shape(ShapeContent content):
shapeContent(content)
{
}


Shape Shape::fromReadChar(char readChar) {
    ShapeContent shapeContent;

    switch(readChar) { // TODO(m-jeu): Optimize by reading ASCII instead of switch case
        case 'A':
        case 'X':
            shapeContent = ShapeContent(rock);
            break;
        case 'B':
        case 'Y':
            shapeContent = ShapeContent(paper);
            break;
        case 'C':
        case 'Z':
            shapeContent = ShapeContent(scissors);
            break;
        default:
            throw std::invalid_argument("Invalid fromReadChar argument: " + readChar);
    }
    return Shape(shapeContent);
}


unsigned int Shape::versus(const Shape &opponent) {
    ShapeContent ops = opponent.getShapeContent();
    unsigned int score = 0;

    if(this->shapeContent == ops){ // TODO(m-jeu): Could be optimized massively
        score += 3;
    }else if(this->shapeContent - ops == 1 || this->shapeContent - ops == -2){
        score += 6;
    } // Else: Lose = 0 increase to score.

    score += this->shapeContent;

    return score;
}




