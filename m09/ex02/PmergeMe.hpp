
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <utility>
#include <sys/time.h>
#include <cstddef>
#include <cstdlib>
#include <cerrno>
#include <climits>

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        static void sortAndMeasure(const std::vector<int>& input);

    private:
        static std::vector<int> fordJohnsonSortVector(const std::vector<int>& input);
        static std::deque<int>  fordJohnsonSortDeque(const std::deque<int>& input);

        static std::vector<size_t> buildJacobsthalOrder(size_t pendingCount);

        template <typename Seq>
        static size_t lowerBoundIndex(const Seq& seq, int value, size_t left, size_t right);

        template <typename Seq>
        static void insertAt(Seq& seq, size_t pos, int value);

        static double nowMicros();
};
