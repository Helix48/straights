#include "StraightsEngine.h"
#include <string>
#include <algorithm>
#include <array>
#include <chrono>
#include <random>

int main(int argc, char** argv){
    if(argc == 2){
        StraightsEngine se{atoi(argv[1])};
        //StraightsEngine se{44};
        se.start();
    } else{
        //std::cout<<"hi"<<std::endl;
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        StraightsEngine se{seed};
        se.start();
    }
    return 0;
}
