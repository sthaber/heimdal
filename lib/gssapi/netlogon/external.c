/*
 * Copyright (c) 2010-2018 Kungliga Tekniska Högskolan
 * (Royal Institute of Technology, Stockholm, Sweden).
 * All rights reserved.
 *
 * Portions Copyright (c) 2010 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include "netlogon.h"

static gssapi_mech_interface_desc netlogon_mech = {
    GMI_VERSION,
    "netlogon",
    {6, rk_UNCONST("\x2a\x85\x70\x2b\x0e\x02") },
    0,
    _netlogon_acquire_cred,
    _netlogon_release_cred,
    _netlogon_init_sec_context,
    _netlogon_accept_sec_context,
    _netlogon_process_context_token,
    _netlogon_delete_sec_context,
    _netlogon_context_time,
    _netlogon_get_mic,
    NULL, /* gm_get_mic_iov */
    _netlogon_verify_mic,
    NULL, /* gm_verify_mic_iov */
    NULL,
    NULL,
    _netlogon_display_status,
    NULL,
    _netlogon_compare_name,
    _netlogon_display_name,
    _netlogon_import_name,
    _netlogon_export_name,
    _netlogon_release_name,
    _netlogon_inquire_cred,
    _netlogon_inquire_context,
    _netlogon_wrap_size_limit,
    _netlogon_add_cred,
    _netlogon_inquire_cred_by_mech,
    _netlogon_export_sec_context,
    _netlogon_import_sec_context,
    _netlogon_inquire_names_for_mech,
    _netlogon_inquire_mechs_for_name,
    _netlogon_canonicalize_name,
    _netlogon_duplicate_name,
    NULL,
    NULL,
    NULL,
    _netlogon_set_cred_option,
    NULL,
    _netlogon_wrap_iov,
    _netlogon_unwrap_iov,
    _netlogon_wrap_iov_length,
    NULL, /* gm_store_cred */
    NULL, /* gm_export_cred */
    NULL, /* gm_import_cred */
    NULL, /* gm_acquire_cred_from */
    NULL, /* gm_acquire_cred_impersonate_name */
    NULL, /* gm_iter_creds */
    NULL, /* gm_destroy_cred */
    NULL, /* gm_cred_hold */
    NULL, /* gm_cred_unhold */
    NULL, /* gm_cred_label_get */
    NULL, /* gm_cred_label_set */
    NULL, /* gm_mo */
    0,    /* gm_mo_num */
    NULL, /* gm_localname */
    NULL, /* gm_authorize_localname */
    NULL, /* gm_display_name_ext */
    NULL, /* gm_inquire_name */
    NULL, /* gm_get_name_attribute */
    NULL, /* gm_set_name_attribute */
    NULL, /* gm_delete_name_attribute */
    NULL, /* gm_export_name_composite */
    NULL, /* gm_duplicate_cred */
    NULL, /* gm_add_cred_from */
    NULL, /* gm_store_cred_into */
    NULL  /* gm_compat */
};

gssapi_mech_interface
__gss_netlogon_initialize(void)
{
    return &netlogon_mech;
}
