//
//  load_data.hpp
//  NearestNeighbours
//
//  Created by Daniel Ramyar on 04/06/18.
//  Copyright © 2018 Daniel Ramyar. All rights reserved.
//

#ifndef load_data_hpp
#define load_data_hpp

#include "armadillo.hpp"
#include <cassert>

template <typename T>
arma::Mat<T> load_data(std::string file) {

    std::ifstream read_file(file);
    assert(read_file.is_open());
    
    arma::Mat<T> A;
    
    int i=0;
    int j=0;
    std::string line;
    
    while (std::getline(read_file, line)) {
        std::istringstream iss(line);
        double number;
        
        while (iss >> number) {
            A(i,j) = number;
            j++;
        }
        
        i++;
    }
    read_file.close();
    
    
    return A;
}

#endif /* load_data_hpp */
