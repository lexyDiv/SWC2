#include "../../protoObj/ProtoObj.cpp"

template <typename T>
int getIndex(vector<T> *v, T K)
{
    auto begin = v->begin();
    auto end = v->end();
    auto it = find(begin, end, K);
    if (it != end)
    {
        int index = it - begin;
        return index;
    }
    return -1;
}