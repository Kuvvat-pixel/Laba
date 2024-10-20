#include <iostream>
#include <cmath>

int main() {
    double x, z, p, K, C, D, A, B, Y;
    
    std::cout << "Введите значения x, z, p, K, C, D: ";
    std::cin >> x >> z >> p >> K >> C >> D;
    
    A = sin(x) - z;
    B = std::abs(p - x);
    Y = pow(A + B, 2) - (K / (C * D));
    
    std::cout << "Результат Y: " << Y << std::endl;
    
    return 0;
}