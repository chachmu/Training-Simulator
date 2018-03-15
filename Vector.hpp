#ifndef __Vector__
#define __Vector__

#include <math.h>
#include <cmath>
#include <vector>
#include <string>

class vec2d{
    public:
    float x;
    float y;

    vec2d() : x(0), y(0) {};

    vec2d(float x, float y) : x(x), y(y) {};

    vec2d operator+ (vec2d other) const{
        return vec2d(x+other.x,y+other.y);
    };

    vec2d operator- (vec2d other) const{
        return vec2d(x-other.x,y-other.y);
    };

    vec2d operator/ (vec2d other) const{
        return vec2d(x/other.x,y/other.y);
    };

    vec2d operator* (vec2d other) const{
        return vec2d(x*other.x,y*other.y);
    };

    vec2d operator+ () const{
        return vec2d(-x,-y);
    };

    vec2d operator* (float other) const{
        return vec2d(x*other,y*other);
    };

    vec2d operator/ (float other) const{
        return vec2d(x/other,y/other);
    };

    bool operator==(vec2d other) const {
        return x==other.x && y==other.y;
    };

    bool operator!=(vec2d other) const {
        return x!=other.x && y!=other.y;
    };

    float mag() const{
        return sqrtf(pow(x,2) + pow(y,2));
    };

    float dot(vec2d other) const {
        return x*other.x + y*other.y;
    };

    vec2d normal(){
        if(mag()!=0){
            return vec2d(x/mag(),y/mag());
        }
        else{
            return vec2d();
        }
    };

    float angle(vec2d other){
        return acosf((dot(other) / (mag() * other.mag())))*(180/M_PI);
    };

    float angle(){
        return angle(vec2d(1,0));
    };

    vec2d rot(float angle) {
        float newX = x * cos(angle) - y * sin(angle);
        float newY = y * cos(angle) + x * sin(angle);
        return vec2d(newX, newY);
    };

    //Rotates based on angle in degrees
    vec2d rotDeg(float angle) {
        float angleRad = angle*(M_PI/180);
        float newX = x * cos(angleRad) - y * sin(angleRad);
        float newY = y * cos(angleRad) + x * sin(angleRad);
        return vec2d(newX, newY);
    }

};

std::vector <float> Normalize(std::vector <float> u){
    //make a vectors magnitude 1

    float umagnitude=0;
    //add the square of each value of u to umagnitude
    for(int i=0;i<u.size();i++){
        umagnitude+=u[i]*u[i];
    }
    //take the square root of umagnitude, this will give the actual magnitude of u
    umagnitude=sqrt(umagnitude);

    //if umagnitude is not 0, divide every member of u by umagnitude
    if(umagnitude){
        for(int i=0;i<u.size();i++){
            u[i]=u[i]/umagnitude;
        }
    }

    //u is now normalized to a magnitude of 1

    return u;
};

float Dot(std::vector <float> u,std::vector <float> v){
    // u<u1,u2,...> dot v<v1,v2,...> = u1v1+u2v2+...

    float dot=0;

    //for every member that exists in both u and v, multiply them together and add to the total
    for(int i=0;i<u.size() and i<v.size();i++){
        dot+=u[i]*v[i];
    }
    return dot;
};


//All of these return the angle in degrees, if there is no second vector given, it is compared to a horizontal vector pointing along the + x axis
float Angle(std::vector <float> u, std::vector <float> v){
    float angle=0;

    //normalize vectors u and v
    u=Normalize(u);
    v=Normalize(v);

    //cos inverse of the dot product of u and v, then convert from radians to degrees
    angle = (acosf(Dot(u,v)))*(180/M_PI);

    if(u[1]>0){
        angle = 360-angle;
    }

    return angle;
};

float Angle(std::vector <float> u){
    float angle=0;
    //set up vector v as a horizontal vector of magnitude 1 pointing along the + x axis
    std::vector <float> v;
    v.push_back(1);
    v.push_back(0);

    angle=Angle(u,v);

    return angle;
};

float Angle(float ux, float uy, float vx, float vy){
    float angle=0;

    std::vector <float> u;
    u.push_back(ux);
    u.push_back(uy);

    std::vector <float> v;
    v.push_back(vx);
    v.push_back(vy);

    angle=Angle(u,v);

    return angle;
};

float Angle(float ux, float uy){
    float angle=0;

    std::vector <float> u;
    u.push_back(ux);
    u.push_back(uy);

    angle=Angle(u);

    return angle;
};

//takes angle and the type to be converted to
float Convert(float angleIn, std::string type){
    float angle=angle;
    if(type=="R"){
        angle=angleIn*(M_PI/180.0);
    }
    else if(type=="D"){
        angle=angleIn*(180.0/M_PI);
    }

    return angle;
};

std::vector <float> Rotate(float x, float y, float angle){
    std::vector<float> out;
    angle = Convert(angle,"R");
    out.push_back(x*cos(angle)-y*sin(angle));
    out.push_back(x*sin(angle)+y*cos(angle));
    if(-.001<=out[0] and out[0]<=.001){
        out[0]=0;
    }
    if(-.001<=out[1] and out[1]<=.001){
        out[1]=0;
    }

    return out;
};

std::vector <float> abv(std::vector <float> inp){
    for(int i=0;i<inp.size();i++){
        if(inp[i]<0){
            inp[i]=-inp[i];
        }
    }
    return inp;
};

std::vector <float> abv(float x, float y){
    std::vector <float> inp;
    inp.push_back(x);
    inp.push_back(y);
    return abv(inp);
};

#endif // __Vector__

