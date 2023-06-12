#include "MagicalContainer.hpp"
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
using namespace ariel;


void MagicalContainer::addElement(int elem) {
    this->originalContainer.push_back(elem);
    this->updateOriginalContainer();        //update Original elements
    this->updateAscendingContainer();       //update Ascending elements
    this->updateSideCrossContainer();       //update SideCross elements
    this->updatePrimeContainer();           //update Prime elements
}

void MagicalContainer::removeElement(int elem) {
    auto ptr = std::find(originalContainer.begin(), originalContainer.end(), elem);
        if (ptr == originalContainer.end())
        {
            throw runtime_error("The element wasn't found");
            return;
        }
        originalContainer.erase(std::remove(originalContainer.begin(), originalContainer.end(), elem), originalContainer.end());
        this->updateOriginalContainer();        //update original elements
        this->updateAscendingContainer();       //update Ascending elements
        this->updateSideCrossContainer();       //update SideCross elements
        this->updatePrimeContainer();           //update Prime elements
}

bool MagicalContainer::isPrime(int elem) {
    if (elem <= 1) {
        return false;
    }
    for (int i = 2; i <= std::sqrt(elem); ++i) {
        if (elem % i == 0) {
            return false;
        }
    }
    return true;
}

int MagicalContainer::size() {
    return this->originalContainer.size();
}

void MagicalContainer::updateOriginalContainer(){
    size_t n = originalContainer.size();
    for (size_t i = 0; i < n; ++i){
        for (size_t j = 0; j < n - i - 1; ++j){
            if (originalContainer[j] > originalContainer[j + 1]){
                swap(originalContainer[j], originalContainer[j + 1]);
            }
        }
    }
}

void MagicalContainer::updateAscendingContainer(){
    this->ascendingContainer.clear();
    for (auto ptr = originalContainer.begin(); ptr != originalContainer.end(); ++ptr){
        this->ascendingContainer.push_back(&(*ptr));
    }
}

void MagicalContainer::updateSideCrossContainer(){    
    this->sideCrossContainer.clear();
    auto begin = originalContainer.begin();
    auto end = originalContainer.end();
    --end;
    while (begin <= end){
        this->sideCrossContainer.push_back(&(*begin));
        if (begin != end){
            this->sideCrossContainer.push_back(&(*end));
        }
        ++begin;
        --end;
    }
}

void MagicalContainer::updatePrimeContainer(){
    this->primeContainer.clear();
    for (auto ptr = originalContainer.begin(); ptr != originalContainer.end(); ++ptr){
        if (isPrime(*ptr)){
            this->primeContainer.push_back(&(*ptr));
        }
    }
}

//-----------------Ascending iterator------------------------------------------------------------------------------

MagicalContainer::AscendingIterator::AscendingIterator( MagicalContainer& magicalContainer):magicalContainer(&magicalContainer), ptr(magicalContainer.ascendingContainer.begin()), pos(0) {}

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other):magicalContainer(other.magicalContainer), ptr(other.ptr), pos(other.pos) {}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other) {
    if(this->magicalContainer != other.magicalContainer){
        throw runtime_error("Error : iterators not from the same containers");
    }
    else if(this != &other){
        this->magicalContainer = other.magicalContainer;
        this->ptr = other.ptr;
    }
    return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
    if(this->magicalContainer != other.magicalContainer){
        throw invalid_argument("Error : iterators not from the same containers");
    }
    return pos == other.pos;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
    if(this->operator==(other)){
        return false;
    } else {
        return true;
    }
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
    if(this->magicalContainer != other.magicalContainer){
        throw invalid_argument("Error : iterators not from the same containers");
    }
    return pos > other.pos;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
    if(this->magicalContainer != other.magicalContainer){
        throw invalid_argument("Error : iterators not from the same containers");
    }
    return pos < other.pos;
}

