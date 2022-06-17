#include <curl/curl.h>

#include <mutex>
#include <string>
#include <vector>

#include "prometheus/detail/http_method.h"

namespace prometheus {
namespace detail {

class CurlWrapper {
 public:
  CurlWrapper(const std::string& username, const std::string& password);

  CurlWrapper(const CurlWrapper&) = delete;
  CurlWrapper(CurlWrapper&&) = delete;
  CurlWrapper& operator=(const CurlWrapper&) = delete;
  CurlWrapper& operator=(CurlWrapper&&) = delete;

  ~CurlWrapper();

  int performHttpRequest(HttpMethod method, const std::string& uri,
                         const std::string& body);
  void addOptHttpHeader(const std::string& header);

 private:
  CURL* curl_;
  std::string auth_;
  std::mutex mutex_;
  std::vector<std::string> optHttpHeader_;
};

}  // namespace detail
}  // namespace prometheus
