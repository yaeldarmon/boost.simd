//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SIMD_FAST_TOINT_INCLUDED
#define BOOST_SIMD_FUNCTION_SIMD_FAST_TOINT_INCLUDED

#include <boost/simd/function/scalar/fast_toint.hpp>
#include <boost/simd/arch/common/generic/function/autodispatcher.hpp>

#if defined(BOOST_HW_SIMD_X86)

#  if BOOST_HW_SIMD_X86 >= BOOST_HW_SIMD_X86_AVX2_VERSION
// #    include <boost/simd/arch/x86/avx2/simd/function/fast_toint.hpp>
#  endif

#endif

#endif
