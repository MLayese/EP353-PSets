#include "chain.h"

m_node* m_next(const m_node* rhs){
    int i = 1;

    long v = rand() % UINT16_MAX - 1;
    //printf("v : %li\n", v);

    long total = rhs->_conns[i]._probability;

    while(v >= total){
        //printf("prob : %u\n", rhs->_conns[i]._probability);
        total += rhs->_conns[i]._probability;
        ++i;
    }

    return rhs->_conns[i - 1]._node;
}