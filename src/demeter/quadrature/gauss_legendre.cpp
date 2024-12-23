#include "gauss_legendre.hpp"

#include <cmath>
#include <iostream>
#include <Eigen/Dense>

// To do
// 1 - Automatiser le calcul des racines et des poids pour
//     aller jusqua 48 (python)
// Tous les poids sont a diviser par deux
// teta est dans [0,pi] pas besoin des angles teta
// dans [pi,2pi] on fait teta_k+pi avec 
// w_{k+pi} = w_k  

namespace Demeter {

// nteta = 2
template <>
Eigen::ArrayXd GaussLegendre<2>::weights_(1);
template <>
Eigen::ArrayXd GaussLegendre<2>::costeta_(1);
template <>
Eigen::ArrayXd GaussLegendre<2>::teta_(1);
template <>
void GaussLegendre<2>::initialization() {
    weights_ << 1.0000000;
    costeta_ << 0.57735027;
    teta_ << 0.00000;
}
// nteta = 4
template <>
Eigen::ArrayXd GaussLegendre<4>::weights_(2);
template <>
Eigen::ArrayXd GaussLegendre<4>::costeta_(2);
template <>
Eigen::ArrayXd GaussLegendre<4>::teta_(2);
template <>
void GaussLegendre<4>::initialization() {
    weights_ << 0.65214515, 0.34785485;
    costeta_ << 0.33998104, 0.86113631;
    teta_ << 0.00000;
}
// nteta = 6
template <>
Eigen::ArrayXd GaussLegendre<6>::weights_(3);
template <>
Eigen::ArrayXd GaussLegendre<6>::costeta_(3);
template <>
Eigen::ArrayXd GaussLegendre<6>::teta_(3);
template <>
void GaussLegendre<6>::initialization() {
    weights_ << 0.46791393, 0.36076157, 0.17132449;
    costeta_ << 0.23861919, 0.66120939, 0.93246951;
    teta_ << 0.00000;
}
// nteta = 8
template <>
Eigen::ArrayXd GaussLegendre<8>::weights_(4);
template <>
Eigen::ArrayXd GaussLegendre<8>::costeta_(4);
template <>
Eigen::ArrayXd GaussLegendre<8>::teta_(4);
template <>
void GaussLegendre<8>::initialization() {
    weights_ << 0.36268378, 0.31370665, 0.22238103, 0.10122854;
    costeta_ << 0.18343464, 0.52553241, 0.79666648, 0.96028986;
    teta_ << 0.00000;
}
// nteta = 10
template <>
Eigen::ArrayXd GaussLegendre<10>::weights_(5);
template <>
Eigen::ArrayXd GaussLegendre<10>::costeta_(5);
template <>
Eigen::ArrayXd GaussLegendre<10>::teta_(5);
template <>
void GaussLegendre<10>::initialization() {
    weights_ << 0.29552422, 0.26926672, 0.21908636, 0.14945135, 0.06667134;
    costeta_ << 0.14887434, 0.43339539, 0.67940957, 0.86506337, 0.97390653;
    teta_ << 0.00000;
}
// nteta = 12
template <>
Eigen::ArrayXd GaussLegendre<12>::weights_(6);
template <>
Eigen::ArrayXd GaussLegendre<12>::costeta_(6);
template <>
Eigen::ArrayXd GaussLegendre<12>::teta_(6);
template <>
void GaussLegendre<12>::initialization() {
    weights_ << 0.24914705, 0.23349254, 0.20316743, 0.16007833, 0.10693933,
                0.04717534;
    costeta_ << 0.12523341, 0.3678315,  0.58731795, 0.76990267, 0.90411726,
                0.98156063;
    teta_ << 0.00000;
}
// nteta = 14
template <>
Eigen::ArrayXd GaussLegendre<14>::weights_(7);
template <>
Eigen::ArrayXd GaussLegendre<14>::costeta_(7);
template <>
Eigen::ArrayXd GaussLegendre<14>::teta_(7);
template <>
void GaussLegendre<14>::initialization() {
    weights_ << 0.21526385, 0.20519846, 0.1855384, 0.15720317, 0.12151857,
                0.08015809, 0.03511946;
    costeta_ << 0.10805495, 0.31911237, 0.51524864, 0.6872929, 0.82720132, 
                0.92843488, 0.98628381;
    teta_ << 0.00000;
}
// nteta = 16
template <>
Eigen::ArrayXd GaussLegendre<16>::weights_(8);
template <>
Eigen::ArrayXd GaussLegendre<16>::costeta_(8);
template <>
Eigen::ArrayXd GaussLegendre<16>::teta_(8);
template <>
void GaussLegendre<16>::initialization() {
    weights_ << 0.18945061, 0.18260342, 0.16915652, 0.14959599, 0.12462897, 
                0.09515851, 0.06225352, 0.02715246;
    costeta_ << 0.09501251, 0.28160355, 0.45801678, 0.61787624, 0.75540441, 
                0.8656312, 0.94457502, 0.98940093;
    teta_ << 0.00000;
}
// nteta = 18
template <>
Eigen::ArrayXd GaussLegendre<18>::weights_(9);
template <>
Eigen::ArrayXd GaussLegendre<18>::costeta_(9);
template <>
Eigen::ArrayXd GaussLegendre<18>::teta_(9);
template <>
void GaussLegendre<18>::initialization() {
    weights_ << 0.16914238, 0.16427648, 0.15468468, 0.14064291, 0.12255521, 
                0.10094204, 0.07642573, 0.04971455, 0.02161601;
    costeta_ << 0.00000;
    teta_ << 0.00000;
}
// nteta = 20
template <>
Eigen::ArrayXd GaussLegendre<20>::weights_(10);
template <>
Eigen::ArrayXd GaussLegendre<20>::costeta_(10);
template <>
Eigen::ArrayXd GaussLegendre<20>::teta_(10);
template <>
void GaussLegendre<20>::initialization() {
    weights_ << 0.15275339, 0.14917299, 0.14209611, 0.13168864, 0.11819453, 
                0.10193012, 0.08327674, 0.06267205, 0.04060143, 0.01761401;
    costeta_ << 0.07652652, 0.22778585, 0.37370609, 0.510867,   0.63605368,
                0.74633191, 0.83911697, 0.91223443, 0.96397193, 0.9931286;
    teta_ << 0.00000;
}
// nteta = 22
template <>
Eigen::ArrayXd GaussLegendre<22>::weights_(11);
template <>
Eigen::ArrayXd GaussLegendre<22>::costeta_(11);
template <>
Eigen::ArrayXd GaussLegendre<22>::teta_(11);
template <>
void GaussLegendre<22>::initialization() {
    weights_ << 0.13925187, 0.1365415 , 0.1311735 , 0.12325238, 0.1129323,  
                0.10041414, 0.08594161, 0.06979647, 0.05229334, 0.0337749,  
                0.014628;
    costeta_ << 0.06973927, 0.20786043, 0.34193582, 0.46935584, 0.5876404,  
                0.69448726, 0.78781681, 0.86581258, 0.92695677, 0.9700605,  
                0.99429459;
    teta_ << 0.00000;
}
// nteta = 24
template <>
Eigen::ArrayXd GaussLegendre<24>::weights_(12);
template <>
Eigen::ArrayXd GaussLegendre<24>::costeta_(12);
template <>
Eigen::ArrayXd GaussLegendre<24>::teta_(12);
template <>
void GaussLegendre<24>::initialization() {
    weights_ << 0.00000;
    costeta_ << 0.00000;
    teta_ << 0.00000;
}
// nteta = 26
template <>
Eigen::ArrayXd GaussLegendre<26>::weights_(13);
template <>
Eigen::ArrayXd GaussLegendre<26>::costeta_(13);
template <>
Eigen::ArrayXd GaussLegendre<26>::teta_(13);
template <>
void GaussLegendre<26>::initialization() {
    weights_ << 0.00000;
    costeta_ << 0.00000;
    teta_ << 0.00000;
}
// nteta = 28
template <>
Eigen::ArrayXd GaussLegendre<28>::weights_(14);
template <>
Eigen::ArrayXd GaussLegendre<28>::costeta_(14);
template <>
Eigen::ArrayXd GaussLegendre<28>::teta_(14);
template <>
void GaussLegendre<28>::initialization() {
    weights_ << 0.00000;
    costeta_ << 0.00000;
    teta_ << 0.00000;
}
// nteta = 30
template <>
Eigen::ArrayXd GaussLegendre<30>::weights_(15);
template <>
Eigen::ArrayXd GaussLegendre<30>::costeta_(15);
template <>
Eigen::ArrayXd GaussLegendre<30>::teta_(15);
template <>
void GaussLegendre<30>::initialization() {
    weights_ << 0.00000;
    costeta_ << 0.00000;
    teta_ << 0.00000;
}
// nteta = 32
template <>
Eigen::ArrayXd GaussLegendre<32>::weights_(16);
template <>
Eigen::ArrayXd GaussLegendre<32>::costeta_(16);
template <>
Eigen::ArrayXd GaussLegendre<32>::teta_(16);
template <>
void GaussLegendre<32>::initialization() {
    weights_ << 0.00000;
    costeta_ << 0.00000;
    teta_ << 0.00000;
}
// nteta = 34
template <>
Eigen::ArrayXd GaussLegendre<34>::weights_(17);
template <>
Eigen::ArrayXd GaussLegendre<34>::costeta_(17);
template <>
Eigen::ArrayXd GaussLegendre<34>::teta_(17);
template <>
void GaussLegendre<34>::initialization() {
    weights_ << 0.00000;
    costeta_ << 0.00000;
    teta_ << 0.00000;
}
// nteta = 36
template <>
Eigen::ArrayXd GaussLegendre<36>::weights_(18);
template <>
Eigen::ArrayXd GaussLegendre<36>::costeta_(18);
template <>
Eigen::ArrayXd GaussLegendre<36>::teta_(18);
template <>
void GaussLegendre<36>::initialization() {
    weights_ << 0.00000;
    costeta_ << 0.00000;
    teta_ << 0.00000;
}
// nteta = 38
template <>
Eigen::ArrayXd GaussLegendre<38>::weights_(19);
template <>
Eigen::ArrayXd GaussLegendre<38>::costeta_(19);
template <>
Eigen::ArrayXd GaussLegendre<38>::teta_(19);
template <>
void GaussLegendre<38>::initialization() {
    weights_ << 0.00000;
    costeta_ << 0.00000;
    teta_ << 0.00000;
}
// nteta = 40
template <>
Eigen::ArrayXd GaussLegendre<40>::weights_(20);
template <>
Eigen::ArrayXd GaussLegendre<40>::costeta_(20);
template <>
Eigen::ArrayXd GaussLegendre<40>::teta_(20);
template <>
void GaussLegendre<40>::initialization() {
    weights_ << 0.00000;
    costeta_ << 0.00000;
    teta_ << 0.00000;
}
// nteta = 42
template <>
Eigen::ArrayXd GaussLegendre<42>::weights_(21);
template <>
Eigen::ArrayXd GaussLegendre<42>::costeta_(21);
template <>
Eigen::ArrayXd GaussLegendre<42>::teta_(21);
template <>
void GaussLegendre<42>::initialization() {
    weights_ << 0.00000;
    costeta_ << 0.00000;
    teta_ << 0.00000;
}
// nteta = 44
template <>
Eigen::ArrayXd GaussLegendre<44>::weights_(22);
template <>
Eigen::ArrayXd GaussLegendre<44>::costeta_(22);
template <>
Eigen::ArrayXd GaussLegendre<44>::teta_(22);
template <>
void GaussLegendre<44>::initialization() {
    weights_ << 0.00000;
    costeta_ << 0.00000;
    teta_ << 0.00000;
}
// nteta = 46
template <>
Eigen::ArrayXd GaussLegendre<46>::weights_(23);
template <>
Eigen::ArrayXd GaussLegendre<46>::costeta_(23);
template <>
Eigen::ArrayXd GaussLegendre<46>::teta_(23);
template <>
void GaussLegendre<46>::initialization() {
    weights_ << 0.00000;
    costeta_ << 0.00000;
    teta_ << 0.00000;
}
// nteta = 48
template <>
Eigen::ArrayXd GaussLegendre<48>::weights_(24);
template <>
Eigen::ArrayXd GaussLegendre<48>::costeta_(24);
template <>
Eigen::ArrayXd GaussLegendre<48>::teta_(24);
template <>
void GaussLegendre<48>::initialization() {
    weights_ << 0.00000;
    costeta_ << 0.00000;
    teta_ << 0.00000;
}
} // namespace Demeter
