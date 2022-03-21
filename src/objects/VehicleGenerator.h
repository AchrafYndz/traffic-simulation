#ifndef TRAFFICSIM_VEHICLEGENERATOR_H
#define TRAFFICSIM_VEHICLEGENERATOR_H


class VehicleGenerator {
private:
    VehicleGenerator* _init;

    int frequency{};
    double position{};

public:
    // Constructors / destructors
    VehicleGenerator() {_init = this;}

    // General methods
    int getFrequency() const;
    void setFrequency(int frequency_);

    void setPosition(double p);
    double getPosition() const;

    // Safety specific
    bool properlyInitialized() const { return _init == this; }
};


#endif //TRAFFICSIM_VEHICLEGENERATOR_H
