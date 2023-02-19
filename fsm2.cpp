#include <iostream>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

enum TrafficLightState {
  RED,
  YELLOW,
  GREEN
};

class TrafficLight {
public:
  TrafficLight() : currentState(RED) {}

  void buttonPressed(TrafficLightState newState) {
    if (newState == currentState) {
      std::cout << "Traffic light is already in state " << currentState << std::endl;
      return;
    }

    switch (newState) {
      case RED:
        std::cout << "Stop!" << std::endl;
        break;
      case YELLOW:
        std::cout << "Prepare to stop!" << std::endl;
        break;
      case GREEN:
        std::cout << "Go!" << std::endl;
        break;
    }

    currentState = newState;
    switch (currentState) {
      case RED:
        std::this_thread::sleep_for(20s); // Wait for 20 seconds
        buttonPressed(GREEN);
        break;
      case YELLOW:
        std::this_thread::sleep_for(5s); // Wait for 5 seconds
        buttonPressed(RED);
        break;
      case GREEN:
        std::this_thread::sleep_for(15s); // Wait for 15 seconds
        buttonPressed(YELLOW);
        break;
    }
  }

private:
  TrafficLightState currentState;
};

int main() {
  TrafficLight trafficLight;
  trafficLight.buttonPressed(RED);
  trafficLight.buttonPressed(GREEN);
  return 0;
}
