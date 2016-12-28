#include <iostream>
#include <vector>

int main() {
    std::vector<int> container;
    int M, N, input;
    std::cin >> M >> N;
    while(std::cin>>input) {
        container.push_back(input);
    }
    int size = static_cast<int>(container.size());
    for(int i=0, m=M-N;i<size;i++,m++) {
        std::cout << container[m%size];
        if(i!=size-1) std::cout << " ";
    }
    return 0;
}
