#include "unittest.h"

#include <iostream>
#include <vector>
#include <chrono>

#define REETOSTRING_IMPL(T) \
template<> std::string reeToString(const T t) { \
    return std::to_string(t); \
}

REETOSTRING_IMPL(char)
REETOSTRING_IMPL(unsigned char)
REETOSTRING_IMPL(short)
REETOSTRING_IMPL(unsigned short)
REETOSTRING_IMPL(int)
REETOSTRING_IMPL(unsigned int)
REETOSTRING_IMPL(long)
REETOSTRING_IMPL(unsigned long)
REETOSTRING_IMPL(long long)
REETOSTRING_IMPL(unsigned long long)
REETOSTRING_IMPL(float)
REETOSTRING_IMPL(double)

template<> std::string reeToString(const char *t) {
    return std::string(t);
}
template<> std::string reeToString(const std::string t) {
    return t;
}

namespace ree {
UnitTestFunc::UnitTestFunc(const std::string &klass, const std::string &name)
    : klass_(klass),
      name_(name),
      failed_(false) {
}
std::string UnitTestFunc::Klass() const {
    return klass_;
}
std::string UnitTestFunc::Name() const {
    return name_;
}
bool UnitTestFunc::Failed() const {
    return failed_;
}
std::string UnitTestFunc::Description() const {
    std::string desc;
    if (failed_) {
        desc += failDescription_;
        desc += ("[ FAILED ] " + Klass() + "." + Name());
    } else {
        desc += ("[   OK   ] " + Klass() + "." + Name());
    }
    return desc;
}

void UnitTestFunc::Fail(const std::string &line, 
    const std::string &checkDescription) {
    failed_ = true;
    failDescription_ += (line + "\n" + checkDescription + "\n");
}
    
class UnitTestImpl {
public:
    void RegisterFunc(UnitTestFunc *func);
    void Init(int argc, const char **argv);
    void RunAllTests();

private:
    std::vector<UnitTestFunc *> funcs_;

    int argc_;
    const char **argv_;
};

void UnitTestImpl::RegisterFunc(UnitTestFunc *func) {
    funcs_.push_back(func);
}

void UnitTestImpl::Init(int argc, const char **argv) {
    argc_ = argc;
    argv_ = argv;
}

void UnitTestImpl::RunAllTests() {
    for (std::vector<UnitTestFunc *>::iterator it = funcs_.begin();
        it != funcs_.end(); ++it) {
        UnitTestFunc *func = *it;
        func->Run();
        std::cout << func->Description() << std::endl;
    }
}

UnitTest &UnitTest::Instance() {
    static UnitTest instance;
    return instance;
}
UnitTest::UnitTest() 
    : impl_(new UnitTestImpl()) {
}
UnitTest::~UnitTest() {
    delete impl_;
}
void UnitTest::RegisterFunc(UnitTestFunc *func) {
    impl_->RegisterFunc(func);
}
void UnitTest::Init(int argc, const char **argv) {
    impl_->Init(argc, argv);
}
void UnitTest::RunAllTests() {
    impl_->RunAllTests();
}

}
