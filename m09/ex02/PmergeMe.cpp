
#include "PmergeMe.hpp"


long long PmergeMe::nowMicros()
{
    timeval currentTime;

    gettimeofday(&currentTime, 0);
    return ((long long)currentTime.tv_sec * 1000000LL + (long long)currentTime.tv_usec);
}

//fct qui definit ordre d'insertion small -> main
std::vector<size_t> PmergeMe::buildJacobsthalOrder(size_t pendingCount)
{
    std::vector<size_t> insertionOrder;
    size_t              jacobPrev2;
    size_t              jacobPrev1;
    size_t              previousLimit;
    size_t              currentLimit;

    if (pendingCount == 0)
    {
        return (insertionOrder);
    }
    insertionOrder.push_back(1);
    jacobPrev2 = 0;
    jacobPrev1 = 1;
    previousLimit = 1;
    currentLimit = 3;
    while (previousLimit < pendingCount)
    {
        size_t blockHigh;

        blockHigh = currentLimit;
        if (blockHigh > pendingCount)
        {
            blockHigh = pendingCount;
        }
        for (size_t index = blockHigh; index > previousLimit; --index)
        {
            insertionOrder.push_back(index);
        }

        size_t nextJacob;

        nextJacob = jacobPrev1 + 2 * jacobPrev2;
        jacobPrev2 = jacobPrev1;
        jacobPrev1 = nextJacob;

        previousLimit = currentLimit;
        currentLimit = jacobPrev1;
        if (currentLimit <= previousLimit)
        {
            currentLimit = previousLimit + 1;
        }
    }
    return (insertionOrder);
}

template <typename Sequence>
size_t PmergeMe::lowerBoundIndex(const Sequence& sequence, int value, size_t left, size_t right)
{
    while (left < right)
    {
        size_t middle;

        middle = left + (right - left) / 2;
        if (sequence[middle] < value)
        {
            left = middle + 1;
        }
        else
        {
            right = middle;
        }
    }
    return (left);
}

template <typename Sequence>
void PmergeMe::insertAt(Sequence& sequence, size_t position, int value)
{
    typename Sequence::iterator iter;

    iter = sequence.begin();
    for (size_t i = 0; i < position; ++i)
    {
        ++iter;
    }
    sequence.insert(iter, value);
}

static void mergePairRangeVector(std::vector< std::pair<int, int> >& pairs,
                                 std::vector< std::pair<int, int> >& buffer,
                                 size_t left,
                                 size_t middle,
                                 size_t right)
{
    size_t i;
    size_t j;
    size_t k;

    i = left;
    j = middle;
    k = left;
    while (i < middle && j < right)
    {
        if (pairs[i].second <= pairs[j].second)
        {
            buffer[k] = pairs[i];
            ++i;
        }
        else
        {
            buffer[k] = pairs[j];
            ++j;
        }
        ++k;
    }
    while (i < middle)
    {
        buffer[k] = pairs[i];
        ++i;
        ++k;
    }
    while (j < right)
    {
        buffer[k] = pairs[j];
        ++j;
        ++k;
    }
    for (size_t index = left; index < right; ++index)
    {
        pairs[index] = buffer[index];
    }
}

static void mergeSortPairsVectorRec(std::vector< std::pair<int, int> >& pairs,
                                   std::vector< std::pair<int, int> >& buffer,
                                   size_t left,
                                   size_t right)
{
    if (right - left <= 1)
        return ;

    size_t middle;

    middle = left + (right - left) / 2;
    mergeSortPairsVectorRec(pairs, buffer, left, middle);
    mergeSortPairsVectorRec(pairs, buffer, middle, right);
    mergePairRangeVector(pairs, buffer, left, middle, right);
}

void PmergeMe::mergeSortPairsVector(std::vector< std::pair<int, int> >& pairs)
{
    std::vector< std::pair<int, int> > buffer;

    if (pairs.size() < 2)
        return ;
        
    buffer.resize(pairs.size());
    mergeSortPairsVectorRec(pairs, buffer, 0, pairs.size());
}

