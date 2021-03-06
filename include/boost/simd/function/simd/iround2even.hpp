//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SIMD_IROUND2EVEN_INCLUDED
#define BOOST_SIMD_FUNCTION_SIMD_IROUND2EVEN_INCLUDED

#include <boost/simd/function/scalar/iround2even.hpp>
#include <boost/simd/arch/common/generic/function/autodispatcher.hpp>
#include <boost/simd/arch/common/generic/function/iround2even.hpp>
#include <boost/simd/arch/common/simd/function/iround2even.hpp>

#if defined(BOOST_HW_SIMD_X86)

#  if BOOST_HW_SIMD_X86 >= BOOST_HW_SIMD_X86_SSE2_VERSION
#    include <boost/simd/arch/x86/sse2/simd/function/iround2even.hpp>
#  endif

#endif

#endif
