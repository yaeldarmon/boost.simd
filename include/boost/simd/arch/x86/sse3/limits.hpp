//==================================================================================================
/*!
  @file

  Aggregate SIMD numerical and type limits for X86 SSE3

  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE3_LIMITS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE3_LIMITS_HPP_INCLUDED

#include <boost/simd/arch/x86/tags.hpp>
#include <boost/simd/arch/common/limits.hpp>
#include <boost/simd/arch/x86/sse2/limits.hpp>

namespace boost { namespace simd
{
  template<> struct limits<boost::simd::sse3_> : limits<boost::simd::sse2_> {};
} }

#endif