std::vector<int> PmergeMe::fordJohnsonSortVector(const std::vector<int>& input)
{
    std::vector< std::pair<int, int> > pairs;
    std::vector<int>                   mainChain;
    bool                               hasStraggler;
    int                                stragglerValue;
    size_t                             processCount;

    if (input.size() <= 1)
    {
        return (input);
    }

    hasStraggler = (input.size() % 2) != 0;
    stragglerValue = 0;
    processCount = input.size();
    if (hasStraggler)
    {
        stragglerValue = input[input.size() - 1];
        processCount = input.size() - 1;
    }

    pairs.reserve(processCount / 2);
    for (size_t index = 0; index < processCount; index += 2)
    {
        int firstValue;
        int secondValue;

        firstValue = input[index];
        secondValue = input[index + 1];
        if (firstValue > secondValue)
        {
            int tmp;

            tmp = firstValue;
            firstValue = secondValue;
            secondValue = tmp;
        }
        pairs.push_back(std::make_pair(firstValue, secondValue));
    }

    mergeSortPairsVector(pairs);

    mainChain.reserve(input.size());
    mainChain.push_back(pairs[0].first);
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        mainChain.push_back(pairs[i].second);
    }

    if (pairs.size() > 1)
    {
        size_t              pendingCount;
        std::vector<size_t> insertionOrder;

        pendingCount = pairs.size() - 1;
        insertionOrder = buildJacobsthalOrder(pendingCount);

        for (size_t oi = 0; oi < insertionOrder.size(); ++oi)
        {
            size_t pairIndex;

            pairIndex = insertionOrder[oi];
            if (pairIndex == 0 || pairIndex >= pairs.size())
            {
                continue ;
            }

            int    smallValue;
            int    largeValue;
            size_t boundIndex;

            smallValue = pairs[pairIndex].first;
            largeValue = pairs[pairIndex].second;

            boundIndex = 0;
            while (boundIndex < mainChain.size() && mainChain[boundIndex] != largeValue)
            {
                ++boundIndex;
            }

            size_t insertIndex;

            insertIndex = lowerBoundIndex(mainChain, smallValue, 0, boundIndex);
            insertAt(mainChain, insertIndex, smallValue);
        }
    }

    if (hasStraggler)
    {
        size_t insertIndex;

        insertIndex = lowerBoundIndex(mainChain, stragglerValue, 0, mainChain.size());
        insertAt(mainChain, insertIndex, stragglerValue);
    }

    return (mainChain);
}

static void mergePairRangeDeque(std::deque< std::pair<int, int> >& pairs,
                                std::deque< std::pair<int, int> >& buffer,
                                size_t left,
                                size_t middle,
                                size_t right)
{
    size_t i;
    size_t j;
    size_t k;

    i = left;
    j = middle;
    k = left;
    while (i < middle && j < right)
    {
        if (pairs[i].second <= pairs[j].second)
        {
            buffer[k] = pairs[i];
            ++i;
        }
        else
        {
            buffer[k] = pairs[j];
            ++j;
        }
        ++k;
    }
    while (i < middle)
    {
        buffer[k] = pairs[i];
        ++i;
        ++k;
    }
    while (j < right)
    {
        buffer[k] = pairs[j];
        ++j;
        ++k;
    }
    for (size_t index = left; index < right; ++index)
    {
        pairs[index] = buffer[index];
    }
}

static void mergeSortPairsDequeRec(std::deque< std::pair<int, int> >& pairs,
                                  std::deque< std::pair<int, int> >& buffer,
                                  size_t left,
                                  size_t right)
{
    if (right - left <= 1)
    {
        return ;
    }

    size_t middle;

    middle = left + (right - left) / 2;
    mergeSortPairsDequeRec(pairs, buffer, left, middle);
    mergeSortPairsDequeRec(pairs, buffer, middle, right);
    mergePairRangeDeque(pairs, buffer, left, middle, right);
}

