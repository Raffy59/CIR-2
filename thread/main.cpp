#include<iostream>
#include<thread>
#include<mutex>


std::mutex mtx;

void afficher(int a){
    mtx.lock();
    for(int i=0;i<=a;i++){
        std::cout<<i<<std::endl;
    }
std::cout<<std::this_thread::get_id()<<" : "<<"C'est mon thread"<<std::endl;
    mtx.unlock();
}

int main(){
    int a = 100;
    int b = 200;
    std::thread t1(afficher,a);
    std::thread t2(afficher,b);
    t1.join();
    t2.join();

    return 0;
}
