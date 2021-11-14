#ifndef SINGLETON_H
#define SINGLETON_H

template <class T> class Singleton
{
public:
        static T* GetInstance();
        static void Kill();
protected:
        static T* m_i;
        private:
        T& operator= (const T&){}
};

class Variable :public Singleton<Variable>
{
        friend Variable* Singleton<Variable>::GetInstance();
        friend void Singleton<Variable>::Kill();

private:
       Variable (const Variable&){}

        Variable();
       ~Variable();
};

#endif


