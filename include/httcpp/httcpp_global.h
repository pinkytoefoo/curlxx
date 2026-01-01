#pragma once 

// TODO: find a better name
class httcpp_manager
{
public:
    static httcpp_manager& instance();

    httcpp_manager(const httcpp_manager&) = delete;
private:
    httcpp_manager();
    ~httcpp_manager();
};
