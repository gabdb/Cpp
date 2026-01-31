
#include "PmergeMe.hpp"

#include <vector>
#include <deque>
#include <climits>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) { (void)other; }
PmergeMe& PmergeMe::operator=(const PmergeMe& other) { (void)other; return *this; }
PmergeMe::~PmergeMe() {}

double PmergeMe::nowMicros()
{
    timeval t;
    gettimeofday(&t, 0);
    return (t.tv_sec * 1000000.0 + t.tv_usec);
}


std::vector<size_t> PmergeMe::buildJacobsthalOrder(size_t pendingCount)
{
    std::vector<size_t> order;

    if (pendingCount == 0)
        return order;

    order.push_back(1);

    size_t prev = 1;
    size_t curr = 3;

    while (prev < pendingCount)
    {
        size_t blockHigh = (curr < pendingCount) ? curr : pendingCount;

        for (size_t i = blockHigh; i > prev; --i)
            order.push_back(i);

        size_t next = curr + 2 * prev;
        prev = curr;
        curr = next;
    }
    return order;
}

template <typename Seq>
size_t PmergeMe::lowerBoundIndex(const Seq& seq, int value, size_t left, size_t right)
{
    while (left < right)
    {
        size_t mid = left + (right - left) / 2;
        if (seq[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

template <typename Seq>
void PmergeMe::insertAt(Seq& seq, size_t pos, int value)
{
    typename Seq::iterator it = seq.begin();
    for (size_t i = 0; i < pos; ++i)
        ++it;
    seq.insert(it, value);
}

void printVectorSequence(const std::vector<int>& seq)
{
    for (size_t i = 0; i < seq.size(); ++i)
    {
        std::cout << seq[i];
        if (i + 1 < seq.size())
            std::cout << " ";
    }
}

size_t indexOfValueVector(const std::vector<int>& seq, int value)
{
    for (size_t i = 0; i < seq.size(); ++i)
        if (seq[i] == value)
            return i;
    return seq.size();
}

size_t indexOfValueDeque(const std::deque<int>& seq, int value)
{
    for (size_t i = 0; i < seq.size(); ++i)
        if (seq[i] == value)
            return i;
    return seq.size();
}

void reorderPairsBySortedBigsVector(std::vector< std::pair<int,int> >& pairs, const std::vector<int>& sortedBigs)
{
    std::vector< std::pair<int,int> > ordered;
    std::vector<char> used(pairs.size(), 0);

    ordered.reserve(pairs.size());

    for (size_t i = 0; i < sortedBigs.size(); ++i)
    {
        int big = sortedBigs[i];
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (!used[j] && pairs[j].second == big)
            {
                ordered.push_back(pairs[j]);
                used[j] = 1;
                break;
            }
        }
    }
    pairs.swap(ordered);
}

void reorderPairsBySortedBigsDeque(std::deque< std::pair<int,int> >& pairs, const std::deque<int>& sortedBigs)
{
    std::deque< std::pair<int,int> > ordered;
    std::vector<char> used(pairs.size(), 0);

    for (size_t i = 0; i < sortedBigs.size(); ++i)
    {
        int big = sortedBigs[i];
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (!used[j] && pairs[j].second == big)
            {
                ordered.push_back(pairs[j]);
                used[j] = 1;
                break;
            }
        }
    }
    pairs.swap(ordered);
}

std::vector<int> PmergeMe::fordJohnsonSortVector(const std::vector<int>& input)
{
    if (input.size() <= 1)
        return input;

    const bool hasStraggler = (input.size() % 2) != 0;
    int stragglerValue = 0;
    size_t processCount = input.size();

    if (hasStraggler)
    {
        stragglerValue = input[input.size() - 1];
        processCount = input.size() - 1;
    }

    std::vector< std::pair<int,int> > pairs;
    pairs.reserve(processCount / 2);

    for (size_t i = 0; i < processCount; i += 2)
    {
        int a = input[i];
        int b = input[i + 1];
        if (a > b)
        {
            int tmp = a; a = b; b = tmp;
        }
        pairs.push_back(std::make_pair(a, b));
    }

    if (pairs.size() > 1)
    {
        std::vector<int> bigs;
        bigs.reserve(pairs.size());
        for (size_t i = 0; i < pairs.size(); ++i)
            bigs.push_back(pairs[i].second);

        std::vector<int> sortedBigs = fordJohnsonSortVector(bigs);
        reorderPairsBySortedBigsVector(pairs, sortedBigs);
    }

    std::vector<int> mainChain;
    mainChain.reserve(input.size());

    mainChain.push_back(pairs[0].first);
    for (size_t i = 0; i < pairs.size(); ++i)
        mainChain.push_back(pairs[i].second);

    if (pairs.size() > 1)
    {
        const size_t pendingCount = pairs.size() - 1;
        const std::vector<size_t> order = buildJacobsthalOrder(pendingCount);

        for (size_t oi = 0; oi < order.size(); ++oi)
        {
            const size_t pairIndex = order[oi];
            if (pairIndex == 0 || pairIndex >= pairs.size())
                continue;

            const int smallValue = pairs[pairIndex].first;
            const int bigValue   = pairs[pairIndex].second;

            size_t boundIndex = indexOfValueVector(mainChain, bigValue);
            if (boundIndex > mainChain.size())
                boundIndex = mainChain.size();

            const size_t insertIndex = lowerBoundIndex(mainChain, smallValue, 0, boundIndex);
            insertAt(mainChain, insertIndex, smallValue);
        }
    }

    if (hasStraggler)
    {
        const size_t insertIndex = lowerBoundIndex(mainChain, stragglerValue, 0, mainChain.size());
        insertAt(mainChain, insertIndex, stragglerValue);
    }

    return mainChain;
}

std::deque<int> PmergeMe::fordJohnsonSortDeque(const std::deque<int>& input)
{
    if (input.size() <= 1)
        return input;

    const bool hasStraggler = (input.size() % 2) != 0;
    int stragglerValue = 0;
    size_t processCount = input.size();

    if (hasStraggler)
    {
        stragglerValue = input[input.size() - 1];
        processCount = input.size() - 1;
    }

    std::deque< std::pair<int,int> > pairs;

    for (size_t i = 0; i < processCount; i += 2)
    {
        int a = input[i];
        int b = input[i + 1];
        if (a > b)
        {
            int tmp = a; a = b; b = tmp;
        }
        pairs.push_back(std::make_pair(a, b));
    }

    if (pairs.size() > 1)
    {
        std::deque<int> bigs;
        for (size_t i = 0; i < pairs.size(); ++i)
            bigs.push_back(pairs[i].second);

        std::deque<int> sortedBigs = fordJohnsonSortDeque(bigs);
        reorderPairsBySortedBigsDeque(pairs, sortedBigs);
    }

    std::deque<int> mainChain;
    mainChain.push_back(pairs[0].first);
    for (size_t i = 0; i < pairs.size(); ++i)
        mainChain.push_back(pairs[i].second);

    if (pairs.size() > 1)
    {
        const size_t pendingCount = pairs.size() - 1;
        const std::vector<size_t> order = buildJacobsthalOrder(pendingCount);

        for (size_t oi = 0; oi < order.size(); ++oi)
        {
            const size_t pairIndex = order[oi];
            if (pairIndex == 0 || pairIndex >= pairs.size())
                continue;

            const int smallValue = pairs[pairIndex].first;
            const int bigValue   = pairs[pairIndex].second;

            size_t boundIndex = indexOfValueDeque(mainChain, bigValue);
            if (boundIndex > mainChain.size())
                boundIndex = mainChain.size();

            const size_t insertIndex = lowerBoundIndex(mainChain, smallValue, 0, boundIndex);
            insertAt(mainChain, insertIndex, smallValue);
        }
    }

    if (hasStraggler)
    {
        const size_t insertIndex = lowerBoundIndex(mainChain, stragglerValue, 0, mainChain.size());
        insertAt(mainChain, insertIndex, stragglerValue);
    }

    return mainChain;
}

void PmergeMe::sortAndMeasure(const std::vector<int>& input)
{
    std::deque<int>  dequeInput;
    std::vector<int> sortedVector;
    std::deque<int>  sortedDeque;

    std::cout << "Before: ";
    printVectorSequence(input);
    std::cout << "\n";

    const double startVector = nowMicros();
    sortedVector = fordJohnsonSortVector(input);
    const double endVector = nowMicros();

    const double startDeque = nowMicros();
    for (size_t i = 0; i < input.size(); ++i)
    {
        dequeInput.push_back(input[i]);
    }
    sortedDeque = fordJohnsonSortDeque(dequeInput);
    const double endDeque = nowMicros();

    std::cout << "After: ";
    printVectorSequence(sortedVector);
    std::cout << "\n";

    std::cout << "Time to process a range of " << input.size()
              << " elements with std::vector : " << (endVector - startVector) << " us\n";
    std::cout << "Time to process a range of " << input.size()
              << " elements with std::deque  : " << (endDeque - startDeque) << " us\n";

    if (sortedVector.size() != sortedDeque.size())
    {
        std::cerr << "Error\n";
        return;
    }
    for (size_t i = 0; i < sortedVector.size(); ++i)
    {
        if (sortedVector[i] != sortedDeque[i])
        {
            std::cerr << "Error\n";
            return;
        }
    }
}

