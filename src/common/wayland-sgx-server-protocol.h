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

#ifndef SGX_SERVER_PROTOCOL_H
#define SGX_SERVER_PROTOCOL_H

#ifdef  __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>
#include "wayland-util.h"

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

/**
 * sgx_wlegl - SGX EGL graphics buffer support
 * @create_buffer: Create a wl_resource from the native handle
 *
 * Interface used in the SGX wrapper libEGL to share graphics buffers
 * between the server and the client.
 */
struct sgx_wlegl_interface {
	/**
	 * create_buffer - Create a wl_resource from the native handle
	 * @id: (none)
	 * @width: (none)
	 * @height: (none)
	 * @stride: (none)
	 * @format: (none)
	 * @handle: (none)
	 *
	 * Pass the Android native_handle_t to the server and attach it
	 * to the new wl_buffer object.
	 */
	void (*create_buffer)(struct wl_client *client,
			      struct wl_resource *resource,
			      uint32_t id,
			      int32_t width,
			      int32_t height,
			      int32_t stride,
			      int32_t format,
			      int32_t handle);
};

#ifdef  __cplusplus
}
#endif

#endif
