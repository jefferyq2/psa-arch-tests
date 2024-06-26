/** @file
 * Copyright (c) 2018-2024, Arm Limited or its affiliates. All rights reserved.
 * SPDX-License-Identifier : Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
**/

#include "test_crypto_common.h"

typedef struct {
    char                    test_desc[50];
    psa_algorithm_t         alg;
    const uint8_t          *input;
    size_t                  input_length;
    uint8_t                *source_hash;
    size_t                  source_hash_size;
    uint8_t                *target_hash;
    size_t                  target_hash_size;
    const uint8_t          *expected_hash;
    size_t                  expected_hash_length;
    psa_status_t            expected_status;
} test_data;

static const test_data check1[] = {
#ifndef ARCH_TEST_HASH_CLONE_UNSUPPORTED
#ifdef ARCH_TEST_MD2
{
    .test_desc            = "Test psa_hash_clone - MD2 algorithm\n",
    .alg                  = PSA_ALG_MD2,
    .input                = &hash_input,
    .input_length         = sizeof(hash_input),
    .source_hash          = expected_output,
    .source_hash_size     = BUFFER_SIZE/2,
    .target_hash          = (expected_output + BUFFER_SIZE/2),
    .target_hash_size     = BUFFER_SIZE/2,
    .expected_hash        = md2_hash,
    .expected_hash_length = 16,
    .expected_status      = PSA_SUCCESS,
},
#endif

#ifdef ARCH_TEST_MD4
{
    .test_desc            = "Test psa_hash_clone - MD4 algorithm\n",
    .alg                  = PSA_ALG_MD4,
    .input                = &hash_input,
    .input_length         = sizeof(hash_input),
    .source_hash          = expected_output,
    .source_hash_size     = BUFFER_SIZE/2,
    .target_hash          = (expected_output + BUFFER_SIZE/2),
    .target_hash_size     = BUFFER_SIZE/2,
    .expected_hash        = md4_hash,
    .expected_hash_length = 16,
    .expected_status      = PSA_SUCCESS,
},
#endif

#ifdef ARCH_TEST_MD5
{
    .test_desc            = "Test psa_hash_clone - MD5 algorithm\n",
    .alg                  = PSA_ALG_MD5,
    .input                = &hash_input,
    .input_length         = sizeof(hash_input),
    .source_hash          = expected_output,
    .source_hash_size     = BUFFER_SIZE/2,
    .target_hash          = (expected_output + BUFFER_SIZE/2),
    .target_hash_size     = BUFFER_SIZE/2,
    .expected_hash        = md5_hash,
    .expected_hash_length = 16,
    .expected_status      = PSA_SUCCESS,
},
#endif

#ifdef ARCH_TEST_RIPEMD160
{
    .test_desc            = "Test psa_hash_clone - RIPEMD160 algorithm\n",
    .alg                  = PSA_ALG_RIPEMD160,
    .input                = &hash_input,
    .input_length         = sizeof(hash_input),
    .source_hash          = expected_output,
    .source_hash_size     = BUFFER_SIZE/2,
    .target_hash          = (expected_output + BUFFER_SIZE/2),
    .target_hash_size     = BUFFER_SIZE/2,
    .expected_hash        = ripemd_160_hash,
    .expected_hash_length = 20,
    .expected_status      = PSA_SUCCESS,
},
#endif

#ifdef ARCH_TEST_SHA1
{
    .test_desc            = "Test psa_hash_clone - SHA1 algorithm\n",
    .alg                  = PSA_ALG_SHA_1,
    .input                = &hash_input,
    .input_length         = sizeof(hash_input),
    .source_hash          = expected_output,
    .source_hash_size     = BUFFER_SIZE/2,
    .target_hash          = (expected_output + BUFFER_SIZE/2),
    .target_hash_size     = BUFFER_SIZE/2,
    .expected_hash        = sha_1_hash,
    .expected_hash_length = 20,
    .expected_status      = PSA_SUCCESS,
},
#endif

#ifdef ARCH_TEST_SHA224
{
    .test_desc            = "Test psa_hash_clone - SHA224 algorithm\n",
    .alg                  = PSA_ALG_SHA_224,
    .input                = &hash_input,
    .input_length         = sizeof(hash_input),
    .source_hash          = expected_output,
    .source_hash_size     = BUFFER_SIZE/2,
    .target_hash          = (expected_output + BUFFER_SIZE/2),
    .target_hash_size     = BUFFER_SIZE/2,
    .expected_hash        = sha_224_hash,
    .expected_hash_length = 28,
    .expected_status      = PSA_SUCCESS,
},
#endif

#ifdef ARCH_TEST_SHA256
{
    .test_desc            = "Test psa_hash_clone - SHA256 algorithm\n",
    .alg                  = PSA_ALG_SHA_256,
    .input                = &hash_input,
    .input_length         = sizeof(hash_input),
    .source_hash          = expected_output,
    .source_hash_size     = BUFFER_SIZE/2,
    .target_hash          = (expected_output + BUFFER_SIZE/2),
    .target_hash_size     = BUFFER_SIZE/2,
    .expected_hash        = sha_256_hash,
    .expected_hash_length = 32,
    .expected_status      = PSA_SUCCESS,
},
#endif

#ifdef ARCH_TEST_SHA384
{
    .test_desc            = "Test psa_hash_clone - SHA384 algorithm\n",
    .alg                  = PSA_ALG_SHA_384,
    .input                = &hash_input,
    .input_length         = sizeof(hash_input),
    .source_hash          = expected_output,
    .source_hash_size     = BUFFER_SIZE/2,
    .target_hash          = (expected_output + BUFFER_SIZE/2),
    .target_hash_size     = BUFFER_SIZE/2,
    .expected_hash        = sha_384_hash,
    .expected_hash_length = 48,
    .expected_status      = PSA_SUCCESS,
},
#endif

#ifdef ARCH_TEST_SHA512
{
    .test_desc            = "Test psa_hash_clone - SHA512 algorithm\n",
    .alg                  = PSA_ALG_SHA_512,
    .input                = &hash_input,
    .input_length         = sizeof(hash_input),
    .source_hash          = expected_output,
    .source_hash_size     = BUFFER_SIZE/2,
    .target_hash          = (expected_output + BUFFER_SIZE/2),
    .target_hash_size     = BUFFER_SIZE/2,
    .expected_hash        = sha_512_hash,
    .expected_hash_length = 64,
    .expected_status      = PSA_SUCCESS,
},
#endif
#endif
};
