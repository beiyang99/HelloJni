
#ifndef _FONE_PLATFORM_HTTP_H_
#define _FONE_PLATFORM_HTTP_H_


#include "fn_http.h"


int fn_adapter_http_request(fn_http_request_node_t *req);
int fn_adapter_http_request_cancel(fn_http_request_node_t *req);

void fn_adapter_http_release(fn_http_request_t *req);

#endif  // _FONE_PLATFORM_HTTP_H_

