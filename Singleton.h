#ifndef SINGLETON_H
#define SINGLETON_H

template <typename T> class Singleton {
    public:
        static T& Instance() {
            if (_instance == nullptr) _instance = new T();
            return *_instance;
        }
    protected:
        virtual ~Singleton() {
            if (_instance != nullptr) delete _instance;
            _instance = nullptr;
    }
private:
    static T* _instance;
};
template<typename T> T* Singleton<T>::_instance = nullptr;


#endif


