#pragma once
#ifndef ThreeDGRIDMAP_H
#define ThreeDGRIDMAP_H

#include <vector>
#include<fstream>
#include<string>
#include<iostream>
#include<algorithm>
#include "PointCloud.h"
#include "Point.h"

class ThreeDGridMap
{
public:
    ThreeDGridMap(int depth, float gridSize);

    void insertPointCloud(PointCloud& pc);
    void insertPoint(Point& p);
    bool getGrid(int x, int y, int z) const;
    bool loadMap(const std::string& fileName);
    bool saveMap(const std::string& fileName);


    void setGridSize(float size);
    float getGridSize() const;
    void setDepth(int depth);
    int getDepth() const;

private:
    std::vector<std::vector<std::vector<bool>>> map;
    float gridSize;
    int depth;
};

#endif // ThreeDGRIDMAP_H
