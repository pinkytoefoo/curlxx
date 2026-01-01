#include <stdexcept>
#include <format>

#include <curl/curl.h>

#include "httcpp/httcpp_global.h"

httcpp_manager::httcpp_manager()
{
    CURLcode did_init = curl_global_init(CURL_GLOBAL_ALL);
    if(did_init != CURLE_OK)
        throw std::runtime_error{std::format("httcpp: curl_global_init(CURL_GLOBAL_ALL) failed: {}", curl_easy_strerror(did_init))};
}

httcpp_manager::~httcpp_manager()
{
    curl_global_cleanup();
}

httcpp_manager& httcpp_manager::instance()
{
    static httcpp_manager s_instance;
    return s_instance;
}
