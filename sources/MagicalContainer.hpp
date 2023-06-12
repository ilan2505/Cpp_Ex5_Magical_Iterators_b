#ifndef MAGICAL_CONTAINER
#define MAGICAL_CONTAINER

#include <cstddef>
#include <stdexcept>
#include <iterator>
#include <set>
#include <list>
#include <vector>

using namespace std;


namespace ariel {

    class MagicalContainer {

        vector<int> originalContainer;      //stores original insertion order
        vector<int*> ascendingContainer;    //stores in ascending order
        vector<int*> sideCrossContainer;    //stores in cross order
        vector<int*> primeContainer;        //stores prime numbers in original order    

    public:
        MagicalContainer() = default;
        ~MagicalContainer() = default;
        
        void addElement(int elem);
        void removeElement(int elem);
        static bool isPrime(int elem);
        int size();

        void updateOriginalContainer();               
        void updateAscendingContainer();
        void updateSideCrossContainer();
        void updatePrimeContainer();

        class AscendingIterator;
        class SideCrossIterator;
        class PrimeIterator;
    };


    class MagicalContainer::AscendingIterator {
        
    MagicalContainer* magicalContainer;
    vector<int*>::iterator ptr;
    size_t pos;

    public:
        AscendingIterator(MagicalContainer& magicalContainer);
        AscendingIterator(const AscendingIterator& other);
        ~AscendingIterator() = default;
        AscendingIterator(AscendingIterator&& other) noexcept = default;
        AscendingIterator& operator=(const AscendingIterator& other);
        AscendingIterator& operator=(AscendingIterator&& other) = default;
        bool operator==(const AscendingIterator& other) const;
        bool operator!=(const AscendingIterator& other) const;
        bool operator>(const AscendingIterator& other) const;
        bool operator<(const AscendingIterator& other) const;
        int operator*() const;
        AscendingIterator& operator++();
        AscendingIterator& begin();
        AscendingIterator& end();
    };


    class MagicalContainer::SideCrossIterator {

    MagicalContainer* magicalContainer;
    vector<int*>::iterator ptr;
    size_t pos;

    public:
        SideCrossIterator(MagicalContainer& magicalContainer);
        SideCrossIterator(const SideCrossIterator& other);
        ~SideCrossIterator() = default;
        SideCrossIterator(SideCrossIterator &&other) noexcept = default;
        SideCrossIterator& operator=(const SideCrossIterator& other);
        SideCrossIterator& operator=(SideCrossIterator &&other) = default;
        bool operator==(const SideCrossIterator& other) const;
        bool operator!=(const SideCrossIterator& other) const;
        bool operator>(const SideCrossIterator& other) const;
        bool operator<(const SideCrossIterator& other) const;
        int operator*() const;
        SideCrossIterator& operator++();
        SideCrossIterator& begin();
        SideCrossIterator& end();
    };


    class MagicalContainer::PrimeIterator {

    MagicalContainer* magicalContainer;
    vector<int*>::iterator ptr;
    size_t pos;

    public:
        PrimeIterator(MagicalContainer& magicalContainer);
        PrimeIterator(const PrimeIterator& other);
        ~PrimeIterator() = default;
        PrimeIterator(PrimeIterator &&other) noexcept = default;
        PrimeIterator& operator=(const PrimeIterator& other);
        PrimeIterator& operator=(PrimeIterator &&other) noexcept;
        bool operator==(const PrimeIterator& other) const;
        bool operator!=(const PrimeIterator& other) const;
        bool operator>(const PrimeIterator& other) const;
        bool operator<(const PrimeIterator& other) const;
        int operator*() const;
        PrimeIterator& operator++();
        PrimeIterator& begin();
        PrimeIterator& end();
    };

}


#endif //MAGICAL_CONTAINER
