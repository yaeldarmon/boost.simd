//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SIMD_HMSB_INCLUDED
#define BOOST_SIMD_FUNCTION_SIMD_HMSB_INCLUDED

#include <boost/simd/function/scalar/hmsb.hpp>
#include <boost/simd/arch/common/generic/function/autodispatcher.hpp>
#include <boost/simd/arch/common/simd/function/hmsb.hpp>

#if defined(BOOST_HW_SIMD_X86)

#  if BOOST_HW_SIMD_X86 >= BOOST_HW_SIMD_X86_SSE_VERSION
#    include <boost/simd/arch/x86/sse1/simd/function/hmsb.hpp>
#  endif
#  if BOOST_HW_SIMD_X86 >= BOOST_HW_SIMD_X86_SSE2_VERSION
#    include <boost/simd/arch/x86/sse2/simd/function/hmsb.hpp>
#  endif
#  if BOOST_HW_SIMD_X86 >= BOOST_HW_SIMD_X86_SSSE3_VERSION
#    include <boost/simd/arch/x86/ssse3/simd/function/hmsb.hpp>
#  endif
#  if BOOST_HW_SIMD_X86 >= BOOST_HW_SIMD_X86_AVX_VERSION
// #    include <boost/simd/arch/x86/avx/simd/function/hmsb.hpp>
#  endif

#endif

#endif
