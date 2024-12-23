#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# Resume: The script the roots and weights of the legendre polynomials
# of order n. 
# See https://mathworld.wolfram.com/Legendre-GaussQuadrature.html

from scipy.special import roots_legendre

roots, weights = roots_legendre(2)
#print(roots_legendre(2))
#print(roots_legendre(4))

a = 0
for i in range(24):
  a +=2
  print("// nteta = " + str(a))
  print("template <>")
  print("Eigen::ArrayXd GaussLegendre<"+str(a)+">::weights_("+str(round(a/2))+");") 
  print("template <>")                                            
  print("Eigen::ArrayXd GaussLegendre<"+str(a)+">::costeta_("+str(round(a/2))+");") 
  print("template <>")
  print("Eigen::ArrayXd GaussLegendre<"+str(a)+">::teta_("+str(round(a/2))+");") 
  print("template <>")
  print("void GaussLegendre<"+str(a)+">::initialization() {")
  print("    weights_ << 0.00000;")
  print("    costeta_ << 0.00000;")
  print("    teta_ << 0.00000;")
  print("}")
  #roots, weights = roots_legendre(2)
  #print(roots)
  #roots, weights = roots_legendre(4)
  #print(roots)
