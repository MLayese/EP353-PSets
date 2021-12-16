#include <stdio.h>
#include <stdlib.h>

#include "chain.h"

#define NOTE_COUNT 7

// sample version of how to progress
m_node* init(){
    printf("init...\n");
    m_node* nodes = (m_node*)malloc(7 * sizeof(m_node));
    m_node* curr;

    //I chord
    curr = nodes;
    curr->_chord = one;
    curr->_conns = (m_conn*)malloc(sizeof(m_conn) * 2);
    curr->_conns[0]._probability = (UINT16_MAX) / 2;
    //printf("I prob : %u\n", curr->_conns[0]._probability);
    curr->_conns[0]._node = nodes + 1; //ii
    curr->_conns[1]._probability = (UINT16_MAX) / 2;
    curr->_conns[1]._node = nodes + 5; //vi

    //ii chord
    curr++;
    curr->_chord = two;
    curr->_conns = (m_conn*)malloc(sizeof(m_conn) * 2);
    curr->_conns[0]._probability = ((UINT16_MAX) / 4) * 3;
    curr->_conns[0]._node = nodes + 4; //V
    curr->_conns[1]._probability = ((UINT16_MAX) / 4);
    curr->_conns[1]._node = nodes + 6; //vii

    //iii chord
    curr++;
    curr->_chord = three;
    curr->_conns = (m_conn*)malloc(sizeof(m_conn) * 1);
    curr->_conns[0]._probability = UINT16_MAX;
    curr->_conns[0]._node = nodes + 5; //vi

    //IV chord
    curr++;
    curr->_chord = four;
    curr->_conns = (m_conn*)malloc(sizeof(m_conn) * 2);
    curr->_conns[0]._probability = ((UINT16_MAX) / 4) * 3;
    curr->_conns[0]._node = nodes + 0; //I
    curr->_conns[1]._probability = ((UINT16_MAX) / 4);
    curr->_conns[1]._node = nodes + 5; //vi

    //V chord
    curr++;
    curr->_chord = five;
    curr->_conns = (m_conn*)malloc(sizeof(m_conn) * 3);
    curr->_conns[0]._probability = ((UINT16_MAX) / 3) * 2;
    curr->_conns[0]._node = nodes + 0; //I
    curr->_conns[1]._probability = ((UINT16_MAX) / 6);
    curr->_conns[1]._node = nodes + 3; //IV
    curr->_conns[2]._probability = ((UINT16_MAX) / 6);
    curr->_conns[2]._node = nodes + 5; //vi

    //vi chord
    curr++;
    curr->_chord = six;
    curr->_conns = (m_conn*)malloc(sizeof(m_conn) * 4);
    curr->_conns[0]._probability = ((UINT16_MAX) / 10) * 3;
    curr->_conns[0]._node = nodes + 0; //I
    curr->_conns[1]._probability = ((UINT16_MAX) / 10);
    curr->_conns[1]._node = nodes + 1; //ii
    curr->_conns[2]._probability = ((UINT16_MAX) / 10) * 5;
    curr->_conns[2]._node = nodes + 4; //V
    curr->_conns[3]._probability = ((UINT16_MAX) / 10);
    curr->_conns[3]._node = nodes + 6; //vii

    //vii
    curr++;
    curr->_chord = seven;
    curr->_conns = (m_conn*)malloc(sizeof(m_conn) * 2);
    curr->_conns[0]._probability = ((UINT16_MAX) / 3) * 2;
    curr->_conns[0]._node = nodes + 0; //I
    curr->_conns[1]._probability = ((UINT16_MAX) / 6);
    curr->_conns[1]._node = nodes + 3; //IV
    curr->_conns[2]._probability = ((UINT16_MAX) / 6);
    curr->_conns[2]._node = nodes + 5; //vi

    return nodes;
}

int main(int argc, char** argv){
    m_node* mchain = init();
    m_node* current = mchain;

    srand(time(NULL));

    int i_count = 0;
    unsigned long ccount = 0;

    while(i_count < 2){
        switch(current->_chord){
            case one:
                printf("I ");
                i_count++;
                break;
            case two:
                printf("ii ");
                break;
            case three:
                printf("iii ");
                break;
            case four:
                printf("IV ");
                break;
            case five:
                printf("V ");
                break;
            case six:
                printf("vi ");
                break;
            case seven:
                printf("vii ");
                break;
        }
        current = m_next(current);
        ccount++;
    }

    printf("\nDone with %lu!\n", ccount);
}