void PmergeMe::mergeSortPairsDeque(std::deque< std::pair<int, int> >& pairs)
{
    std::deque< std::pair<int, int> > buffer;

    if (pairs.size() < 2)
    {
        return ;
    }
    buffer.resize(pairs.size());
    mergeSortPairsDequeRec(pairs, buffer, 0, pairs.size());
}

std::deque<int> PmergeMe::fordJohnsonSortDeque(const std::deque<int>& input)
{
    std::deque< std::pair<int, int> > pairs;
    std::deque<int>                   mainChain;
    bool                              hasStraggler;
    int                               stragglerValue;
    size_t                            processCount;

    if (input.size() <= 1)
    {
        return (input);
    }

    hasStraggler = (input.size() % 2) != 0;
    stragglerValue = 0;
    processCount = input.size();
    if (hasStraggler)
    {
        stragglerValue = input[input.size() - 1];
        processCount = input.size() - 1;
    }

    for (size_t index = 0; index < processCount; index += 2)
    {
        int firstValue;
        int secondValue;

        firstValue = input[index];
        secondValue = input[index + 1];
        if (firstValue > secondValue)
        {
            int tmp;

            tmp = firstValue;
            firstValue = secondValue;
            secondValue = tmp;
        }
        pairs.push_back(std::make_pair(firstValue, secondValue));
    }

    mergeSortPairsDeque(pairs);

    mainChain.push_back(pairs[0].first);
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        mainChain.push_back(pairs[i].second);
    }

    if (pairs.size() > 1)
    {
        size_t              pendingCount;
        std::vector<size_t> insertionOrder;

        pendingCount = pairs.size() - 1;
        insertionOrder = buildJacobsthalOrder(pendingCount);

        for (size_t oi = 0; oi < insertionOrder.size(); ++oi)
        {
            size_t pairIndex;

            pairIndex = insertionOrder[oi];
            if (pairIndex == 0 || pairIndex >= pairs.size())
            {
                continue ;
            }

            int    smallValue;
            int    largeValue;
            size_t boundIndex;

            smallValue = pairs[pairIndex].first;
            largeValue = pairs[pairIndex].second;

            boundIndex = 0;
            while (boundIndex < mainChain.size() && mainChain[boundIndex] != largeValue)
            {
                ++boundIndex;
            }

            size_t insertIndex;

            insertIndex = lowerBoundIndex(mainChain, smallValue, 0, boundIndex);
            insertAt(mainChain, insertIndex, smallValue);
        }
    }

    if (hasStraggler)
    {
        size_t insertIndex;

        insertIndex = lowerBoundIndex(mainChain, stragglerValue, 0, mainChain.size());
        insertAt(mainChain, insertIndex, stragglerValue);
    }

    return (mainChain);
}

static void printVectorSequence(const std::vector<int>& sequence)
{
    for (size_t i = 0; i < sequence.size(); ++i)
    {
        std::cout << sequence[i];
        if (i + 1 < sequence.size())
        {
            std::cout << " ";
        }
    }
}

void PmergeMe::sortAndMeasure(const std::vector<int>& input)
{
    std::deque<int>   dequeInput;
    long long         startVector;
    long long         endVector;
    long long         startDeque;
    long long         endDeque;
    std::vector<int>  sortedVector;
    std::deque<int>   sortedDeque;

    std::cout << "Before: ";
    printVectorSequence(input);
    std::cout << "\n";

    startVector = nowMicros(); //time before algo
    sortedVector = fordJohnsonSortVector(input);
    endVector = nowMicros(); //time after

    for (size_t i = 0; i < input.size(); ++i)
    {
        dequeInput.push_back(input[i]);
    }

    startDeque = nowMicros();
    sortedDeque = fordJohnsonSortDeque(dequeInput);
    endDeque = nowMicros();

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
        return ;
    }
    for (size_t i = 0; i < sortedVector.size(); ++i)
    {
        if (sortedVector[i] != sortedDeque[i])
        {
            std::cerr << "Error\n";
            return ;
        }
    }
}