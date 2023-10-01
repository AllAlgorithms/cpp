#include <vector>

// Equation of 2D line is in form ax +by +c =0
std::vector<float> line_intersection_2d(float a1, float b1, float c1, 
    float a2, float b2, float c2, float slopeTol = 0.01)
{
    std::vector<float> intersectonPt;
  
    float slopeDiff = ((a1/b1)-(a2/b2));
    if(slopeDiff<0)
    {
        slopeDiff *=-1;
    }
    //Checking if lines are parallel
    if(slopeDiff < slopeTol )
    {
        //if parallel, return empty vector
        return intersectonPt;
    }
    float x = (b1*c2-b2*c1)/(a1*b2-a2*b1);
    float y = (c1*a2-c2*a1)/(a1*b2-a2*b1);
    intersectonPt.push_back(x);
    intersectonPt.push_back(y);
    return intersectonPt;
}
