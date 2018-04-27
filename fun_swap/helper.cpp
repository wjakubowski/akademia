#include "helper.h"

void swap(int * p1, int * p2){
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void swap_ref(int & r1, int & r2){
    int tmp = r1;
    r1 = r2;
    r2 = tmp;
}
