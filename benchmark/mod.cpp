#include <iostream>
#include <array>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std::chrono;

constexpr size_t iter = 1e8;

int main() {
  std::minstd_rand rnd_engine{1234};
  std::uniform_int_distribution<int> dist {-1000, 1000};
  auto gen = [&]() { return dist(rnd_engine); };

  std::array<int, 10> a;
  std::generate( a.begin(), a.end(), gen);

  for (size_t size = 2; size < 10; size++) {
    std::cout << "Modulus size = " << size << '\n';
  
    {
      std::cout << "operator%  ";
      long sum = 0;
      size_t x = 0;
      auto start = high_resolution_clock::now();
      for (size_t i = 0; i < iter; ++i) {
        sum += a[x];
        x = (x + 1) % size;
      }
      auto stop = high_resolution_clock::now();
      std::cout << duration_cast<microseconds>(stop - start).count()*0.001
                << "ms\t(sum = " << sum << ")\n";
    }
  
    {
      std::cout << "ternary    ";
      long sum = 0;
      size_t x = 0;
      auto start = high_resolution_clock::now();
      for (size_t i = 0; i < iter; ++i) {
        sum += a[x];
        x = ((x + 1) == size) ? 0 : x + 1;
      }
      auto stop = high_resolution_clock::now();
      std::cout << duration_cast<microseconds>(stop - start).count()*0.001
                << "ms\t(sum = " << sum << ")\n";
    }
    
    {
      std::cout << "branchless ";
      long sum = 0;
      size_t x = 1;
      auto start = high_resolution_clock::now();
      for (size_t i = 0; i < iter; ++i) {
        sum += a[x-1];
        x = ( x != size ) * x + 1;
      }
      auto stop = high_resolution_clock::now();
      std::cout << duration_cast<microseconds>(stop - start).count()*0.001
                << "ms\t(sum = " << sum << ")\n";
    }

  }
  return 0;
}