int MagicalContainer::AscendingIterator::operator*() const {
    if (this->ptr == this->magicalContainer->ascendingContainer.end()){
        throw std::runtime_error("Error : Out of range for the iterator");
    }
    return **this->ptr;
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
    if(this->ptr == this->magicalContainer->ascendingContainer.end()){
        throw runtime_error("Error : Out of range for the iterator");
    }
    this->ptr++;
    ++pos;
    return *this;
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::begin() {
    ptr = magicalContainer->ascendingContainer.begin();   
    pos = 0;
    return *this;
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::end() {
    ptr = magicalContainer->ascendingContainer.end();
    pos = magicalContainer->ascendingContainer.size();
    return *this;
}

//-----------------SideCross iterator-----------------------------------------------------------------------------------------------------------

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& magicalContainer):magicalContainer(&magicalContainer), ptr(magicalContainer.sideCrossContainer.begin()), pos(0) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other):magicalContainer(other.magicalContainer), ptr(other.ptr), pos(other.pos) {}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other) {
    if(this->magicalContainer != other.magicalContainer){
        throw runtime_error("Error : iterators not from the same containers");
    }
    else if(this != &other){
        this->magicalContainer = other.magicalContainer;
        this->ptr = other.ptr;
    }
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
    if(this->magicalContainer != other.magicalContainer){
        throw invalid_argument("Error : iterators not from the same containers");
    }
    return pos == other.pos;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
    if(this->operator==(other)){
        return false;
    } else {
        return true;
    }
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
    if(this->magicalContainer != other.magicalContainer){
        throw invalid_argument("Error : iterators not from the same containers");
    }
    return pos > other.pos;
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
    if(this->magicalContainer != other.magicalContainer){
        throw invalid_argument("Error : iterators not from the same containers");
    }
    return pos < other.pos;
}

int MagicalContainer::SideCrossIterator::operator*() const {
    if (this->ptr == this->magicalContainer->sideCrossContainer.end()){
        throw std::runtime_error("Error : Out of range for the iterator");
    }
    return **this->ptr;
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
    if(this->ptr == this->magicalContainer->sideCrossContainer.end()){
        throw runtime_error("Error : Out of range for the iterator");
    }
    this->ptr++;
    ++pos;
    return *this;
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::begin() {
    ptr = magicalContainer->sideCrossContainer.begin();   
    pos = 0;
    return *this;
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::end() {
    ptr = magicalContainer->sideCrossContainer.end();
    pos = magicalContainer->sideCrossContainer.size();
    return *this;
}

//-----------------Prime iterator-----------------------------------------------------------------------------------------------------------

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& magicalContainer):magicalContainer(&magicalContainer), ptr(magicalContainer.primeContainer.begin()), pos(0) {}

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other):magicalContainer(other.magicalContainer),ptr(other.ptr), pos(other.pos) {}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other) {
    if(this->magicalContainer != other.magicalContainer){
        throw runtime_error("Error : iterators not from the same containers");
    }
    else if(this != &other){
        this->magicalContainer = other.magicalContainer;
        this->ptr = other.ptr;
    }
    return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
    if(this->magicalContainer != other.magicalContainer){
        throw invalid_argument("Error : iterators not from the same containers");
    }
    return pos == other.pos;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
    if(this->operator==(other)){
        return false;
    } else {
        return true;
    }
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
    if(this->magicalContainer != other.magicalContainer){
        throw invalid_argument("Error : iterators not from the same containers");
    }
    return pos > other.pos;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
    if(this->magicalContainer != other.magicalContainer){
        throw invalid_argument("Error : iterators not from the same containers");
    }
    return pos < other.pos;
}

int MagicalContainer::PrimeIterator::operator*() const {
    if (this->ptr == this->magicalContainer->primeContainer.end()){
        throw std::runtime_error("Error : Out of range for the iterator");
    }
    return **this->ptr;
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
    if(this->ptr == this->magicalContainer->primeContainer.end()){
        throw runtime_error("Error : Out of range for the iterator");
    }
    this->ptr++;
    ++pos;
    return *this;
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::begin() {
    ptr = magicalContainer->primeContainer.begin();   
    pos = 0;
    return *this;
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::end() {
    ptr = magicalContainer->primeContainer.end();
    pos = magicalContainer->primeContainer.size();
    return *this;
}