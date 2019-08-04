#include<iostream>
#include<fstream>
#include<mutex>

namespace Delector {//删除器
  template<class T>
    struct DFDel {//默认是new用delete删除
      void operator()(T*& ptr) {
        if ( ptr  ) {
          delete ptr;
          ptr = nullptr;

        }

      }
    };
  template<class T>
    struct Free {//处理maloc的资源
      void operator()(T*& ptr) {
        if ( ptr  ) {
          free (ptr);
          ptr = nullptr;

        }

      }
    };
  struct FClose {
    void operator()(FILE*& pf) {//处理文件流指针和套接字；
      if ( pf  ) {
        fclose (pf);
        pf = nullptr;

      }
    }

  };
}

template<class T , class DF = Delector::DFDel<T>>
class SharedPtr {
  public:
    SharedPtr (T* ptr = nullptr)
      : _ptr (ptr)
        , _pCount (nullptr)
        , _pMutex (nullptr) {
          if ( _ptr  ) {
            _pMutex = new std::mutex;
            _pCount = new int (1);

          }

        }
    SharedPtr (const SharedPtr<T,DF>& sp)
      : _ptr (sp._ptr)
        , _pCount (sp._pCount)
        , _pMutex (sp._pMutex) {
          AddRef ();

        }
    ~SharedPtr () { Release ();  }
    SharedPtr<T,DF>& operator=(const SharedPtr<T,DF>& sp) {
      if ( this != &sp  ) {
        // 释放管理的旧资源
        Release ();
        // 共享管理新对象的资源，并增加引用计数
        _ptr = sp._ptr;
        _pCount = sp._pCount;
        AddRef ();

      }
      return *this;

    }
    T& operator*() { return *_ptr;  }
    T* operator->() { return _ptr;  }
    int UseCount () { return *_pCount;  }
    T* Get () { return _ptr;  }
  private:
    void AddRef () {
      _pMutex->lock ();
      ++*_pCount;
      _pMutex->unlock ();

    }
    int SubRef () {
      _pMutex->lock ();
      --*_pCount;
      _pMutex->unlock ();
      return *_pCount;

    }
    void Release () {
      if ( _ptr && 0 == SubRef ()  ) {
        DF ()(_ptr);
        delete _pCount;
        if ( _pMutex  )
          delete _pMutex;

      }

    }
  private:
    int* _pCount; // 引用计数
    T* _ptr; // 指向管理资源的指针
    std::mutex * _pMutex;//加锁线程安全

};

int main () {
  int * a = (int *)malloc (100 * sizeof (int));
  SharedPtr<int , Delector::Free<int>> test (a);
  return 0;

}

