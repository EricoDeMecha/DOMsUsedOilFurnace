#include "matplotlibcpp.h"
#include <cmath>
namespace plt = matplotlibcpp;

int main(){
    // declare  constants
    const int p_fos = 3; // recommended factor of safety for pressure vessels is between 3.0 - 6.0
    const int D = 800; // internal diameter 800mm
    const int S = (1950 * std::pow(10,6)); // Ultimate tensile strength for Fiber glass
    const float u = 0.23; // poissons ratio for fiber glass

    // prepare the data
    std::vector<double> t,P;

    t.emplace_back(0.001);// 1000th starting thickness
    P.emplace_back(0);// 0 starting pressure 
    while(1){
        double temp = (S*(std::pow(((2*t.back()/D)+1),2)-1))/((1-2*u)+(1+u)*std::pow(((2*t.back()/D)+1),2));
        P.emplace_back(temp);
        t.emplace_back((t.back() + 0.1));// increment thickness by 0.01 
        float _fos = (S / P.back()); // compute factor of safety
        printf("%f\n",_fos);
        if(_fos < 3){
            break;
        }
    }
    printf("Ultimate pressure: %f\n",P.back());
    plt::figure_size(1300,768);
    plt::named_plot("Thickness vs Internal pressure",P,t);
    plt::title("Thickness Vs Internal pressure");
    plt::legend();
    plt::show();
}