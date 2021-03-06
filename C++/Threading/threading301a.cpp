#include <iostream>
#include <chrono>         // std::chrono
#include <future>
#include <string>

using namespace std;

int main(int argc, char**argv) // futures + async
{
  /////////////////////////////////////////////////////////////////////////////
  /// ASYNC

  future<int> f = async([]() -> int  { return 123; });
  cout << "f.get=" << f.get() << endl;

  future<int> futures[] = {
    async([]() { return 123; }),
    async([]() { return 456; }),
    async([]() { return 789; })
  };

  // for(auto f: futures) cout << f.get() << " ";  cout << endl;
  // for(future<int> f: futures) cout << f.get() << " ";  cout << endl;

  cout << futures[0].get() << " ";  
  cout << futures[1].get() << " ";  
  cout << futures[2].get() << " ";  
  cout << "\n";
}
