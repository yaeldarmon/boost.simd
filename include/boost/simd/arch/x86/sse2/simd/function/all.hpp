//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS
    @copyright 2016 J.T.Lapreste

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_ALL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_ALL_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/function/simd/genmask.hpp>
#include <boost/simd/logical.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd =  boost::dispatch;
  namespace bs =  boost::simd;
  BOOST_DISPATCH_OVERLOAD ( all_
                          , (typename A0)
                          , bs::sse2_
                          , bs::pack_<bd::type16_<A0>, bs::sse_>
                         )
  {
    using sA0 =  bd::scalar_of_t<A0>;
    BOOST_FORCEINLINE logical<sA0> operator() ( const A0 & a0) const BOOST_NOEXCEPT
    {
      return _mm_movemask_epi8(genmask(a0)) == 0xFFFF;
    }
  };


} } }

#endif
