/*-
 * Copyright (c) 2005 Doug Rabson
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	$FreeBSD: src/lib/libgssapi/gss_verify_mic.c,v 1.1 2005/12/29 14:40:20 dfr Exp $
 */

#include "mech_locl.h"

GSSAPI_LIB_FUNCTION OM_uint32 GSSAPI_LIB_CALL
gss_verify_mic(OM_uint32 *minor_status,
    gss_const_ctx_id_t context_handle,
    const gss_buffer_t message_buffer,
    const gss_buffer_t token_buffer,
    gss_qop_t *qop_state)
{
	struct _gss_context *ctx = (struct _gss_context *) context_handle;
	gssapi_mech_interface m;

	if (qop_state)
	    *qop_state = 0;
	if (ctx == NULL) {
	    *minor_status = 0;
	    return GSS_S_NO_CONTEXT;
	}

	m = ctx->gc_mech;

	return (m->gm_verify_mic(minor_status, ctx->gc_ctx,
		    message_buffer, token_buffer, qop_state));
}

GSSAPI_LIB_FUNCTION OM_uint32 GSSAPI_LIB_CALL
gss_verify_mic_iov(
	OM_uint32 *minor_status,
	gss_const_ctx_id_t context_handle,
	gss_iov_buffer_desc *iov,
	int iov_count,
	const gss_buffer_t token_buffer)
{
	struct _gss_context *ctx = (struct _gss_context *) context_handle;
	gssapi_mech_interface m;

	if (ctx == NULL) {
		*minor_status = 0;
		return GSS_S_NO_CONTEXT;
	}

	m = ctx->gc_mech;

	if (m->gm_verify_mic_iov == NULL) {
		return GSS_S_UNAVAILABLE;
	}

	return (m->gm_verify_mic_iov(
		minor_status, ctx->gc_ctx, iov, iov_count, token_buffer));
}
