
#pragma once

#include <assert.h>
#include <vector>


//#define SHOW_BUG1_SO
//#define SHOW_BUG2_ASSERT
//#define SHOW_BUG3_SO

class ArrayWrap {
public:
    /**
     \brief construct a map variant
     */
    ArrayWrap()
    { }

    /**
     \brief copy-ctor
     \param other [in] object to copy
     */
    ArrayWrap(const ArrayWrap& other)
#ifdef SHOW_BUG1_SO
        : _array{ other._array }
    { }
#else
    {
        _array = other._array;
    }
#endif

    /**
     \brief move-ctor
     \param other [in] object to move
     */
    ArrayWrap(ArrayWrap&& other) noexcept
#ifdef SHOW_BUG2_ASSERT
        // This will fail assert()s on line 29 and 30 in ConsoleApplication1.cpp
        : _array{ std::move(other._array) }
    { }
#else
    {
        _array = std::move(other._array);
    }
#endif

    /**
     \brief construct an array variant
     */
    ArrayWrap(const std::vector<ArrayWrap>& array)
#ifdef SHOW_BUG3_SO
        : _array{ array }
    { }
#else
    {
        _array = array;
    }
#endif

    /**
     \brief copy operator
     \param other [in] object to copy
     */
    ArrayWrap& operator=(const ArrayWrap& other)
    {
        _array = other._array;
        return *this;
    }

    /**
     \brief move operator
     \param other [in] object to move
     */
    ArrayWrap& operator=(ArrayWrap&& other) noexcept
    {
        _array = std::move(other._array);
        return *this;
    }

#if 0
    /**
     \brief copy operator (array)
     \param newArray [in] array to copy
     */
    JsonNode_t& operator=(const std::vector<JsonNode_t>& array)
    {
        _array = array;
        return *this;
    }

    /**
     \brief move operator (array)
     \param newArray [in] array to move
     */
    JsonNode_t& operator=(std::vector<JsonNode_t>&& array)
    {
        _array = std::move(array);
        return *this;
    }
#endif

    bool operator==(const ArrayWrap& other) const {
        return _array == other._array;
    }

    std::vector<ArrayWrap> _array;
};
