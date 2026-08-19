#pragma once


template <typename T> void swap(T& t1,T& t2){
    T type = t1;
    t1 = t2;
    t2 = type;
}
template <typename T> T min(T a, T b){
    if(a < b)
        return a;
    return b;
}
template <typename T> T max(T a, T b){
    if(a > b)
        return a;
    return b;
}