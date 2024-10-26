#pragma once

#include <stdio.h>  /* printf, scanf, puts, NULL */
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
#include <cstdlib>
#include <ctime>
#include <functional>
#include <set>
#include <algorithm>
#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#include <string>
#include <cmath>
#include <cstring>
#include <fstream>
#include <list>
#include <vector>
#include <iterator>
#include <ranges>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <SDL2/SDL_mixer.h>

using namespace std;

template <typename T>
class Array
{
public:
    Array();
    ~Array();
    //  T &operator[] (int i) { return this->vec[i]; }
    T getItem(int i);
    void push(T el);
    void unshift(T el);
    T pop();
    T shift();
    void changeEl(T item, int i);
    void forEachDel(function<bool(T item, int index, vector<T> vec)> fn);
    void forEach(function<void(T item, int index, vector<T> vec)> fn);
    void forEach(function<void(T item, int index)> fn);
    void forEach(function<void(T item)> fn);
    int indexOf(T el);
    T find(function<bool(T item)> fn);
    void splice(int index, int count, T el);
    void splice(int index, int count);
    void filterSelf(function<bool(T item)> fn);
    void sort(function<bool(T a, T b)> fn);

    void clear();

    int length = 0;

private:
    vector<T> vec;
};

template <typename T>
inline Array<T>::Array()
{
}

template <typename T>
inline Array<T>::~Array()
{
    // delete vec;
    // vec = nullptr;
}

template <typename T>
inline T Array<T>::getItem(int i)
{
    return this->vec.at(i);
}

template <typename T>
inline void Array<T>::push(T el)
{
    this->vec.push_back(el);
    this->length = vec.size();
}

template <typename T>
inline void Array<T>::unshift(T el)
{
    this->vec.insert(this->vec.begin(), el);
    this->length = vec.size();
}

template <typename T>
inline T Array<T>::pop()
{
    if (this->length)
    {
        int lastIndex = vec.size() - 1;
        T el = vec.at(lastIndex);
        vec.erase(vec.begin() + lastIndex);
        this->length = vec.size();
        return el;
    }
    return T();
}

template <typename T>
inline T Array<T>::shift()
{
    if (this->length)
    {
        int lastIndex = 0;
        T el = vec.at(lastIndex);
        vec.erase(vec.begin() + lastIndex);
        this->length = vec.size();
        return el;
    }
    return T();
}

template <typename T>
inline void Array<T>::changeEl(T item, int i)
{
    this->vec[i] = item;
}

template <typename T>
inline void Array<T>::forEachDel(function<bool(T item, int index, vector<T> vec)> fn)
{
    int size = this->vec.size();
    for (int i = 0; i < size; i++)
    {
        T item = this->vec[i];
        bool del = fn(item, i, this->vec);
        if (del)
        {
            vec.erase(vec.begin() + i);
            i--;
            size--;
        }
    }
    this->length = vec.size();
}

template <typename T>
inline void Array<T>::forEach(function<void(T item, int index, vector<T> vec)> fn)
{
    int size = this->vec.size();
    for (int i = 0; i < size; i++)
    {
        T item = this->vec[i];
        fn(item, i, this->vec);
    }
}

template <typename T>
inline void Array<T>::forEach(function<void(T item, int index)> fn)
{
    int size = this->vec.size();
    for (int i = 0; i < size; i++)
    {
        T item = this->vec[i];
        fn(item, i);
    }
}

template <typename T>
inline void Array<T>::forEach(function<void(T item)> fn)
{
    int size = this->vec.size();
    for (int i = 0; i < size; i++)
    {
        T item = this->vec[i];
        fn(item);
    }
}

template <typename T>
inline int Array<T>::indexOf(T el)
{
    auto begin = this->vec.begin();
    auto end = this->vec.end();
    auto it = std::find(begin, end, el);
    if (it != end)
    {
        int index = it - begin;
        return index;
    }
    return -1;
}

template <typename T>
inline T Array<T>::find(function<bool(T item)> fn)
{
    int size = this->vec.size();
    for (int i = 0; i < size; i++)
    {
        T el = this->vec[i];
        if (fn(el))
        {
            return el;
        }
    }
    return nullptr;
}

template <typename T>
inline void Array<T>::splice(int index, int count, T el)
{
    if (count)
    {
        int finI = index + count;
        this->vec.erase(this->vec.begin() + index, this->vec.begin() + finI);
    }
    this->vec.insert(std::next(this->vec.begin(), index), std::move(el));
    this->length = this->vec.size();
}

template <typename T>
inline void Array<T>::splice(int index, int count)
{
    if (count)
    {
        int finI = index + count;
        this->vec.erase(this->vec.begin() + index, this->vec.begin() + finI);
    }
    this->length = this->vec.size();
}

template <typename T>
inline void Array<T>::filterSelf(function<bool(T item)> fn)
{
    this->vec.erase(remove_if(this->vec.begin(), this->vec.end(), [fn](T el)
                              { return fn(el); }),
                    this->vec.end());
    this->length = this->vec.size();
}

template <typename T>
inline void Array<T>::sort(function<bool(T a, T b)> fn)
{
    std::sort(this->vec.begin(), this->vec.end(), [fn](T a, T b)
              { return fn(a, b); });
}

template <typename T>
inline void Array<T>::clear()
{
    this->vec.clear();
    this->length = this->vec.size();
}
