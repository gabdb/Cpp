
#pragma once

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <sys/time.h>
#include <climits>
#include <utility>
#include <cstdlib>
#include <cerrno>


class PmergeMe
{
public:
    static void sortAndMeasure(const std::vector<int>& input);

private:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    static std::vector<int> fordJohnsonSortVector(const std::vector<int>& input);
    static void mergeSortPairsVector(std::vector< std::pair<int,int> >& pairs);

    static std::deque<int> fordJohnsonSortDeque(const std::deque<int>& input);
    static void mergeSortPairsDeque(std::deque< std::pair<int,int> >& pairs);

    static std::vector<size_t> buildJacobsthalOrder(size_t pendingCount);

    template <typename Seq>
    static size_t lowerBoundIndex(const Seq& seq, int value, size_t left, size_t right);

    template <typename Seq>
    static void insertAt(Seq& seq, size_t pos, int value);

    static long long nowMicros();
};