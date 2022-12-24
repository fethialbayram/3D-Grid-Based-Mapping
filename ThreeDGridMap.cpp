#include "ThreeDGridMap.h"
#include "PointCloud.h"
#include "Point.h"



ThreeDGridMap::ThreeDGridMap(int depth, float gridSize)
    : depth(depth), gridSize(gridSize)
{
    // Initialize the map with the specified depth
    
   
    fill(&map[0][0][0], &map[0][0][0] + depth * depth * depth, false);
  


}


void ThreeDGridMap::insertPointCloud(PointCloud & pc)
{
  

    for (int i = 0; pc.pointNumber; i++) {

        insertPoint(pc.points[i]);

    }

}


void ThreeDGridMap::insertPoint(Point & p)
{
    int x = static_cast<int>(p.x / gridSize);
    int y = static_cast<int>(p.y / gridSize);
    int z = static_cast<int>(p.z / gridSize);
  
    if (x >= 0 && x < depth && y >= 0 && y < depth && z >= 0 && z < depth) {

        map[x][y][z] = true;

    }
}

bool ThreeDGridMap::getGrid(int x, int y, int z) const
{
    if (x < 0 || x >= depth || y < 0 || y >= depth || z < 0 || z >= depth) {

        return false;

    }

    return map[x][y][z];
}

bool ThreeDGridMap::loadMap(const std::string & fileName)
{

    std::ifstream in(fileName);


    if (!in.is_open()) {
        return false;
    }

    in >> gridSize;
    in >> depth;

    int value;

    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < depth; j++) {
            for (int k = 0; k < depth; k++) {
                
                value = map[i][j][k] ? 1 : 0;
                in >> value;

            }
        }
    }

    return true;

}

bool ThreeDGridMap::saveMap(const std::string & fileName)
{
    std::ofstream out(fileName);
    if (!out.is_open()) {
        return false;
    }

    out << gridSize << '\n';
    out << depth << '\n';

    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < depth; j++) {
            for (int k = 0; k < depth; k++) {
                out << map[i][j][k] << ' ';
            }
            out << '\n';
        }
    }

    return true;
}


void ThreeDGridMap::setGridSize(float size)
{
    gridSize = size;
}

float ThreeDGridMap::getGridSize() const
{
    return gridSize;
}

void ThreeDGridMap::setDepth(int d)
{
    depth = d;
}

int ThreeDGridMap::getDepth() const
{
    return depth;
}
