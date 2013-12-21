/* 
 * Copyright © 2013 Jolla Ltd
 * 
 * Permission to use, copy, modify, distribute, and sell this
 * software and its documentation for any purpose is hereby granted
 * without fee, provided that the above copyright notice appear in
 * all copies and that both that copyright notice and this permission
 * notice appear in supporting documentation, and that the name of
 * the copyright holders not be used in advertising or publicity
 * pertaining to distribution of the software without specific,
 * written prior permission.  The copyright holders make no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied
 * warranty.
 * 
 * THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS
 * SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS, IN NO EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN
 * AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
 * ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF
 * THIS SOFTWARE.
 */

#ifndef SGX_CLIENT_PROTOCOL_H
#define SGX_CLIENT_PROTOCOL_H

#ifdef  __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>
#include "wayland-client.h"

struct wl_client;
struct wl_resource;

struct sgx_wlegl;

extern const struct wl_interface sgx_wlegl_interface;

#ifndef SGX_WLEGL_ERROR_ENUM
#define SGX_WLEGL_ERROR_ENUM
enum sgx_wlegl_error {
	SGX_WLEGL_ERROR_BAD_HANDLE = 0,
	SGX_WLEGL_ERROR_BAD_VALUE = 1,
};
#endif /* SGX_WLEGL_ERROR_ENUM */

#define SGX_WLEGL_CREATE_BUFFER	0

static inline void
sgx_wlegl_set_user_data(struct sgx_wlegl *sgx_wlegl, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) sgx_wlegl, user_data);
}

static inline void *
sgx_wlegl_get_user_data(struct sgx_wlegl *sgx_wlegl)
{
	return wl_proxy_get_user_data((struct wl_proxy *) sgx_wlegl);
}

static inline void
sgx_wlegl_destroy(struct sgx_wlegl *sgx_wlegl)
{
	wl_proxy_destroy((struct wl_proxy *) sgx_wlegl);
}

static inline struct  wl_buffer *
sgx_wlegl_create_buffer(struct sgx_wlegl *sgx_wlegl, int32_t width, int32_t height, int32_t stride, int32_t format, int32_t handle)
{
	struct wl_proxy *id;

	id = wl_proxy_create((struct wl_proxy *) sgx_wlegl,
			     & wl_buffer_interface);
	if (!id)
		return NULL;

	wl_proxy_marshal((struct wl_proxy *) sgx_wlegl,
			 SGX_WLEGL_CREATE_BUFFER, id, width, height, stride, format, handle);

	return (struct  wl_buffer *) id;
}

#ifdef  __cplusplus
}
#endif

#endif
