#ifndef FISHTANK_H
#define FISHTANK_H

class FishTank {
  private:
    float temperature;
    float pHLevel;
    float volume;
  public:
    FishTank(float temp, float pH, float vol); // constructor for fish tank
    float getTemp(); // returns the temperature of fish tank
    float getpHLevel(); // returns the pH level of fish tank
    float getVolume(); // returns the volume of fish tank
    void setTemp(float temp); // sets the temperature of fish tank
    void setpHLevel(float pH); // sets the pH level of fish tank
    void setVolume(float vol); // sets the volume of fish tank
    void drawTank(); // draws fish tank
};

#endif