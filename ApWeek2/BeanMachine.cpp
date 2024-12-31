#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int* determineBallBuckets(const int numofballs, const int numoflevels) 
{
    int* balls = new int[numofballs];

    for (int i = 0; i < numofballs; i++) 
    {
        int pos = 0;  
        for (int j = 0; j < numoflevels; j++) 
        {
            if (rand() % 2 == 0)
            {
                pos += 1; 
            }
        }
        balls[i] = pos;  
    }
    return balls; 
}

int* tallyBalls(const int noofballs, const int* balls, const int noofbuckets)
{
    int* bucketCount = new int[noofbuckets];  

    for (int i = 0; i < noofbuckets; i++) 
    {
        bucketCount[i] = 0;
    }

    for (int i = 0; i < noofballs; i++)
    {
        int bucket = balls[i];
        bucketCount[bucket]++;
    }

    return bucketCount; 
}

int main() 
{
    srand(time(0));  

    cout << "How many balls would like to drop?:\n";
    int balls;
    cin >> balls;

    cout << "How many levels would you like to drop them?:\n";
    int levels;
    cin >> levels;

    int bucketCount = levels + 1; 

    int* ballPositions = determineBallBuckets(balls, levels);

    int* ballDistribution = tallyBalls(balls, ballPositions, bucketCount);

    cout << "Ball distribution:\n";
    for (int i = 0; i < bucketCount; i++)
    {
        cout << "Bucket " << i << ": " << ballDistribution[i] << " balls\n";
    }

    delete[] ballPositions;
    delete[] ballDistribution;

    return 0;
}
