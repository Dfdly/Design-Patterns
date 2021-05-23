#include<iostream>
#include<mutex>
#include<pthread.h>
#include<unistd.h>
#define NUM_THREADS 5 // threads number

class Singleton
{
private:
    static Singleton *instance;
    static std::mutex m_Mutex;

    Singleton();
    Singleton(const Singleton &signal);
    const Singleton &operator=(const Singleton &signal);
public:
    static Singleton *get_instance();
};

std::mutex Singleton::m_Mutex;

Singleton::Singleton()
{}

Singleton* Singleton::instance = NULL;

Singleton *Singleton::get_instance()
{
    if(instance == NULL)
    {
        //make sure threads safe by lock 
        std::unique_lock<std::mutex> lock(m_Mutex);
        if(instance == NULL)
        {
            instance = new Singleton();
        }
        // instance = new Singleton();
        
    }
    return instance;
}

// 线程函数
void *PrintHello(void *threadid)
{
    // 主线程与子线程分离，两者相互不干涉，子线程结束同时子线程的资源自动回收
    pthread_detach(pthread_self());

    // 对传入的参数进行强制类型转换，由无类型指针变为整形数指针，然后再读取
    int tid = *((int *)threadid);

    std::cout << "Hi, 我是线程 ID:[" << tid << "]" << std::endl;

    // 打印实例地址
    Singleton *s = Singleton::get_instance();
    std::cout<<s<<std::endl;

    pthread_exit(NULL);
}

//test
int main(int argc, char const *argv[])
{
    pthread_t threads[NUM_THREADS] = {0};
    int indexes[NUM_THREADS] = {0};
    int ret = 0;
    int i = 0;
    for(i=0;i<NUM_THREADS;i++)
    {
        std::cout<<"create thread ["<<i<<"]"<<std::endl;
        indexes[i] = i;
        ret = pthread_create(&threads[i],NULL,PrintHello,(void*)&indexes[i]);
        if (ret)
        {
            std::cout << "Error:无法创建线程," << ret << std::endl;
            exit(-1);
        }
    }
    // Singleton *s1 = Singleton::get_instance();
    // Singleton *s2 = Singleton::get_instance();
    // if(s1 == s2)
    // {
    //     std::cout<<"s1==s2"<<std::endl;
    // }
    pause();
    return 0;
}
