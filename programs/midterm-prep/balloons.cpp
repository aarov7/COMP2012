#include<iostream>
#include<typeinfo>
class Balloon
{
private:
    double maxRadius; // The maximum radius of the balloon
    double inflationRatio; // Amount of gas required for unit radius increment
    double radius; // The current radius of the balloon
    double volume; // The volume of gas in the balloon
    bool popped; // Flag that indicates whether the balloon is popped
public:
    /* ----- Functions to implement ----- */
    // Construct a balloon with the given maximum radius, inflation ratio, current radius,
    // current volume and a boolean value representing whether the balloon is popped or not
    // Initially, the balloon is deflated (radius is 0, volume is 0) and is not popped
    Balloon(double maxRad = 0, double ratio = 0, double r = 0, double v = 0, bool p = 0)
        : maxRadius(maxRad), inflationRatio(ratio), radius(r), volume(v), popped(p){}
    // Increase the radius of the balloon according to the input volume of gas
    // The balloon is popped if the radius is increased beyond the maximum radius
    // A popped balloon has radius 0 and volume 0
    // No effect if the balloon is already popped
    virtual void blow(int vol){
        if(!popped){
            volume+=vol;
            radius+=(vol/inflationRatio);
            if(radius>maxRadius){
                radius=0;
                volume=0;
                popped=1;
            }
        }
    }
    // Print all the data of balloon
    virtual void print() const{
        std::cout<<"Max rad., Inflat. rat., rad, vol, popped: "<<maxRadius<<", "<<inflationRatio<<", "<<radius<<", "<<volume<<", "<<((popped)?"Yes":"No")<<std::endl;
    }
    /* ----- Accessor member functions ----- */
    // Return maxRadius of the balloon
    double getMaxRadius() const { return maxRadius; }
    // Return inflationRatio of the balloon
    double getInflationRatio() const { return inflationRatio; }
    // Return the current radius of the balloon
    double getRadius() const { return radius; }
    // Return the current volume in the balloon
    double getVolume() const { return volume; }
    // Check whether the ballooon is popped
    bool isPopped() const { return popped; }
};

class FoilBalloon : public Balloon {
private:
    double maxGasVolume; // The maximum gas volume of the foil balloon
public:
    // Construct a foil balloon with the given maximum radius, maximum gas volume and
    // inflation ratio, current volume and a boolean value representing whether the
    // foil balloon is popped or not
    // As foil ballon is not elastic, its radius would always remain as max radius
    FoilBalloon(double rad = 0, double ratio = 0, double maxGasVol = 0, double v = 0, bool p = 0)
        : Balloon(rad,ratio,rad,v,p), maxGasVolume(maxGasVol){  
    }
    // As foil balloon is not elastic, its radius would always remain as max radius and
    // will not be popped because of the gas injection
    // Increase the gas volume of the balloon according to the input gas volume,
    // subject to the maximum gas volume
    void blow(int vol){
        double newVol=getVolume()+vol;
        newVol=((newVol>maxGasVolume)?maxGasVolume:newVol);
        *this=FoilBalloon(getMaxRadius(),getInflationRatio(),maxGasVolume,newVol,0);
    }
    // Prints all the data of FoilBalloon
    void print() const{
        Balloon::print();
        std::cout<<"Maximum gas volume: "<<maxGasVolume<<std::endl;
    }
};

class BalloonBouquet {
private:
    Balloon** bouquet; // A pointer which points to an array of pointers in Balloon type
    int numBalloon; // The number of balloons for the bouquet
    // It refers to the size of the pointer array pointed by bouquet
public:
    // Default constructor
    BalloonBouquet() : bouquet(NULL), numBalloon(0) { }
    // Copy constructor - Perform deep copying
    //
    // Note: Two different types of objects will be pointed by the array of pointers.
    // Create Balloon object when the object to be duplicated is in Balloon type.
    // Create FoilBalloon object when the object to be duplicated is in FoilBalloon type.
    //
    // Hint: Use typeid(<type>).name() and typeid(<expression>).name()
    BalloonBouquet(const BalloonBouquet& bb)
        : numBalloon(bb.numBalloon){
        bouquet=new Balloon*[numBalloon];
        for(int i=0;i<numBalloon;i++){
            if(typeid(*bb.bouquet[i])==typeid(Balloon)){
                bouquet[i]=new Balloon;
            }
            else{
                bouquet[i]=new FoilBalloon;
            }
            *bouquet[i]=(*bb.bouquet[i]);
        }
    }
    // Destructor - De-allocate all dynamically-allocated memory to avoid any memory
    // leak as the program finishes
    ~BalloonBouquet(){
        for(int i=0;i<numBalloon;i++){
            delete bouquet[i];
            bouquet[i]=nullptr;
        }
        delete[] bouquet;
        bouquet=nullptr;
    }
    // Adds the balloon to the bouquet
    void addBalloon(Balloon& balloon){
        Balloon** temp=new Balloon*[numBalloon+1];
        for(int i=0;i<numBalloon;i++){
            temp[i]=bouquet[i];
        }
        temp[numBalloon]=&balloon;
        delete[] bouquet;
        bouquet=temp;
        numBalloon++;
    }
};
