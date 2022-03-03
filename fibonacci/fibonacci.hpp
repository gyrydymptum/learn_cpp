#pragma once

constexpr int fibonacci_iterative(int sequence) {
    int first = 0;
    int second = 1;
    int third = 1;
    if (sequence < 2)
        return sequence;
    else
        for (int i = 1; i < sequence; i++) {
            third = first + second;
            first = second;
            second = third;
        }
    return third;
}

 constexpr int fibonacci_recursive(int sequence) {
    if (sequence <= 2){
        return 1;
    }
    return fibonacci_recursive(sequence - 1) + fibonacci_recursive(sequence - 2);
}
