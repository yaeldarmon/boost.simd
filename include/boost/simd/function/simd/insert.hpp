//==================================================================================================
/*!
  @file

  Copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SIMD_INSERT_INCLUDED
#define BOOST_SIMD_FUNCTION_SIMD_INSERT_INCLUDED

#include <boost/simd/function/scalar/insert.hpp>
#include <boost/simd/arch/common/simd/function/insert.hpp>

#if defined(BOOST_HW_SIMD_X86)

#if BOOST_HW_SIMD_X86 >= BOOST_HW_SIMD_X86_SSE2_VERSION
#include <boost/simd/arch/x86/sse2/simd/function/insert.hpp>
#endif

#if BOOST_HW_SIMD_X86 >= BOOST_HW_SIMD_X86_SSE4_1VERSION
#include <boost/simd/arch/x86/sse4_1/simd/function/insert.hpp>
#endif

#if BOOST_HW_SIMD_X86 >= BOOST_HW_SIMD_X86_AVX_VERSION
// #include <boost/simd/arch/x86/avx/simd/function/insert.hpp>
#endif

#if BOOST_HW_SIMD_X86 >= BOOST_HW_SIMD_X86_AVX2_VERSION
// #include <boost/simd/arch/x86/avx2/simd/function/insert.hpp>
#endif

#endif
#endif

