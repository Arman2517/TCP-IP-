#pragma once
#include <mutex>
#include <condition_variable>


template<typename T>
class Sbuffer : private std::mutex, private std::condition_variable
{
    bool newDataAvailable;
    T buffer;

public:
    Sbuffer() : newDataAvailable(false) {}

    void writeB(T toBuffer)//Ввод в буфер
    {
        std::unique_lock<std::mutex> lock(*this);
        buffer = std::move(toBuffer);
        newDataAvailable = true;
        lock.unlock();
        notify_all();
    }

    T readB()//Вывод из буфера
    {
        std::unique_lock<std::mutex> lock(*this);
        wait(lock, [this] { return newDataAvailable; });
        T bufferOut = std::move(buffer);
        buffer.clear();
        newDataAvailable = false;
        lock.unlock();
        return bufferOut;
    }
};