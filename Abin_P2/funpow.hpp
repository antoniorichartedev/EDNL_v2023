//
// Created by Anton on 07/03/2023.
//

#ifndef ABIN_P2_FUNPOW_HPP
#define ABIN_P2_FUNPOW_HPP


unsigned powi(unsigned a, unsigned b){
    unsigned res = 1;
    for(unsigned i = 0; i < b; i++)
        res *= a;

    return res;
}
#endif //ABIN_P2_FUNPOW_HPP
