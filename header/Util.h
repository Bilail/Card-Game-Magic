//
// Created by dope on 12/01/2022.
//

#ifndef MAGIC_UTIL_H
#define MAGIC_UTIL_H

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

template<typename Base, typename T>
inline bool instanceof(const T*) {
    return std::is_base_of<Base, T>::value;
}

template<typename T>
int getIndex(std::vector<T> v, T K) {
    auto it = find(v.begin(), v.end(), K);
    if (it != v.end())
        return it - v.begin();
    else
        return -1;
}

#endif //MAGIC_UTIL_H
