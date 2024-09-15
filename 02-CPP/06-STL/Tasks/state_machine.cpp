#include <iostream>
#include <map>
#include <functional>

enum class State {
    Red,
    Green,
    Yellow
};

enum class Event {
    TurnGreen,
    TurnYellow,
    TurnRed
};

class TrafficLight {
public:
    TrafficLight() {
        // Initial state
        currentState = State::Red;

        // Define state transitions and actions using lambda expression
        stateTransitions[State::Red][Event::TurnGreen] = [this]() {
            std::cout << "Transition: Red -> Green" << std::endl;
            currentState = State::Green;
        };

        stateTransitions[State::Green][Event::TurnYellow] = [this]() {
            std::cout << "Transition: Green -> Yellow" << std::endl;
            currentState = State::Yellow;
        };

        stateTransitions[State::Yellow][Event::TurnRed] = [this]() {
            std::cout << "Transition: Yellow -> Red" << std::endl;
            currentState = State::Red;
        };
    }

    void handleEvent(Event event) {
        auto stateIt = stateTransitions.find(currentState);
        if (stateIt != stateTransitions.end()) {
            auto eventIt = stateIt->second.find(event);
            if (eventIt != stateIt->second.end()) {
                eventIt->second();  // Execute the transition action
            } else {
                std::cout << "Invalid event for current state." << std::endl;
            }
        } else {
            std::cout << "Current state not found." << std::endl;
        }
    }

    State getCurrentState() const {
        return currentState;
    }

private:
    State currentState;
    std::map<State, std::map<Event, std::function<void()>>> stateTransitions;
};

int main() {
    TrafficLight light;

    std::cout << "Initial state: Red" << std::endl;
    
    // Simulate events
    light.handleEvent(Event::TurnGreen);
    light.handleEvent(Event::TurnYellow);
    light.handleEvent(Event::TurnRed);

    return 0;
}
