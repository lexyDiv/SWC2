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

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <SDL2/SDL_mixer.h>

using namespace std;

template <typename T>
class Array
{
public:
    Array(int size);
    ~Array();
    int getSize();
    void add(T el);
    void forEach(function<void(T item, int index, T *arr)> fn);
    void forEach(function<void(T item, int index)> fn);
    void forEach(function<void(T item)> fn);
    int indexOf(T el);
    int findIndex(function<bool(T item)> fn);
    T find(function<bool(T item)> fn);



    void clear();
    T getElem(int index);

    int length = 0;

private:
    int size = 0;
    T *arr;
};

template <typename T>
inline Array<T>::Array(int size)
{
    this->size = size;
    this->arr = new T[size]{nullptr};
}

template <typename T>
inline Array<T>::~Array()
{
    delete[] this->arr;
    this->arr = nullptr;
}

template <typename T>
inline int Array<T>::getSize()
{
    return this->size;
}

template <typename T>
inline void Array<T>::add(T el)
{
    for (int i = 0; i < this->size; i++)
    {
        T &element = this->arr[i];
        if (element == nullptr)
        {
            element = el;
            this->length++;
            break;
        }
    }
}

template <typename T>
inline void Array<T>::forEach(function<void(T item)>
                                  fn)
{
    int l = this->length;
    for (int i = 0; i < this->size; i++)
    {
        if (l)
        {
            T &el = this->arr[i];
            if (el != nullptr)
            {
                fn(el);
                l--;
                if (el == nullptr)
                {
                    this->length--;
                }
            }
        }
        else
        {
            break;
        }
    }
}

template <typename T>
inline int Array<T>::indexOf(T el)
{
    for (int i = 0; i < this->size; i++)
    {
        T &element = this->arr[i];
        if (element != nullptr && el == element)
        {
            return i;
        }
    }
    return -1;
}

template <typename T>
inline int Array<T>::findIndex(function<bool(T item)> fn)
{
    for (int i = 0; i < this->size; i++)
    {
        T &el = this->arr[i];
        if (el != nullptr && fn(el))
        {
            return i;
        }
    }
    return -1;
}

template <typename T>
inline T Array<T>::find(function<bool(T item)> fn)
{
    for (int i = 0; i < this->size; i++)
    {
        T &el = this->arr[i];
        if (el != nullptr && fn(el))
        {
            return el;
        }
    }
    return nullptr;
}

template <typename T>
inline void Array<T>::forEach(function<void(T item, int index)>
                                  fn)
{
    int l = this->length;
    for (int i = 0; i < this->size; i++)
    {
        if (l)
        {
            T &el = this->arr[i];
            if (el != nullptr)
            {
                fn(el, i);
                l--;
                if (el == nullptr)
                {
                    this->length--;
                }
            }
        }
        else
        {
            break;
        }
    }
}

template <typename T>
inline void Array<T>::forEach(function<void(T item, int index, T *arr)>
                                  fn)
{
    int l = this->length;
    for (int i = 0; i < this->size; i++)
    {
        if (l)
        {
            T &el = this->arr[i];
            if (el != nullptr)
            {
                fn(el, i, this->arr);
                l--;
                if (el == nullptr)
                {
                    this->length--;
                }
            }
        }
        else
        {
            break;
        }
    }
}

// template <typename T>
// inline Array<int *> *Array<T>::map(function<int *(T item, int index, T *arr)> fn)
// {
//     Array<int*> *array = new Array<int*>(this->size);
//     return array;
// }

template <typename T>
inline void Array<T>::clear()
{
    this->forEach([](T el, int i, T *arr)
                  {
        delete el;
        el = nullptr;
        arr[i] = nullptr; });
}

template <typename T>
inline T Array<T>::getElem(int index)
{
    return this->arr[index];
}

// template <typename T>
// template <typename T2>
// inline Array<T2> *Array<T>::hz(T a, T2 b)
// {
//     return nullptr;
// }

