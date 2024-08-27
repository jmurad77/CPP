#include "Threading_Async_Lambdas.h"

LambThreads::LambThreads()
{
    myInternalCounter = 0;

    myLocalThread = std::thread
    (
        []()
        {
            // Running async counting function in parallel
            std::future<void> printCountFut = std::async
            (std::launch::async,
                []()
                {
                    int count = 0;
                    while (count < 5)
                    {
                        printf("Current Count: %i\n", count);
                        this_thread::sleep_for(std::chrono::milliseconds(100));
                        count++;
                    }
                }      
            );

            // Running async vector printing in parallel
            int fourTwenty = 420;
            std::future<string> fut = std::async
            (std::launch::async,
                
                [&fourTwenty]()-> string
                {
                    printf("VALUE I: %i\n", fourTwenty);
                    vector<int> temp = {0,5,10,15,20};

                    printf("<><><><> For Loop with NO & <><><><>\n");
                    for (auto a : temp)
                    {
                        a = 69; // when there is no & for auto a its a copy not a refrence
                        printf("Element in Vec: %i\n", a);
                    }
                    printf("\n");

                    printf("<><><><> For Loop with & <><><><>\n");
                    for (auto& a : temp)
                    {
                        printf("Element in Vec: %i\n", a);
                    }
                    printf("\n");

                    printf("<><><><> For Loop with TWO && <><><><>\n");
                    for (auto&& a : temp)
                    {
                        printf("Element in Vec: %i\n", a);
                    }
                    printf("\n");

                    return "PASS\n";
                }
            ); 

            auto asyncVal = fut.get();
            printCountFut.get();
            printf("Value returned from async future: %s", asyncVal.c_str());

            // Counting Number fast
            Timer performance("COUNTERS ASYNC");
            std::atomic<uint32_t> numberCounter = 0;
            vector<std::future<void>> countingThreads;
            for (int i = 0; i < 4; i++)
            {
                countingThreads.push_back(
                    std::async(std::launch::async,
                        [&numberCounter]()
                        {
                            while (true)
                            {
                                if (numberCounter >= 10000000)
                                {
                                    break;
                                }
                                else
                                {
                                    numberCounter = numberCounter + 1;
                                }
                            }
                        }
                    )
                );
            }
            
            for(auto it = countingThreads.begin(); it != countingThreads.end(); it++)
            {
                it->get();
            }
            uint32_t rawNumber = numberCounter;
            printf("NUMBER COUNTER: %u\n", rawNumber);
        }
    );    
}

void LambThreads::Stop()
{
    if (myLocalThread.joinable())
    {
        myLocalThread.join();
    }
}

LambThreads::~LambThreads()
{
    if (myLocalThread.joinable())
    {
        myLocalThread.join();
    }
}

void Test_Performance_Vector()
{
    Timer vecPermTimer("Vector Performance");
    std::vector<Entity> list;

    std::cout << "list.push_back({10000,10.15f}): No reserve Worst case bec it copies for every resize\n";
    for (int i = 0; i < 3; i++)
    {    
        list.push_back({10000,10.15f});
    }

    list.clear();
    list.reserve(3);
    std::cout <<  "list.emplace_back(Entity(10000,10.15f)): Creates a copy of Entity that needs to be copies into the vector\n";
    for (int i = 0; i < 3; i++)
    {    
        list.emplace_back(Entity(10000,10.15f));
    }

    list.clear();
    std::cout << "list.push_back({10000,10.15f}): Same as emplace back above this creates a copy\n";
    for (int i = 0; i < 3; i++)
    {    
        list.push_back({10000,10.15f});
    }
    
    list.clear();
    std::cout << "list.emplace_back(10000,10.15f): No copy just creates Entity inside vector element\n";
    for (int i = 0; i < 3; i++)
    {
        list.emplace_back(10000,10.15f);
    }
}