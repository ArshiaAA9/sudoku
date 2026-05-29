#pragma once

#include <chrono>

class Stopwatch {
public:
    void start() { m_start = std::chrono::steady_clock::now(); }

    void reset() { start(); }

    int elapsedSeconds() const {
        auto now = std::chrono::steady_clock::now();
        return std::chrono::duration_cast<std::chrono::seconds>(now - m_start).count();
    }

    std::string format() const {
        int total = elapsedSeconds();
        int m = total / 60, s = total % 60;
        return std::to_string(m) + ":" + (s < 10 ? "0" : "") + std::to_string(s);
    }

private:
    std::chrono::steady_clock::time_point m_start;
};
