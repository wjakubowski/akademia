#ifndef HELPER_H
#define HELPER_H

void swap(int*, int*);

void swap_ref(int&, int&);

template<class Type>
void swap_template(Type*, Type*);

//Nie umiem przeniesc implementacji do innego pliku/ bledy linkera
template<class Type>
void swap_template(Type * p1, Type * p2){
    Type tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

#endif // HELPER_H
