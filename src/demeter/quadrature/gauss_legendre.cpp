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
    weights_ << 0.1279382 , 0.12583746, 0.12167047, 0.11550567, 0.10744427, 
                0.09761865, 0.08619016, 0.07334648, 0.05929858, 0.04427744,
                0.02853139, 0.01234123;
    costeta_ << 0.06405689, 0.19111887, 0.31504268, 0.43379351, 0.54542147, 
                0.64809365, 0.74012419, 0.82000199, 0.88641553, 0.93827455, 
                0.97472856, 0.99518722;
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
    weights_ << 0.11832142, 0.11666044, 0.11336182, 0.10847184, 0.10205916, 
                0.0942138 , 0.08504589, 0.07468415, 0.06327405, 0.05097583, 
                0.03796238, 0.02441785, 0.01055137;
    costeta_ << 0.05923009, 0.17685882, 0.29200484, 0.40305176, 0.50844071,
                0.60669229, 0.69642726, 0.77638595, 0.84544594, 0.90263786,
                0.94715907, 0.97838545, 0.9958857;
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
    weights_ << 0.11004701, 0.10871119, 0.10605577, 0.10211297, 0.09693066, 
                0.09057174, 0.08311342, 0.07464621, 0.06527292, 0.05510735, 
                0.04427293, 0.03290143, 0.02113211, 0.00912428;
    costeta_ << 0.05507929, 0.16456928, 0.27206163, 0.37625152, 0.47587422, 
                0.56972047, 0.65665109, 0.73561088, 0.80564137, 0.86589252, 
                0.91563303, 0.95425928, 0.98130317, 0.9964425;
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
    weights_ << 0.10285265, 0.10176239, 0.09959342, 0.09636874, 0.09212252,
                0.08689979, 0.0807559 , 0.07375597, 0.06597423, 0.05749316,
                0.04840267, 0.03879919, 0.02878471, 0.01846647, 0.00796819;
    costeta_ << 0.05147184, 0.15386991, 0.25463693, 0.35270473, 0.44703377, 
                0.53662415, 0.62052618, 0.69785049, 0.76777743, 0.82956576, 
                0.88256054, 0.92620005, 0.96002186, 0.98366812, 0.99689348;
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
    weights_ << 0.09654009, 0.09563872, 0.0938444 , 0.09117388, 0.08765209, 
                0.08331192, 0.0781939 , 0.07234579, 0.06582222, 0.05868409, 
                0.05099806, 0.0428359 , 0.03427386, 0.02539207, 0.01627439, 
                0.00701861;
    costeta_ << 0.04830767, 0.14447196, 0.23928736, 0.3318686 , 0.42135128, 
                0.50689991, 0.58771576, 0.66304427, 0.73218212, 0.7944838 , 
                0.84936761, 0.89632116, 0.93490608, 0.96476226, 0.98561151, 
                0.99726386;
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
    weights_ << 0.09095674, 0.09020304, 0.0887019 , 0.08646574, 0.0835131 , 
                0.07986844, 0.07556197, 0.07062938, 0.06511152, 0.05905414, 
                0.05250741, 0.04552561, 0.03816659, 0.03049138, 0.02256372, 
                0.01445016, 0.00622914;
    costeta_ << 0.04550982, 0.13615236, 0.22566669, 0.31331108, 0.39835928, 
                0.48010655, 0.5578755 , 0.63102173, 0.69893911, 0.76106488,
                0.81688423, 0.86593464, 0.90780968, 0.9421624 , 0.96870826,
                0.98722782, 0.99757175;
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
    weights_ << 0.08598328, 0.08534669, 0.08407822, 0.08218727, 0.07968783, 
                0.07659841, 0.07294189, 0.06874532, 0.0640398 , 0.05886014, 
                0.05324471, 0.04723508, 0.04087575, 0.03421381, 0.02729862, 
                0.02018152, 0.01291595, 0.00556572;
    costeta_ << 0.0430182 , 0.1287361 , 0.21350089, 0.296685  , 0.37767255, 
                0.4558639 , 0.53068029, 0.60156766, 0.66800124, 0.72948917, 
                0.78557623, 0.83584717, 0.8799298 , 0.91749777, 0.94827298, 
                0.97202769, 0.98858648, 0.99783046;
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
    weights_ << 0.08152503, 0.08098249, 0.07990103, 0.07828784, 0.07615366, 
                0.07351269, 0.07038251, 0.06678394, 0.06274093, 0.0582804 , 
                0.05343202, 0.04822806, 0.04270316, 0.03689408, 0.0308395 , 
                0.02457974, 0.01815658, 0.01161344, 0.00500288;
    costeta_ << 0.04078515, 0.12208403, 0.20257045, 0.28170881, 0.35897244, 
                0.43384717, 0.50583472, 0.57445602, 0.63925442, 0.69979868, 
                0.7556859 , 0.80654417, 0.85203502, 0.89185574, 0.92574133, 
                0.95346633, 0.97484633, 0.98973945, 0.99804993;
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
    weights_ << 0.07750595, 0.07703982, 0.07611036, 0.07472317, 0.07288658, 
                0.07061165, 0.06791205, 0.06480401, 0.06130624, 0.05743977, 
                0.05322785, 0.04869581, 0.04387091, 0.03878217, 0.0334602 , 
                0.02793701, 0.02224585, 0.01642106, 0.01049828, 0.00452128;
    costeta_ << 0.03877242, 0.11608407, 0.19269758, 0.26815219, 0.34199409, 
                0.4137792 , 0.4830758 , 0.54946713, 0.61255389, 0.67195668, 
                0.72731826, 0.77830565, 0.82461223, 0.8659595 , 0.90209881, 
                0.93281281, 0.95791682, 0.97725995, 0.99072624, 0.99823771;
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
    weights_ << 0.07386423, 0.07346081, 0.07265618, 0.07145471, 0.06986299, 
                0.0678897 , 0.06554562, 0.06284356, 0.05979826, 0.05642637, 
                0.0527463 , 0.04877814, 0.04454358, 0.04006574, 0.03536907, 
                0.03047924, 0.02542296, 0.02022787, 0.01492244, 0.00953622, 
                0.004106;
    costeta_ << 0.03694894, 0.11064503, 0.18373681, 0.25582508, 0.32651612, 
                0.39542385, 0.46217191, 0.52639575, 0.5877446 , 0.64588339, 
                0.70049459, 0.75127994, 0.79796205, 0.84028598, 0.87802057, 
                0.91095972, 0.93892356, 0.96175937, 0.97934251, 0.99157729, 
                0.99839962;
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
    weights_ << 0.07054916, 0.07019769, 0.06949649, 0.06844907, 0.06706064, 
                0.06533811, 0.06329008, 0.06092674, 0.05825986, 0.05530274, 
                0.0520701 , 0.04857805, 0.04484398, 0.04088651, 0.03672535, 
                0.03238122, 0.02787578, 0.02323148, 0.01847148, 0.01361959, 
                0.00870048, 0.0037454;
    costeta_ << 0.03528924, 0.1056919 , 0.17556801, 0.24456946, 0.31235247, 
                0.37857935, 0.44292017, 0.50505439, 0.56467245, 0.62147735, 
                0.67518607, 0.72553105, 0.77226148, 0.81514454, 0.8539666 , 
                0.88853424, 0.91867526, 0.94423951, 0.96509965, 0.98115183, 
                0.99231639, 0.9985402;
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
    weights_ << 0.06751869, 0.06721061, 0.06659587, 0.06567727, 0.064459  , 
                0.06294662, 0.06114703, 0.05906843, 0.05672033, 0.05411342, 
                0.0512596 , 0.0481719 , 0.0448644 , 0.04135219, 0.03765131, 
                0.03377863, 0.02975183, 0.02558929, 0.02131   , 0.01693351, 
                0.01247988, 0.0079699 , 0.0034303;
    costeta_ << 0.03377219, 0.10116248, 0.16809118, 0.23425292, 0.29934582, 
                0.36307288, 0.42514331, 0.48527392, 0.54319033, 0.59862829, 
                0.65133485, 0.70106951, 0.74760536, 0.79073006, 0.83024684, 
                0.86597539, 0.89775271, 0.9254338 , 0.94889236, 0.96802139, 
                0.98273367, 0.99296235, 0.99866304;
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
    weights_ << 0.0647377 , 0.06446616, 0.06392424, 0.06311419, 0.06203942, 
                0.06070444, 0.05911484, 0.05727729, 0.0551995 , 0.05289019, 
                0.05035904, 0.04761666, 0.04467456, 0.04154508, 0.03824135, 
                0.03477722, 0.03116723, 0.02742651, 0.02357076, 0.01961616, 
                0.01557932, 0.01147723, 0.00732755, 0.00315335;
    costeta_ << 0.03238017, 0.0970047 , 0.16122236, 0.22476379, 0.28736249, 
                0.34875589, 0.40868648, 0.4669029 , 0.52316097, 0.57722473, 
                0.6288674 , 0.67787238, 0.72403413, 0.76715903, 0.8070662 , 
                0.84358826, 0.87657202, 0.90587914, 0.93138669, 0.9529877 , 
                0.97059159, 0.98412458, 0.99353017, 0.99877101;
    teta_ << 0.00000;
}
} // namespace Demeter
