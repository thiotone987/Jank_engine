#include <iostream>
#include "Object.h"
#include "TheFirstMover.h"

int main() {
    Object obj(PhysicsVector(2, 3), PhysicsVector(1, 2));
    std::cout << "obj: " << obj << std::endl;
    start_motion();
    Object obj2(PhysicsVector(3, 4), PhysicsVector(-5, 10));
    std::cout << "obj2: " << obj2 << std::endl;
    for (int i = 0; i < 10; i++) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "obj: " << obj << std::endl;
        std::cout << "obj2: " << obj2 << std::endl;
    }
    end_motion();
    return 0;
}
