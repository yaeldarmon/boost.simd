//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS
  Copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SIMD_BITWISE_CAST_INCLUDED
#define BOOST_SIMD_FUNCTION_SIMD_BITWISE_CAST_INCLUDED

#include <boost/simd/function/scalar/bitwise_cast.hpp>
#include <boost/simd/arch/common/generic/function/bitwise_cast.hpp>

#if defined(BOOST_HW_SIMD_X86)

#if BOOST_HW_SIMD_X86 >= BOOST_HW_SIMD_X86_SSE2_VERSION
#  include <boost/simd/arch/x86/sse2/simd/function/bitwise_cast.hpp>
#endif

#if BOOST_HW_SIMD_X86 >= BOOST_HW_SIMD_X86_AVX_VERSION
#  include <boost/simd/arch/x86/avx/simd/function/bitwise_cast.hpp>
#endif

#if BOOST_HW_SIMD_X86 >= BOOST_HW_SIMD_X86_AVX2_VERSION
#  include <boost/simd/arch/x86/avx2/simd/function/bitwise_cast.hpp>
#endif

#endif
#endif
