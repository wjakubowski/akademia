#include <algorithm>
#include <iterator>
#include <string>
#include <iostream>
#include <vector>

struct Person {
    std::string name;
    int age;
};

template <typename Col>
void print(const Col& col) {
    for (const auto& item : col) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}


void example() {
    int data[5] = {1, 2, 3, 4, 5};
    std::vector<int> vec{6, 6, 6, 6, 6, 6, 6, 6, 6};
    // fill vec with 7's instead, apart from first element
    std::fill(vec.begin() + 1, vec.end(), 7);

    // copy data[1],...,data[3] to vec[3],...,vec[5]
    std::copy(data + 1, data + 4, vec.begin() + 3);
    // vec = {6, 7, 7, 2, 3, 4, 7, 7, 7}
    print(vec);

    // append first 2 elemenst of data to vec
    std::copy_n(data, 2, std::back_inserter(vec));
    // vec = {6, 7, 7, 2, 3, 4, 7, 7, 7, 1, 2}
    print(vec);

    // How many 7's are there in vec?
    int sevens = std::count(vec.begin(), vec.end(), 7);
    std::cout << "# of 7's: " << sevens << std::endl;

    // Where is the first number less than 3?
    auto pos = std::find_if(vec.begin(), vec.end(), [](int n) { return n < 3; });
    int offset = std::distance(vec.begin(), pos);
    std::cout << "First <3 is element no. " << offset << " and it's " << *pos << std::endl;

    // Remove all 7's
    // Huge lie - std::remove doesn't remove anything! see docs
    auto end = std::remove(vec.begin(), vec.end(), 7);
    vec.erase(end, vec.end());
    print(vec);

    vec.clear(); // vec = {};
    // append all even elements of data to vec
    std::copy_if(std::begin(data), std::end(data), std::back_inserter(vec),
            [](int n) { return n % 2 == 0; });
    // vec = {2, 4}
    print(vec);

    // square elements of vec
    std::for_each(vec.begin(), vec.end(), [](int& n) { n = n * n; });

    // print vec to stdout
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>{std::cout, ", "});
    std::cout << std::endl;

    // print 10 random numbers
    std::generate_n(std::ostream_iterator<int>{std::cout, ", "}, 10, std::rand);
    std::cout << std::endl;
}



struct A{
    int n=0;
    int operator ()(){
        return n++;
    }
};

void ex2(){
    A a;
    for(int i=0; i<4;++i)
        std::cout<<a()<<std::endl;
}

//jak wzozec strategia
struct B {
    //int n;
    //B(int n) : n(n){}
    bool operator ()(int a, int n) const {
        return a < n;;
    }
};

struct C {
    int n;
    C(int n) : n(n){}
    bool operator ()(int a) const {
        return a < n;;
    }
};

void ex3(){
    std::vector<int> v{5,3,3,2,7,1};
    print(v);
    //std::sort(v.begin(), v.end(), C{3});
    //print(v);
    std::sort(v.begin(), v.end(), B{});
    print(v);
    for(int i=2;i<7;++i)
        std::cout<<i<<"\t"<<std::count_if(v.begin(), v.end(), [i](int a) {return a%i==0;}) << std::endl;
    /* [=] - wszystkie zmiennne uzywane w lambdzie,
     * [&i] - referencja do i,
     * [&,k, c=12,] -wszystko uzywane przez referencje(domyslnei), ale k  przez wartos, c - jak r-wartosc
    jak mutable to "c" bedize jak zmienna statyczne w funkcji - moze byc licznikiem, id generatorem*/



}

std::vector<int> primes(int N) {
    std::vector<int> numbers(N);
    std::generate_n(numbers.begin(), N, [i=2]() mutable {return i++;});


    auto id_divideble_by = [](int n, int& e){return e%n==0;};
    int pos;
    for(int& n : numbers){
             auto new_end = std::remove_if(numbers.begin()+(n-1), numbers.end(), [n](int& e){return e%n==0;});
             numbers.erase(new_end, numbers.end());

    }


    //numbers.erase(numbers.end(), numbers.begin()+N);
    //std::cout<<std::count_if(numbers.begin(), numbers.end(),[numbers,n=2](int& e){e%n==0;})<<std::endl;

    return numbers;
}

int main() {
    //example();
    ex2();
    ex3();

    print(primes(1001));
}
