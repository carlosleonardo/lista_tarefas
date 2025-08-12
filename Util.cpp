//
// Created by carlo on 29/07/2025.
//
#ifdef WIN32
#include <windows.h>
#endif
#include "Util.h"

/**  @file Util.cpp
 * @brief Implementation of utility functions.
 *
 * This file contains the implementation of utility functions used in the application.
 */
std::string cp1252_to_utf8(const std::string &input) {
#ifdef WIN32
    // Etapa 1: CP1252 → UTF-16 (wstring)
    int wide_len = MultiByteToWideChar(1252, 0, input.c_str(), -1, nullptr, 0);
    std::wstring wide_str(wide_len, 0);
    MultiByteToWideChar(1252, 0, input.c_str(), -1, &wide_str[0], wide_len);

    // Etapa 2: UTF-16 → UTF-8
    int utf8_len = WideCharToMultiByte(CP_UTF8, 0, wide_str.c_str(), -1, nullptr, 0, nullptr, nullptr);
    std::string utf8_str(utf8_len, 0);
    WideCharToMultiByte(CP_UTF8, 0, wide_str.c_str(), -1, &utf8_str[0], utf8_len, nullptr, nullptr);

    // Remover terminador nulo
    utf8_str.pop_back();
    return utf8_str;
#else
    return input; // Em sistemas não-Windows, retorna a string original
#endif
}
