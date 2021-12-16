#ifndef _MARKOV_H_
#define _MARKOV_H_

#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <stdio.h>

enum chord {
    one = 0x01,
    two = 0x02,
    three = 0x04,
    four = 0x08,
    five = 0x10,
    six = 0x20,
    seven = 0x40,
};

// probability out of the size of a short
struct m_conn {
    uint16_t _probability;
    struct m_node* _node;
};
typedef struct m_conn m_conn;

struct m_node {
    enum chord _chord;
    struct m_conn* _conns;
};
typedef struct m_node m_node;

// get next node, respecting probability
m_node* m_next(const m_node*);

#endif //!_MARKOV_H_