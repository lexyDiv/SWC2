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

template <typename T>
class Array
{
    public:
    Array(int size);
    ~Array();
    int getSize();
    void add(T el);
    T getElem(int index);
    

    private:
    int size = 0;
    T* arr;
    
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
    for (int i = 0; i < this->size; i++) {
        T &element = this->arr[i];
        if (element == nullptr) {
            element = el;
            break;
        }
    }
}

template <typename T>
inline T Array<T>::getElem(int index)
{
    return this->arr[index];
}
