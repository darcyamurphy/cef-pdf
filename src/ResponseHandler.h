#ifndef RESPONSE_HANDLER_H_
#define RESPONSE_HANDLER_H_

#include <cstdlib>
#include <string>

#include "include/cef_resource_handler.h"
#include "include/cef_scheme.h"

namespace cefpdf {

class ResponseHandler : public CefResourceHandler,
                        public CefSchemeHandlerFactory
{
    public:

    ResponseHandler(const CefString& data);

    // CefResourceHandler methods:
    virtual bool ProcessRequest(
        CefRefPtr<CefRequest> request,
        CefRefPtr<CefCallback> callback
    ) OVERRIDE;

    virtual void GetResponseHeaders(
        CefRefPtr<CefResponse> response,
        int64& response_length,
        CefString& redirectUrl
    ) OVERRIDE;

    virtual bool ReadResponse(
        void* data_out,
        int bytes_to_read,
        int& bytes_read,
        CefRefPtr<CefCallback> callback
    ) OVERRIDE;

    virtual void Cancel() OVERRIDE;

    // CefSchemeHandlerFactory methods:
    virtual CefRefPtr<CefResourceHandler> Create(
        CefRefPtr<CefBrowser> browser,
        CefRefPtr<CefFrame> frame,
        const CefString& scheme_name,
        CefRefPtr<CefRequest> request
    ) OVERRIDE;

    private:

    std::string m_data;
    std::size_t m_offset;

    // Include the default reference counting implementation.
    IMPLEMENT_REFCOUNTING(ResponseHandler);
};

} // namespace cefpdf

#endif // RESPONSE_HANDLER_H_