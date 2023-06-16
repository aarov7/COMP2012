#include "Boar.h"
#include "StrayDog.h"
#include "TherapyDog.h"

int main() {
    TherapyDog tdog{"Coffee", "UST", "full-time"};
    Boar boar{"Bob", "UST"};
    StrayDog sdog1{"Doge", "UST", "yellow"};
    StrayDog sdog2{"Dollar", "UST", "brown"};

//  TODO: Complete the main function
    std::string tower_b="TowerB", ggt="GlobalGraduateTower";
    tdog.go_to(tower_b);
    boar.go_to(ggt);
    sdog1.go_to(ggt);
    sdog2.go_to(tower_b);
    tdog.smile();
    sdog1.bark_to_boar();
    boar.go_to(tower_b);
    boar.bite_package();
    sdog2.bark_to_boar();
    return 0;
}
