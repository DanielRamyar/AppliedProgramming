//
//  NearestNeighbours.cpp
//  NearestNeighbours
//
//  Created by Daniel Ramyar on 04/06/18.
//  Copyright © 2018 Daniel Ramyar. All rights reserved.
//

#include "armadillo.hpp"

void NearestNeightbours(std::string x_i, std::string test, std::string y);

int main(int argc, const char * argv[]) {
    
    
    NearestNeightbours("dataX.dat", "dataY.dat", "dataXtest.dat");
    
    return 0;
}


void NearestNeightbours(std::string X, std::string Y, std::string TEST) {
    
    arma::mat x, y, test;
    x.load(X, arma::raw_ascii);
    y.load(Y, arma::raw_ascii);
    test.load(TEST, arma::raw_ascii);
    
    std::cout << size(x) << "\n";
    std::cout << size(y) << "\n";
    std::cout << size(test) << "\n";
    
    arma::Col<int> labels(size(test)[0]);
    
    int k = 5;
    
    for (int i=0; i<size(test)[0]; i++) {
    
        // Creating distance matrix and subtracting whole matrix by test point and find distance to test point
        arma::mat d = x.each_row() - test.row(i);
        d = arma::pow(d, 2);
        d = arma::sum(d, 1);
        d = arma::sqrt(d);
        
        // Sorting d in ascending order
        arma::uvec indicies = sort_index(d, "ascend");

        
        // Counting which label appear most often
        int counter=0;
        int j=0;
        while (j < k) {
            counter += y(indicies(j));
            j++;
        }

        // Sets the label for test sample according to the nearest neighbour majority
        if (counter > 0) {
            labels(i) = 1;
        }
        else {
            labels(i) = -1;
        }
    }
    
    
    labels.save("NN.dat", arma::raw_ascii);
    
    
}
