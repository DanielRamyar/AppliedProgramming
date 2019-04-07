//
//  NearestNeighbours.cpp
//  NearestNeighbours
//
//  Created by Daniel Ramyar on 04/06/18.
//  Copyright © 2018 Daniel Ramyar. All rights reserved.
//

#include "armadillo.hpp"

void LogisticRegression(std::string x_i, std::string test, std::string y);

int main(int argc, const char * argv[]) {
    
    
    LogisticRegression("dataX.dat", "dataY.dat", "dataXtest.dat");
    
    return 0;
}


void LogisticRegression(std::string X, std::string Y, std::string TEST) {
    
    arma::mat x, y, test;
    x.load(X, arma::raw_ascii);
    y.load(Y, arma::raw_ascii);
    test.load(TEST, arma::raw_ascii);
    
    std::cout << size(x) << "\n";
    std::cout << size(y) << "\n";
    std::cout << size(test) << "\n";
    
    // Initiating values
    arma::Col<int> labels(size(test)[0]);
    
    double alpha = 0.5;
    arma::vec w(size(x)[1]);
    w.fill(0);
    unsigned long long N = size(x)[0];
    double eta = 10e-7;
    double norm_L = 1.0;
    
    while (norm_L > eta) {
    
        arma::mat temporary_0(size(x)[1], 1);
        temporary_0.fill(0);
        arma::mat temporary_3(size(x)[1], 1);
        for (int j=0; j<N; j++) {
            arma::mat temporary_1 =  y(j) * w.t() * x.row(j).t();
            
            temporary_0 += as_scalar(y(j) *  1.0 /(1.0 + exp(temporary_1))) * x.row(j).t();
        }
    
        arma::mat derivative_L = - (1.0/N) * temporary_0;

        norm_L = norm(derivative_L);
        w -= alpha * derivative_L;
    }

    for (int i=0; i<size(test)[0]; i++) {
        auto x = as_scalar(sign(w.t() * test.row(i).t()));
        labels(i) = x;
    }
    std::cout << size(labels) << "\n";
    labels.save("LogReg.dat", arma::raw_ascii);
    
    
}
