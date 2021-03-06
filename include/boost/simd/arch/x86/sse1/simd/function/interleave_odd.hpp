//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS
    @copyright 2016 J.T.Lapreste

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_INTERLEAVE_ODD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_INTERLEAVE_ODD_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

//#include <boost/simd/function/shuffle.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd =  boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( interleave_odd_
                          , (typename A0)
                          , bs::sse_
                          , bs::pack_<bd::single_<A0>, bs::sse_>
                          , bs::pack_<bd::single_<A0>, bs::sse_>
                         )
  {
    BOOST_FORCEINLINE A0 operator() ( const A0 & a0
                                    , const A0 & a1 ) const BOOST_NOEXCEPT
    {
      return _mm_unpacklo_ps( details::shuffle<0, 2, 0, 2>(a0)
                            , details::shuffle<0, 2, 0, 2>(a1)
                            );
    }
  };
} } }

#endif

