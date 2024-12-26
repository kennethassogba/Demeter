#ifndef GLOBALS_H
#define GLOBALS_H

#include <Eigen/Dense>

namespace Demeter {

// 1. definir grandeurs utiles pour methode 
//    puissance iteree et calcul sources
//
// 2. voir comment fixer les valeurs a partir
//    jeu de donnees: a la fin, ce sera les 
//    donnees rentrees par lutilisateur qui 
//    fixeront la valeur des variables et la taille
//    des tableaux
// 3. a quel moments faire cette initialisation
//    des le debubt du jdd ou apres definition
//    geo, materiaux ?


// phase space treatment
extern size_t nbgroup;  // nber of energy groups
extern size_t nbangle;  // nber of angles
extern size_t nbreg;    // nber of regions

extern size_t nphi;     // nber of azimuthal angles
extern size_t nteta;    // nber of polar angles

// scattering treatment
extern size_t naniso;   // anisotropy order 
extern size_t nmomsa;   // nber of angular moments
extern size_t nmomsp;   // nber of spatial moments
extern size_t nmoms;    // total nber of moments

double keffs;           // keff from solver 
double keffb;           // keff from balance
double kinf;            // infinite multiplication factor

// flux, moments, sources
// Multi-group arrays
extern ArrayXd mg_fiss_src(nbgroup*nbreg*nmoms);     // fission source
extern ArrayXd mg_osca_src(nbgroup*nbreg*nmoms);     // out-of-group scattering source
extern ArrayXd mg_wsca_src(nbgroup*nbreg*nmoms);     // within-group scattering source
extern ArrayXd mg_exte_src(nbgroup*nbreg*nmoms);     // fission and ouf-of-groupe source
extern ArrayXd mg_moments(nbgroup*nbreg*nmoms);      // moments of the angular flux

// Mono-group arrays
extern ArrayXd fiss_src(nbgroup*nbreg*nmoms);        // fission source
extern ArrayXd osca_src(nbgroup*nbreg*nmoms);        // out-of-group scattering source
extern ArrayXd wsca_src(nbgroup*nbreg*nmoms);        // within-group scattering source
extern ArrayXd exte_src(nbgroup*nbreg*nmoms);        // fission and ouf-of-groupe source
extern ArrayXd moments(nbgroup*nbreg*nmoms);         // moments of the angular flux


} // namespace Demeter
#endif // GLOBALS_H
