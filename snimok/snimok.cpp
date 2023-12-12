#include <iostream>
#include <string>
#include <vector>

// Memento
class Memento {
private:
    std::string state;

public:
    Memento(const std::string& state) : state(state) {}

    const std::string& getState() const {
        return state;
    }
};

// Originator
class Originator {
private:
    std::string state;

public:
    void setState(const std::string& state) {
        this->state = state;
    }

    Memento createMemento() const {
        return Memento(state);
    }

    void restoreMemento(const Memento& memento) {
        state = memento.getState();
    }

    void showState() const {
        std::cout << "Current State: " << state << std::endl;
    }
};

// Caretaker
class Caretaker {
private:
    std::vector<Memento> mementos;

public:
    void addMemento(const Memento& memento) {
        mementos.push_back(memento);
    }

    const Memento& getMemento(size_t index) const {
        if (index < mementos.size()) {
            return mementos[index];
        }
        else {
            throw std::out_of_range("Index out of range");
        }
    }
};

int main() {
    Originator originator;
    Caretaker caretaker;

    originator.setState("State 1");
    originator.showState();
    caretaker.addMemento(originator.createMemento());

    originator.setState("State 2");
    originator.showState();
    caretaker.addMemento(originator.createMemento());

    originator.setState("State 3");
    originator.showState();

    // Відновлення попереднього стану
    originator.restoreMemento(caretaker.getMemento(1));
    originator.showState();

    return 0;
}
