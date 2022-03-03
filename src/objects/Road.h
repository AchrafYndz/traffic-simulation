#ifndef TRAFFICSIM_ROAD_H
#define TRAFFICSIM_ROAD_H

#include <string>

class Road {
public:
    const std::string &getName() const;

    void setName(const std::string &name);

    int getLength() const;

    void setLength(int length);

private:
    std::string name;
    int length;
};



#endif //TRAFFICSIM_ROAD_H
