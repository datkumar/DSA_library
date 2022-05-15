#include <bits/stdc++.h>
using namespace std;

namespace Random // capital R to avoid conflicts with functions named random()
{
    // std::mt19937 mt{std::random_device{}()};

    std::random_device rd;

    // get 8 integers of random numbers from std::random_device for our seed
    std::seed_seq ss{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};

    // initialize our Mersenne Twister with the std::seed_seq
    std::mt19937 mt{ss};

    int get(int min, int max)
    {
        // we can create a distribution in any function that needs it
        // and then generate a random number from our global generator
        std::uniform_int_distribution generator{min, max};
        return generator(mt);
    }
}
int main()
{
    for (int count = 0; count < 40; ++count)
    {
        if (count % 5 == 0)
            cout << endl;
        std::cout << Random::get(1, (int)1e9 + 7) << " , ";
    }
    std::cout << Random::get(1, (int)1e9 + 7) << endl;

    return 0;
}