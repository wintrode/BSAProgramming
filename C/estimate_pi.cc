#include <iostream>
#include <random>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {

  std::random_device rd;  // Will be used to obtain a seed for the random number engine
  std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
  std::uniform_real_distribution<> dis(0.0, 1.0);
  
  int N;
  
  cout << "Enter a number of points: ";
  cin >> N;

  int hit=0;
  double x,y,d;
  for (int i=0; i < N; i++) {
    // generate a random point (x,y) between (0,0) and (1,1)
    x = dis(gen);
    y = dis(gen);
    d = sqrt(x*x+ y*y);
    if ( d < 1)
      hit++;
  }

  double pi = 4 * (double) hit / (double)N;

  cout << "Your estimate for pi is " << pi << "\n";
  
  return 0;
}
