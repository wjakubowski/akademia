#include <iterator>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

template <typename Col>
void print(const Col& col) {
    for (const auto& item : col) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

int main() {
    {
        // Iterator archetype - pointer
        int data[] = {1, 2, 3};
        int* ptr = data;
        int first = *ptr;    // data[0]
        ++ ptr;
        int second = *ptr;   // data[1]
        *ptr = 5;            // data = {1, 5, 3}
        *(ptr + 1) = 8;      // data = {1, 5, 8}
    }

    // Ordinary vector iterators
    std::vector<int> vec{1, 2, 3, 4, 5, 6};

    auto it = vec.begin(); // std::vector<int>::iterator it = ...

    // Pointer-like syntax:
    int first = *it;       // vec[0]
    ++ it;
    int second = *it;      // vec[1]
    *it = 5;               // vec = {1, 5, 3, 4, 5, 6}
    *(it + 3) = 9;         // vec = {1, 5, 3, 4, 9, 6}
    // it + offset - only RandomAccess iterators (doesn't work e.g. for std::list)

    for (auto it = begin(vec); it != end(vec); ++ it) { // same as vec.begin()
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    vec.assign({1, 2});                    // vec = {1, 2}

    // More weird iterators
    auto ins_it = std::back_inserter(vec); // std::back_insert_iterator<std::vector<int>>

    *ins_it = 5;                  // pushes back 5
    *ins_it = 6;                  // pushes back 6

    ++ ins_it;                    // does nothing
    ins_it = 7;                   // does the same as *ins_it = 7, operator * does nothing
    print(vec);                   // 1 2 5 6 7

    // IO iterators
    {
        std::istringstream input{"Ala jest w posiadaniu kota"};
        std::istream_iterator<std::string> in{input};
        std::istream_iterator<std::string> end{}; // default ctor = end-of-stream iterator

        while (in != end) {
            // it++ fetches next string from input
            std::cout << "Word: " << *in++ << std::endl;
        }
    }
    {
        // Works with ints etc as well
        std::istringstream input{"13 27 11 -5"};
        std::istream_iterator<int> in{input};
        std::istream_iterator<int> end{};
        while (in != end) {
            int val = *in++;
            std::cout << "Value: " << val << std::endl;
        }
    }
    // Can do output, too
    std::ostream_iterator<int> out{std::cout};
    for (auto item : vec) {
        out = item;
        // *out++ = item; // same as above - * and ++ does nothing, like for back_inserter
    }
    std::cout << std::endl;
}
