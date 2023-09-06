#ifndef KEYWORDS_H
#define KEYWORDS_H

#include <QStringList>

namespace Keywords {

// 声明一个 QStringList 来存放C++关键字
const QStringList keywords = {
    "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum",
        "extern", "float", "for", "goto", "if", "inline", "int", "long", "register", "return", "short", "signed",
        "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while",
        "bool", "true", "false", "namespace", "using", "class", "public", "private", "protected", "virtual",
        "template", "typename", "try", "catch", "throw", "const_cast", "dynamic_cast", "reinterpret_cast",
        "static_cast", "operator", "this", "new", "delete", "friend", "explicit", "mutable", "namespace", "sizeof",
        "typeid", "typename", "virtual", "wchar_t", "override", "final", "nullptr", "constexpr", "noexcept",
        "thread_local", "alignas", "alignof", "and", "and_eq", "bitand", "bitor", "compl", "not", "not_eq", "or",
        "or_eq", "xor", "xor_eq",
        "main", "include", "iostream", "cin", "cout", "endl", "vector", "string", "list", "map", "set", "pair",
        "make_pair", "iterator", "begin", "end", "const_iterator", "size", "push_back", "pop_back", "front",
        "back", "clear", "empty", "find", "insert", "erase", "lower_bound", "upper_bound", "sort", "reverse",
        "max_element", "min_element", "count", "accumulate", "abs", "pow", "sqrt", "ceil", "floor", "log",
        "log10", "exp", "sin", "cos", "tan", "asin", "acos", "atan", "rand", "srand", "time", "clock", "rand_r",
        "memcpy", "memset", "malloc", "free",
         // STL容器
        "array", "vector", "deque", "list", "forward_list", "set", "multiset", "map", "multimap", "unordered_set",
        "unordered_multiset", "unordered_map", "unordered_multimap", "stack", "queue", "priority_queue",

        // STL算法和函数
        "sort", "stable_sort", "partial_sort", "partial_sort_copy", "nth_element", "make_heap", "push_heap",
        "pop_heap", "sort_heap", "min", "max", "min_element", "max_element", "accumulate", "inner_product",
        "adjacent_difference", "iota", "generate", "replace", "replace_if", "replace_copy", "replace_copy_if",
        "fill", "fill_n", "copy", "copy_if", "copy_n", "move", "move_backward", "swap", "iter_swap", "reverse",
        "reverse_copy", "rotate", "rotate_copy", "unique", "unique_copy", "binary_search", "lower_bound",
        "upper_bound", "equal_range", "merge", "inplace_merge", "includes", "set_union", "set_intersection",
        "set_difference", "set_symmetric_difference", "next_permutation", "prev_permutation"
};
}

#endif // KEYWORDS_H
