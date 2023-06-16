#include <iostream>
using namespace std;
class Weapon { };
class Sword : public Weapon {
public:
Sword(int n = 1) { cout << n << " x S" << endl; }
~Sword() { cout << "~S" << endl; }
};
class Hero {
Weapon* w;
public:
Hero() { cout << "H" << endl; w = new Weapon; }
~Hero() { cout << "~H" << endl; delete w; }
virtual const Hero& operator=(const Hero& h) { cout << "H=" << endl; }
};
class SpiderMan : public Hero {
Weapon* w;
public:
SpiderMan() { cout << "SM" << endl; w = new Weapon; }
SpiderMan(const SpiderMan& s) { cout << "Copy SM" << endl; w = new Weapon; }
virtual ~SpiderMan() { cout << "~SM" << endl; delete w; }
const SpiderMan& operator=(const SpiderMan& s) { cout << "SM=" << endl; }
};
class DeadPool : public SpiderMan {
Sword sword;
public:
DeadPool() : sword(2) { cout << "DP" << endl; }
DeadPool(const DeadPool& d) : SpiderMan(d) { cout << "Copy DP" << endl; }
~DeadPool() { cout << "~DP" << endl; }
const DeadPool& operator=(const DeadPool& d) { cout << "DP=" << endl; }
};
int main() {
cout << "--- Block 1 ---" << endl;
Hero* hero = new DeadPool;
cout << "--- Block 2 ---" << endl;
SpiderMan* spiderman = new DeadPool;
cout << "--- Block 3 ---" << endl;
DeadPool deadpool(*dynamic_cast<DeadPool*>(spiderman));
cout << "--- Block 4 ---" << endl;
*hero = *spiderman;
cout << "--- Block 5 ---" << endl;
delete hero;
cout << "--- Block 6 ---" << endl;
delete spiderman;
}